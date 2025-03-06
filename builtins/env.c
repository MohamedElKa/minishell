/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:32:03 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/13 11:54:56 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_env(t_env **env)
{
	t_env	*tmp;

	tmp = (*env);
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (tmp->flag != 2)
		{
			ft_putstr_fd(tmp->key, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(tmp->value, 1);
			ft_putstr_fd("\n", 1);
		}
		tmp = tmp->next;
	}
}
