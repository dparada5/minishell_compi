/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:19:45 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:35:42 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		{
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		}
		i++;
	}
	return (0);
}

/*int main(void)
{
	const void	*s1 = "Testing";
	const void	*s2 = "Testjng";
	size_t		n = 7;

	printf("First string: %s\n", s1);
	printf("Second string: %s\n", s2);
	printf("Lex diff: %d\n", ft_memcmp(s1, s2, n));
}*/