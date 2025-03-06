/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:16:56 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/12 07:53:23 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size == SIZE_MAX)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		exit(1);
	ft_bzero(p, count * size);
	return (p);
}
