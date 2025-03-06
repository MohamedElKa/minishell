/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:07:32 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/11 16:18:50 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstclear(t_token **lst)
{
	t_token	*prev;
	t_token	*curr;

	curr = *lst;
	while (curr)
	{
		prev = curr->next;
		free(curr->str);
		free(curr);
		curr = prev;
	}
	*lst = NULL;
}

void	ft_lstclear_(t_cmds **lst)
{
	t_cmds	*prev;
	t_cmds	*curr;

	curr = *lst;
	while (curr)
	{
		prev = curr->next;
		if (curr->cmd)
			free_2d_tab(curr->cmd);
		free(curr);
		curr = prev;
	}
	*lst = NULL;
}

void	ft_lstclear__(t_env **lst)
{
	t_env	*prev;
	t_env	*curr;

	curr = *lst;
	while (curr)
	{
		prev = curr->next;
		free(curr->declare);
		free(curr->value);
		free(curr->key);
		free(curr);
		curr = prev;
	}
	*lst = NULL;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i++]);
	}
	free(tab);
}

void	free3d_atab(char ***str, int l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < l)
	{
		j = 0;
		while (str[i][j])
		{
			free(str[i][j]);
			j++;
		}
		free(str[i]);
		i++;
	}
	free(str);
}
