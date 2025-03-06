/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:36:28 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/12 13:57:52 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_builtins_solo(t_cmds **tmp, t_env **env, t_env **exp)
{
	t_cmds	*head;
	int		pid;

	head = (*tmp);
	if ((head->in_fd > 0 || head->out_fd > 0) && \
	ft_strncmp(head->cmd[0], "cd", 2))
	{
		pid = fork();
		if (pid == 0)
		{
			check_in_out(head);
			choose_cmd(tmp, env, exp);
			exit(0);
		}
		return (1);
	}
	else
		return (choose_cmd(tmp, env, exp));
	return (0);
}
