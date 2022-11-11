/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:23:45 by okrich            #+#    #+#             */
/*   Updated: 2022/11/11 20:24:39 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static ssize_t	check_newline(char *reader)
{
	ssize_t	i;

	i = 0;
	if (reader == NULL)
		return (-1);
	while (reader[i] != '\0')
	{
		if (reader[i] == '\n')
			break ;
		i++;
	}
	if (reader[i] == '\0')
		return (-1);
	return (i + 1);
}

static char	*get_resteofline(ssize_t n, char **rest, char *line)
{
	char	*tmp;

	line = ft_strndup(*rest, n);
	if (line == NULL)
		return (NULL);
	if (n < ft_strlen(*rest))
	{
		tmp = ft_strndup(*rest + n, -1);
		free(*rest);
		if (tmp == NULL)
			return (NULL);
		*rest = tmp;
	}
	else
	{
		free(*rest);
		*rest = NULL;
	}
	return (line);
}

static ssize_t	read_and_get_line(ssize_t n, int fd, char **line, char **rest)
{
	char	*reader[OPEN_MAX];
	ssize_t	pos;

	reader[fd] = malloc(BUFFER_SIZE + 1);
	if (reader[fd] == NULL)
		return (0);
	while (n > 0)
	{
		n = read(fd, reader[fd], BUFFER_SIZE);
		if (n <= 0)
			break ;
		reader[fd][n] = '\0';
		pos = check_newline(reader[fd]);
		if (pos != -1)
		{
			*line = ft_strnjoin(*line, reader[fd], pos);
			if (pos < n && *line != NULL)
				*rest = ft_strndup(reader[fd] + pos, -1);
			break ;
		}
		*line = ft_strnjoin(*line, reader[fd], n);
		if (*line == NULL)
			break ;
	}
	return (free(reader[fd]), n);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*line[OPEN_MAX];
	ssize_t		n;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	line[fd] = NULL;
	n = check_newline(rest[fd]);
	if (rest[fd] != NULL && n != -1)
	{		
		line[fd] = get_resteofline(n, &rest[fd], line[fd]);
		return (line[fd]);
	}
	line[fd] = rest[fd];
	rest[fd] = NULL;
	n = read_and_get_line(1, fd, &line[fd], &rest[fd]);
	if (n == -1)
		return (free(line[fd]), NULL);
	return (line[fd]);
}
