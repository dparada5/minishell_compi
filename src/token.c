/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:49:38 by dparada           #+#    #+#             */
/*   Updated: 2024/06/12 18:54:08 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	tokens(char *line, t_token **token, int *i)
{
	if (line[*i] == '|')
	{
		create_token(token, T_P, ft_strdup("|"), 1);
		(*i)++;
	}
	else if (line[*i] == '\'' || line[*i] == '\"')
		quotes(token, line, line[*i], i);
	else if (line[*i] == '>')
		greater_token(line, token, i, 1);
	else if (line[*i] == '<')
		less_token(line, token, i, 1);
	return (*i);
}

void	create_token(t_token **token, t_token_num token_num, \
char *content, int flag)
{
	t_token	*aux;

	if (!*token)
		*token = new_token(token_num, content, flag);
	else
	{
		aux = new_token(token_num, content, flag);
		if (!aux)
			return ;
		ft_lstadd_back_token(token, aux);
	}
	free(content);
}

t_token	*get_tokens(char *line)
{
	int		i;
	t_token	*token;

	i = 0;
	token = NULL;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (ft_strchr("|<>\"'", line[i]))
			tokens(line, &token, &i);
		else
			words(line, &token, &i, 1);
	}
	printf_tokens(token);
	token_next(token);
	return (token);
}
