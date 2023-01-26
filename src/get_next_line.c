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
    int             n;
    static  int     end_of_file;

    buff_str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buff_str)
        return(0);
    n = read(fd, buff_str, BUFFER_SIZE);
    buff_str[n] = 0;
//    printf("\nBUFFER:\n==\n%s\n==", buff_str);
  if (n < BUFFER_SIZE)
        end_of_file = 1;
//   printf("\nn=%d\nemd_of_file=%d", n, end_of_file);
     next_line = ft_line_to_print(buff_str, end_of_file);
   if (!next_line)
        next_line = get_next_line(fd);
//    free(buff_str);
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
//    printf("\nSAVED IS: \n%s\n", saved);
//    printf("\nTO_PARSE IS: \n%s\n", to_parse);
//    printf("\nEND FILE: %d\n", end_of_file);
    while (to_parse[index])
    {
        if (to_parse[index] == 10 && !is_nl)
        {            
            to_print = ft_strndup(to_parse, index + 1);
            index_last = index + 1;
            is_nl = 1;
        }
        index++;
    }
    if (is_nl == 1)
    {
        saved = ft_substr(to_parse, index_last, (index - index_last));
        return (to_print);
    }
    else if (is_nl == 0 && end_of_file == 1)
    {
        end_of_file = 2;
        return(to_parse);
    }
    else
    {
        saved = to_parse;
        return(NULL);
    }
}