/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:57:10 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:38:33 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = start;
	j = 0;
	if (ft_strlen(s) == 0 || len <= 0 || i > ft_strlen(s))
		return ((char *)ft_calloc(1, 1));
	while (s[i] && j < len)
	{
		i++;
		j++;
	}
	str = (char *)malloc((j + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s))
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
