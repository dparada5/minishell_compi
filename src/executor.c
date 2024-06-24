
#include "../inc/mshell_exec.h"

int	ft_check_for_builtins(t_minishell *mshll, t_cmds *cmd)
{
	char	**cmds_flags;
	int		len;

	cmds_flags = cmd->cmds_flags;
	len = ft_strlen(cmds_flags[0]);
	if (ft_strncmp(cmds_flags[0], "cd", len) == 0)
		ft_cd(mshll, mshll->env, 0);
	else if (ft_strncmp(cmds_flags[0], "echo", len) == 0)
		ft_echo(mshll->cmds);
	else if (ft_strncmp(cmds_flags[0], "env", len) == 0)
		ft_env(mshll->env);
	else if (ft_strncmp(cmds_flags[0], "exit", len) == 0)
		ft_exit(0, mshll);
	else if (ft_strncmp(cmds_flags[0], "export", len) == 0 && !cmds_flags[1])
		ft_export_print(mshll->exp);
	else if (ft_strncmp(cmds_flags[0], "export", len) == 0 && cmds_flags[1])
		ft_export_insert(mshll, cmds_flags[1]);
	else if (ft_strncmp(cmds_flags[0], "pwd", len) == 0)
		ft_pwd();
	else if (ft_strncmp(cmds_flags[0], "unset", len) == 0)
		ft_unset(mshll, cmds_flags[1]);
	else
		return (0);
	return (1);
}

//void	ft_factory(t_minishell *mshll, )

int	ft_kindergarden(t_minishell *mshll, t_cmds *cmd, int pipes_left)
{
	char	*exec_path;

	if (ft_check_for_builtins(mshll, cmd))
		exit(0);
	exec_path = ft_get_exec_path(mshll, cmd->cmds);
	//me falta añadir el env como matriz que está casi listo en env_utils
	execve(exec_path, mshll->cmds->cmds_flags, )
}

void	ft_bedroom(t_minishell *mshll, int	pipes_left)
{
	int		fd[2];
	pid_t	pid;
	t_cmds	*runner;
	int		kids;

	kids = 0;
	runner = mshll->cmds;
	while (pipes_left >= 0)
	{
		pid = fork();
		if (pid == -1)
			return ;//añadir gestión en este caso de error
		if (pid == 0)
			ft_kindergarden(mshll, runner, pipes_left);
		runner = runner->next;
		pipes_left--;
	}
}

void	ft_executor(t_minishell *mshll)
{
	int		pipes;

	pipes = ft_pipes_count(mshll);
	ft_bedroom(mshll, pipes);
}

