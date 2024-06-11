/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:49:38 by dparada           #+#    #+#             */
/*   Updated: 2024/06/11 17:40:45 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	words(char *line, t_token **token)
{
	int	i;

	i = 0;
	while (!ft_strchr("| <>", line[i]) && line[i])
		i++;
	create_token_list(token, T_W, ft_substr(line, 0, i));
	return (i);
}

int	quotes(t_token **tokens, char *line, char c)
{
	int		i;

	i = 0;
	while (line[i] == c)
		i++;
	if (i > 1)
		create_token_list(tokens, T_W, ft_strdup(""));
	return (i + 1);
}

int	tokens(char *line, t_token **token, int i)
{
	if (line[i] == '|')
	{
		create_token_list(token, T_P, ft_strdup("|"));
		return (1);
	}
	else if (line[i] == '\'' || line[i] == '\"')
		i += quotes(token, &line[i], line[i]);
	else if ((line[i + 1] == '<' && line[i] == '<') || \
	(line[i] == '>' && line[i + 1] == '>'))
	{
		if (line[i] == '>' && line[i + 1] == '>')
			create_token_list(token, T_DG, ft_strdup(">>"));
		else if (line[i + 1] == '<' && line[i] == '<')
			create_token_list(token, T_DL, ft_strdup("<<"));
		return (2);
	}
	else if (line[i] == '>' || line[i] == '<')
	{
		if (line[i] == '>')
			create_token_list(token, T_G, ft_strdup(">"));
		else
			create_token_list(token, T_L, ft_strdup("<"));
		return (1);
	}
	return (i);
}

void	create_token_list(t_token **token, t_token_num token_num, char *content)
{
	t_token	*aux;

	if (!*token)
		*token = new_token(token_num, content);
	else
	{
		aux = new_token(token_num, content);
		if (!aux)
			return ;
		ft_lstadd_back_token(token, aux);
	}
	free(content);
}

t_token	*get_tokens(char *line)
{
	int		i;
	t_token	*token;

	i = 0;
	token = NULL;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (ft_strchr("|<>\"'", line[i]))
			i += tokens(&line[i], &token, 0);
		else
			i += words(&line[i], &token);
	}
	printf_tokens(token);
	token_next(token);
	return (token);
}
