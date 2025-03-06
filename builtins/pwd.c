/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:30:15 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/08 13:49:47 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	our_pwd(char *str)
{
	char	cwd[1024];

	if (str != NULL)
		perror("pwd");
	else
	{
		getcwd(cwd, sizeof(cwd));
		ft_putstr_fd(cwd, 1);
		ft_putchar_fd('\n', 1);
	}
}
