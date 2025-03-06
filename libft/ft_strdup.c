/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:21:56 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/12 09:45:40 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	if (!s1)
		return (NULL);
	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (!s2)
		exit(1);
	i = 0;
	while (s1 && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strdup_char(char source)
{
	char	*str;

	str = malloc(2);
	if (!str)
		exit(1);
	str[0] = source;
	str[1] = '\0';
	return (str);
}
