/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:13:37 by dparada           #+#    #+#             */
/*   Updated: 2024/06/19 18:52:44 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*pop(t_token *token, char *buffer)
{
	t_token	*aux;
	char	*string;

	string = ft_strjoin(buffer, token->next->content);
	aux = token->next;
	token->next = aux->next;
	aux->next = NULL;
	ft_lstclear_token(&aux);
	return (string);
}

// static void	check_join(char *buffer, t_token *aux, int i, char **matrix)

char	**cmds(t_token *tokens, int i, char *buffer, int len)
{
	t_token	*aux;
	char	**matrix;
	char	*aux2;

	aux = tokens;
	matrix = ft_calloc(sizeof(char *) * (len + 1), 1);
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
				buffer = pop(aux, buffer);
			}
			matrix[i++] = ft_strdup(buffer);
			free(buffer);
		}
		aux = aux->next;
	}
	matrix[i] = NULL;
	return (matrix);
}
