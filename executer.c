/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:19:48 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/12 16:23:28 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_child_status;

void	free_2d_tab_int(int **p, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(p[i]);
		i++;
	}
	free(p);
}

void	init_vars(t_exec *exec, t_cmds **head)
{
	exec->tmp = (*head);
	exec->pid = 1;
	exec->status = 0;
	exec->pipes = ft_pipes_num(head);
}

void	get_status(int pid, int status)
{
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_child_status = WEXITSTATUS(status);
}

void	executer(t_cmds **head, t_data **x)
{
	t_exec	exec;

	init_vars(&exec, head);
	if (exec.pipes > 0)
		exec.pipefd = alloc(exec.pipes);
	exec.i = -1;
	while (exec.tmp != NULL)
	{
		if (exec.tmp->next == NULL && exec.tmp->prev->cmd == NULL)
			exec.pid = solo_command(exec.tmp, x);
		else if (exec.tmp->next != NULL && exec.tmp->prev->cmd == NULL)
			first_command(exec.tmp, x, &exec.i, exec.pipefd);
		else if (exec.tmp->next == NULL && exec.tmp->prev != NULL)
			exec.pid = last_command(exec.tmp, x, &exec.i, exec.pipefd);
		else if (exec.tmp->next != NULL && exec.tmp->prev != NULL)
			middle_command(exec.tmp, x, &exec.i, exec.pipefd);
		exec.tmp = exec.tmp->next;
	}
	if (g_child_status != 1)
		get_status(exec.pid, exec.status);
	while (wait(0) != -1)
		;
	if (exec.pipes != 0)
		free_2d_tab_int(exec.pipefd, exec.pipes);
}
