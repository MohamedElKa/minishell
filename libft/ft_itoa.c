/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:27:35 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/12 07:53:35 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calcdigit(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*setdigit(int l, long n)
{
	char	*p;
	int		t;

	if (n < 0)
		n *= -1;
	t = l;
	p = (char *)malloc(l + 1);
	if (!p)
		exit(1);
	if (n == 0)
		p[0] = '0';
	while (n)
	{
		p[l - 1] = (n % 10) + 48;
		n /= 10;
		l--;
	}
	p[t] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	int		l;
	char	*p;

	if (n < 0)
		l = calcdigit(n) + 1;
	else
		l = calcdigit(n);
	p = setdigit(l, n);
	if (!p)
		return (NULL);
	if (n < 0)
		p[0] = '-';
	return (p);
}
