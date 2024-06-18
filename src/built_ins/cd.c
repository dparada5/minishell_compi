
#include "../../inc/mshell_exec.h"

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
