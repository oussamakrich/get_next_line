/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:22:01 by okrich            #+#    #+#             */
/*   Updated: 2022/11/11 20:21:13 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static	ssize_t	read_and_get_line(ssize_t	n, int fd, char **line, char **rest)
{
	char	*reader;
	ssize_t	pos;

	reader = malloc(BUFFER_SIZE + 1);
	if (reader == NULL)
		return (0);
	while (n > 0)
	{
		n = read(fd, reader, BUFFER_SIZE);
		if (n <= 0)
			break ;
		reader[n] = '\0';
		pos = check_newline(reader);
		if (pos != -1)
		{
			*line = ft_strnjoin(*line, reader, pos);
			if (pos < n && *line != NULL)
				*rest = ft_strndup(reader + pos, -1);
			break ;
		}
		*line = ft_strnjoin(*line, reader, n);
		if (*line == NULL)
			break ;
	}
	return (free(reader), n);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	ssize_t		n;

	line = NULL;
	n = check_newline(rest);
	if (rest != NULL && n != -1)
	{		
		line = get_resteofline(n, &rest, line);
		return (line);
	}
	line = rest;
	rest = NULL;
	n = read_and_get_line(1, fd, &line, &rest);
	if (n == -1)
		return (free(line), NULL);
	return (line);
}
