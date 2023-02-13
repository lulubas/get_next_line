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
	char			*to_print;
	static char		*to_parse;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	to_parse = ft_get_buf(fd, to_parse);
	if (!to_parse)
		return (NULL);
	to_print = ft_get_print(to_parse);
	to_parse = ft_to_save(to_parse);
	return (to_print);
}

char	*ft_get_buf(int fd, char *to_parse)
{
	char	*buff_str;
	int		n;

	n = 1;
	buff_str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff_str)
		return (NULL);
	while (!ft_strchr(to_parse, '\n'))
	{
		n = read(fd, buff_str, BUFFER_SIZE);
		if (n == -1)
		{
			free (buff_str);
			free (to_parse);
			return (0);
		}
		else if (n == 0)
			break ;
		buff_str[n] = '\0';
		to_parse = ft_strjoin(to_parse, buff_str);
	}
	free(buff_str);
	return (to_parse);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 && s2)
		s1 = ft_strdup("");
	else if (!s1 && !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen (s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_get_print(char *str)
{
	char	*line;
	int		len;

	if (!*str)
		return (0);
	if (ft_strchr(str, '\n'))
		len = ft_strchr(str, 10) - str + 1;
	else
		len = ft_strlen(str);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	ft_strlcpy(line, str, len + 1);
	return (line);
}

char	*ft_to_save(char *str)
{	
	char	*to_save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!ft_strchr(str, '\n'))
	{
		free(str);
		return (NULL);
	}
	while (str[i] != '\n')
		i++;
	to_save = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!to_save)
		return (NULL);
	while (str[++i])
		to_save[j++] = str[i];
	to_save[j] = '\0';
	free(str);
	return (to_save);
}
