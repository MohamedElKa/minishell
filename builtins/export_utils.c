/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:58:48 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/12 16:17:30 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_without_plus(char *key)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc((ft_strlen(key) - 1) + 1);
	if (!str)
		exit(1);
	while (key[i] && key[i] != '+')
	{
		str[i] = key[i];
		i++;
	}
	free(key);
	return (str);
}

char	***get_variables(char **key)
{
	int		num;
	char	***str;
	char	**test;
	int		i;

	num = num_of_var(key);
	str = malloc(sizeof(char ***) * num);
	if (!str)
		exit(1);
	i = 0;
	while (i < num)
	{
		test = ft_split_exp(key[i], '=', 0, -1);
		str[i] = test;
		i++;
	}
	return (str);
}

int	ft_isalpha_(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')
		return (1);
	return (0);
}

int	check_plus(char *str, int equal)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' && equal == 0)
		{
			g_child_status = 1;
			ft_putstr_fd("not a valid identifier\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_regex(char *key, int equal)
{
	int	i;

	i = 0;
	if (ft_isalpha_(key[i]) == 0)
	{
		g_child_status = 1;
		ft_putstr_fd("not a valid identifier\n", 2);
		return (0);
	}
	i++;
	while (key[i])
	{
		if (ft_isalpha_(key[i]) == 0 && \
		ft_isdigit(key[i]) == 0 && key[i] != '+')
		{
			g_child_status = 1;
			ft_putstr_fd("not a valid identifieddr\n", 2);
			return (0);
		}
		i++;
	}
	if (check_plus(key, equal) == 0)
		return (0);
	return (1);
}
