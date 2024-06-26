/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:00:17 by dparada           #+#    #+#             */
/*   Updated: 2024/06/26 16:19:58 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// t_token	*open_to_close(t_token *token, t_minishell *minishell)
// {
// 	int	fd;

// 	fd = 0;
// 	if (token->token == T_G)
// 	{
// 		token = token->next;
// 		fd = open(token->content, O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	}
// 	else if (token->token == T_DG)
// 	{
// 		token = token->next;
// 		fd = open(token->content, O_RDWR | O_CREAT | O_APPEND, 0644);
// 	}
// 	else if (token->token == T_L)
// 	{
// 		token = token->next;
// 		fd = open(token->content, O_RDONLY);
// 		if (fd < 0)
// 			msj_error("No such file or directory\n", minishell, 1);
// 	}
// 	else if (token->token == T_DL)
// 	{
// 		token = token->next;
// 		here_doc(token, NULL, minishell);
// 		unlink(".here_doc.tmp");
// 	}
// 	if (fd > 0)
// 		close(fd);
// 	return (token);
// }

void	file_descriptor(t_cmds *cmds, t_token *tokens, t_minishell *minishell)
{
	t_token	*aux;

	aux = tokens;
	while (aux && aux->token != T_P)
	{
		if (aux->token == T_DG)
			aux = open_append(aux, cmds, minishell);
		else if (aux->token == T_L)
			aux = open_infile(aux, cmds, minishell);
		else if (aux->token == T_G)
			aux = open_trunc(aux, cmds, minishell);
		else if (aux->token == T_DL)
			aux = here_doc(aux->next, cmds, minishell);
		if (aux)
			aux = aux->next;
	}
}

t_cmds	*new_cmd(int i, char **matrix, t_token *tokens, t_minishell *minishell)
{
	t_cmds	*cmds;

	cmds = ft_calloc(sizeof(t_cmds), 1);
	if (!cmds && minishell->flag != 1)
		msj_error(MALLOC_FAILED, minishell, 0);
	cmds->cmds = ft_strdup(matrix[0]);
	cmds->cmds_flags = ft_calloc (sizeof(char *), (i + 1));
	if ((!cmds->cmds || !cmds->cmds_flags) && minishell->flag != 1)
		msj_error(MALLOC_FAILED, minishell, 0);
	i = 0;
	while (matrix[i])
	{
		cmds->cmds_flags[i] = ft_strdup(matrix[i]);
		if (!cmds->cmds_flags[i] && minishell->flag != 1)
			msj_error(MALLOC_FAILED, minishell, 0);
		i++;
	}
	matrix = ft_free(matrix);
	cmds->cmds_flags[i] = NULL;
	cmds->fd_in = STDIN_FILENO;
	cmds->fd_out = STDOUT_FILENO;
	file_descriptor(cmds, tokens, minishell);
	cmds->next = NULL;
	return (cmds);
}

t_cmds	*ft_lstadd_back_cmd(t_cmds **lst, t_cmds *new)
{
	t_cmds	*aux;

	aux = *lst;
	if (!(*lst))
		(*lst) = new;
	else if (*lst)
	{
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		(*lst)->next = new;
		(*lst) = aux;
	}
	return (*lst);
}
