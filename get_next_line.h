/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:13:26 by vess              #+#    #+#             */
/*   Updated: 2022/03/14 14:22:10 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

size_t ft_strlen(char *str);
char *ft_strchr(char *str, int c);
char *ft_strjoin(char *s1, char *s2);
char *ft_get_line(char *save);
char *ft_save(char *save);
char *ft_read_save(int fd, char *save);
char *get_next_line(int fd);


#endif
