/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:36:46 by dparada           #+#    #+#             */
/*   Updated: 2024/06/25 15:02:28 by dparada          ###   ########.fr       */
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

t_env	*new_env(char *key, char *content, t_minishell *minishell)
{
	t_env	*env;

	env = malloc (sizeof(t_env));
	if (!env)
		msj_error(MALLOC_FAILED, minishell, 0);
	env->key = ft_strdup(key);
	env->content = ft_strdup(content);
	if (!env->content || !env->key)
		msj_error(MALLOC_FAILED, minishell, 0);
	env->next = NULL;
	free(key);
	key = NULL;
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

t_env	*save_env(char **env, int i, t_minishell *minishell)
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
			environment = new_env(ft_substr(env[i], 0, j), &env[i][j + 1], minishell);
		else
		{
			aux = new_env(ft_substr(env[i], 0, j), &env[i][j + 1], minishell);
			ft_lstadd_back_env(&environment, aux);
		}
	}
	return (environment);
}
