/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:28:26 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/10 15:43:07 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strnncmp(char *str, char c)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
		while (str[i])
		{
			if (str[i] != c)
				return (str[i] - c);
			i++;
		}
	}
	else if (str[i] != '-')
		return (-1);
	return (0);
}

void	print_with_line(char **arg, int i)
{
	while (arg[i])
	{
		ft_putstr_fd(arg[i], 1);
		ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}

void	ft_echo(char **arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (ft_strnncmp(arg[i], 'n') != 0)
			break ;
		i++;
	}
	if (i > 1)
	{
		while (arg[i])
		{
			ft_putstr_fd(arg[i], 1);
			i++;
			if (arg[i] != NULL)
				ft_putstr_fd(" ", 1);
		}
	}
	else
		print_with_line(arg, i);
}
