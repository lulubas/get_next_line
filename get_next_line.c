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
	char			*to_print;
	int				n;
	static char		*to_parse;
	int				len;

	buff_str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff_str)
		return (NULL);
	n = read(fd, buff_str, BUFFER_SIZE);
	printf("\nn = %d\nto_parse = %s\nbuffer = %s\n", n, to_parse, buff_str);
	to_parse = ft_strjoin(to_parse, buff_str);
	free(buff_str);
	if (!ft_strchr(to_parse, '\n') && n)
	{
		printf("printf_in_loop: %s", to_parse);
		to_parse = get_next_line(fd);
	}
	if (!n)
		return(to_parse);
	len = ft_strchr(to_parse, 10) - to_parse;
	printf("\nlen = %d\n", len);	
	to_print = ft_strndup(to_parse, len + 1);
	to_parse = ft_strchr(to_parse, 10);
	return (to_print);
}

/*
int	ft_line_to_print(char *str)
{
	int				index;

	index = 0;
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
 	printf("\nn = %d\nbuffer = %s\n", n, buff_str);
*/