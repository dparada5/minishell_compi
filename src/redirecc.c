/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:50:53 by dparada           #+#    #+#             */
/*   Updated: 2024/06/19 18:30:46 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// t_token	*here_doc(t_token *token, t_minishell *minishell)
// {
// 	int		fd;
// 	char	*line;
// 	int		len;

// 	line = NULL;
// 	(void)minishell;
// 	fd = open (".here_doc.tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	if (fd < 0)
// 		msj_error("FD doesn't exist\n");
// 	while (1)
// 	{
// 		write(1, "> ", 2);
// 		line = get_next_line(0);
// 		len = ft_strlen(line) - 1;
// 		if (ft_strncmp(line, token->content, len) == 0)
// 		{
// 			free(line);
// 			break ;
// 		}
// 		ft_putstr_fd(line, fd);
// 		free(line);
// 	}
// 	close (fd);
// 	unlink(".here_doc.tmp");
// 	// minishell->fd_in = open("here_doc.tmp", O_RDONLY);
// 	return (token->next);
// }

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
	minishell->fd_in = open("here_doc.tmp", O_RDONLY);
	return (token->next);
}
