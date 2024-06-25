/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:37:30 by dparada           #+#    #+#             */
/*   Updated: 2024/06/25 15:14:03 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*val_error(t_minishell *minishell, t_token *token, int *i, int l)
{
	char	*new_string;
	char	*val;
	int		j;

	j = 0;
	val = ft_itoa(minishell->val_error);
	new_string = malloc(((ft_strlen(token->content) - 2) + \
	ft_strlen(val) + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	if (token->content[0] != '$')
	{
		while (j < *i)
			new_string[l++] = token->content[j++];
	}
	j = 0;
	while (val[j])
		new_string[l++] = val[j++];
	j = *i + 2;
	while (token->content[j])
		new_string[l++] = token->content[j++];
	new_string[l] = '\0';
	minishell->val_error = 0;
	*i += ft_strlen(val);
	return (new_string);
}


static char	*get_var(t_token *token, int *i, int len, t_minishell *minishell)
{
	int	j;
	int	l;
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
	if (!aux && minishell->flag == 0)
		msj_error(MALLOC_FAILED, minishell, 0);
	j = *i;
	l = 0;
	while (++j <= len)
		aux[l++] = token->content[j];
	aux[l] = '\0';
	return (aux);
}

static char	*check_var(t_minishell *minishell, t_token *token, t_env *aux_env, int *i)
{
	char	*aux;
	char	*new_string;
	
	aux = get_var(token, i, *i, minishell);
	aux_env = ft_get_envvar(minishell->env, aux);
	if (token->content[*i - 1] == '\\')
		new_string = is_not_expandable(token, i - 1);
	else if (token->content[*i + 1] == '?')
		new_string = val_error(minishell, token, i, 0);
	else if (!aux_env)
		new_string = does_not_exist(token, aux, i);
	else
		new_string = expand(token, aux_env, i, 0);
	if (!new_string && minishell->flag == 0)
		msj_error(MALLOC_FAILED, minishell, 0);
	// *i += ft_strlen(aux_env->content);
	// free(token->content);
	return (new_string);
}

void	expansion(t_token *token, t_minishell *minishell)
{
	int	i;
	t_token	*aux;

	aux = token;
	if (minishell->flag != 1)
	{
		while (aux)
		{
			if (aux->token == T_W || aux->token == T_DQ)
			{
				i = 0;
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
	
}
