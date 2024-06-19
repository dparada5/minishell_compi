
#include "../inc/mshell_exec.h"

void	ft_check_for_builtins(t_minishell *mshll)
{
	char	**cmds_flags;
	int		len;

	cmds_flags = mshll->cmds->cmds_flags;
	len = ft_strlen(cmds_flags[0]);
	if (ft_strncmp(cmds_flags[0], "cd", len) == 0)
		ft_cd(mshll, mshll->env, 0);
	if (ft_strncmp(cmds_flags[0], "echo", len) == 0)
		ft_echo(mshll->cmds);
	if (ft_strncmp(cmds_flags[0], "env", len) == 0)
		ft_env(mshll->env);
	if (ft_strncmp(cmds_flags[0], "exit", len) == 0)
		ft_exit(0, mshll);
	if (ft_strncmp(cmds_flags[0], "export", len) == 0 && !cmds_flags[1])
		ft_export_print(exp);
	if (ft_strncmp(cmds_flags[0], "export", len) == 0 && cmds_flags[1])
		ft_export_insert(mshll, exp, cmds_flags[1]);
	if (ft_strncmp(cmds_flags[0], "pwd", len) == 0)
		ft_pwd();
	if (ft_strncmp(cmds_flags[0], "unset", len) == 0)
		ft_unset(mshll, exp, cmds_flags[1]);
}

void	ft_executor(t_minishell *mshll)
{
	ft_check_for_builtins(mshll);
}

