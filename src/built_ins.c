
#include "../inc/mshell_exec.h"

void	ft_env(t_env *env)
{
	t_env	*aux;

	aux = env;
	while (aux)
	{
		ft_putstr_fd(aux->key, 1);
		write(1, '=', 1);
		ft_putendl_fd(aux->content, 1);
		aux = aux->next;
	}
}

void	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		perror("error at getcwd()");
	ft_printf("%s\n", cwd);
	free (cwd);
}

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

int	ft_cd_dir(char	*pre_path, char *end_path, t_env *env)
{
	char	*aux;
	int		return_value ;
	t_env	*pwd;
	t_env	*oldpwd;

	pwd = ft_get_envvar(env, "PWD");
	oldpwd = ft_get_envvar(env, "OLDPWD");
	aux = ft_strjoin(pre_path, end_path);
	free (pre_path);
	ft_change_envvar(env, "OLDPWD", pwd->content);
	ft_change_envvar(env, "PWD", aux);
	return_value = chdir(aux);
	free (aux);
	return (return_value);
}
//Hay que ver como reducir esta mierda en varias funciones para que la jodida norminette no se queje
int	ft_cd(t_minishell *minishell)
{
	t_env	*env;
	t_env	*pwd;
	t_env	*oldpwd;
	char	*aux_pwd;
	char	*new_dir;
	int		error_check;

	env = minishell->env;
	pwd = ft_get_envvar(env, "PWD");
	oldpwd = ft_get_envvar(env, "OLDPWD");
	aux_pwd = NULL;
	new_dir = minishell->cmds->cmds_flags[1];
	if (!new_dir || !ft_strncmp("~", new_dir, ft_strlen(new_dir)))
	{
		ft_change_envvar(env, "OLDPWD", pwd->content);
		ft_change_envvar(env, "PWD", ft_get_envvar(env, "HOME")->content);
		error_check = chdir(pwd->content);
	}
	else if (!ft_strncmp("-", new_dir, ft_strlen(new_dir)))
	{
		aux_pwd = ft_strdup(oldpwd->content);
		ft_change_envvar(env, "OLDPWD", pwd->content);
		ft_change_envvar(env, "PWD", aux_pwd);
		free (aux_pwd);
		error_check = chdir(pwd->content);
	}
	else
		error_check = ft_cd_dir(ft_strjoin(pwd->content, "/"), new_dir, env);
	return (error_check);
}
