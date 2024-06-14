/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:37:30 by dparada           #+#    #+#             */
/*   Updated: 2024/06/14 16:13:42 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_var(t_token *token, int *i, int len)
{
	int		j;
	int		l;
	char	*aux;

	j = *i + 1;
	l = 0;
	while (token->content[j])
	{
		if (ft_isalnum(token->content[j]) == 0 && token->content[j] != '_')
			break ;
		len++;
		j++;
		l++;
	}
	aux = malloc(sizeof(char) * (l + 1));
	if (!aux)
		return (NULL);
	j = *i;
	l = 0;
	while (++j <= len)
		aux[l++] = token->content[j];
	aux[l] = '\0';
	return (aux);
}

char	*check_var(t_minishell *minishell, t_token *token, t_env *aux_env, \
int *i)
{
	char	*aux;
	char	*new_string;

	aux = get_var(token, i, *i);
	aux_env = ft_get_envvar(minishell->env, aux);
	if (token->content[*i - 1] == '\\')
		new_string = is_not_expandable(token, i - 1);
	else if (!aux_env)
		new_string = does_not_exist(token, aux, i);
	else
		new_string = expand(token, aux_env, i, 0);
	if (!new_string)
		return (NULL);
	// free(token->content);
	return (new_string);
}

void	expansion(t_token *token, t_minishell *minishell)
{
	int		i;
	t_token	*aux;

	aux = token;
	while (aux)
	{
		i = 0;
		if (aux->token == T_W || aux->token == T_DQ)
		{
			while (aux->content[i])
			{
				if (aux->content[i] == '$')
					aux->content = check_var(minishell, aux, NULL, &i);
				else
					i++;
			}
		}
		aux = aux->next;
	}
}
