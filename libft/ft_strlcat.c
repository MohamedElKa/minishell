/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:34:07 by abel-all          #+#    #+#             */
/*   Updated: 2022/10/22 15:26:15 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dl;

	if (!dst && !dstsize)
		return (ft_strlen(src));
	dl = ft_strlen(dst);
	i = 0;
	if (dstsize == 0 || dstsize < dl)
		return (ft_strlen(src) + dstsize);
	while (src[i] && (i + dl) < (dstsize -1))
	{
		dst[i + dl] = src[i];
		i++;
	}
	dst[i + dl] = '\0';
	return (ft_strlen(src) + dl);
}
