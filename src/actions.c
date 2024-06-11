/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:00:17 by dparada           #+#    #+#             */
/*   Updated: 2024/06/07 16:18:43 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstclear_cmds(t_cmds **lst)
{
	t_cmds	*aux;
	int		i;

	i = 0;
	aux = *lst;
	while (*lst)
	{
		aux = (*lst)->next;
		free((*lst)->cmds);
		while ((*lst)->cmds_flags[i])
		{
			free((*lst)->cmds_flags[i]);
			i++;
		}
		free((*lst)->cmds_flags);
		free(*lst);
		*lst = aux;
	}
}

t_cmds	*new_cmd(int i, t_token *token)
{
	t_cmds	*cmds;
	t_token	*aux;

	aux = token;
	cmds = malloc(sizeof(t_cmds));
	if (!cmds)
		return (NULL);
	cmds->cmds = ft_strdup(aux->content);
	cmds->cmds_flags = malloc (sizeof(char *) * (i + 1));
	if (!cmds->cmds || !cmds->cmds_flags)
		return (NULL);
	i = 0;
	while (aux && aux->token == T_W)
	{
		cmds->cmds_flags[i] = ft_strdup(aux->content);
		if (!cmds->cmds_flags[i])
			return (NULL);
		i++;
		aux = aux->next;
	}
	cmds->cmds_flags[i] = NULL;
	cmds->next = NULL;
	return (cmds);
}

t_cmds	*ft_lstadd_back_cmd(t_cmds **lst, t_cmds *new)
{
	t_cmds	*aux;

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
	return (*lst);
}

t_token	*word_token(t_token *token, t_minishell *minishell)
{
	t_token	*aux;
	int		i;
	t_cmds	*aux_cmd;

	aux = token;
	i = 0;
	while (aux && aux->token == T_W)
	{
		i++;
		aux = aux->next;
	}
	if (minishell->cmds)
	{
		aux_cmd = new_cmd(i, token);
		if (!aux_cmd)
			return (NULL);
		ft_lstadd_back_cmd(&minishell->cmds, aux_cmd);
	}
	else
		minishell->cmds = new_cmd(i, token);
	return (aux);
}

void	token_actions(t_minishell *minishell)
{
	t_token	*aux;

	aux = minishell->tokens;
	while (aux)
	{
		if (aux->token == T_W)
			aux = word_token(aux, minishell);
		if (aux && aux->token == T_P)
			aux = aux->next;
		else if (aux && aux->token == T_G)
			aux = redirecc(minishell, aux);
		else if (aux && aux->token == T_L)
			aux = redirecc(minishell, aux);
		else if (aux && aux->token == T_DG)
			aux = redirecc(minishell, aux);
		else if (aux && aux->token == T_DL)
			aux = here_doc(aux->next, minishell);
	}
	// printf_cmds(minishell->cmds);
}
