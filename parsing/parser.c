/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:36:36 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/12 12:09:01 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <sys/fcntl.h>

int	create_cmds(t_token *tmp, t_data *x, t_cmds *cmds, char ***p)
{
	ft_create_node_cmds(cmds, *p, x->in_fd, x->out_fd);
	free_2d_tab(*p);
	if (tmp->next)
	{
		*p = malloc(sizeof(char *) * x->list_len);
		if (!*p)
			exit(1);
	}
	x->out_fd = -2;
	x->in_fd = -2;
	return (0);
}

void	pars_red_help(t_token **tmp, t_data *x)
{
	if ((*tmp)->tok == INP_REDIRECTION)
		parser_helper_inred(tmp, x, INP_REDIRECTION);
	else if ((*tmp)->tok == OUT_REDIRECTION)
		parser_helper_outred(tmp, x, OUT_REDIRECTION);
	else if ((*tmp)->tok == LESSLESS)
		parser_helper_inred(tmp, x, LESSLESS);
	else if ((*tmp)->tok == GREATGREAT)
		parser_helper_outred(tmp, x, GREATGREAT);
}

int	parser_helper(t_token *tmp, t_data *x, t_cmds *cmds, int i)
{
	char	**p;

	p = malloc(sizeof(char *) * x->list_len);
	if (!p)
		exit(1);
	while (tmp)
	{
		if (tmp->tok == INP_REDIRECTION || tmp->tok == OUT_REDIRECTION \
		|| tmp->tok == LESSLESS || tmp->tok == GREATGREAT)
			pars_red_help(&tmp, x);
		else
		{
			if (tmp->tok != SPACE && tmp->tok != ROOT && tmp->tok != PIPE)
				p[i++] = ft_strdup(tmp->str);
		}
		if ((tmp->tok == PIPE || tmp->next == NULL))
		{
			p[i] = NULL;
			i = create_cmds(tmp, x, cmds, &p);
			if (i == -1)
				return (-1);
		}
		tmp = tmp->next;
	}
	return (i);
}

int	clean_list(t_cmds *cmds, int i)
{
	ft_lstclear_(&cmds);
	return (i);
}

void	parser(t_token **tokens, t_data *x)
{
	t_cmds	*cmds;
	t_token	*tmp;
	int		i;

	tmp = init_for_parcer(*tokens, x);
	cmds = ft_lstnew_cmds(NULL, -2, -2);
	if (!cmds)
		return ;
	i = parser_helper(tmp, x, cmds, 0);
	if (i == -1)
		return ;
	ft_lstclear(tokens);
	if (cmds->next->cmd != NULL)
	{
		executer(&cmds->next, &x);
		ft_lstclear_(&cmds);
	}
}
