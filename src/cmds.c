/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:13:37 by dparada           #+#    #+#             */
/*   Updated: 2024/06/20 15:15:28 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*pop(t_token *token, char *aux2)
{
	t_token	*aux;
	char	*string;

	string = ft_strjoin(aux2, token->next->content);
	aux = token->next;
	token->next = aux->next;
	aux->next = NULL;
	ft_lstclear_token(&aux);
	return (string);
}

static char	*check_join(t_token *aux)
{
	char	*aux2;
	char	*buffer;
	
	buffer = ft_strdup(aux->content);
	while (is_join (aux->next) == 1)
	{
		aux2 = buffer;
		buffer = pop(aux, aux2);
		aux2 = NULL;
	}
	// matrix[i++] = ft_strdup(buffer);
	// free(buffer);
	// buffer = NULL;
	return (buffer);
}

char	**cmds(t_token *tokens, int i, int len)
{
	t_token	*aux;
	char	**matrix;

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
			matrix[i++] = check_join(aux);
			
			
		}
		aux = aux->next;
	}
	matrix[i] = NULL;
	return (matrix);
}

void	token_actions(t_minishell *minishell)
{
	t_token	*aux;
	int		i;

	i = 0;
	aux = minishell->tokens;
	while (aux)
	{
		if (aux && aux->token == T_P)
			aux = aux->next;
		else
			aux = command_create(aux, minishell);
	}
	printf_cmds("en token to cmds", minishell->cmds);
}
