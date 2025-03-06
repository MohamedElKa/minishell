/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:11:14 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/12 07:54:43 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_exec(char *s1, char *s2)
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
