/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_exec.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:58:58 by malena-b          #+#    #+#             */
/*   Updated: 2024/06/19 12:04:30 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSHELL_EXEC_H
# define MSHELL_EXEC_H

# include "./libft.h"
# include "./minishell.h"

//funciones de delfi que no tengo, solo para que no se queje de errores el código
void	ft_free_minishell(t_minishell *minishell);
t_env	**ft_lstadd_back_env(t_env **lst, t_env *new);

//-----------------------------------UTILS-----------------------------------//
t_env	*ft_get_envvar(t_env *env, char *var_name);
int		ft_change_envvar(t_env *env, char *var_name, char *new_value);
void	ft_swap_envnodes(t_env *prev, t_env *act, t_env *next, t_env *last);
t_env	*new_env_exp(char *key, char *content);

//----------------------------------BUILTINS---------------------------------//
int		ft_cd(t_minishell *minishell, t_env *env, int error_check);
void	ft_echo(t_cmds *cmd);
void	ft_env(t_env *env);
void	ft_exit(int error_code, t_minishell *minishell);
void	ft_export_print(t_env **exp);
void	ft_export_insert(t_minishell *mshll, t_env *exp, char *str);
void	ft_pwd(void);
void	ft_unset(t_minishell *mshll, t_env *exp, char *key_to_delete);

#endif