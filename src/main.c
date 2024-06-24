/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:40:10 by dparada           #+#    #+#             */
/*   Updated: 2024/06/24 12:59:07 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
//912

// void	init_minishell(char **env, t_minishell *minishell)
// {
// }

int	main(int argc, char **argv, char **env)
{
	t_minishell	*minishell;
	
	// char		*aux;
	(void)argv;
	(void)argc;
	minishell = malloc(sizeof(t_minishell));
	// init_minishell(env, minishell);
	minishell->line = readline("minishell> ");
	minishell->env = save_env(env, -1, minishell);
	minishell->exp = save_env(env, -1, minishell);
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
			ft_free_minishell(minishell);
			write(1, "exit\n", 5);
			exit (0);
		}
		add_history(minishell->line);
		states(minishell->line, minishell);
		minishell->tokens = get_tokens(minishell->line, minishell);
		if (!minishell->tokens)
			return (0);
		expansion(minishell->tokens, minishell);
		printf_tokens(minishell->tokens);
		token_actions(minishell);
		// printf_cmds(minishell->cmds);
		ft_free_minishell(minishell);
		minishell->line = readline("minishell$ ");
	}
	rl_clear_history();
}
