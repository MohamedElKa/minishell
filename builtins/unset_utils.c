/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:31:28 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/12 13:12:36 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_link_node(t_env **tmp, t_env *save)
{
	(*tmp)->prev->next = save;
}

void	ft_link_node_exp(t_env **tmp2, t_env *save2)
{
	(*tmp2)->prev->next = save2;
}

void	ft_link_node_env_(t_env **tmp)
{
	(*tmp)->next->prev = (*tmp)->prev;
}

void	ft_link_node_exp_(t_env **tmp2)
{
	(*tmp2)->next->prev = (*tmp2)->prev;
}

void	ft_delete_node(t_env **env)
{
	t_env	*tmp;

	tmp = (*env);
	free(tmp->declare);
	free(tmp->key);
	free(tmp->value);
	free(tmp);
}
