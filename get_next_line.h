/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:16:17 by lbastien          #+#    #+#             */
/*   Updated: 2023/01/24 14:16:19 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_get_buf(int fd, char *to_parse);
char	*ft_to_save(char *str);
char	*ft_get_print(char *str);
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);

#endif