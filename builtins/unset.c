/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:40:20 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/12 13:12:51 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_delete_node_exp(t_env **exp)
{
	t_env	*tmp2;

	tmp2 = (*exp);
	free(tmp2->declare);
	free(tmp2->key);
	free(tmp2->value);
	free(tmp2);
}

void	export_unset(t_env **exp, t_env *save2, char *key)
{
	t_env	*tmp2;

	tmp2 = (*exp);
	while (tmp2 != NULL)
	{
		save2 = tmp2->next;
		if (!ft_strncmp(key, tmp2->key, ft_strlen(tmp2->key)))
		{
			if (tmp2->prev != NULL)
				ft_link_node_exp(&tmp2, save2);
			if (tmp2->next != NULL)
				ft_link_node_exp_(&tmp2);
			ft_delete_node(&tmp2);
			break ;
		}
		tmp2 = tmp2->next;
	}
}

void	ft_unset(t_env **env, t_env **exp, char *key)
{
	t_env	*tmp;
	t_env	*tmp2;
	t_env	*save;

	tmp = (*env)->next;
	tmp2 = (*exp)->next;
	while (tmp != NULL)
	{
		save = tmp->next;
		if (!ft_strncmp(key, tmp->key, ft_strlen(tmp->key)))
		{
			if (tmp->prev != NULL)
				ft_link_node(&tmp, save);
			if (tmp->next != NULL)
				ft_link_node_env_(&tmp);
			ft_delete_node(&tmp);
			break ;
		}
		tmp = tmp->next;
	}
	export_unset(&tmp2, NULL, key);
}
