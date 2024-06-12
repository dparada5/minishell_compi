/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:45:46 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:38:45 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*read_and_save(int fd, char *pre_read)
{
	char		*buffer;
	char		*aux;
	int			bytes_readed;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_readed = 1;
	while (!ft_strchr(buffer, '\n') && bytes_readed > 0)
	{
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(pre_read);
			return (NULL);
		}
		aux = pre_read;
		pre_read = ft_strjoin_gnl(aux, buffer, bytes_readed);
	}
	free (buffer);
	if (ft_strlen_gnl(pre_read) == 0)
		return (free(pre_read), NULL);
	return (pre_read);
}

char	*get_new_line(char	*pre_read)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	while (pre_read[i] && pre_read[i] != '\n')
		i++;
	new_line = malloc((i + 1 + (pre_read[i] == '\n')) * sizeof(char));
	if (!new_line)
		exit (0);
	j = 0;
	while (j < i)
	{
		new_line[j] = pre_read[j];
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}

void	copy_read(char *pre_read, char *copy, int j, int len)
{
	int	i;

	i = 0;
	while (j < len)
	{
		copy[i] = pre_read[j];
		i++;
		j++;
	}
}

char	*clean_pre_read(char	*pre_read)
{
	int		i;
	int		j;
	char	*new_pre_read;

	i = 0;
	while (pre_read[i] && pre_read[i] != '\n')
		i++;
	if (!pre_read)
		return (free(pre_read), NULL);
	j = i;
	while (pre_read[j])
		j++;
	if (j - i <= 0)
	{
		free(pre_read);
		return (NULL);
	}
	new_pre_read = ft_calloc((j - i), sizeof(char));
	if (!new_pre_read)
		return (NULL);
	j = i + 1;
	copy_read(pre_read, new_pre_read, j, ft_strlen_gnl(pre_read));
	free (pre_read);
	return (new_pre_read);
}

char	*get_next_line(int fd)
{
	static char	*pre_read[1024];
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(pre_read[fd]);
		pre_read[fd] = NULL;
		return (NULL);
	}
	pre_read[fd] = read_and_save(fd, pre_read[fd]);
	if (!pre_read[fd])
		return (NULL);
	new_line = get_new_line(pre_read[fd]);
	pre_read[fd] = clean_pre_read(pre_read[fd]);
	return (new_line);
}
/* La función lo que hace es devolver la siguiente linea del fd dado como 
parámetro leyendo cada vez una cantidad de caracteres BUFFER_SIZE hasta que 
se encuentre el final de linea o del archivo.
Para ello, lo primero que hace es comprobar si en el buffer, que puede ya tener
un valor de una llamada previa, hay algún salto de linea usando ft_strchr.
Si lo hay, no volver a usar read, si no que creamos nuestra linea a imprimir
desde el inicio del buffer hasta el primer salto de linea que encontremos, tras
imprimirla modificar el buffer para eliminar la linea ya impresa por pantalla.
En el caso de que al comprobar el buffer no haya ningún salto de linea,
concatenar el buffer ya existente con el resultado de hacer un nuevo read al fd
y volver a imprimir por pantalla el buffer desde el inicio hasta el siguiente
salto de linea con su consecuente eliminación de los caracteres impresos del
buffer por pantalla*/