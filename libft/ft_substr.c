/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:34:07 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/12 07:56:08 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*p;

	if (!s)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	if (len > l)
		len = l;
	if (start > l)
		len = 0;
	p = (char *)malloc(len + 1);
	if (!p)
		exit(1);
	while ((i < len) && s[start])
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*p;

	if (!s)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	if (len > l)
		len = l;
	if (start > l)
		len = 0;
	p = (char *)malloc(len + 1);
	if (!p)
		exit(1);
	while ((start < len) && s[start])
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
