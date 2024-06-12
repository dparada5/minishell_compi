/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:00:58 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:36:07 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_sethex(unsigned long ln, char *base, int printed_chars)
{
	if (ln > 15)
	{
		printed_chars = ft_sethex(ln / 16, base, printed_chars);
		write (1, &(base[ln % 16]), 1);
		printed_chars++;
	}
	else
	{
		write (1, &(base[ln]), 1);
		printed_chars++;
	}
	return (printed_chars);
}

int	ft_printhex(unsigned long i, char c)
{
	char	*lowbase;
	char	*upbase;
	int		printed_chars;

	lowbase = "0123456789abcdef";
	upbase = "0123456789ABCDEF";
	printed_chars = 0;
	if (c == 'X')
		printed_chars = ft_sethex((unsigned int)i, upbase, printed_chars);
	else if (c == 'p')
	{
		write (1, "0x", 2);
		printed_chars = ft_sethex(i, lowbase, printed_chars);
	}
	else if (c == 'x')
		printed_chars = ft_sethex((unsigned int)i, lowbase, printed_chars);
	return (printed_chars);
}
