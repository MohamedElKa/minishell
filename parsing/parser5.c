/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:13:59 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/12 10:15:01 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parser_helper_inred(t_token **tmp, t_data *x, int type)
{
	if (x->in_fd != -2)
		x->in_fd = close(x->in_fd);
	*tmp = (*tmp)->next;
	while ((*tmp)->tok == SPACE)
		*tmp = (*tmp)->next;
	if (type == INP_REDIRECTION)
	{
		x->in_fd = open((*tmp)->str, O_RDONLY);
		if (x->in_fd == -1)
			perror("minishell");
	}
	else
		x->in_fd = ft_handle_heredoc(*tmp, x);
}
