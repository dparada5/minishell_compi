/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:14:58 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:38:10 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_check(const char	*h, const char	*n, size_t l, size_t	i)
{
	size_t	j;

	j = 0;
	while (n[j])
	{
		if (i >= l || n[j] != h[i])
			return (0);
		j++;
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t len)
{
	size_t	i;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
			if (ft_check(haystack, needle, len, i) == 1)
				return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
