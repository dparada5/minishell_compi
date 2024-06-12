/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_prueba.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:30:55 by dparada           #+#    #+#             */
/*   Updated: 2024/06/12 18:53:30 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	words(char *line, t_token **token, int *i, int flag)
{
	int start;

	start = *i;
	if (*i > 0 && line[*i - 1] == ' ')
		flag = 0;
	while (!ft_strchr("| <>\"\'", line[*i]) && line[*i])
		(*i)++;
	create_token(token, T_W, ft_substr(line, start, *i - start), flag);
}

int	greater_token(char *line, t_token **token, int *i, int flag)
{
	if (line[*i] == '>' && line[*i + 1] == '>')
	{
		create_token(token, T_DG, ft_strdup(">>"), flag);
		*i += 1;
	}
	else
		create_token(token, T_G, ft_strdup(">"), flag);
	*i += 1;
	return (0);
}

int	less_token(char *line, t_token **token, int *i, int flag)
{
	if (line[*i] == '<' && line[*i + 1] == '<')
	{
		create_token(token, T_DL, ft_strdup("<<"), flag);
		*i += 1;
	}
	else
		create_token(token, T_L, ft_strdup("<"), flag);
	*i += 1;
	return (0);
}

void	quotes(t_token **tokens, char *line, char c, int *i)
{
	int flag;
	int	start;

	flag = 1;
	if (*i > 0 && line[*i - 1] == ' ')
		flag = 0;
	start = ++(*i);
	while (line[*i] && line[*i] != c)
		(*i)++;
	if (c == '\"')
		create_token(tokens, T_DQ, ft_substr(line, start, *i - start), flag);
	else if (c == '\'')
		create_token(tokens, T_SQ, ft_substr(line, start, *i - start), flag);
	if (line[*i] == c)
		(*i)++;
}