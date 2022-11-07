#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	int		j;
	size_t	i;

	i = ft_strlen(src);
	if (dstsize == 0)
		return (i);
	j = 0;
	while (--dstsize && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	ret;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (dstsize + ft_strlen(src));
	ret = dstlen + ft_strlen(src);
	ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*join;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = malloc(sizeof(char) * len);
	if (join == NULL)
		return (NULL);
	ft_strlcpy(join, s1, (ft_strlen(s1) + 1));
	ft_strlcat(join, s2, len);
	free(s1);
	return (join);
}

char	*ft_strljoin(char *s1, char *s2, int i)
{
	char	*join;
	size_t	len;

	len = ft_strlen(s1);
	join = malloc(sizeof(char) * (len + i + 1));
	if (join == NULL)
		return (NULL);
	ft_strlcpy(join, s1, (len + 1));
	ft_strlcat(join, s2,(len + i + 1));
	free (s1);
	return (join);
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(s1);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, len + 1);
	return (dst);
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*tmp;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s) - start;
	tmp = (char *)s + start;
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, tmp, len + 1);
	return (sub);
}
