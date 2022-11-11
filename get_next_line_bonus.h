/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:54:45 by okrich            #+#    #+#             */
/*   Updated: 2022/11/11 20:17:53 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/fcntl.h>
# include <stddef.h>
# include <sys/_types/_ssize_t.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/fcntl.h>
# include <sys/syslimits.h>
# include <limits.h>

char	*ft_strnjoin(char *s1, char *s2, ssize_t i);
char	*ft_strndup(char *s1, ssize_t n);
char	*get_next_line(int fd);
ssize_t	ft_strlen(char *str);

#endif
