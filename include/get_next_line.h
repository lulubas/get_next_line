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

#ifndef GET_NEXT_LNE_H
# define GET_NEXT_LNE_H

# include<unistd.h>
# include<stdlib.h>
# include <fcntl.h>
#include <stdio.h>

char    *get_next_line(int fd);
char    *ft_line_to_print(char *buff_str, int end_of_file);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strndup(const char *str, unsigned int len);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif