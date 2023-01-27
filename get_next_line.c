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
	char			*buff_str;
	char			*next_line;
	int				n;
	static int		end_of_read;

	buff_str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff_str)
		return (0);
	n = read(fd, buff_str, BUFFER_SIZE);
	buff_str[n] = 0;
	if (n < BUFFER_SIZE)
		end_of_read = 1;
	next_line = ft_line_to_print(buff_str, end_of_read);
	if (!next_line && !end_of_read)
		next_line = get_next_line(fd);
	return (next_line);
}

char	*ft_line_to_print(char *buff_str, int end_of_read)
{
	int				index;
	static int		end_of_print;
	char			*to_print;
	static char		*to_parse;

	index = 0;
	to_parse = ft_strjoin(to_parse, buff_str);
	while (to_parse[index])
	{
		if (to_parse[index] == 10)
		{
			to_print = ft_strndup(to_parse, index + 1);
			to_parse += index + 1;
			return (to_print);
		}
		index++;
	}
	if (end_of_read && !end_of_print)
	{
		end_of_print = 1;
		return (to_parse);
	}
	return (NULL);
}
