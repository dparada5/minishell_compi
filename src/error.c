/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:02:54 by dparada           #+#    #+#             */
/*   Updated: 2024/06/25 14:04:32 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	msj_error(char *str, t_minishell *minishell, int val_error)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	minishell->flag = 1;
	minishell->val_error = val_error;
}

//mensaje ede error pa errores