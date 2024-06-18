/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:13:37 by dparada           #+#    #+#             */
/*   Updated: 2024/06/18 20:06:18 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*pop(t_token *token)
{
	t_token	*aux;
	char	*string;

	string = ft_strjoin(token->content, token->next->content);
	aux = token->next;
	token->next = aux->next;
	aux->next = NULL;
	ft_lstclear_token(&aux);
	return (string);
}

// int	is_join(t_token *tokens)
// {
// 	if (tokens && (tokens->token == T_W \
// 	|| tokens->token == T_DQ || tokens->token == T_SQ))
// 	{
// 		if (tokens->flag == 1 && tokens->content)
// 			return (1);
// 	}
// 	else
// 		return (2);
// 	return (0);
// }

// t_token	*word_token(t_token *token, t_minishell *minishell, int i)
// {
// 	t_token	*aux;
// 	char	**split;
// 	t_cmds	*aux_cmd;

// 	aux = token;
// 	while (aux && aux->token != T_P)
// 	{
// 		if (aux->token >= T_G && aux->token <= T_DL)
// 			aux = aux->next;
// 		if (is_join(aux->next) == 0)
// 			i++;
// 		aux = aux->next;
// 	}
// 	split = cmds(&token, 0, NULL, i);
// 	if (minishell->cmds)
// 	{
// 		aux_cmd = new_cmd(i, split);
// 		if (!aux_cmd)
// 			return (NULL);
// 		ft_lstadd_back_cmd(&minishell->cmds, aux_cmd);
// 	}
// 	else
// 		minishell->cmds = new_cmd(i, split);
// 	return (aux);
// }

char	**cmds(t_token *tokens, int i, char *buffer, int len)
{
	t_token	*aux;
	char	**matrix;
	char	*aux2;

	aux = tokens;
	matrix = malloc (sizeof(char *) * (len + 1));
	if (!matrix)
		return (NULL);
	while (aux && aux->token != T_P)
	{
		if (aux->token >= T_G && aux->token <= T_DL)
			aux = aux->next;
		else if (aux->content)
		{
			buffer = ft_strdup(aux->content);
			while (is_join (aux->next) == 1)
			{
				aux2 = buffer;
				buffer = pop(aux);
			}
			matrix[i++] = ft_strdup(buffer);
			free(buffer);
		}
		aux = aux->next;
	}
	matrix[i] = NULL;
	return (matrix);
}
