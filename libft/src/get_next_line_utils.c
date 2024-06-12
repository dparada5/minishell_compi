/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:46:07 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:38:52 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *pre_read, char *buffer, int bytes_readed)
{
	char	*str;
	int		i;
	int		j;

	if (!pre_read)
		pre_read = ft_calloc(1, 1);
	str = malloc((ft_strlen(pre_read) + ft_strlen(buffer) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (pre_read[i])
		str[j++] = pre_read[i++];
	i = 0;
	while (i < bytes_readed)
		str[j++] = buffer[i++];
	str[j] = '\0';
	free (pre_read);
	return (str);
}
