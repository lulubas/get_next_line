/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:19:45 by lbastien          #+#    #+#             */
/*   Updated: 2023/01/24 13:19:49 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/get_next_line.h"

char *get_next_line(int fd)
{
    char            *buff_str;
    char            *next_line;
    size_t          buffer_size;
    size_t          n;
    static  int     end_of_file;

    buffer_size = 10;
    buff_str = (char *)malloc(sizeof(char) * (buffer_size) + 1);
    if (!buff_str)
        return(0);
    buff_str[buffer_size] = 0;
    n = read(fd, buff_str, (buffer_size));
    printf("\nBUFFER:\n==\n%s\n==", buff_str);
    if (n < buffer_size)
        end_of_file = 1;
    next_line = ft_line_to_print(buff_str, end_of_file);
    if (!next_line)
        next_line = get_next_line(fd);
    free(buff_str);
    return (next_line);
}

char    *ft_line_to_print(char *buff_str, int end_of_file)
{
    int             index;
    int             index_last;
    char            *to_print;
    char            *to_parse;
    static char     *saved;
    int             is_nl;

    is_nl = 0;
    index = 0;
    index_last = 0;
    to_parse = ft_strjoin(saved, buff_str);
    free(saved);
    while (to_parse[index])
    {
        if (buff_str[index] == 10 && !is_nl)
        {            
            to_print = ft_strndup(buff_str, index + 1);
            index_last = index;
            is_nl = 1;
        }
        index++;
    }
    free(to_parse);
    if (is_nl)
    {
        saved = ft_substr(to_parse, index_last, (index - index_last + 1));
        return (to_print);
    }
    else if (!is_nl && end_of_file)
        return(to_parse);
    else
        return(NULL); 
}
/*
char    *ft_line_to_print(char *buff_str, int end_of_file)
{
    static int  index;
    static int  index_last;
    char        *to_print;
    int         is_nl;

    is_nl = 0;
    while (buff_str[index])
    {
        if (buff_str[index] == 10)
        {
            to_print = ft_substr(buff_str, index_last, (index - index_last + 1));
            index_last = index;
            is_nl = 1; 
        }
        index++;
    }
    if (is_nl)
        return (to_print);
    else if (!is_nl && end_of_file)
    {
        to_print = ft_substr(buff_str, index_last, (index - index_last + 1));
        return(to_print);
    }
    else
        return(NULL); 
}
*/