/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:40:44 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/12 07:56:58 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlcheck(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			exit(1);
		*s1 = 0;
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1);
	if (!str)
		exit(1);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[len] = '\0';
	return (free(s1), str);
}

static char	*ft_returnline(char	*save)
{
	int		i;
	char	*line;

	if (!*save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
		line = (char *)malloc(i + 1);
	else
		line = (char *)malloc(i + 2);
	if (!line)
		exit(1);
	i = -1;
	while (save[++i] && save[i] != '\n')
		line[i] = save[i];
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_savepos(char *save)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (free(save), NULL);
	p = (char *)malloc(ft_strlen(save) - i + 1);
	if (!p)
		exit(1);
	j = 0;
	while (save[++i])
		p[j++] = save[i];
	p[j] = '\0';
	return (free(save), p);
}

char	*get_next_line(int fd)
{
	int			r;
	char		*line;
	char		*buffer;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		exit(1);
	r = 1;
	while (ft_nlcheck(save) == 0 && r)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
			return (free(buffer), NULL);
		buffer[r] = '\0';
		save = ft_strjoin_gnl(save, buffer);
	}
	line = ft_returnline(save);
	save = ft_savepos(save);
	return (free(buffer), line);
}
