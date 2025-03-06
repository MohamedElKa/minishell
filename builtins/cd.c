/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:31:27 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/12 15:49:30 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_home(t_env **env)
{
	t_env	*tmp;

	tmp = (*env);
	while (tmp)
	{
		if (ft_strncmp(tmp->key, "HOME", ft_strlen(tmp->key)) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	our_cd(char *str, t_env **env)
{
	char	*s;

	s = get_home(env);
	if (!str)
		chdir(s);
	else
	{
		if (chdir(str) == -1)
		{
			g_child_status = 1;
			ft_putstr_fd("cd: >>No such file or directory\n", 2);
		}
	}
}
