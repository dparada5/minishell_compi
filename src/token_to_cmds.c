/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:00:17 by dparada           #+#    #+#             */
/*   Updated: 2024/06/19 17:59:07 by dparada          ###   ########.fr       */
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
	printf("llego");
	token = token->next;
	if (cmds->fd_out != 1)
		close (cmds->fd_out);
	cmds->fd_out = open(token->content, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (cmds->fd_out < 0)
		msj_error(ERROR_FD);
	return (token);
}

t_token	*open_to_close(t_token *token)
{
	int	fd;

	fd = 0;
	if (token->token == T_G)
	{
		token = token->next;
		fd = open(token->content, O_RDWR | O_CREAT | O_TRUNC, 0644);
	}
	else if (token->token == T_DG)
	{
		token = token->next;
		fd = open(token->content, O_RDWR | O_CREAT | O_APPEND, 0644);
	}
	else if (token->token == T_L)
	{
		token = token->next;
		fd = open(token->content, O_RDONLY);
	}
	// else if (crear heredoc)
	if (fd > 0)
		close(fd);
	return (token);
}

void	file_descriptor(t_cmds *cmds, t_token *tokens)
{
	t_token	*aux;

	aux = tokens;
	while (aux && aux->token != T_P)
	{
		if (aux->token == T_DG)
			aux = open_append(aux, cmds);
		else if (aux->token == T_L)
			aux = open_infile(aux, cmds);
		else if (aux->token == T_G)
		{
			printf("holi\n");
			aux = open_trunc(aux, cmds);
		
		}
		else if (aux->token == T_DL)
			aux = here_doc(aux, NULL);
		aux = aux->next;
	}
}

t_cmds	*new_cmd(int i, char **matrix, t_token *tokens)
{
	t_cmds	*cmds;

	cmds = malloc(sizeof(t_cmds));
	if (!cmds)
		return (NULL);
	cmds->cmds = ft_strdup(matrix[0]);
	cmds->cmds_flags = malloc (sizeof(char *) * (i + 1));
	if (!cmds->cmds || !cmds->cmds_flags)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		cmds->cmds_flags[i] = ft_strdup(matrix[i]);
		if (!cmds->cmds_flags[i])
			return (NULL);
		i++;
	}
	ft_free(matrix);
	cmds->cmds_flags[i] = NULL;
	cmds->fd_in = STDIN_FILENO;
	cmds->fd_out = STDOUT_FILENO;
	file_descriptor(cmds, tokens);
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

void	token_actions(t_minishell *minishell)
{
	t_token	*aux;
	int		i;

	i = 0;
	aux = minishell->tokens;
	while (aux)
	{
		if (aux && aux->token == T_P)
			aux = aux->next;
		else
			aux = command_create(aux, minishell);
		// else if (aux && aux->token == T_G)
		// 	aux = open_append(aux, NULL);
		// else if (aux && aux->token == T_L)
		// 	aux = open_infile(aux, )
		// else if (aux && aux->token == T_DG)
		// 	aux = redirecc(minishell, aux);
		// else if (aux && aux->token == T_DL)
		// 	aux = here_doc(aux->next, minishell);
	}
	printf_cmds("en token to cmds", minishell->cmds);
}
