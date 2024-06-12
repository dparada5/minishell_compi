/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:30:59 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:37:34 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_size;
	size_t	dst_size;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	i = dst_size;
	j = 0;
	if (dst_size >= dstsize)
		return (dstsize + src_size);
	while (i < (dstsize - 1) && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (src_size + dst_size);
}
