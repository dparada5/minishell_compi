/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:57:48 by malena-b          #+#    #+#             */
/*   Updated: 2023/09/20 10:09:58 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = (long)n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln > 9)
	{
		ft_putnbr_fd((int)(ln / 10), fd);
		ft_putchar_fd(ln % 10 + 48, fd);
	}
	else
		ft_putchar_fd(ln + '0', fd);
}
