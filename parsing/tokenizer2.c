/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:34:58 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/13 08:30:06 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_qoutation(t_data *x)
{
	if (x->d_qoute % 2 != 0 || x->s_qoute % 2 != 0)
	{
		g_child_status = 258;
		return (perror("minishell : syntax error\n"), 0);
	}
	return (1);
}

int	index_of_next_d_qoutation(char *s, int *i)
{
	while (s[++(*i)])
	{
		if (s[*i] == '"')
			break ;
	}
	return (*i);
}

int	index_of_next_s_qoutation(char *s, int *i)
{
	while (s[++(*i)])
	{
		if (s[*i] == '\'')
			break ;
	}
	return (*i);
}

int	nbr_of_qoutes(char *cmdline, t_data *x)
{
	int	i;

	i = -1;
	x->d_qoute = 0;
	x->s_qoute = 0;
	while (cmdline[++i])
	{
		if (cmdline[i] == '"')
			x->d_qoute++;
		if (cmdline[i] == '\'')
			x->s_qoute++;
	}
	return (check_qoutation(x));
}

void	tokenizer_helper_(char *cmdline, int *i, t_token **tokens)
{
	char	*s;
	char	*str;

	str = NULL;
	s = NULL;
	ft_create_node_tok(*tokens, "$", WORD);
	while (cmdline[*i + 1] && strchr(SPECIEL_CHARS, cmdline[*i + 1]) == \
	NULL && strchr(WHITE_SP, cmdline[*i + 1]) == NULL && cmdline[*i + 1] != '"' \
	&& cmdline[*i + 1] != '$' && cmdline[*i + 1] != '\'')
	{
		++(*i);
		str = ft_strdup_char(cmdline[*i]);
		s = ft_strjoin_tok(s, str);
	}
	if (s)
		ft_create_node_tok(*tokens, s, ENV_VAR);
	free(s);
}
