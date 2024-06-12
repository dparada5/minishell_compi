/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebis_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:17:00 by dparada           #+#    #+#             */
/*   Updated: 2024/06/12 16:04:17 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_quotes(char *line, int d, int s)
{
	int		i;

	i = 0;
	if (line[i] == d)
	{
		while (line[i] == d)
			i++;
	}
	if (line[i] == s)
	{
		while (line[i] == s)
			i++;
	}
	if (i > 2 && (line[i] == ' ' || line[i] == '\0'))
		return (0);
	else
		return (1);
}

char	*check_quotes(char *line, char d, char s)
{
	int	i;

	i = 0;
	if (count_quotes(line, d, s) == 0)
		return ("muchas comillas\n");
	while (line[i])
	{
		if (line[i] == d && line[i + 1] == d && line[i + 1])
			i++;
		if (line[i] == d && line[i + 1] != d && line[i + 1])
		{
			i++;
			while (line[i] != d && line[i])
			{
				if (line[i] == '$')
					 printf("expandeeeee\n");
				else
				{
					printf("guarda hasta la siguiente comilla doble dudeee\n");
				}
				printf("%c", line[i]);
				i++;
			}
			if (line[i] == d)
				i++;
			printf("\n");
		}
		if (line[i] == s && line[i + 1] == s)
			i++;
		if (line[i] == s && line[i + 1] != s && line[i + 1])
		{
			i++;
			printf("guarda hasta la siguiente comilla simp dudeee\n");
			while (line[i] != s && line[i])
			{
				printf("%c", line[i]);
				i++;
			}
			printf("\n");
			if (line[i] == s)
				i++;
		}
		i++;
	}
	return ("hoi");
}

int main(void)
{
	check_quotes("\"\"$USER\"\"", '\"', '\'');
}