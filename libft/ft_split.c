/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 08:23:59 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/12 07:54:04 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_2dtab(char **p, int j)
{
	while (j >= 0)
		free(p[j--]);
	free(p);
	return (NULL);
}

static int	wd_nbr(char const *str, char sep)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (i == 0 && str[i] != sep)
			n++;
		if (str[i] == sep && str[i + 1] != sep && str[i + 1] != '\0')
			n++;
		i++;
	}
	return (n);
}

static int	wd_len(char const *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		lw;
	int		j;
	char	**p;

	if (!s)
		return (NULL);
	i = 0;
	j = -1;
	p = malloc(sizeof(char *) * (wd_nbr(s, c) + 1));
	if (!p)
		exit(1);
	while (++j < wd_nbr(s, c))
	{
		while (s[i] == c)
			i++;
		lw = wd_len(s + i, c);
		p[j] = ft_substr_(s, i, lw);
		if (!p[j])
			return (free_2dtab(p, j));
		i += lw;
	}
	p[j] = NULL;
	return (p);
}

char	**ft_split_exp(char const *s, char c, int i, int j)
{
	char	**p;

	if (!s)
		return (NULL);
	p = malloc(sizeof(char *) * 3);
	if (!p)
		exit(1);
	while (s[i])
	{
		if (s[i] == c)
		{
			p[++j] = ft_substr(s, 0, i);
			s += ++i;
			break ;
		}
		i++;
	}
	while (s[i++])
		;
	p[++j] = ft_substr(s, 0, i);
	p[++j] = NULL;
	return (p);
}
