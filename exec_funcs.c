/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:11:20 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/12 16:04:42 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	solo_command(t_cmds *tmp, t_data **x)
{
	t_exfu	exec;

	exec.y = (*x);
	exec.j = 0;
	if (tmp->cmd[0] != NULL && check_builtins(&tmp) == 0)
		return (execute_builtins_solo(&tmp, &exec.y->env, &exec.y->exp));
	if (exec.j == 0)
	{
		exec.pid = fork();
		if (exec.pid == -1)
			ft_putstr_fd("Forking Error\n", 2);
		if (exec.pid == 0)
		{
			signal(SIGQUIT, SIG_DFL);
			if (check_in_out(tmp) != -1)
				ft_exec_func_solo(tmp, exec.y);
			else
				exit(1);
		}
	}
	return (exec.pid);
}

void	first_command(t_cmds *tmp, t_data **x, int *i, int **pipefd)
{
	t_exfu	exec;

	exec.y = (*x);
	*i = *i + 1;
	open_pipes(pipefd[*i]);
	exec.pid = fork();
	if (exec.pid == -1)
		ft_putstr_fd("Forking Error\n", 2);
	if (exec.pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		close(pipefd[*i][0]);
		dup2(pipefd[*i][1], 1);
		if (check_in_out(tmp) != -1)
			ft_exec_func(tmp, exec.y);
		else
			exit(1);
		close(pipefd[*i][1]);
	}
	close(pipefd[*i][1]);
}

int	last_command(t_cmds *tmp, t_data **x, int *i, int **pipefd)
{
	int		pid;
	t_data	*y;

	y = (*x);
	pid = fork();
	if (pid == -1)
		ft_putstr_fd("Forking Error\n", 2);
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		dup2(pipefd[*i][0], 0);
		if (check_in_out(tmp) != -1)
			ft_exec_func(tmp, y);
		else
			exit(1);
		close(pipefd[*i][0]);
	}
	close(pipefd[*i][0]);
	return (pid);
}

void	ft_execute_middle(t_exfu *exec, int **pipefd, t_cmds *tmp, int *i)
{
	if (exec->pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		close(pipefd[*i][0]);
		dup2(pipefd[*i - 1][0], 0);
		dup2(pipefd[*i][1], 1);
		if (check_in_out(tmp) != -1)
			ft_exec_func(tmp, exec->y);
		else
			exit(1);
		close(pipefd[*i - 1][0]);
		close(pipefd[*i][1]);
	}
}

void	middle_command(t_cmds *tmp, t_data **x, int *i, int **pipefd)
{
	t_exfu	exec;

	exec.y = (*x);
	*i = *i + 1;
	open_pipes(pipefd[*i]);
	exec.pid = fork();
	if (exec.pid == -1)
		ft_putstr_fd("Forking Error\n", 2);
	ft_execute_middle(&exec, pipefd, tmp, i);
	close(pipefd[*i - 1][0]);
	close(pipefd[*i][1]);
}
