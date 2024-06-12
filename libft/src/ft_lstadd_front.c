/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:43:39 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:35:01 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	t_list	*first_node;
	t_list	*second_node;
	t_list	*third_node;
	t_list	*new_first_node;
	t_list	*temp;

	first_node = ft_lstnew((char *)("Original first"));
	second_node = ft_lstnew((char *)("Second"));
	third_node = ft_lstnew((char *)("Third"));
	new_first_node = ft_lstnew("New first");
	ft_lstadd_back(&first_node, second_node);
	ft_lstadd_back(&first_node, third_node);
	temp = first_node;
	printf("Original chain: ");
	while (temp->next)
	{
		printf("%s -> ", temp->content);
		temp = temp->next;
	}
	printf("%s\n", temp->content);
	ft_lstadd_front(&first_node, new_first_node);
	temp = new_first_node;
	printf("Modified chain: ");
	while (temp->next)
	{
		printf("%s -> ", temp->content);
		temp = temp->next;
	}
	printf("%s\n", temp->content);
}*/
