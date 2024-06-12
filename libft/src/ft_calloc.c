/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:00:32 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:34:30 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	len;
	size_t	i;

	i = 0;
	len = size * count;
	mem = malloc(len);
	if (mem == NULL)
		return (NULL);
	while (i < len)
	{
		((unsigned char *)mem)[i] = '\0';
		i++;
	}
	return (mem);
}
