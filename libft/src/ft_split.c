/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:57:35 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/30 11:54:15 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_mallocformat(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[0] != c && s[0] != '\0')
		count++;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			i++;
			count++;
			while (s[i] != '\'')
				i++;
		}
		else
		{
			if (s[i] == c && s[i + 1] && s[i + 1] != c && s[i + 1] != '\'' )
				count++;
		}
		i++;
	}
	return (count);
}

static int	nd(const char *s, char c, int i)
{
	if (s[i] == '\'')
	{
		c = '\'';
		i++;
	}
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == '\'')
		i++;
	return (i);
}

static int	ft_reduce_lines(char **mat, int count, int *mp)
{
	mat[count] = NULL;
	*mp = 0;
	return (0);
}

char	**ft_split(char const *s, char c, int i, int count)
{
	char	**m;
	int		mp;
	char	*temp;

	count = ft_mallocformat(s, c);
	m = (char **)malloc((count + 1) * sizeof(char *));
	if (m == NULL)
		return (NULL);
	i = ft_reduce_lines(m, count, &mp);
	while (mp < count)
	{
		while (s[i])
		{
			if (s[i] != c && s[i])
			{
				temp = ft_substr(s, i, (nd(s, c, i) - i));
				m[mp++] = ft_strtrim(temp, "\'");
				free (temp);
				i = nd(s, c, i);
			}
			else
				i++;
		}
	}
	return (m);
}
