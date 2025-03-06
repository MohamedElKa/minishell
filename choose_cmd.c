/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:29:45 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/12 16:24:24 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	choose_cmd_three(t_cmds **head, t_env **env, t_env **exp)
{
	t_cmds	*tmp;

	tmp = (*head);
	if (ft_strncmp(tmp->cmd[0], "export", 6) == 0)
	{
		ft_export(env, exp, tmp->cmd + 1);
		g_child_status = 0;
		return (1);
	}
	return (0);
}

int	choose_cd_exit(t_cmds **head, t_env **env)
{
	t_cmds	*tmp;

	tmp = (*head);
	if (ft_strncmp(tmp->cmd[0], "exit", 4) == 0)
	{
		our_exit(tmp->cmd, 1);
		return (1);
	}
	if (ft_strncmp(tmp->cmd[0], "cd", 2) == 0)
	{
		our_cd(tmp->cmd[1], env);
		return (1);
	}
	return (0);
}

int	choose_export(t_cmds **head, t_env **env, t_env **exp)
{
	t_cmds	*tmp;

	tmp = (*head);
	if (ft_strncmp(tmp->cmd[0], "export", ft_strlen(tmp->cmd[0])) == 0)
	{
		ft_export(env, exp, tmp->cmd + 1);
		return (1);
	}
	if (ft_strncmp(tmp->cmd[0], "unset", ft_strlen(tmp->cmd[0])) == 0)
	{
		ft_unset(env, exp, tmp->cmd[1]);
		return (1);
	}
	if (ft_strncmp(tmp->cmd[0], "env", 3) == 0)
	{
		ft_print_env(env);
		return (1);
	}
	return (0);
}

int	choose_cmd(t_cmds **head, t_env **env, t_env **exp)
{
	t_cmds	*tmp;

	tmp = (*head);
	if (ft_strncmp(tmp->cmd[0], "echo", 4) == 0)
	{
		ft_echo(tmp->cmd);
		return (1);
	}
	if (ft_strncmp(tmp->cmd[0], "pwd", 3) == 0)
	{
		our_pwd(tmp->cmd[1]);
		return (1);
	}
	if (choose_cd_exit(head, env) != 0)
		return (1);
	if (choose_export(head, env, exp) == 1)
		return (1);
	return (0);
}
