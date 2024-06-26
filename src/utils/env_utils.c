/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:18:29 by malena-b          #+#    #+#             */
/*   Updated: 2024/06/26 12:23:57 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mshell_exec.h"

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

int	ft_change_envvar(t_env *env, char *var_name, char *new_value)
{
	t_env	*aux;

	aux = env;
	while (aux->key != var_name && aux)
		aux = aux->next;
	if (!aux)
		return (0);
	free (aux->content);
	aux->content = ft_strdup(new_value);
	return (1);
}

void	ft_swap_envnodes(t_env *prev, t_env *act, t_env *next, t_env *last)
{
	prev->next = next;
	next->next = act;
	act->next = last;
}

t_env	*new_env_exp(char *key, char *content)
{
	t_env	*env;

	env = malloc (sizeof(t_env));
	if (!env)
		return (NULL);
	env->key = ft_strdup(key);
	if (content)
		env->content = ft_strdup(content);
	if ((!env->content && content) || !env->key)
		return (NULL);
	env->next = NULL;
	free(key);
	return (env);
}

void	ft_save_env_mat(t_minishell *mshll)
{
	int		size;
	int		i;
	t_env	*env_runner;
	char	*join_aux;

	if (mshll->env_mat)
		ft_free_mat(mshll->env_mat);
	mshll->env_mat = NULL;
	size =0;
	env_runner = mshll->env;
	while (env_runner)
	{
		size ++;
		env_runner = env_runner->next;
	}
	env_runner = mshll->env;
	mshll->env_mat = ft_calloc(size, sizeof(char *));
	i = -1;
	while (++i < size)
	{
		join_aux = ft_strjoin(env_runner->key, "=");
		mshll->env_mat[i] = ft_strjoin(join_aux, env_runner->content);
		free (join_aux);
		env_runner = env_runner->next;
	}
}
