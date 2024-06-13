/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:00:17 by dparada           #+#    #+#             */
/*   Updated: 2024/06/13 19:17:33 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstclear_cmds(t_cmds **lst)
{
	t_cmds	*aux;
	int		i;

	i = 0;
	aux = *lst;
	while (*lst)
	{
		aux = (*lst)->next;
		free((*lst)->cmds);
		while ((*lst)->cmds_flags[i])
		{
			free((*lst)->cmds_flags[i]);
			i++;
		}
		free((*lst)->cmds_flags);
		free(*lst);
		*lst = aux;
	}
}

t_cmds	*new_cmd(int i, char **matrix)
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
	cmds->cmds_flags[i] = NULL;
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

int	is_join(t_token *tokens)
{
	if (tokens && (tokens->token == T_W || tokens->token == T_DQ || tokens->token == T_SQ))
	{
		if (tokens->flag == 1 && tokens->content)
			return (1);
	}
	return (0);
}
t_token	*word_token(t_token *token, t_minishell *minishell)
{
	t_token	*aux;
	int		i;
	char 	**split;
	t_cmds	*aux_cmd;

	aux = token;
	i = 0;
	(void)minishell;
	while (aux && (aux->token == T_W || aux->token == T_DQ || aux->token == T_SQ))
	{
		if (is_join(aux->next) == 0)
			i++;
		aux = aux->next;
	}
	split = cmds(token, 0, NULL, i);
	// i = 0;
	// while (split[i])
	// {
	// 	printf("")
	// }
	if (minishell->cmds)
	{
		aux_cmd = new_cmd(i, split);
		if (!aux_cmd)
			return (NULL);
		ft_lstadd_back_cmd(&minishell->cmds, aux_cmd);
	}
	else
		minishell->cmds = new_cmd(i, split);
	return (aux);
}


char	**cmds(t_token *tokens, int i, char *buffer, int len)
{
	t_token	*aux;
	char	**matrix;
	char	*aux2;
	
	aux = tokens;
	// (void)buffer;
	matrix = malloc (sizeof(char *) * (len + 1));
	while (len > 0)
	{
		if (aux->content)
		{
			if (!buffer)
				buffer = ft_strdup(aux->content);
			while (is_join (aux->next) == 1)
			{
				aux2 = buffer;
				buffer = ft_strjoin(aux2, aux->next->content);
				
				aux = aux->next;
			}
			matrix[i] = ft_strdup(buffer);
			printf("en cmds %s\n", matrix[i]);
			i++;
		}
		len--;
		if (aux->next)
			aux = aux->next;
	}
	matrix[i] = NULL;
	return (matrix);
}

void	token_actions(t_minishell *minishell)
{
	t_token	*aux;
	int		i;

	i = 0;
	aux = minishell->tokens;
	while (aux)
	{
		if (aux->token == T_W)
			aux = word_token(aux, minishell);
		if (aux && aux->token == T_P)
			aux = aux->next;
		else if (aux && aux->token == T_G)
			aux = redirecc(minishell, aux);
		else if (aux && aux->token == T_L)
			aux = redirecc(minishell, aux);
		else if (aux && aux->token == T_DG)
			aux = redirecc(minishell, aux);
		else if (aux && aux->token == T_DL)
			aux = here_doc(aux->next, minishell);
	}
	printf_cmds(minishell->cmds);
}
