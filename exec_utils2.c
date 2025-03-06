/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:54:36 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/13 11:52:58 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hard_code(char **check)
{
	check[0] = ft_strdup("echo");
	check[1] = ft_strdup("export");
	check[2] = ft_strdup("unset");
	check[3] = ft_strdup("env");
	check[4] = ft_strdup("cd");
	check[5] = ft_strdup("pwd");
	check[6] = ft_strdup("exit");
	check[7] = NULL;
}

int	check_builtins(t_cmds **head)
{
	char	**check;
	t_cmds	*tmp;
	int		i;

	tmp = (*head);
	i = 0;
	check = malloc(8 * sizeof(char *));
	if (!check)
		exit(1);
	hard_code(check);
	while (i < 7)
	{
		if (ft_strncmp(tmp->cmd[0], check[i], ft_strlen(tmp->cmd[0])) == 0)
			return (free_2d_tab(check), 0);
		i++;
	}
	free_2d_tab(check);
	return (1);
}

void	ft_exec_func_solo(t_cmds *tmp, t_data *y)
{
	if (tmp->cmd[0] != NULL)
	{
		if (execve(getpath(&y->env, tmp->cmd[0]), tmp->cmd, NULL) == -1)
		{
			ft_putstr_fd("command not found\n", 2);
			exit(127);
		}
	}
	else
		exit(0);
}

void	ft_exec_func(t_cmds *tmp, t_data *y)
{
	if (tmp->cmd[0] != NULL)
	{
		if (choose_cmd(&tmp, &y->env, &y->exp) == 1)
		{
			if (g_child_status == 1)
			{
				exit(1);
			}
			exit(0);
		}
		else if (execve(getpath(&y->env, tmp->cmd[0]), tmp->cmd, NULL) == -1)
		{
			ft_putstr_fd("command not found\n", 2);
			exit(127);
		}
	}
	else
		exit(0);
}
