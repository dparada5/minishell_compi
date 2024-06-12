/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 08:25:17 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:34:59 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if ((*lst) != NULL)
		(ft_lstlast(*lst))->next = new;
	else
		*lst = new;
}

/*int	main(void)
{
	t_list	**header;
	t_list	*temp;

	*header = ft_lstnew((char *)("First"));
	ft_lstadd_back(header, ft_lstnew((char *)("Second")));
	ft_lstadd_back(header, ft_lstnew((char *)("Third")));
	ft_lstadd_back(header, ft_lstnew((char *)("Fourth")));
	temp = *header;
	while (temp->next)
	{
		printf("%s -> ", temp->content);
		temp = temp->next;
	}
	printf("%s\n", temp->content);
}*/
