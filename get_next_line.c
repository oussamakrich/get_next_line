/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:08:28 by okrich            #+#    #+#             */
/*   Updated: 2022/11/07 16:59:55 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*reader;
	char		*line;
	int			n;
	int			i;

	line = rest;
	if (line != NULL)
	{
		i = check_newline(line);
		if (i != -1)
		{
			line = ft_substr(line, 0, i + 1);
			rest = ft_substr(rest , i + 1, ft_strlen(rest) - i);
			return (line);
		}
	}
	reader = malloc(BUFFER_SIZE + 1);
	if (reader == NULL)
		return (NULL);
	n = read(fd, reader, BUFFER_SIZE);
	if (n <= 0)
		return (NULL);
	reader[BUFFER_SIZE] = '\0';
	i = check_newline(reader);
	while(i == -1 || n <= 0)
	{
		line = ft_strjoin(line, reader);
		n = read(fd , reader, BUFFER_SIZE);
		i = check_newline(reader);
	}
	if (i != -1)
	{
		line = ft_strljoin(line, reader, i + 1);
		rest = ft_substr(reader, i + 1, ft_strlen(reader));
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
