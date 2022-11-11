/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:19:58 by okrich            #+#    #+#             */
/*   Updated: 2022/11/11 20:21:26 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/_types/_ssize_t.h>
# include <sys/fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_strnjoin(char *s1, char *s2, ssize_t i);
char	*ft_strndup(char *s1, ssize_t n);
char	*get_next_line(int fd);
ssize_t	ft_strlen(char *str);

#endif
