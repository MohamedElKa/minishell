/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:04:45 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/11 16:24:43 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
//hhhhhhhh

int	join_value(t_env *env, char *value)
{
	t_env	*tmp;

	tmp = env;
	if (value != NULL)
	{
		free(tmp->value);
		tmp->value = ft_strjoin(tmp->value, value);
	}
	else
	{
		free(tmp->value);
		tmp->value = ft_strdup("");
	}
	return (1);
}

void	join_value_(t_env *exp, char *value)
{
	t_env	*tmp2;

	tmp2 = exp;
	if (value != NULL)
	{
		free(tmp2->value);
		tmp2->value = ft_strjoin(tmp2->value, value);
	}
	else
	{
		free(tmp2->value);
		tmp2->value = ft_strdup("");
	}
}

int	exp_add(t_env **head, char *key, char *value, int plus)
{
	t_env	*tmp2;

	tmp2 = (*head);
	while (tmp2)
	{
		if (ft_strncmp(key, tmp2->key, ft_strlen(key)) == 0 && plus == 0)
		{
			change_value_(tmp2, value);
			tmp2->flag = 0;
			return (1);
		}
		else if (ft_strncmp(key, tmp2->key, ft_strlen(key)) == 0 && plus != 0)
		{
			join_value_(tmp2, value);
			return (1);
		}
		tmp2 = tmp2->next;
	}
	return (0);
}

int	check_existant(t_tnp *y, char *key, char *value, int plus)
{
	t_env	*tmp;
	t_env	*tmp2;
	int		flag;

	tmp = y->tmp;
	tmp2 = y->tmp2;
	flag = exp_add(&tmp2, key, value, plus);
	while (tmp)
	{
		if (ft_strncmp(key, tmp->key, ft_strlen(key)) == 0 && plus == 0)
		{
			flag = change_value(tmp, value);
			break ;
		}
		else if (ft_strncmp(key, tmp->key, ft_strlen(key)) == 0 && plus != 0)
		{
			flag = join_value(tmp, value);
			break ;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL)
		ft_create_node_env(&y->tmp, key, value, 0);
	return (flag);
}

int	check_existant_exp(t_tnp *y, char *key)
{
	t_env	*tmp;

	tmp = (y->tmp2);
	while (tmp)
	{
		if (ft_strncmp(tmp->key, key, ft_strlen(key)) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
