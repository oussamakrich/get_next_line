/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:23:45 by okrich            #+#    #+#             */
/*   Updated: 2022/11/11 17:19:54 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <sys/fcntl.h>
#include <sys/syslimits.h>

static int	check_newline(char *reader)
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

static char	*get_resteofline(int n, char **rest, char *line)
{
	char	*tmp;

	line = ft_strndup(*rest, n);
	if (line == NULL)
		return (NULL);
	if (n < ft_strlen(*rest))
	{
		tmp = ft_strndup(*rest + n, -1);
		free(*rest);
		*rest = tmp;
	}
	else
	{
		free(*rest);
		*rest = NULL;
	}
	return (line);
}

static int	read_and_get_line(int fd, char **line, char **rest)
{
	char	*reader[OPEN_MAX];
	int		n;
	int		pos;

	reader[fd] = malloc(BUFFER_SIZE + 1);
	if (reader[fd] == NULL)
		return (0);
	n = 1;
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
	}
	return (free(reader[fd]), n);
}

char	*get_next_line_bonus(int fd)
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
	n = read_and_get_line(fd, &line, &rest);
	if (n == -1)
		return (free(line), NULL);
	return (line);
}
//
// void my_exit()
// {
// 	system("leaks a.out");
// }
//
// int main()
// {
// 	int fd =  open("txt1",O_RDONLY);
// 	int fd2 = open("txt2",O_RDONLY);
// 	char *str;
// 	char *str2;
// 	while((str = get_next_line_bonus(fd)) && (str2 = get_next_line_bonus(fd2)))
// 	{
// 		printf("%s",str2);
// 		printf("%s",str);
// 		free(str);
// 		free(str2);
// 	}
// 	atexit(my_exit);
// }
