// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   token_to_cmds.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/06/12 16:13:37 by dparada           #+#    #+#             */
// /*   Updated: 2024/06/21 13:32:52 by dparada          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../minishell.h"

// int	is_join(t_token *tokens)
// {
// 	if (tokens && (tokens->token == T_W \
// 	|| tokens->token == T_DQ || tokens->token == T_SQ))
// 	{
// 		if (tokens->flag == 1 && ft_strlen(tokens->content) > 0)
// 			return (1);
// 	}
// 	else
// 		return (2);
// 	return (0);
// }

// static char	*pop(t_token *token, char *buffer)
// {
// 	t_token	*aux;
// 	char	*string;
	
// 	string = ft_strjoin(buffer, token->next->content);
// 	aux = token->next;
// 	token->next = aux->next;
// 	aux->next = NULL;
// 	ft_lstclear_token(&aux);
// 	return (string);
// }

// static char	*check_join(t_token *aux)
// {
// 	char	*buffer;
// 	char	*aux2;
	
// 	aux2 = NULL;
// 	buffer = ft_strdup(aux->content);
// 	while (is_join (aux->next) == 1)
// 	{
// 		aux2 = buffer;
// 		buffer = pop(aux, aux2);
// 		aux2 = NULL;
// 	}
// 	return (buffer);
// }



// t_token	*word_token(t_token *token, t_minishell *minishell)
// {
// 	t_token	*aux;
// 	int		i;
// 	char	**split;
// 	t_cmds	*aux_cmd;

// 	aux = token;
// 	i = 0;
// 	while (aux && aux->token != T_P)
// 	{
// 		if (aux->token >= T_G && aux->token <= T_DL)
// 			aux = aux->next;
// 		if (is_join(aux->next) == 0)
// 			i++;
// 		aux = aux->next;
// 	}
// 	split = cmds(minishell, token, NULL, i);
// 	if (minishell->cmds)
// 	{
// 		aux_cmd = new_cmd(i, split, minishell);
// 		ft_lstadd_back_cmd(&minishell->cmds, aux_cmd);
// 	}
// 	else
// 		minishell->cmds = new_cmd(i, split, minishell);
// 	return (aux);
// }

// char	**cmds(t_minishell *minishell, t_token *token, char *buffer, int len)
// {
// 	t_token	*aux;
// 	char	**matrix;
// 	int		i;

// 	i = 0;
// 	aux = token;
// 	matrix = malloc (sizeof(char *) * (len + 1));
// 	if (!matrix && minishell->flag != 1)
// 		msj_error(MALLOC_FAILED, minishell);
// 	while (aux && aux->token != T_P)
// 	{
// 		if (aux->token >= T_G && aux->token <= T_DL)
// 			aux = aux->next;
// 		else if (ft_strlen(aux->content) != 0)
// 		{
// 			matrix[i++] = check_join(aux);
// 			free(buffer);
// 		}
// 		aux = aux->next;
// 	}
// 	matrix[i] = NULL;
// 	return (matrix);
// }
