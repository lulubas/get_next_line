/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:01:25 by lbastien          #+#    #+#             */
/*   Updated: 2023/01/24 16:01:46 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/get_next_line.h"

int main(void)
{
    int         lines;
    int         fd;
    int         i;
    const char  *path;
    char        *read;

    lines = 6;
    path = "test_file.txt";
    fd = open(path, O_RDONLY);
    for (i = 0; i < lines; i++)
    {
       read = get_next_line(fd);
       printf("%s", read);
    }
}