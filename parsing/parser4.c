/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:03:25 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/13 12:34:21 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	join_quotes_helper(t_token *tmp)
{
	if (tmp->prev->tok != PIPE && tmp->prev->tok \
	!= SPACE && tmp->prev->tok != ROOT)
	{
		tmp->str = ft_strjoin_par(tmp->prev->str, tmp->str);
		tmp = delete_node(tmp->prev);
	}
	while (tmp->next && tmp->next->tok != SPACE && tmp->next->tok != PIPE \
	&& tmp->next->tok != INP_REDIRECTION && tmp->next->tok != OUT_REDIRECTION \
	&& tmp->next->tok != LESSLESS && tmp->next->tok != GREATGREAT)
	{
		tmp->str = ft_strjoin_par2(tmp->str, tmp->next->str);
		tmp = delete_next_node(tmp->next);
	}
}

void	free_2d_tab(char **p)
{
	int	j;

	j = 0;
	while (p[j])
	{
		free(p[j]);
		j++;
	}
	free(p);
}

int	ft_lstsize_tok(t_token *tokens)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = tokens->next;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_token	*init_for_parcer(t_token *tokens, t_data *x)
{
	t_token	*tmp;

	tmp = ft_clean_nodes(tokens);
	tmp = ft_join_qoutes_node(tokens);
	x->in_fd = -2;
	x->out_fd = -2;
	x->list_len = ft_lstsize_tok(tokens);
	return (tmp);
}

void	parser_helper_outred(t_token **tmp, t_data *x, int type)
{
	if (x->out_fd != -2)
		x->out_fd = close(x->out_fd);
	*tmp = (*tmp)->next;
	while ((*tmp)->tok == SPACE)
		*tmp = (*tmp)->next;
	if (type == OUT_REDIRECTION)
		x->out_fd = open((*tmp)->str, O_CREAT | O_RDWR | O_TRUNC, 0644);
	else
		x->out_fd = open((*tmp)->str, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (x->out_fd == -1)
		perror("minishell");
}
