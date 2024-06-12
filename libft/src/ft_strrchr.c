/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 08:14:42 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:38:16 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	const char	*last;
	int			i;

	last = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (const char)c)
			last = (const char *)&s[i];
		i++;
	}
	if ((unsigned char)c == '\0' && s[i] == '\0')
		return ((char *)&s[i]);
	return ((char *)last);
}
