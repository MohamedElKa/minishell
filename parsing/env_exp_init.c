/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exp_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:26:58 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/13 11:53:39 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_env	*init_empty_env(void)
{
	t_env	*env;
	char	pwd[1024];

	getcwd(pwd, sizeof(pwd));
	env = ft_lstnew_env("hello", "hello", 0);
	ft_create_node_env(&env, "PWD", pwd, 0);
	ft_create_node_env(&env, "SHLVL", "1", 0);
	ft_create_node_env(&env, "PATH", \
	"/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.", 2);
	ft_create_node_env(&env, "_", "/usr/bin/env", 0);
	return (env);
}

static t_env	*init_empty_exp(void)
{
	t_env	*exp;
	char	pwd[1024];

	getcwd(pwd, sizeof(pwd));
	exp = ft_lstnew_env("hello", "hello", 0);
	ft_create_node_env(&exp, "OLDPWD", "\0", 1);
	ft_create_node_env(&exp, "PWD", pwd, 0);
	ft_create_node_env(&exp, "SHLVL", "1", 0);
	return (exp);
}

static t_env	*init_env(char **enva)
{
	int		i;
	char	**tab;
	t_env	*head;

	i = -1;
	head = ft_lstnew_env("hello", "hello", 0);
	while (enva[++i])
	{
		tab = ft_split(enva[i], '=');
		ft_create_node_env(&head, tab[0], tab[1], 0);
		free_tab(tab);
	}
	return (head);
}

static t_env	*init_exp(char **enva)
{
	int		i;
	char	**tab;
	t_env	*head;

	i = -1;
	head = ft_lstnew_env("hello", "hello", 0);
	while (enva[++i])
	{
		tab = ft_split(enva[i], '=');
		ft_create_node_env(&head, tab[0], tab[1], 0);
		free_tab(tab);
	}
	return (head);
}

void	env_exp_init(char **enva, t_data *x)
{
	if (!*enva)
	{
		x->env = init_empty_env();
		x->exp = init_empty_exp();
	}
	else
	{
		x->enva = enva;
		x->env = init_env(enva);
		x->exp = init_exp(enva);
	}
}
