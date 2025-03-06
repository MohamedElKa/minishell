/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:37:00 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/12 07:50:58 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_path(char *str, char **s)
{
	int		i;
	char	*path;

	i = 0;
	str = ft_strjoin("/", str);
	while (s[i])
	{
		path = ft_strjoin(s[i], str);
		if (access(path, X_OK) == 0)
		{
			free_2d_tab(s);
			return (path);
		}
		i++;
	}
	return (NULL);
}

void	ft_errors(void)
{
	ft_putstr_fd("command not found\n", 2);
	exit(127);
}

int	ft_pipes_num(t_cmds **head)
{
	t_cmds	*tmp;
	int		i;

	i = 0;
	tmp = (*head);
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	i--;
	return (i);
}

int	**alloc(int pipe_nums)
{
	int	**pipefd;
	int	i;

	i = 0;
	pipefd = malloc(pipe_nums * sizeof(int *));
	if (!pipefd)
		exit(1);
	while (i < pipe_nums)
	{
		pipefd[i] = malloc(2 * sizeof(int));
		if (!pipefd[i])
			exit(1);
		i++;
	}
	return (pipefd);
}
