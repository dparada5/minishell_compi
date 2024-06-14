/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:37:30 by dparada           #+#    #+#             */
/*   Updated: 2024/06/14 10:46:40 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_var(t_token *token, int *i)
{
	int	j;
	int	l;
	char	*aux;
	
	j = *i;
	l = 0;
	*i++;
	while (token->content[*i])
	{
		if (ft_isalnum(token->content[*i]) == 0 && token->content[i] != '_')
			break ;
		*i++;
	}
	aux = malloc(sizeof(char) * (*i + 1));
	if (!aux)
		return (NULL);
	while (++j < *i)
		aux[l++] = token->content[j];
	aux[l] = '\0';
	return (aux);
}

char	replace(t_token *token, int len_env, int len_str, char *aux)
{
	int	l;
	int	i;
	int	total;
	char	*new_string;
	
	total = (len_str - ft_strlen(aux) + 1) + len_env;
	new_string = malloc(sizeof(char) * total + 1);
	if (token->content[0] != '$' && token->content != '\\')
	{
		while (token->content[i] && token->content[0] != '$' && token->content != '\\')
	}
}

char	*check_var(t_minishell *minishell, t_token *token, t_env *aux_env, int *i)
{
	int	len_env;
	int	len_str;
	int	total;
	char	*aux;
	char	*new_string;
	
	if (token->content[*i - 1] == '\\')
		return (token->content);
	aux = get_var(token, i);
	aux_env = ft_get_envvar(minishell->env, aux);
	len_env = ft_strlen(aux_env->content);
	len_str = ft_strlen(token->content);
	
	
}

t_token *expansion(t_token *token)
{
	int	i;
	t_token	*aux;

	aux = token;
	i = 0;
	while (aux)
	{
		if (aux->token == T_W || aux->token == T_DQ)
		{
			while (aux->content[i])
			{
				if (aux->content[i] == '$')
					aux->content = check_var(aux->content, &i);
				else
					i++;
			}
		}
	}
}