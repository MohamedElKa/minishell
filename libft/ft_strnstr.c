/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 08:31:31 by abel-all          #+#    #+#             */
/*   Updated: 2022/10/17 13:28:09 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack && !len)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && needle[j] == haystack[i + j] && (i + j) < len)
			j++;
		if (!needle[j])
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
