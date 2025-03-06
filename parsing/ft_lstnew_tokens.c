/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:11:21 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/12 08:58:54 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_lstnew_tok(char *content, int tok)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		exit(1);
	new->str = ft_strdup(content);
	new->tok = tok;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstaddback_tok(t_token *head, t_token *new)
{
	t_token	*tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_create_node_tok(t_token *head, char *content, int type)
{
	t_token	*new;

	new = ft_lstnew_tok(content, type);
	ft_lstaddback_tok(head, new);
}
