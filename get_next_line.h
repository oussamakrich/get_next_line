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


char	*ft_strjoin(char *s1, char *s2);
char	*ft_strljoin(char *s1, char *s2, int i);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
