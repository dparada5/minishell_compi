/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:13:37 by dparada           #+#    #+#             */
/*   Updated: 2024/06/12 19:11:02 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**cmds(int i, t_token *tokens)
{
	t_token	*aux;
	char	**matrix;
	char	*aux1;
	char	*aux2;
	char	*buffer;
	int		i;

	i = 0;
	aux = tokens;
	buffer = NULL;
	while (aux && (aux->token == T_W || aux->token == T_DQ || aux->token == T_SQ))
	{
		if (aux->content)
		{
			matrix[i] = ft_strdup(aux->content);
			if (aux->next && (aux->next->token == T_W || aux->next->token == T_DQ || aux->next->token == T_SQ))
			{
				if (aux->next->flag == 1)
				{
					aux2 = buffer;
					buffer = ft_strjoin(aux2, aux->next->content);
					free(aux2);
				}	
			}	
		}
		aux = aux->next;
	}
}
