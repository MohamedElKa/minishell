/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:57:03 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/13 08:31:27 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	tok_hlpr_q(char *cmdline, int flag, t_token **tokens, int *i)
{
	int		end;
	int		start;
	char	*s;

	start = *i + 1;
	if (!flag)
	{
		end = index_of_next_d_qoutation(cmdline, i);
		flag = D_QUOTES;
	}
	else
	{
		end = index_of_next_s_qoutation(cmdline, i);
		flag = S_QUOTES;
	}
	s = ft_substr(cmdline, start, end);
	if (!s)
		return ;
	ft_create_node_tok(*tokens, s, flag);
	free(s);
}

static void	tokenizer_helper_word(char *cmdline, int *i, t_token **tokens)
{
	char	*s;
	char	*str;

	str = NULL;
	s = NULL;
	while (cmdline[*i] && ft_strchr(STOP_WORD, cmdline[*i]) == NULL)
	{
		str = ft_strdup_char(cmdline[*i]);
		s = ft_strjoin_tok(s, str);
		(*i)++;
	}
	if (s)
		ft_create_node_tok(*tokens, s, WORD);
	free(s);
	(*i)--;
}

static void	tokenizer_helper_red(t_token **tokens, int flag, int *i)
{
	if (flag == GREATGREAT)
		ft_create_node_tok(*tokens, ">>", GREATGREAT);
	else
		ft_create_node_tok(*tokens, "<<", LESSLESS);
	(*i)++;
}

static void	tokenizer_helper(char *cmdline, int *i, t_token **tokens)
{
	if (cmdline[*i] == '|')
		ft_create_node_tok(*tokens, "|", PIPE);
	else if (cmdline[*i] == '>' && cmdline[*i + 1] == '>')
		tokenizer_helper_red(tokens, GREATGREAT, i);
	else if (cmdline[*i] == '<' && cmdline[*i + 1] == '<')
		tokenizer_helper_red(tokens, LESSLESS, i);
	else if (cmdline[*i] == '>')
		ft_create_node_tok(*tokens, ">", OUT_REDIRECTION);
	else if (cmdline[*i] == '<')
		ft_create_node_tok(*tokens, "<", INP_REDIRECTION);
	else if (strchr(WHITE_SP, cmdline[*i]))
		ft_create_node_tok(*tokens, " ", SPACE);
	else if (cmdline[*i] == '$')
		tokenizer_helper_(cmdline, i, tokens);
	else if (cmdline[*i] == '"')
		tok_hlpr_q(cmdline, 0, tokens, i);
	else if (cmdline[*i] == '\'')
		tok_hlpr_q(cmdline, 1, tokens, i);
	else
		tokenizer_helper_word(cmdline, i, tokens);
}

void	tokenizer(char *cmdline, t_data *x)
{
	t_token	*tokens;
	int		i;
	char	*s;

	s = NULL;
	i = -1;
	tokens = ft_lstnew_tok("root", ROOT);
	if (!tokens)
		return ;
	if (!nbr_of_qoutes(cmdline, x))
		return ;
	while (cmdline[++i])
		tokenizer_helper(cmdline, &i, &tokens);
	if (!check_syntax(&tokens, x))
	{
		g_child_status = 258;
		ft_lstclear(&tokens);
		return ;
	}
}
