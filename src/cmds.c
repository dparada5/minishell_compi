/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:00:17 by dparada           #+#    #+#             */
/*   Updated: 2024/06/14 12:00:22 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	ft_free(matrix);
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

void	token_actions(t_minishell *minishell)
{
	t_token	*aux;
	int		i;

	i = 0;
	aux = minishell->tokens;
	while (aux)
	{
		if (aux->token == T_W || aux->token == T_DQ || aux->token == T_SQ)
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
