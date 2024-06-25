/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:46:28 by dparada           #+#    #+#             */
/*   Updated: 2024/06/25 12:54:11 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_join(t_token *tokens)
{
	if (tokens && (tokens->token == T_W \
	|| tokens->token == T_DQ || tokens->token == T_SQ))
	{
		if (tokens->content && tokens->flag == 1)
			return (1);
	}
	else
		return (2);
	return (0);
}

t_token	*command_words(t_token *aux, int i, t_minishell *minishell, t_token *token)
{
	char	**split;
	t_cmds	*aux_cmd;
	t_token	*save;

	save = aux;
	while (aux && aux->token != T_P)
	{
		if (aux->token >= T_G && aux->token <= T_DL)
			aux = aux->next;
		if (is_join(aux->next) == 0)
			i++;
		aux = aux->next;
	}
	split = cmds(save, i, minishell);
	if (minishell->cmds)
	{
		aux_cmd = new_cmd(i, split, token, minishell);
		ft_lstadd_back_cmd(&minishell->cmds, aux_cmd);
	}
	else
		minishell->cmds = new_cmd(i, split, token, minishell);
	return (aux);
}

t_token	*command_create(t_token *token, t_minishell *minishell)
{
	t_token	*aux;
	
	aux = token;
	while (aux)
	{
		//que hago con pipe
		if (aux->token >= T_G && aux->token <= T_DL && aux->next->next)
			aux = aux->next;
		else if (aux->token >= T_G && aux->token <= T_DL)
			aux = open_to_close(aux);
		else if (ft_strlen(aux->content) > 0)
			break ;
		aux = aux->next;
	}
	if (!aux)
		return (aux);
	aux = command_words(aux, 1, minishell, token);
	//puede llegar a ser un error hacer i = 1;
	return (aux);
}
