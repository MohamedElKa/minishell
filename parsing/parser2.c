/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:00:58 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/13 12:52:27 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	heredoc_signal(int sigint)
{
	(void)sigint;
	close(0);
}

char	*ft_check_and_replace(char *str, t_data *x, int end)
{
	char	*join;
	char	*tab;
	char	*tab1;
	char	*env;

	tab1 = NULL;
	tab = ft_substr(str, 0, end);
	if (!tab)
		return (NULL);
	env = check_env(&str[end], x, &end);
	if (!env)
	{
		free(tab);
		return (str);
	}
	if (str[end])
	{
		tab1 = ft_substr(str, end, ft_strlen(str));
		if (!tab1)
			return (NULL);
	}
	join = ft_strjoin_tok(tab, env);
	free(str);
	str = ft_strjoin_tok(join, tab1);
	return (str);
}

char	*handle_hdc_helper(char *str, t_token *head, t_data *x, int i)
{
	write(1, "> ", 2);
	str = get_next_line(0);
	if (!str)
		return (NULL);
	if (!ft_strcmp(str, head->str))
		return (free(str), NULL);
	if (head->tok != D_QUOTES && head->tok != S_QUOTES \
	&& head->tok != DELIMITER_Q)
	{
		while (str[++i])
		{
			if (str[i] == '$')
			{
				str = ft_check_and_replace(str, x, i);
				if (!str)
					break ;
			}
		}
		i = -1;
	}
	return (str);
}

void	hendle_heredoc_helper(char *str, t_data *x, t_token *head, int fd)
{
	while (1)
	{
		signal(SIGINT, heredoc_signal);
		str = handle_hdc_helper(NULL, head, x, -1);
		if (!str)
			break ;
		ft_putstr_fd(str, fd);
		free(str);
	}
}

int	ft_handle_heredoc(t_token *head, t_data *x)
{
	int		tmpfile_fd;
	int		fd;
	int		tty_fd;
	char	*tmpfile;

	tmpfile = ".tmp";
	tmpfile_fd = open(tmpfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (tmpfile_fd == -1)
		return (perror("minishell"), -1);
	hendle_heredoc_helper(NULL, x, head, tmpfile_fd);
	close(tmpfile_fd);
	fd = open(tmpfile, O_RDONLY);
	if (fd == -1)
		perror("minishell");
	if (!ttyname(0))
	{
		tty_fd = open(ttyname(1), O_RDONLY);
		dup2(tty_fd, 0);
		return (-5);
	}
	return (fd);
}
