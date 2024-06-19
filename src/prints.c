/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:09:16 by dparada           #+#    #+#             */
/*   Updated: 2024/06/19 18:26:27 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	printf_cmds(char *str, t_cmds *cmds)
{
	int		i;
	t_cmds	*aux;

	aux = cmds;
	
	while (aux)
	{
		i = 0;
		printf("%s Command: %s and fd in %d, fd out %d\n", str, aux->cmds, aux->fd_in, aux->fd_out);
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
		else if (aux->token == T_DQ)
			printf("Token: DQ\t");
		else if (aux->token == T_SQ)
			printf("Token: SQ\t");
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
		printf("Flag: %d\t", aux->flag);
		printf("Content: %s\n", aux->content);
		aux = aux->next;
	}
	printf("------------------------------------------\n");
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

void	print_state(t_state *state)
{
	if (state->type == S_S)
		printf("STATE == START\n");
	else if (state->type == S_W)
		printf("STATE == WORD\n");
	else if (state->type == S_QS)
		printf("STATE == SIMPLE QUOT\n");
	else if (state->type == S_DQ)
		printf("STATE == DOBLE QUOTES\n");
	else if (state->type == S_D)
		printf("STATE == DOLAR\n");
	else if (state->type == S_CD)
		printf("STATE == COMILLA CON DOLAR\n");
	else if (state->type == S_SU)
		printf("STATE == SUMILERO (?\n");
}
