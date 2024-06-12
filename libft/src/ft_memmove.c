/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:49:12 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:35:48 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	i = 0;
	if (dst == src)
		return (dst);
	if (dst < src)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len > 0)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	return (dst);
}

/*int	main(void)
{
	char		dst[] = "1234567890";
	//const void	*src = "Copied";
	char		*copy;
	size_t		n = 4;

	printf("Original: %s\n", dst);
	copy = (char *)ft_memmove(dst + 1, dst, n);
	printf("Copy: %s\n", dst);
}*/
