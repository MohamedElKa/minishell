/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_cmds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:32:48 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/12 07:57:26 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_2d_tabdup(char **cmds)
{
	int		i;
	char	**dup;

	if (!cmds || !*cmds)
		return (NULL);
	i = 0;
	while (cmds[i++])
		;
	dup = malloc(sizeof(char *) * (i + 1));
	if (!dup)
		exit(1);
	i = 0;
	while (cmds[i])
	{
		dup[i] = ft_strdup(cmds[i]);
		if (!dup[i])
			return (NULL);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

t_cmds	*ft_lstnew_cmds(char **cmds, int in_fd, int out_fd)
{
	t_cmds	*new;

	new = malloc(sizeof(t_cmds));
	if (!new)
		exit(1);
	new->cmd = ft_2d_tabdup(cmds);
	new->in_fd = in_fd;
	new->out_fd = out_fd;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstaddback_cmds(t_cmds *head, t_cmds *new)
{
	t_cmds	*tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_create_node_cmds(t_cmds *head, char **cmds, int in_fd, int out_fd)
{
	t_cmds	*new;

	new = ft_lstnew_cmds(cmds, in_fd, out_fd);
	if (!new)
		return ;
	ft_lstaddback_cmds(head, new);
}
