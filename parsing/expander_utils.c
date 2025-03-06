/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:04:24 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/13 10:23:57 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*delete_node(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens->next;
	if (!tokens->next)
		tokens->prev->next = NULL;
	else
	{
		tokens->prev->next = tokens->next;
		tokens->next->prev = tokens->prev;
	}
	free(tokens->str);
	free(tokens);
	return (tmp);
}

t_token	*delete_next_node(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens->prev;
	if (!tokens->next)
		tokens->prev->next = NULL;
	else
	{
		tokens->prev->next = tokens->next;
		tokens->next->prev = tokens->prev;
	}
	free(tokens->str);
	free(tokens);
	return (tmp);
}

void	check_env_helper(char *s, char *tab, int *i)
{
	while (s[*i] && !strchr(SPECIEL_CHARS, s[*i]) && \
	!strchr(WHITE_SP, s[*i]) && s[*i] != '$' && s[*i] != '\'')
	{
		tab[*i - 1] = s[*i];
		(*i)++;
	}
	tab[*i - 1] = '\0';
}

char	*check_env(char *s, t_data *x, int *end)
{
	int		i;
	char	*tab;
	char	*e;
	t_env	*tmp;

	tmp = x->env->next;
	tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tab)
		exit(1);
	e = NULL;
	i = 1;
	check_env_helper(s, tab, &i);
	if (i == 1)
		return (free(tab), e);
	while (tmp)
	{
		if (!ft_strcmp(tab, tmp->key))
			e = ft_strdup(tmp->value);
		tmp = tmp->next;
	}
	return (*end += i, free(tab), e);
}
