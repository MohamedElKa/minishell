/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:24:50 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/13 10:54:52 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_export(t_env **exp)
{
	t_env	*tmp;

	tmp = (*exp);
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->flag != 2)
		{
			ft_putstr_fd(tmp->declare, 1);
			ft_putstr_fd(" ", 1);
			ft_putstr_fd(tmp->key, 1);
			if (tmp->flag != 1)
				ft_putstr_fd("=", 1);
			if (tmp->flag != 1)
				ft_putstr_fd("\"", 1);
			ft_putstr_fd(tmp->value, 1);
			if (tmp->flag != 1)
				ft_putstr_fd("\"", 1);
			ft_putstr_fd("\n", 1);
		}
		tmp = tmp->next;
	}	
}

int	ft_strvarcmp(char *str, char *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c[j])
			j++;
		if (c[j] == '\0')
			return (0);
		i++;
	}	
	return (1);
}

void	checking(t_var *var, t_tnp y)
{
	if (ft_strchr(var->values[var->i][0], '+') != 0)
		var->plus++;
	if (ft_strchr(y.key[var->i], '=') != 0)
		var->equal++;
}

void	export_helper(t_tnp y, t_var var)
{
	while (++var.i < var.num)
	{
		checking(&var, y);
		if (check_regex(var.values[var.i][0], var.equal) != 0)
		{
			var.values[var.i][0] = get_without_plus(var.values[var.i][0]);
			if (var.equal == 1)
			{
				if (var.values[var.i][0] != NULL \
				&& var.values[var.i][1] == NULL)
					ft_final_export(y, var);
				else if (var.values[var.i][0] != NULL \
				&& var.values[var.i][1] != NULL)
					ft_final_export_(y, var);
				var.equal = 0;
				var.plus = 0;
			}
			else
			{
				if (check_existant_exp(&y, var.values[var.i][0]) != 0)
					ft_create_node_env(&y.tmp2, var.values[var.i][0], "", 1);
			}
		}
	}
}

void	ft_export(t_env **env, t_env **exp, char **key)
{
	t_var	var;
	t_tnp	y;

	var.equal = 0;
	var.num = num_of_var(key);
	if (key[0] != NULL)
		var.values = get_variables(key);
	y.tmp = (*env);
	y.tmp2 = (*exp);
	y.key = key;
	var.i = -1;
	var.plus = 0;
	if (key[0] == NULL)
		ft_print_export(&y.tmp2);
	else
	{
		export_helper(y, var);
		free3d_atab(var.values, var.num);
	}
}
