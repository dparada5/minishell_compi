/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:50:53 by dparada           #+#    #+#             */
/*   Updated: 2024/06/20 15:03:06 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*open_infile(t_token *token, t_cmds *cmds)
{
	token = token->next;
	if (cmds->fd_in != 0)
		close (cmds->fd_in);
	cmds->fd_in = open(token->content, O_RDONLY);
	if (cmds->fd_in < 0)
		msj_error(ERROR_FD);
	return (token);
}

t_token	*open_append(t_token *token, t_cmds *cmds)
{
	token = token->next;
	if (cmds->fd_out != 1)
		close (cmds->fd_out);
	cmds->fd_out = open(token->content, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (cmds->fd_out < 0)
		msj_error(ERROR_FD);
	return (token);
}

t_token	*open_trunc(t_token *token, t_cmds *cmds)
{
	token = token->next;
	if (cmds->fd_out != 1)
		close (cmds->fd_out);
	cmds->fd_out = open(token->content, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (cmds->fd_out < 0)
		msj_error(ERROR_FD);
	return (token);
}
t_token	*here_doc(t_token *token, t_minishell *minishell)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open ("here_doc.tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		msj_error(ERROR_FD);
	while (1)
	{
		line = readline("heredoc> ");
		if (ft_strcmp(line, token->content) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	close (fd);
	(void)minishell;
	// minishell->fd_in = open("here_doc.tmp", O_RDONLY);
	return (token->next);
}
