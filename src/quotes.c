/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:18:01 by dparada           #+#    #+#             */
/*   Updated: 2024/06/11 17:41:07 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	count_quotes(char *line, char c)
// {
// 	int	i;
// 	int	flag;

// 	i = 0;
// 	flag = 1;
// 	while (line[i])
// 	{
// 		if (line[i] == c && line[i + 1] == c)
// 			flag++;
// 		i++;
// 	}
// 	return (flag);
// }

// int	next_ocurrence(char *line, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == c)
// 			return (i);
// 		i++;
// 	}
// 	return (i);
// }

// int	quotes(t_token **tokens, char *line, char c)
// {
// 	int		i;

// 	i = 0;
// 	while (line[i] == c)
// 		i++;
// 	if (i > 1)
// 		create_token_list(tokens, T_W, ft_strdup(""));
// 	return (i + 1);
// }
