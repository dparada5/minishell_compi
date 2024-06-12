/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:46:18 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:35:03 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*void	delete(void *content)
{
	free(content);
}*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
}

/*int	main(void)
{
	t_list	**list;
	t_list	*print;

	*list = ft_lstnew(ft_strdup("First"));
	ft_lstadd_back(list, ft_lstnew(ft_strdup("Second")));
	ft_lstadd_back(list, ft_lstnew(ft_strdup("Third")));
	ft_lstadd_back(list, ft_lstnew(ft_strdup("Fourth")));
	print = *list;
	while (print->next)
	{
		printf("%s -> ", print->content);
		print = print->next;
	}
	printf("%s\n", print->content);
	ft_lstclear(&((*list)->next)->next, delete);
	print = *list;
	while (print->next)
	{
		printf("%s -> ", print->content);
		print = print->next;
	}
	printf("%s\n", print->content);
}*/
