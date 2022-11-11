/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:54:45 by okrich            #+#    #+#             */
/*   Updated: 2022/11/11 17:51:15 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/fcntl.h>
# include <sys/syslimits.h>

void	ft_free(char **ptr);
char	*ft_strnjoin(char *s1, char *s2, int i);
char	*ft_strdup(char *s1);
char	*ft_strndup(char *s1, int n);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
char	*get_next_line(int fd);

#endif
