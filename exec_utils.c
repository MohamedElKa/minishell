/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:22:56 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/10 11:00:22 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_pipes(int	*pipefd)
{
	if (pipe(pipefd) == -1)
		perror("pipe");
}

int	ft_check_path(char *str)
{
	if (ft_strncmp(str, "/usr", 4) == 0)
		return (1);
	else if (ft_strncmp(str, "/bin", 4) == 0)
		return (1);
	return (0);
}

char	*getpath(t_env **env, char *str)
{
	t_env	*tmp;
	char	**s;
	char	*cmd;

	tmp = (*env);
	s = NULL;
	if (access(str, X_OK) == 0)
		return (str);
	while (tmp)
	{
		if (ft_strncmp(tmp->key, "PATH", ft_strlen(tmp->key)) == 0)
		{
			s = ft_split(tmp->value, ':');
			break ;
		}
		tmp = tmp->next;
	}
	if (s == NULL)
		ft_errors();
	cmd = join_path(str, s);
	return (cmd);
}
