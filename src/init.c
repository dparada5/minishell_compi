/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:40:10 by dparada           #+#    #+#             */
/*   Updated: 2024/06/25 15:05:21 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
//912

void	init_ev_exp(t_minishell *minishell, char **env)
{
	minishell->env = save_env(env, -1, minishell);
	minishell->exp = save_env(env, -1, minishell);
	minishell->val_error = 0;
}

void	check_line(t_minishell *minishell)
{
	states(minishell->line, minishell);
	minishell->tokens = get_tokens(minishell->line, minishell);
	expansion(minishell->tokens, minishell);
	printf_tokens(minishell->tokens);
	token_actions(minishell);
	printf_cmds(minishell->cmds);
}

void	init_minishell(t_minishell *minishell)
{
	minishell->line = readline("minishell> ");
	while (minishell->line)
	{
		minishell->tokens = NULL;
		minishell->cmds = NULL;
		if (!ft_strlen(minishell->line))
		{
			minishell->line = readline("minishell$ ");
			continue ;
		}
		if (ft_strcmp("exit", minishell->line) == 0)
		{
			ft_free_minishell(minishell, 1);
			write(1, "exit\n", 5);
			exit (0);
		}
		add_history(minishell->line);
		check_line(minishell);
		if (minishell->flag != 1)
		{
			ft_putstr_fd("al ejecutor\n", 2);
			minishell->val_error = 0;
		}
		ft_free_minishell(minishell, 0);
		minishell->line = readline("minishell$ ");
	}
	rl_clear_history();
}