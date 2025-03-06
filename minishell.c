/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:28:43 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/12 16:24:05 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"
#include <stdio.h>

void	rl_replace_line(char *s, int n);

void	free_env(t_data *x)
{
	ft_lstclear__(&x->env);
	ft_lstclear__(&x->exp);
	free(x);
	exit(0);
}

void	signal_catcher(int signum)
{
	int	status;

	(void)signum;
	if (waitpid(-1, &status, WNOHANG) == 0)
		return ;
	else
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	ft_handling_signals(void)
{
	signal(SIGINT, &signal_catcher);
	signal(SIGQUIT, SIG_IGN);
}

static void	run_promt(char *line, t_data *x)
{
	line = readline("minishell > ");
	if (!line)
	{
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	if (*line)
	{
		line = ft_strtrim(line, " \t\n");
		add_history(line);
		tokenizer(line, x);
	}
	free(line);
}

int	main(int ac, char **av, char **env)
{
	t_data	*x;

	(void)ac;
	(void)av;
	x = malloc(sizeof(t_data));
	if (!x)
		exit(1);
	env_exp_init(env, x);
	while (1)
	{
		ft_handling_signals();
		run_promt(NULL, x);
	}
	free_env(x);
}
