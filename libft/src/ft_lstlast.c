/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:17:42 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:35:10 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux;

	aux = lst;
	if (!lst)
		return (NULL);
	while (aux->next)
		aux = aux->next;
	return (aux);
}
