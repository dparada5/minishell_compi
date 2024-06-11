/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:50:58 by dparada           #+#    #+#             */
/*   Updated: 2024/06/11 17:24:39 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_minishell(t_minishell *minishell)
{
	// printf("%s\n", minishell->line);
	if (minishell->tokens || minishell->cmds || minishell->env)
	{
		if (minishell->tokens)
			ft_lstclear_token(&minishell->tokens);
		if (minishell->env)
			ft_lstclear_env(&minishell->env);
		if (minishell->cmds)
			ft_lstclear_cmds(&minishell->cmds);
		if (minishell->line)
			free(minishell->line);
	}
}