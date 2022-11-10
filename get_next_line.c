/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:22:01 by okrich            #+#    #+#             */
/*   Updated: 2022/11/10 16:33:15 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

int	check_newline(char *reader)
{
	int	i;

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

char	*get_resteofline(int n, char **rest, char *line)
{
	char	*tmp;

	line = ft_strndup(*rest, n);
	tmp = ft_strndup(*rest + n, -1);
	free(*rest);
	*rest = tmp;
	return (line);
}

int	read_and_get_line(int fd, char **line, char **rest)
{
	char	*reader;
	int		n;
	int		pos;

	reader = malloc(BUFFER_SIZE);
	if (reader == NULL)
		return (0);
	n = 1;
	while (n > 0)
	{
		n = read(fd, reader, BUFFER_SIZE);
		reader[n] = '\0';
		if (n <= 0)
			break ;
		pos = check_newline(reader);
		if (pos != -1)
		{
			*line = ft_strnjoin(*line, reader, pos);
			if (pos < n)
				*rest = ft_strndup(reader + pos, -1);
			break ;
		}
		*line = ft_strnjoin(*line, reader, n);
	}
	return (free(reader), n);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	ssize_t		n;

	n = check_newline(rest);
	if (rest != NULL && n != -1)
	{		
		line = get_resteofline(n, &rest, line);
		return (line);
	}
	line = rest;
	rest = NULL;
	n = read_and_get_line(fd, &line, &rest);
	if (n == -1)
		return (free(line), NULL);
	return (line);
}
void my_exit()
{
	system("leaks a.out");
}

int main()
{
	int fd = open("txt.txt",O_RDONLY);
	char *str;
	while((str = get_next_line(fd)))
	{
		printf("%s",str);
		free(str);
	}
	atexit(my_exit);
}
