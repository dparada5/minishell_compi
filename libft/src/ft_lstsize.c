/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:03:18 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:35:36 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (i);
	else
	{
		i++;
		while (lst->next)
		{
			i++;
			lst = lst->next;
		}
	}
	return (i);
}
