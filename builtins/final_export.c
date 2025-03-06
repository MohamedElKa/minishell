/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:43:23 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/10 15:49:55 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_final_export(t_tnp y, t_var var)
{
	if (check_existant(&y, var.values[var.i][0], \
	var.values[var.i][1], var.plus) == 0)
		ft_add_export(y, var);
}

void	ft_final_export_(t_tnp y, t_var var)
{
	if (check_existant(&y, var.values[var.i][0], \
	var.values[var.i][1], var.plus) == 0)
		ft_add_export_value(y, var);
}
