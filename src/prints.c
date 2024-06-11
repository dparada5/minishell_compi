/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:09:16 by dparada           #+#    #+#             */
/*   Updated: 2024/06/07 16:10:30 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	printf_cmds(t_cmds *cmds)
{
	int		i;
	t_cmds	*aux;

	aux = cmds;
	while (aux)
	{
		i = 0;
		printf("Command: %s\n", aux->cmds);
		while (aux->cmds_flags[i])
		{
			printf("\tFlags: %s\n", aux->cmds_flags[i]);
			i++;
		}
		aux = aux->next;
	}
}

void	printf_tokens(t_token *token)
{
	t_token	*aux;

	if (!token)
		printf("no\n");
	aux = token;
	while (aux)
	{
		if (aux->token == T_W)
			printf("Token:	W\t");
		else if (aux->token == T_P)
			printf("Token:	P\t");
		else if (aux->token == T_G)
			printf("Token:	G\t");
		else if (aux->token == T_L)
			printf("Token:	L\t");
		else if (aux->token == T_DG)
			printf("Token:  DG\t");
		else if (aux->token == T_DL)
			printf("Token:	DL\t");
		printf("Content: %s\n", aux->content);
		aux = aux->next;
	}
}

void	print_env(t_env *env)
{
	t_env	*aux;

	aux = env;
	while (aux)
	{
		printf("%sKey:%s %s\t%sContent:%s%s\n", \
		RED, RST, aux->key, RED, RST, aux->content);
		aux = aux->next;
	}
}
