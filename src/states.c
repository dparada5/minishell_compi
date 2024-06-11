/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:47:06 by dparada           #+#    #+#             */
/*   Updated: 2024/06/07 16:12:25 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	save_word(char *line)

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

int	state_word(t_state *state, char *line)
{
	int	i;

	i = 0;
	state->type = S_W;
	while (line[i] != ' ' && line[i])
		i++;
	if (line[i] == ' ')
		state->type = S_S;
	return (i);
}

int	simple_quote(t_state *state, char *line)
{
	int	i;

	i = 1;
	state->type = S_QS;
	while (line[i] != '\'' && line[i])
		i++;
	if (line[i] == '\'')
		state->type = S_W;
	else
		msj_error(ERROR_SQ);
	return (i + 1);
}

int	doble_quote(t_state *state, char *line)
{
	int	i;

	i = 1;
	if (line[i] == '$')
		state->type = S_CD;
	else
	{
		state->type = S_DQ;
		while (line[i] != '\"' && line[i])
			i++;
		if (line[i] == '\"')
			state->type = S_W;
		else
			msj_error(ERROR_DQ);
	}
	return (i + 1);
}

void	states(char *line)
{
	t_state	*state;
	int		i;

	i = 0;
	state = malloc (sizeof(t_state));
	if (!state)
		return ;
	state->type = S_S;
	while (line[i])
	{
		if (line[i] == '\'')
			i += simple_quote(state, &line[i]);
		else if (line[i] == '\"')
			i += doble_quote(state, &line[i]);
		else if (!ft_strchr("|<> ", line[i]))
			i += state_word(state, &line[i]);
		else
			i++;
	}
	free(state);
}
