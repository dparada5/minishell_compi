/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_exec.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:58:58 by malena-b          #+#    #+#             */
/*   Updated: 2024/06/11 14:12:14 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSHELL_EXEC_H
# define MSHELL_EXEC_H

# include "./libft.h"
# include "./minishell.h"

t_env	*ft_get_envvar(t_env *env, char *var_name);
int		ft_change_envvar(t_env *env, char *var_name, char *new_value);

#endif