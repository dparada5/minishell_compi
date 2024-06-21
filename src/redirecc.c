/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:50:53 by dparada           #+#    #+#             */
/*   Updated: 2024/06/21 11:16:45 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



t_token	*here_doc(t_token *token, t_minishell *minishell)
{
	int		fd;
	char	*line;
	int		len;

	line = NULL;
	(void)minishell;
	fd = open (".here_doc.tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		msj_error("FD doesn't exist\n");
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
