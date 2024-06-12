/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 08:19:53 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:36:02 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_countdec(long ln)
{
	int	i;

	i = 1;
	if (ln < 0)
	{
		ln *= -1;
		i++;
	}
	while (ln >= 10)
	{
		ln /= 10;
		i++;
	}
	return (i);
}

int	ft_printdecimal(int n)
{
	long	ln;
	int		printed_chars;
	char	c;

	printed_chars = 1;
	ln = (long)n;
	c = '-';
	if (ln < 0)
	{
		ft_printchar(c);
		printed_chars++;
		ln *= -1;
	}
	if (ln > 9)
	{
		ft_printdecimal((int)(ln / 10));
		ft_printchar(ln % 10 + 48);
	}
	else
		ft_printchar(ln + '0');
	printed_chars = ft_countdec((long)n);
	return (printed_chars);
}
