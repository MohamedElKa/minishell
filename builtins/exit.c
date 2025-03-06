/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:52:54 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/11 17:06:04 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_error(int flag)
{
	if (flag == 1)
		ft_putstr_fd("exit\n", 2);
}

int	check_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	check_first_arg(char **str, int flag)
{
	int	j;

	j = 0;
	while (str[1][j])
	{
		if (ft_isdigit(str[1][j]) == 0)
		{
			exit_error(flag);
			ft_putstr_fd("numeric argument required\n", 1);
			exit(255);
		}
		j++;
	}
}

void	check_null(char **str, int flag)
{
	if (str[1] == NULL)
	{
		exit_error(flag);
		exit(0);
	}
}

void	our_exit(char **str, int flag)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	check_null(str, flag);
	check_first_arg(str, flag);
	while (str[i])
	{
		j += check_numeric(str[i]);
		if (j >= 2)
		{
			ft_putstr_fd("too many arguments\n", 2);
			g_child_status = 1;
			return ;
		}
		i++;
	}
	if (j == 1 && i == 2)
		exit((256 + ft_atoi(str[1])) % 256);
	else
	{
		ft_putstr_fd("too many arguments\n", 2);
		g_child_status = 1;
	}
}
