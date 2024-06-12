/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:21:15 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:38:27 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_checksamechars(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;
	int		i;

	if (!s1[0])
		return ((char *)ft_calloc(1, 1));
	start = 0;
	while (s1[start] && ft_checksamechars(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (ft_checksamechars(s1[end - 1], set) && end > start)
		end--;
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
