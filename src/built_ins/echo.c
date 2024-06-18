
#include "../../inc/mshell_exec.h"

void	ft_echo(t_cmds *cmd)
{
	int	nnl_flag;
	int	i;

	nnl_flag = 0;
	i = 1;
	if (!ft_strncmp(cmd->cmds_flags[1], "-n", 3))
	{
		nnl_flag = 1;
		i = 2;
	}
	while (cmd->cmds_flags[i])
	{
		ft_putstr_fd(cmd->cmds_flags[i], 1);
		if (cmd->cmds_flags[i + 1])
			write (1, " ", 1);
	}
	if (!nnl_flag)
		write(1, "\n", 1);
}
