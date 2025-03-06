/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:53:47 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/13 10:11:45 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_right_of_pipe(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens->next;
	while (tmp)
	{
		if (tmp->tok == WORD)
			return (1);
		else if (tmp->tok == INP_REDIRECTION || tmp->tok == OUT_REDIRECTION)
			return (1);
		else if (tmp->tok == LESSLESS || tmp->tok == GREATGREAT)
			return (1);
		else if (tmp->tok == D_QUOTES || tmp->tok == S_QUOTES)
			return (1);
		else if (tmp->tok == SPACE)
			tmp = tmp->next;
		else
			return (0);
	}
	return (0);
}

static int	check_pipe_syntax(t_token *tmp)
{
	int	pipe_left;
	int	pipe_right;

	pipe_left = check_left_of_pipe(tmp);
	pipe_right = check_right_of_pipe(tmp);
	if (pipe_left != 1 || pipe_right != 1)
		return (ft_error(PIPE_ERR_MSG), 0);
	return (1);
}

static int	heredoc_syntax(t_token **tmp, int flag, int q_flag)
{
	if (flag == 1 && (*tmp)->str[0] == '$')
	{
		while ((*tmp)->next && (*tmp)->next->tok != \
		SPACE && (*tmp)->next->tok != PIPE)
		{
			if ((*tmp)->next->tok == S_QUOTES || (*tmp)->next->tok == D_QUOTES)
				q_flag = 1;
			(*tmp)->str = ft_strjoin_par2((*tmp)->str, (*tmp)->next->str);
			*tmp = delete_next_node((*tmp)->next);
		}
	}
	if (flag == 1 && q_flag == 1)
		(*tmp)->tok = DELIMITER_Q;
	else
		(*tmp)->tok = DELIMITER;
	return (1);
}

static int	check_red_syntax(t_token **tokens, int flag)
{
	t_token	*tmp;

	if ((*tokens)->tok == LESSLESS)
		flag = 1;
	tmp = (*tokens)->next;
	while (tmp)
	{
		if (tmp->tok == WORD)
			return (heredoc_syntax(&tmp, flag, 0));
		if (tmp->tok == D_QUOTES || tmp->tok == S_QUOTES)
		{
			if (flag == 1)
				join_delimiter_q(&tmp);
			return (1);
		}
		else if (tmp->tok == SPACE)
			tmp = tmp->next;
		else
			return (ft_error(RED_ERR_MSG), 0);
	}
	return (ft_error(RED_ERR_MSG), 0);
}

int	check_syntax(t_token **tokens, t_data *x)
{
	t_token	*tmp;

	tmp = (*tokens)->next;
	while (tmp)
	{
		if (tmp->tok == PIPE)
		{
			if (!check_pipe_syntax(tmp))
				return (0);
		}
		else if (tmp->tok == INP_REDIRECTION || tmp->tok == OUT_REDIRECTION || \
		tmp->tok == GREATGREAT || tmp->tok == LESSLESS)
		{
			if (!check_red_syntax(&tmp, 0))
				return (0);
		}
		tmp = tmp->next;
	}
	expander(tokens, x);
	return (1);
}
