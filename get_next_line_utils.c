/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:19:03 by lbastien          #+#    #+#             */
/*   Updated: 2023/01/27 17:53:22 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	a;

	if (!str)
		return (0);
	a = c;
	while (*str && *str != a)
		str++;
	if (*str != a)
		return (0);
	return ((char *)str);
}

char	*ft_strndup(const char *str, unsigned int len)
{
	size_t	n;
	char	*ctr;

	n = ft_strlen(str);
	if (len > n)
		len = n;
	ctr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ctr)
		return (0);
	ft_strlcpy(ctr, str, len + 1);
	return (ctr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	n;
	size_t	n1;
	size_t	n2;

	if (!s1)
		return (ft_strndup(s2, ft_strlen(s2)));
	if (!s2)
		return (ft_strndup(s1, ft_strlen(s1)));
	n1 = ft_strlen((char *)s1);
	n2 = ft_strlen((char *)s2);
	n = n1 + n2;
	str = (char *)malloc(sizeof(char) * n + 1);
	if (!str)
		return (NULL);
	ft_strlcat(str, s1, n1 + 1);
	ft_strlcat(str, s2, n + 1);
	return (str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	srcl;
	size_t	dstl;

	i = 0;
	srcl = ft_strlen(src);
	dstl = ft_strlen(dst);
	if (n <= dstl)
		return (srcl + n);
	while (src[i] && (dstl + i) < n - 1)
	{
		dst[dstl + i] = src[i];
		i++;
	}
	dst[dstl + i] = 0;
	return (srcl + dstl);
}
