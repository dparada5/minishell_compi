/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 08:21:45 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:34:57 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_calcsize(int n, long ln)
{
	int		i;

	i = 1;
	while (ln > 9)
	{
		ln = ln / 10;
		i++;
	}
	if (n < 0)
		i += 2;
	else
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	long	ln;
	char	*str;
	int		len;

	ln = (long)n;
	if (ln < 0)
		ln *= -1;
	len = ft_calcsize(n, ln);
	str = (char *)ft_calloc(len, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (--len > 0 && ln >= 1)
	{
		str[len - 1] = ln % 10 + 48;
		ln = ln / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/*int	main(void)
{
	int		n;

	n = 0;
	printf("Original number: %d\n", n);
	printf("Number in array: %s\n", ft_itoa(n));
}*/