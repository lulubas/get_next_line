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
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (src[j] != 0)
		j++;
	if (n == 0)
		return (j);
	while (*src && i < n - 1)
	{
		*dst = *src;
		i++;
		dst++;
		src++;
	}
	*dst = 0;
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	n;
	size_t	n1;
	size_t	n2;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	n1 = ft_strlen((char *)s1);
	n2 = ft_strlen((char *)s2);
	n = n1 + n2;
	str = (char *)malloc(sizeof(char) * n + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, n1 + 1);
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
