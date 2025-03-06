/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 08:33:37 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/11 02:24:54 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	if (!s1 || !s2)
		return (1);
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while ((a[i] || b[i]) && (a[i] == b[i]) && (i < (n -1)))
		i++;
	return (a[i] - b[i]);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*a;
	unsigned char	*b;
	char			*s;
	size_t			i;

	if (!s1 || !s2)
		return (-1);
	s = ft_strtrim_(s1, "\n");
	a = (unsigned char *)s;
	b = (unsigned char *)s2;
	i = 0;
	while (a[i] && b[i] && (a[i] == b[i]))
		i++;
	return (free(s), a[i] - b[i]);
}
