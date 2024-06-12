/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:05:45 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:35:05 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*void	delete(void *content)
{
	free(content);
}*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del (lst->content);
	free(lst);
}

/*int	main(void)
{
	t_list	*node_one;
	t_list	*node_two;
	t_list	*print;
	char	*second_str;

	second_str = (char *)malloc(6);
	second_str = ft_strdup("Second");
	node_one = ft_lstnew("First");
	node_two = ft_lstnew(second_str);
	ft_lstadd_back(&node_one, node_two);
	print = node_one;
	while (print->next)
	{
		printf("%s\n", print->content);
		print = print->next;
	}
	printf("%s\n", print->content);
	ft_lstdelone(node_two, delete);
	print = node_one;
	while (print->next)
	{
		printf("%s\n", print->content);
		print = print->next;
	}
	printf("%s\n", print->content);
}*/
