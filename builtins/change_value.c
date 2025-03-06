/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:54:52 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/11 16:25:03 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	change_value(t_env *env, char *value)
{
	t_env	*tmp;

	tmp = env;
	if (value != NULL)
	{
		free(tmp->value);
		tmp->value = ft_strdup(value);
	}
	else
	{
		free(tmp->value);
		tmp->value = ft_strdup("");
	}
	return (1);
}

void	change_value_(t_env *exp, char *value)
{
	t_env	*tmp2;

	tmp2 = exp;
	if (value != NULL)
	{
		free(tmp2->value);
		tmp2->value = ft_strdup(value);
	}
	else
	{
		free(tmp2->value);
		tmp2->value = ft_strdup("");
	}
}
