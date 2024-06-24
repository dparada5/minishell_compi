/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:29:02 by dparada           #+#    #+#             */
/*   Updated: 2024/06/24 13:50:13 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lib/LIBFT/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

# define RST    "\033[0m"      /* Reset to default color */
# define RED    "\033[1;31m"   /* Bold Red */
# define G      "\033[1;32m"   /* Bold Green */
# define Y      "\033[1;33m"   /* Bold Yellow */
# define B      "\033[1;34m"   /* Bold Blue */
# define M      "\033[1;35m"   /* Bold Magenta */
# define C      "\033[1;36m"   /* Bold Cyan */
# define W      "\033[1;37m"   /* Bold White */

/*tanselmo y misaguir estuvieron aquí :)*/

# define ERROR_FD	"FD doesn't exist"
# define ERROR_EOF 	"syntax error: unexpected end of file\n"
# define ERROR_UPIPE	"syntax error near unexpected token '|'\n"
# define ERROR_UT	"syntax error near unexpected token\n"
# define ERROR_SQ	"unexpected EOF while looking for matching quote '''\n"
# define ERROR_DQ	"unexpected EOF while looking for matching quote '\"'\n"
# define MALLOC_FAILED "malloc failed.\n"

typedef enum e_state_num
{
	S_S,
	S_W,
	S_QS,
	S_DQ,
	S_D,
	S_CD,
	S_SU,
}	t_state_num;

typedef enum e_token_num
{
	T_W,
	T_DQ,
	T_SQ,
	T_P,
	T_G,
	T_L,
	T_DG,
	T_DL,
}	t_token_num;

typedef struct s_token
{
	int				flag;
	t_token_num		token;
	char			*content;
	struct s_token	*next;
}				t_token;

typedef struct s_cmds
{
	char			*cmds;
	char			**cmds_flags;
	int				fd_in;
	int				fd_out;
	struct s_cmds	*next;
}				t_cmds;

typedef struct s_state
{
	t_state_num		type;
}				t_state;

typedef struct s_env
{
	char			*key;
	char			*content;
	struct s_env	*next;
}				t_env;

typedef struct s_minishell
{
	t_env		*env;
	t_env		*exp;
	t_token		*tokens;
	t_cmds		*cmds;
	char		**env_mat;
	char		*line;
	int			flag;
}				t_minishell;

//int main(void);
void	init_ev_exp(t_minishell *minishell, char **env);
void	init_minishell(t_minishell *minishell);
//------------------variable expand--------------------------
void	expansion(t_token *token, t_minishell *minishell);
char	*is_not_expandable(t_token *token, int *i);
char	*does_not_exist(t_token *token, char *var, int *i);
char	*expand(t_token *token, t_env *aux_env, int *i, int l);
//------------------actions----------------------------------
void	token_actions(t_minishell *minishell);
//_____cmds__________________________________________________
char	**cmds(t_token *token,int len, t_minishell *minishell);
t_token	*word_token(t_token *token, t_minishell *minishell);
// void	pop(t_token *token);
t_cmds	*new_cmd(int i, char **matrix, t_token *tokens, t_minishell *minishell);
t_cmds	*ft_lstadd_back_cmd(t_cmds **lst, t_cmds *new);
t_token	*command_create(t_token *token, t_minishell *minishell);
int	is_join(t_token *tokens);
//_____redirecc__________________________________________________
t_token	*open_to_close(t_token *token);
t_token *open_infile(t_token *token, t_cmds *cmds, t_minishell *minishell);
t_token *open_trunc(t_token *token, t_cmds *cmds, t_minishell *minishell);
t_token *open_append(t_token *token, t_cmds *cmds, t_minishell *minishell);
t_token	*here_doc(t_token *token, t_minishell *minishell);
//------------------token------------------------------------
int		words(char *line, t_token **token, int *i, int flag);
int		quotes(t_token **tokens, char *line, char c, int *i);
int		greater_token(char *line, t_token **token, int *i, int flag);
int		less_token(char *line, t_token **token, int *i, int flag);
t_token	*get_tokens(char *line, t_minishell *minishell);
int		create_token(t_token **token, t_token_num token_num, \
char *content, int flag);
//------------------token_utils------------------------------------
t_token	*new_token(t_token_num token_num, char *content, int flag);
t_token	**ft_lstadd_back_token(t_token **lst, t_token *new);
void	token_next(t_token *token, t_minishell *minishell);
//------------------states-----------------------------------
void	states(char *line, t_minishell *minishell);
//------------------env--------------------------------------
t_env	*save_env(char **env, int i, t_minishell *minishell);
//------------------utils------------------------------------
void	msj_error(char *str, t_minishell *minishell);
//------------------memory free------------------------------
// void	ft_lstclear_env(t_env **lst);
void	ft_lstclear_token(t_token *lst);
// void	ft_lstclear_cmds(t_cmds **lst);
void	ft_free_minishell(t_minishell *minishell, int bool);
//------------------prints------------------------------------
void	printf_tokens(t_token *token);
void	print_env(t_env *env);
void	printf_cmds(t_cmds *cmds);
void	print_state(t_state *state);
t_env	*ft_get_envvar(t_env *env, char *var_name);
#endif