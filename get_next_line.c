/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:08:28 by okrich            #+#    #+#             */
/*   Updated: 2022/11/07 19:04:09 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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

int rest_line(char **line, char **rest)
{
	int pos;

	if (*line == NULL)
		return 0;
	pos = check_newline(*line);
	if (pos != -1)
	{
		*line = ft_substr(*line, 0, pos + 1);
		*rest = ft_substr(*rest , pos + 1, ft_strlen(*rest) - pos);
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
	int			pos;

	line = rest;
	if (rest_line(&line, &rest))
		return (line);
	reader = malloc(BUFFER_SIZE + 1);
	if (reader == NULL)
		return (NULL);
	while (1)
	{
		n = read(fd, reader, BUFFER_SIZE);
		reader[BUFFER_SIZE] = '\0';
		pos = check_newline(reader);
		if (pos != -1 || n == 0)
			break ;
		line = ft_strjoin(line, reader);
	}
	if (pos != -1)
	{
		line = ft_strljoin(line, reader, pos + 1);
		rest = ft_substr(reader, pos + 1, ft_strlen(reader));
	}
	free(reader);
	return (line);
}



int main()
{
	int fd = open("txt.txt",O_RDONLY);
	// int i = 0;
	// while(i < 2)
	// {
		printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));
	// 	i++;
	// }
}
