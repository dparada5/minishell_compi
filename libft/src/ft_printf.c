/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:11:14 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:36:04 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_checkprint(const char *str, va_list params, int i)
{
	int	printed_chars;

	printed_chars = 0;
	if (str[i + 1] == 'c')
		printed_chars = ft_printchar(va_arg(params, int));
	else if (str[i + 1] == 's')
		printed_chars = ft_printstr(va_arg(params, char *));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		printed_chars = ft_printdecimal(va_arg(params, int));
	else if (str[i + 1] == 'u')
		printed_chars = ft_printunsint(va_arg(params, unsigned int));
	else if (str[i + 1] == 'x' || str[i + 1] == 'X')
		printed_chars = ft_printhex(va_arg(params, unsigned long), str[i + 1]);
	else if (str[i + 1] == 'p')
	{
		printed_chars = ft_printhex(va_arg(params, unsigned long), str[i + 1]);
		printed_chars += 2;
	}
	else if (str[i + 1] == '%')
	{
		write (1, "%", 1);
		printed_chars++;
	}
	return (printed_chars);
}

int	ft_printf(char const *str, ...)
{
	va_list	params;
	int		i;
	int		printed_chars;

	printed_chars = 0;
	i = 0;
	va_start(params, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			write (1, &(str[i++]), 1);
			printed_chars++;
		}
		else
		{
			printed_chars += ft_checkprint(str, params, i);
			i += 2;
		}
	}
	va_end(params);
	return (printed_chars);
}
