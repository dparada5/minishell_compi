/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:29:02 by dparada           #+#    #+#             */
/*   Updated: 2024/06/07 11:51:08 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
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
	T_P,
	T_G,
	T_L,
	T_DG,
	T_DL,
}	t_token_num;

typedef struct s_token
{
	t_token_num		token;
	char			*content;
	struct s_token	*next;
}				t_token;

typedef struct s_cmds
{
	char			*cmds;
	char			**cmds_flags;
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
	int				index;
	struct s_env	*next;
}				t_env;

typedef struct s_minishell
{
	t_env		*env;
	t_token		*tokens;
	t_cmds		*cmds;
	int			fd_in;
	int			fd_out;
	char		*line;
}				t_minishell;

#endif