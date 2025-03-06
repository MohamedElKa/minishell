/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:35:56 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/13 09:33:07 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error(char *s)
{
	write (2, s, ft_strlen(s));
}

int	check_left_of_pipe(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens->prev;
	while (tmp)
	{
		if (tmp->tok == WORD)
			return (1);
		else if (tmp->tok == DELIMITER || tmp->tok == DELIMITER_Q)
			return (1);
		else if (tmp->tok == ENV_VAR)
			return (1);
		else if (tmp->tok == D_QUOTES || tmp->tok == S_QUOTES)
			return (1);
		else if (tmp->tok == SPACE)
			tmp = tmp->prev;
		else
			return (0);
	}
	return (0);
}

void	join_delimiter_q(t_token **tmp)
{
	while ((*tmp)->next && (*tmp)->next->tok != \
	SPACE && (*tmp)->next->tok != PIPE)
	{
		(*tmp)->str = ft_strjoin_par2((*tmp)->str, (*tmp)->next->str);
		*tmp = delete_next_node((*tmp)->next);
	}
	(*tmp)->tok = DELIMITER_Q;
}
