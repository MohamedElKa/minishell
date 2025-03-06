/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:02:29 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/13 12:34:38 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	join_quotes_helper_(t_token *tmp)
{
	if (tmp->prev->tok != PIPE && tmp->prev->tok \
	!= SPACE && tmp->prev->tok != ROOT)
	{
		tmp->str = ft_strjoin_par(tmp->prev->str, tmp->str);
		tmp = delete_node(tmp->prev);
	}
	if (tmp->next && tmp->next->tok != SPACE && tmp->next->tok != PIPE \
	&& tmp->next->tok != INP_REDIRECTION && tmp->next->tok != OUT_REDIRECTION \
	&& tmp->next->tok != LESSLESS && tmp->next->tok != GREATGREAT)
	{
		tmp->str = ft_strjoin_par2(tmp->str, tmp->next->str);
		tmp = delete_next_node(tmp->next);
	}
}

t_token	*ft_join_qoutes_node(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		if ((tmp->tok == D_QUOTES || tmp->tok == S_QUOTES))
			join_quotes_helper(tmp);
		else if (tmp->tok == ENV_VAR)
			join_quotes_helper_(tmp);
		tmp = tmp->next;
	}
	return (tokens);
}

void	remove_env_helper(char *s, t_token *tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tmp->str[i])
	{
		if (tmp->str[i] == '$')
		{
			i++;
			while (!strchr(SPECIEL_CHARS, tmp->str[i]) \
			&& !strchr(WHITE_SP, tmp->str[i]) \
			&& tmp->str[i] != '$' && tmp->str[i] != '\'')
				i++;
		}
		else
			s[j++] = tmp->str[i++];
	}
	s[j] = 0;
}

t_token	*ft_remove_env(t_token *tmp)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = malloc(sizeof(char) * (ft_strlen(tmp->str) + 1));
	if (!s)
		exit(1);
	remove_env_helper(s, tmp);
	free(tmp->str);
	tmp->str = ft_strdup(s);
	return (free(s), tmp);
}

t_token	*ft_clean_nodes(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		if (tmp->tok == RM)
		{
			tmp = delete_node(tmp);
			if (!tmp)
				break ;
		}
		if (tmp->tok == D_QUOTES)
		{
			if (ft_strchr(tmp->str, '$'))
				tmp = ft_remove_env(tmp);
		}
		tmp = tmp->next;
	}
	return (tokens);
}
