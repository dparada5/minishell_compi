/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:36:46 by dparada           #+#    #+#             */
/*   Updated: 2024/06/19 18:52:34 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_get_envvar(t_env *env, char *var_name)
{
	t_env	*aux;

	aux = env;
	while (aux)
	{
		if (!ft_strncmp(aux->key, var_name, ft_strlen(aux->key)))
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}

t_env	*new_env(char *key, char *content)
{
	t_env	*env;

	env = ft_calloc(sizeof(t_env), 1);
	if (!env)
		return (NULL);
	env->key = ft_strdup(key);
	env->content = ft_strdup(content);
	if (!env->content || !env->key)
		return (NULL);
	env->next = NULL;
	free(key);
	return (env);
}

t_env	**ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*aux;

	aux = *lst;
	if (!(*lst))
		(*lst) = new;
	else if (*lst)
	{
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		(*lst)->next = new;
		(*lst) = aux;
	}
	return (lst);
}

t_env	*save_env(char **env, int i)
{
	int		j;
	t_env	*environment;
	t_env	*aux;

	while (env[++i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		if (i == 0)
		{
			environment = new_env(ft_substr(env[i], 0, j), &env[i][j + 1]);
			if (!environment)
				return (NULL);
		}
		else
		{
			aux = new_env(ft_substr(env[i], 0, j), &env[i][j + 1]);
			if (!aux)
				return (NULL);
			ft_lstadd_back_env(&environment, aux);
		}
	}
	return (environment);
}
