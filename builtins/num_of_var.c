/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_of_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:54:47 by mel-karm          #+#    #+#             */
/*   Updated: 2023/04/10 14:55:03 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	num_of_var(char **key)
{
	int	i;

	i = 0;
	while (key[i])
		i++;
	return (i);
}
