/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:07:34 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/12 07:55:30 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	k;
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	i = 0;
	k = 0;
	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		exit(1);
	while (s1[k])
		p[i++] = s1[k++];
	k = 0;
	while (s2[k])
		p[i++] = s2[k++];
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin_par(char *s1, char *s2)
{
	size_t	i;
	size_t	k;
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	i = 0;
	k = 0;
	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		exit(1);
	while (s1[k])
		p[i++] = s1[k++];
	k = 0;
	while (s2[k])
		p[i++] = s2[k++];
	p[i] = '\0';
	return (free(s2), p);
}

char	*ft_strjoin_tok(char *s1, char *s2)
{
	size_t	i;
	size_t	k;
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	i = 0;
	k = 0;
	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		exit(1);
	while (s1[k])
		p[i++] = s1[k++];
	k = 0;
	while (s2[k])
		p[i++] = s2[k++];
	p[i] = '\0';
	return (free(s1), free(s2), p);
}

char	*ft_strjoin_par2(char *s1, char *s2)
{
	size_t	i;
	size_t	k;
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	i = 0;
	k = 0;
	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		exit(1);
	while (s1[k])
		p[i++] = s1[k++];
	k = 0;
	while (s2[k])
		p[i++] = s2[k++];
	p[i] = '\0';
	return (free(s1), p);
}

char	*ft_strjoin_char(char *s1, char s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = ft_strdup("");
	}
	str = malloc(strlen(s1) + 2);
	if (!str)
		exit(1);
	while (s1[i])
		str[j++] = s1[i++];
	str[j++] = s2;
	str[j] = '\0';
	return (str);
}
