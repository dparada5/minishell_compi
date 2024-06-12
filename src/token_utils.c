/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:00:36 by dparada           #+#    #+#             */
/*   Updated: 2024/06/12 18:56:07 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*new_token(t_token_num token_num, char *content, int flag)
{
	t_token	*token;

	token = malloc (sizeof(t_token));
	if (!token)
		return (NULL);
	token->token = token_num;
	token->content = ft_strdup(content);
	if (!token->content)
		return (NULL);
	token->flag = flag;
	token->next = NULL;
	return (token);
}

t_token	**ft_lstadd_back_token(t_token **lst, t_token *new)
{
	t_token	*aux;

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
	return (lst);
}

void	ft_lstclear_token(t_token **lst)
{
	t_token	*aux;

	aux = *lst;
	while (*lst)
	{
		aux = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = aux;
	}
}

void	token_next(t_token *token)
{
	t_token	*aux;
	int		flag;

	flag = 0;
	aux = token;
	while (aux)
	{
		if (aux->next == NULL && aux->token != T_W && aux->token != T_DQ && aux->token != T_SQ)
			msj_error(ERROR_EOF);
		else if (aux->token == T_P && flag == 0)
			msj_error(ERROR_UPIPE);
		else if (aux->token >= T_G && aux->token <= T_DL)
		{
			if (aux->next != NULL && aux->next->token != T_W && aux->next->token != T_DQ && aux->next->token != T_SQ)
				msj_error(ERROR_UT);
			
		}
		else if (aux->token == T_P && aux->next && aux->next->token == T_P)
			msj_error(ERROR_UT);
		aux = aux->next;
		flag = 1;
	}
}

// void	printf_tokens(t_token *token)
// {
// 	t_token	*aux;

// 	if (!token)
// 		printf("no");
// 	aux = token;
// 	while (aux)
// 	{
// 		if (aux->token == T_W)
// 			printf("Token:	W\t");
// 		else if (aux->token == T_P)
// 			printf("Token:	P\t");
// 		else if (aux->token == T_G)
// 			printf("Token:	G\t");
// 		else if (aux->token == T_L)
// 			printf("Token:	L\t");
// 		else if (aux->token == T_DG)
// 			printf("Token:  DG\t");
// 		else if (aux->token == T_DL)
// 			printf("Token:	DL\t");
// 		printf("Content: %s\n", aux->content);
// 		aux = aux->next;
// 	}
// }
