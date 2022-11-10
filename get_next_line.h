/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:19:58 by okrich            #+#    #+#             */
/*   Updated: 2022/11/09 15:52:56 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>
#ifndef BUFFER_SIZE

#define BUFFER_SIZE 1

#endif
#include <sys/fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void	ft_free(char **ptr);
char	*ft_strnjoin(char *s1, char *s2, int i);
char	*ft_strdup(char *s1);
char	*ft_strndup(char *s1, int n);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);

#endif

