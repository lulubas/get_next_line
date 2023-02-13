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
	if (!str)
		return (0);
	while (str[i] != '\0')
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

char	*ft_strndup(char *str, size_t len)
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
	free (str);
	return (ctr);
}

size_t	ft_strlcat(char *dst, char *src, size_t n)
{
	size_t	i;
	size_t	srcl;
	size_t	dstl;

	if (!src)
		return (0);
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
	dst[dstl + i] = '\0';
	return (srcl + dstl);
}

size_t	ft_strlcpy(char *dst, char *src, size_t n)
{
	size_t	i;
	int		j;

	if (!src)
		return (0);
	i = 0;
	j = ft_strlen(src);
	if (n == 0)
		return (j);
	while (src[i] && i < n - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
