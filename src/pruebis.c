/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:58:49 by dparada           #+#    #+#             */
/*   Updated: 2024/06/13 18:21:04 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_flag(char *line, char d, char s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (line[i])
	{
		if (line[i] == d && line[i + 1] == s)
		{
			flag++;
			i++;
		}
		else if (line[i] == s && line[i + 1] == d)
		{
			flag++;
			i++;
		}
		else if (line[i] == d || line[i] == s)
			flag++;
		i++;
	}
	return (i - flag);
}

char	*copy_quote(char *line, char d, char s, int j)
{
	int		i;
	char	c;
	char	*dst;

	i = count_flag (line, d, s);
	dst = malloc (sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == d && line[i + 1] == s)
			i++;
		else if (line[i] == s && line[i + 1] == d)
			i++;
		if (line[i] == d || line[i] == s)
		{
			c = line[i];
			while (line[i] == c)
				i++;
		}
		dst[j++] = line[i++];
	}
	dst[j] = '\0';
	return (dst);
}

char	*rm_quotes(char *line, char d, char s)
{
	int		i;
	char	*dst;

	i = 0;
	if (line[i] == d)
	{
		while (line[i] == d)
			i++;
	}
	if (line[i] == s)
	{
		while (line[i] == s)
			i++;
	}
	if (i > 2 && (line[i] == ' ' || line[i] == '\0'))
		return (line);
	dst = copy_quote(line, d, s, 0);
	free(line);
	return (dst);
}
int	quotes(t_token **tokens, char *line, char c, int i)
{
	int		flag;
	char	*aux1;
	char	*aux2;
	char	*buffer;

	buffer = count_quotes(line, c, &flag, &i);
	if (buffer)
		i = ft_strlen(line) - i;
	while (flag > 0)
	{
		while (line[i] && line[i] == c)
			i++;
		aux1 = ft_substr(line, i, next_ocurrence(&line[i], c));
		aux2 = buffer;
		if (!aux2)
			buffer = ft_strdup(aux1);
		else
			buffer = ft_strjoin(aux2, aux1);
		flag--;
		i += next_ocurrence(&line[i], c);
		free(aux1);
	}
	if (buffer)
		create_token_list(tokens, T_W, buffer);
	return (i + 1);
}