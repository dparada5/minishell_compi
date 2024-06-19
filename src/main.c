/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:40:10 by dparada           #+#    #+#             */
/*   Updated: 2024/06/19 17:55:49 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
//912

void	init_minishell(char **env, t_minishell *minishell)
{
	minishell->env = save_env(env, -1);
	if (!minishell->env)
		return ;
	minishell->exp = save_env(env, -1);
	if (!minishell->exp)
		return ;
	minishell->cmds = NULL;
	minishell->tokens = NULL;
}

int	main(int argc, char **argv, char **env)
{
	t_minishell	*minishell;
	char		**split;
	int			i;

	(void)argv;
	(void)argc;
	i = 0;
	split = NULL;
	minishell = malloc(sizeof(t_minishell));
	init_minishell(env, minishell);
	minishell->line = readline("minishell> ");
	while (minishell->line)
	{
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
		states(minishell->line);
		minishell->tokens = get_tokens(minishell->line);
		if (!minishell->tokens)
			return (0);
		expansion(minishell->tokens, minishell);
		token_actions(minishell);
		ft_free_minishell(minishell);
		minishell->line = readline("minishell$ ");
	}
	rl_clear_history();
}
