/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:10:47 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/20 13:38:27 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*void	*ft_memchr(const void	*s, int c, size_t n)
{
	size_t	i;

	if (!c && !n)
		return (0);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(&s[i]));
		i++;
	}
	return (0);
}*/

/*int	main(void)
{
	const char	*s = "Helelo";
	int			c = 'e';
	size_t		n = 1;

	printf("String since last occurence in orig ft: %s\n", memchr(s, c, n));
	printf("String since last occurence in my ft: %s", ft_memchr(s, c, n));
}*/