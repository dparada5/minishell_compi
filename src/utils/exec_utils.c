/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:39:37 by malena-b          #+#    #+#             */
/*   Updated: 2024/06/24 13:49:23 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mshell_exec.h"

char	*ft_get_exec_path(t_minishell *mshll, char *cmd)
{
	int	i;
	t_env	*path_var;
	char	**path_splitted;
	char	*exec_line;
	char	join_aux;

	path_var = ft_get_envvar(mshll->env, "PATH");
	path_splitted = ft_split(path_var->content, ':', 0, 0);
	i = -1;
	while (path_splitted[++i])
	{
		join_aux = ft_strjoin(path_splitted[i], "/");
		exec_line = ft_strjoin(join_aux, cmd);
		free(join_aux);
		join_aux = NULL;
		if (access(exec_line, F_OK | X_OK) == 0)
			return (exec_line);
		free(exec_line);
		exec_line = NULL;
	}
	ft_free_mat(path_splitted);
	path_splitted = NULL;
	return (NULL);
}
