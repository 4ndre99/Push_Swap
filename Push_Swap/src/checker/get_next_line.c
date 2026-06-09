/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcooli <marcooli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:20:53 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/09 16:03:38 by marcooli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*ft_join(char *str, char *buf)
{
	char	*stored;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str && str[i])
		i++;
	while (buf[j])
		j++;
	stored = malloc(i + j + 1);
	if (!stored)
		return (free(str), NULL);
	i = 0;
	j = 0;
	while (str && str[i])
		stored[j++] = str[i++];
	i = 0;
	while (buf[i])
		stored[j++] = buf[i++];
	stored[j] = '\0';
	return (free(str), stored);
}

static char	*joinbuffers(int fd, char *str)
{
	char	*buf;
	ssize_t	br;
	int		i;
	br = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(str), NULL);
	while (br > 0)
	{
		br = read(fd, buf, BUFFER_SIZE);
		if (br < 0)
			return (free(buf), free(str), NULL);
		if (br == 0)
			break ;
		buf[br] = '\0';
		str = ft_join(str, buf);
		if (!str)
			return (free(buf), NULL);
		i = 0;
		while (buf[i] != '\n')
			i++;
		if (buf[i] == '\n')
			break ;
	}
	return (free(buf), str);
}

static char	*trim_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str || !*str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*next_start(char *str)
{
	char	*next;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
		return (free(str), NULL);
	j = i;
	while (str[j])
		j++;
	next = malloc(j - i + 1);
	if (!next)
		return (free(str), NULL);
	i++;
	j = 0;
	while (str[i])
		next[j++] = str[i++];
	next[j] = '\0';
	return (free(str), next);
}

char	*get_next_line(int fd)
{
	static char	*buffers[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffers[fd] = joinbuffers(fd, buffers[fd]);
	if (!buffers[fd])
		return (NULL);
	line = trim_line(buffers[fd]);
	if (!line)
	{
		free(buffers[fd]);
		buffers[fd] = NULL;
		return (NULL);
	}
	buffers[fd] = next_start(buffers[fd]);
	return (line);
}
