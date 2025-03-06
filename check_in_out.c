/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:23:19 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/11 12:21:08 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_in_out(t_cmds *tmp)
{
	if (tmp->out_fd > -1)
		dup2(tmp->out_fd, 1);
	if (tmp->in_fd > -1)
		dup2(tmp->in_fd, 0);
	else if (tmp->in_fd == -1 || tmp->out_fd == -1 || tmp->in_fd == -5)
		return (-1);
	return (0);
}
