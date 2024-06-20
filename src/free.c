/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:50:58 by dparada           #+#    #+#             */
/*   Updated: 2024/06/20 15:02:38 by dparada          ###   ########.fr       */
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
		free((*lst)->cmd);
		ft_free((*lst)->cmds_flags);
		if ((*lst)->fd_in != 0)
			close ((*lst)->fd_in);
		if ((*lst)->fd_out != 1)
			close ((*lst)->fd_out);
		free(*lst);
		*lst = aux;
	}
}

void	ft_lstclear_token(t_token **lst)
{
	t_token	*aux;

	aux = *lst;
	while (*lst)
	{
		aux = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = aux;
	}
}

void	ft_lstclear_env(t_env **lst)
{
	t_env	*aux;

	aux = *lst;
	while (*lst)
	{
		aux = (*lst)->next;
		free ((*lst)->key);
		free ((*lst)->content);
		free (*lst);
		*lst = aux;
	}
}

void	ft_free_minishell(t_minishell *minishell)
{
	if (minishell->tokens || minishell->cmds || minishell->env)
	{
		if (minishell->tokens)
			ft_lstclear_token(&minishell->tokens);
		// if (minishell->env)
		// 	ft_lstclear_env(&minishell->env);
		// if (minishell->exp)
		// 	ft_lstclear_env(&minishell->exp);
		if (minishell->cmds)
			ft_lstclear_cmds(&minishell->cmds);
		if (minishell->line)
			free(minishell->line);
	}
}
