/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:38:02 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/12 08:58:41 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_lstnew_env(char *key, char *value, int flag)
{
	t_env	*head;

	head = malloc(sizeof(t_env));
	if (!head)
		exit(1);
	head->key = ft_strdup(key);
	head->value = ft_strdup(value);
	head->declare = ft_strdup("declare -x");
	head->next = NULL;
	head->prev = NULL;
	head->flag = flag;
	return (head);
}

void	ft_lstaddback_env(t_env **head, t_env *new)
{
	t_env	*tmp;

	tmp = (*head);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_create_node_env(t_env **head, char *key, char *value, int flag)
{
	t_env	*new;

	new = ft_lstnew_env(key, value, flag);
	ft_lstaddback_env(head, new);
}
