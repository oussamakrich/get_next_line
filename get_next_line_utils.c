/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:13:04 by okrich            #+#    #+#             */
/*   Updated: 2022/11/11 20:29:45 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/_types/_ssize_t.h>

ssize_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dst, char *src, ssize_t dstsize)
{
	ssize_t	j;
	ssize_t	i;

	i = ft_strlen(src);
	if (dstsize == 0)
		return (dst);
	j = 0;
	while (dstsize-- && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_strnjoin(char *s1, char *s2, ssize_t i)
{
	char	*join;
	ssize_t	len;

	len = ft_strlen(s1);
	join = malloc(sizeof(char) * (len + i + 1));
	if (join == NULL)
		return (NULL);
	ft_strncpy(join, s1, len);
	ft_strncpy(join + len, s2, i);
	free (s1);
	return (join);
}

char	*ft_strndup(char *s1, ssize_t n)
{
	int		len;
	char	*dst;

	len = ft_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	if (n == -1)
		n = len;
	ft_strncpy(dst, s1, n);
	return (dst);
}
