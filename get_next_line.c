/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:08:28 by okrich            #+#    #+#             */
/*   Updated: 2022/11/08 19:36:37 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int	check_newline(char *reader)
{
	int i;

	i = 0;
	while(reader[i] != '\0')
	{
		if (reader[i] == '\n')
			break ;
		i++;
	}
	if (reader[i] == '\0')
		return (-1);
	return (i);
}

int	bring_line(char **reader, char **rest, char **line)
{

	int		pos;
	char	*tmp;

	pos = check_newline(*reader);
	if (pos != -1)
	{
		*line = ft_strnjoin(*line, *reader, pos + 1);
		tmp = ft_substr(*reader, pos + 1, ft_strlen(*reader));
		free(*rest);
		*rest = tmp;
		return (1);
	}
	*line = ft_strnjoin(*line, *reader, ft_strlen(*reader));
	return (0);
}

int bring_restofline(char **line, char **rest)
{
	int		pos;
	char	*tmp;

	if (*rest == NULL)
		return 0;
	pos = check_newline(*rest);
	if (pos != -1)
	{
		*line = ft_substr(*rest, 0, pos + 1);
		tmp = ft_substr(*rest , pos + 1, ft_strlen(*rest) - pos);
		free(*rest);
		*rest = tmp;
		return 1;
	}
	return 0;
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*reader;
	char		*line;
	int			n;

	n = 1;
	if (bring_restofline(&line, &rest))
		return (line);
	reader = malloc(BUFFER_SIZE + 1);
	if (reader == NULL)
		return (NULL);
	while (n > 0)
	{
		n = read(fd, reader, BUFFER_SIZE);
		reader[n] = '\0';
		if (n <= 0)
			break ;
		if (bring_line(&reader, &rest, &line))
			break ;
	}
	if (n == -1)
	{
		free(reader);
		return (NULL);
	}
	free(reader);
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
