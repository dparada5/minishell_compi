/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:55:58 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:35:23 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mod_lst;
	t_list	*mod_node;

	if (!f || !del)
		return (NULL);
	mod_lst = NULL;
	while (lst)
	{
		mod_node = ft_lstnew(f(lst->content));
		if (!mod_node)
		{
			ft_lstclear(&mod_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&mod_lst, mod_node);
		lst = lst->next;
	}
	return (mod_lst);
}
