// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   token_quotes.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/06/12 16:13:37 by dparada           #+#    #+#             */
// /*   Updated: 2024/06/13 18:26:56 by dparada          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../minishell.h"

// int	is_join(t_token *tokens)
// {
// 	if (tokens && (tokens->token == T_W || tokens->token == T_DQ || tokens->token == T_SQ))
// 	{
// 		if (tokens->flag == 1 && tokens->content)
// 			return (1);
// 	}
// 	return (0);
// }
// t_token	*word_token(t_token *token, t_minishell *minishell)
// {
// 	t_token	*aux;
// 	int		i;
// 	char 	**split;
// 	t_cmds	*aux_cmd;

// 	aux = token;
// 	i = 0;
// 	(void)minishell;
// 	while (aux && (aux->token == T_W || aux->token == T_DQ || aux->token == T_SQ))
// 	{
// 		if (is_join(aux->next) == 0)
// 			i++;
// 		aux = aux->next;
// 	}
// 	split = cmds(token, 0, NULL, i);
// 	if (minishell->cmds)
// 	{
// 		aux_cmd = new_cmd(i, token);
// 		if (!aux_cmd)
// 			return (NULL);
// 		ft_lstadd_back_cmd(&minishell->cmds, aux_cmd);
// 	}
// 	else
// 		minishell->cmds = new_cmd(i, token);
// 	return (aux);
// }


// char	**cmds(t_token *tokens, int i, char *buffer, int len)
// {
// 	t_token	*aux;
// 	char	**matrix;
// 	char	*aux2;
	
// 	aux = tokens;
// 	// (void)buffer;
// 	matrix = malloc (sizeof(char *) * (len + 1));
// 	while (len > 0)
// 	{
// 		if (aux->content)
// 		{
// 			if (!buffer)
// 				buffer = ft_strdup(aux->content);
// 			while (is_join (aux->next) == 1)
// 			{
// 				aux2 = buffer;
// 				buffer = ft_strjoin(aux2, aux->next->content);
// 				// free(aux2);
// 				aux = aux->next;
// 			}
// 			matrix[i] = ft_strdup(buffer);
// 			// printf("%s\n", matrix[i]);
// 			i++;
// 			// free(buffer);
// 		}
// 		len--;
// 		if (aux->next)
// 			aux = aux->next;
// 	}
// 	matrix[i] = NULL;
// 	return (matrix);
// }
