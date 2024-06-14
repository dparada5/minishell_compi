/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:40:10 by dparada           #+#    #+#             */
/*   Updated: 2024/06/14 09:36:38 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
//912

void	init_minishell(char **env, t_minishell *minishell)
{
	minishell->env = save_env(env, 0);
	if (!minishell->env)
		return ;
	minishell->exp = save_env(env, 0);
	if (!minishell->env)
		return ;
	minishell->cmds = NULL;
	minishell->tokens = NULL;
}

int	main(int argc, char **argv, char **env)
{
	t_minishell	minishell;
	char		**split;
	
	// char		*aux;
	(void)argv;
	(void)argc;
	split = NULL;
	init_minishell(env, &minishell);
	minishell.line = readline("minishell$ ");
	while (minishell.line)
	{
		if (!ft_strlen(minishell.line))
		{
			minishell.line = readline("minishell$ ");
			continue ;
		}
		if (ft_strcmp("exit", minishell.line) == 0)
		{
			ft_free_minishell(&minishell);
			write(1, "exit\n", 5);
			exit (0);
		}
		add_history(minishell.line);
		states(minishell.line);
		minishell.tokens = get_tokens(minishell.line);
		if (!minishell.tokens)
			return (0);
		token_actions(&minishell);
		ft_free_minishell(&minishell);
		minishell.line = readline("minishell$ ");
	}
	rl_clear_history();
}
