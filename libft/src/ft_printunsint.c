/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:39:17 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:36:15 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_countdec(long ln)
{
	int	i;

	i = 1;
	while (ln >= 10)
	{
		ln = ln / 10;
		i++;
	}
	return (i);
}

int	ft_printunsint(unsigned int n)
{
	long	ln;
	int		printed_chars;
	long	aux;

	aux = 0;
	printed_chars = 1;
	ln = (long)n;
	if (ln < 0)
		ln = 4294967295 + ln;
	aux = ln;
	if (ln > 9)
	{
		ft_printunsint((unsigned int)(ln / 10));
		ft_printchar(ln % 10 + 48);
	}
	else
		ft_printchar(ln + '0');
	printed_chars = ft_countdec(aux);
	return (printed_chars);
}
