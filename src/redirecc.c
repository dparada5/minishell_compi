/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:50:53 by dparada           #+#    #+#             */
/*   Updated: 2024/06/21 14:08:06 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token *open_append(t_token *token, t_cmds *cmds, t_minishell *minishell)
{
	token = token->next;
	if (cmds->fd_out != 1)
		close(cmds->fd_out);
	cmds->fd_out =  open(token->content, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (cmds->fd_out < 0)
		msj_error(ERROR_FD, minishell);
	return (token);
}

t_token *open_trunc(t_token *token, t_cmds *cmds, t_minishell *minishell)
{
	token = token->next;
	if (cmds->fd_out != 1)
		close(cmds->fd_out);
	cmds->fd_out =  open(token->content, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (cmds->fd_out < 0)
		msj_error(ERROR_FD, minishell);
	return (token);
}

t_token *open_infile(t_token *token, t_cmds *cmds, t_minishell *minishell)
{
	token = token->next;
	if (cmds->fd_in != 0)
		close(cmds->fd_in);
	cmds->fd_in =  open(token->content, O_RDONLY);
	if (cmds->fd_in < 0)
		msj_error(ERROR_FD, minishell);
	return (token);
}

t_token	*here_doc(t_token *token, t_minishell *minishell)
{
	int		fd;
	char	*line;
	int		len;

	line = NULL;
	(void)minishell;
	fd = open (".here_doc.tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	// if (fd < 0)
		// msj_error("FD doesn't exist\n");
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		len = ft_strlen(line) - 1;
		if (ft_strncmp(line, token->content, len) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	close (fd);
	unlink(".here_doc.tmp");
	// minishell->fd_in = open("here_doc.tmp", O_RDONLY);
	return (token->next);
}

// void	here_doc(char **argv, t_pipex *info)
// {
// 	int		fd;
// 	char	*line;

// 	line = NULL;
// 	fd = open ("here_doc.tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	if (fd < 0)
// 		ft_error("FD doesn't exist\n", 1);
// 	while (1)
// 	{
// 		write(1, "heredoc> ", 9);
// 		line = get_next_line(0);
// 		if (ft_strcmp(line, argv[2]) == 0)
// 		{
// 			free(line);
// 			break ;
// 		}
// 		ft_putstr_fd(line, fd);
// 		free(line);
// 	}
// 	close (fd);
// 	info->fd[0] = open("here_doc.tmp", O_RDONLY);
// }
