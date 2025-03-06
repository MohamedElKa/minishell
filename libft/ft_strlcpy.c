/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:26:01 by abel-all          #+#    #+#             */
/*   Updated: 2022/10/17 14:38:25 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	sl;

	i = 0;
	sl = ft_strlen(src);
	if (dstsize == 0)
		return (sl);
	while (i < dstsize - 1)
	{
		if (src[i] != '\0')
			dst[i] = src[i];
		else
			break ;
		i++;
	}
	dst[i] = '\0';
	return (sl);
}
