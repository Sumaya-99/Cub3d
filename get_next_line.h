/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:41:43 by suhelal           #+#    #+#             */
/*   Updated: 2024/02/26 10:12:44 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);

void	ft_bzero(void *s, size_t n);

size_t	ft_strlen(const char *str);

void	ft_bzero(void *s, size_t n);

char	*ft_strdup(const char *s1);

char	*ft_strchr(const char *s, int c);

char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif