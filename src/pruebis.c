/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:58:49 by dparada           #+#    #+#             */
/*   Updated: 2024/06/21 13:06:45 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*is_not_expandable(t_token *token, int *i)
{
	int	l;
	int	j;
	char	*aux;
	
	l = 0;
	j = 0;
	aux = malloc(sizeof(char) * (ft_strlen(token->content) - 1) + 1);
	if (!aux)
		return (NULL);
	while (token->content[j] != '\\')
		aux[l++] = token->content[j++];
	j++;
	while (token->content[j])
	{
		aux[l++] = token->content[j++];
		(*i)++;
	}
	aux[l] = '\0';
	
	return (aux);
}

char	*does_not_exist(t_token *token, char *var, int *i)
{
	int	l;
	int	j;
	char	*aux;
	
	l = 0;
	j = 0;
	if (token->content[0] == '$')
	{
		aux = ft_strdup("");
	}
	else
	{
		aux = malloc(sizeof(char) * (ft_strlen(token->content) - (ft_strlen(var)) + 1) + 1);
		if (!aux)
			return (NULL);
		while (token->content[j] != '$')
			aux[l++] = token->content[j++];
		j += ft_strlen(var) + 1;
		while (token->content[j])
			aux[l++] = token->content[j++];
		aux[l] = '\0';

	}
	*i += ft_strlen(var);
	return (aux);
}

char	*expand(t_token *token, t_env *aux_env, int *i, int l)
{
	int	j;
	int	len_str;
	int	total;
	char	*new_string;

	j = 0;
	len_str = ft_strlen(token->content);
	total = (len_str - (ft_strlen(aux_env->key) + 1));
	new_string = malloc(sizeof(char) * (total + ft_strlen(aux_env->content) + 1));
	if (!new_string)
		return (NULL);
	if (token->content[0] != '$')
	{
		while (j < *i)
			new_string[l++] = token->content[j++];
	}
	j = 0;
	while (aux_env->content[j])
		new_string[l++] = aux_env->content[j++];
	j = *i + ft_strlen(aux_env->key);
	*i += ft_strlen(aux_env->content);
	while (token->content[++j])
		new_string[l++] = token->content[j];
	new_string[l] = '\0';
	return (new_string);
}
