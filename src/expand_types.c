/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:58:49 by dparada           #+#    #+#             */
/*   Updated: 2024/06/26 17:54:49 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*is_not_expandable(char *line, int *i)
{
	int		l;
	int		j;
	char	*aux;

	l = 0;
	j = 0;
	aux = malloc(sizeof(char) * (ft_strlen(line) - 1) + 1);
	if (!aux)
		return (NULL);
	while (line[j] != '\\')
		aux[l++] = line[j++];
	j++;
	while (line[j])
	{
		aux[l++] = line[j++];
		(*i)++;
	}
	aux[l] = '\0';
	return (aux);
}

char	*does_not_exist(char *line, char *var, int *i)
{
	int		l;
	int		j;
	char	*aux;

	l = 0;
	j = 0;
	if (line[0] == '$')
		aux = ft_strdup("");
	else
	{
		aux = malloc(sizeof(char) * (ft_strlen(line) - \
		(ft_strlen(var)) + 1) + 1);
		if (!aux)
			return (NULL);
		while (line[j] != '$')
			aux[l++] = line[j++];
		j += ft_strlen(var) + 1;
		while (line[j])
			aux[l++] = line[j++];
		aux[l] = '\0';
	}
	*i -= 1;
	return (aux);
}

char	*expand(char *line, t_env *aux_env, int *i, int l)
{
	int		j;
	int		total;
	char	*new_string;

	j = 0;
	total = (ft_strlen(line) - (ft_strlen(aux_env->key) + 1));
	new_string = malloc(sizeof(char) * \
	(total + ft_strlen(aux_env->content) + 1));
	if (!new_string)
		return (NULL);
	if (line[0] != '$')
	{
		while (j < *i)
			new_string[l++] = line[j++];
	}
	j = 0;
	while (aux_env->content[j])
		new_string[l++] = aux_env->content[j++];
	j = *i + ft_strlen(aux_env->key);
	*i += ft_strlen(aux_env->content);
	while (line[++j])
		new_string[l++] = line[j];
	new_string[l] = '\0';
	return (new_string);
}
