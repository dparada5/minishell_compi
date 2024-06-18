/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:46:28 by dparada           #+#    #+#             */
/*   Updated: 2024/06/18 18:56:20 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_join(t_token *tokens)
{
	if (tokens && (tokens->token == T_W \
	|| tokens->token == T_DQ || tokens->token == T_SQ))
	{
		if (tokens->flag == 1 && tokens->content)
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
	split = cmds(save, 0, NULL, i);
	if (minishell->cmds)
	{
		aux_cmd = new_cmd(i, split, token);
		if (!aux_cmd)
			return (NULL);
		ft_lstadd_back_cmd(&minishell->cmds, aux_cmd);
	}
	else
		minishell->cmds = new_cmd(i, split, token);
	return (aux);
}

t_token	*command_create(t_token *token, t_minishell *minishell)
{
	t_token	*aux;
	
	aux = token;
	while (aux)
	{
		if (aux->token >= T_G && aux->token <= T_DL && aux->next->next)
			aux = aux->next;
		else if (aux->token >= T_G && aux->token <= T_DL)
			aux = open_to_close(aux);
		else
			break ;
		aux = aux->next;
	}
	if (!aux)
		return (aux);
	aux = command_words(aux, 0, minishell, token);
	return (aux);
}
