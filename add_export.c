/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:27:17 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/11 15:21:45 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_export(t_tnp y, t_var var)
{
	ft_create_node_env(&y.tmp, var.values[var.i][0], "", 0);
	ft_create_node_env(&y.tmp2, var.values[var.i][0], "", 0);
}

void	ft_add_export_value(t_tnp y, t_var var)
{
	ft_create_node_env(&y.tmp2, var.values[var.i][0], var.values[var.i][1], 0);
}
