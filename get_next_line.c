/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:19:45 by lbastien          #+#    #+#             */
/*   Updated: 2023/01/27 17:53:08 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int				len;
	char			*to_print;
	static char		*to_parse;
	static int		end_of_print;

	if (end_of_print || fd < 1 || BUFFER_SIZE < 1)
		return (NULL);
	to_parse = ft_get_buf(fd, to_parse);
	if (ft_strchr(to_parse, '\n'))
	{
		len = ft_strchr(to_parse, 10) - to_parse + 1;
		to_print = ft_strndup(to_parse, len);
		to_parse += len;
		return (to_print);
	}
	else
		end_of_print = 1;
	return (to_parse);
}

char	*ft_get_buf(int fd, char *to_parse)
{
	char	*buff_str;
	int		n;

	while (!ft_strchr(to_parse, '\n'))
	{
		buff_str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff_str)
			return (NULL);
		n = read(fd, buff_str, BUFFER_SIZE);
		if (!n)
		{	
			free(buff_str);
			break ;
		}
		else if (n == -1)
		{
			free (buff_str);
			return (NULL);
		}
		to_parse = ft_strjoin(to_parse, buff_str);
		free (buff_str);
	}
	return (to_parse);
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
