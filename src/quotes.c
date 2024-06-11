/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:18:01 by dparada           #+#    #+#             */
/*   Updated: 2024/06/11 11:03:11 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*count_quotes(char *line, char c, int *flag, int *i)
{
	int	l;

	(*flag) = 0;
	while (line[*i] == c)
		(*i)++;
	// if ((*i) == (int)ft_strlen(line))
	// 	return (ft_substr(line, 1, (*i)++ - 2));
	if ((*i) > 1 &&  line[(*i) + 1] == ' ')
	{
		(*i)++;
		return (NULL);
	}
	l = (*i);
	(*flag) = 1;
	while (line[l])
	{
		if (line[l] == c && line[l + 1] == c)
			(*flag)++;
		l++;
	}
	return (NULL);
}

int	next_ocurrence(char *line, char c, char t)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != c)
			i++;
		else
			break ;
	}
	if (line[i] == c && t == 1)
		return (i);
	else if (t == 0)
	{
		if (line[i] == c && line[i + 1] == '\0')
			return (i);
		else
			return (i + 1);
	}
	return (i);
}

int	quotes(t_token **tokens, char *line, char c, int i)
{
	int		flag;
	char	*aux1;
	char	*aux2;
	char	*buffer;

	buffer = count_quotes(line, c, &flag, &i);
	while (flag > 0)
	{
		while (line[i] && line[i] == c)
			i++;
		aux1 = ft_substr(line, i, next_ocurrence(&line[i], c, 1));
		aux2 = buffer;
		if (!aux2)
			buffer = ft_strdup(aux1);
		else
			buffer = ft_strjoin(aux2, aux1);
		flag--;
		i += next_ocurrence(&line[i], c, 1);
		free(aux1);
	}
	if (buffer)
		create_token_list(tokens, T_W, buffer);
	i += next_ocurrence(&line[i], c, 0);
	return (i);
}
