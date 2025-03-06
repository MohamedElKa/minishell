/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:22:10 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/13 10:25:26 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	expand_env_var_(t_token **tokens, t_data *x)
{
	t_env	*tmp;
	int		i;

	tmp = x->env->next;
	i = 0;
	while (tmp)
	{
		if (!ft_strcmp((*tokens)->str, tmp->key))
		{
			free((*tokens)->str);
			(*tokens)->str = ft_strdup(tmp->value);
			i++;
		}
		tmp = tmp->next;
	}
	*tokens = delete_node((*tokens)->prev);
	if (!i)
		(*tokens)->tok = RM;
}

void	expand_env_var(t_token **tokens, t_data *x, int end)
{
	char	*join;
	char	*tab;
	char	*tab1;
	char	*env;

	tab1 = NULL;
	tab = ft_substr((*tokens)->str, 0, end);
	if (!tab)
		return ;
	env = check_env(&(*tokens)->str[end], x, &end);
	if (!env)
	{
		free(tab);
		return ;
	}
	if ((*tokens)->str[end])
		tab1 = ft_substr((*tokens)->str, end, ft_strlen((*tokens)->str));
	join = ft_strjoin_tok(tab, env);
	free((*tokens)->str);
	(*tokens)->str = ft_strjoin_tok(join, tab1);
}

t_token	*skip_helper(t_token **tmp, int i, t_data *x)
{
	if ((*tmp)->tok == SPACE)
	{
		*tmp = (*tmp)->next;
		while ((*tmp)->tok == SPACE)
			*tmp = delete_node(*tmp);
	}
	if ((*tmp)->tok == D_QUOTES)
	{
		while ((*tmp)->str[++i])
			if ((*tmp)->str[i] == '$')
				expand_env_var(tmp, x, i);
	}
	if ((*tmp)->tok == ENV_VAR)
	{
		if (!ft_strcmp((*tmp)->str, "?"))
		{
			free((*tmp)->str);
			(*tmp)->str = ft_itoa(g_child_status);
			*tmp = delete_node((*tmp)->prev);
		}
		else
			expand_env_var_(tmp, x);
	}
	return ((*tmp)->next);
}

void	skip_spaces_and_expand(t_token **tokens, t_data *x)
{
	t_token	*tmp;

	tmp = (*tokens)->next;
	while (tmp)
	{
		tmp = skip_helper(&tmp, -1, x);
	}
}

void	expander(t_token **tokens, t_data *x)
{
	skip_spaces_and_expand(tokens, x);
	parser(tokens, x);
}
