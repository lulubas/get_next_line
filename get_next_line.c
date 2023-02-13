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
	size_t			len;
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
		if (len == ft_strlen(to_parse))
			to_parse = NULL;
		else
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
		buff_str[BUFFER_SIZE] = '\0';
		n = read(fd, buff_str, BUFFER_SIZE);
		if (n == 0)
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
	}
	return (to_parse);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	n1;
	size_t	n2;

	if (!s1 && s2)
		str = ft_strndup(s2, ft_strlen(s2));
	else if (!s2 && s1)
		str = ft_strndup(s1, ft_strlen(s1));
	else if (!s1 && !s2)
		return (NULL);
	else
	{
		n1 = ft_strlen((char *)s1);
		n2 = ft_strlen((char *)s2);
		str = (char *)malloc(sizeof(char) * (n1 + n2) + 1);
		if (!str)
			return (NULL);
		ft_strlcpy(str, s1, n1 + 1);
		ft_strlcat(str, s2, n1 + n2 + 1);
		free(s1);
		free(s2);
	}
	return (str);
}
