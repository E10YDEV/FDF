/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:41:24 by eloymart          #+#    #+#             */
/*   Updated: 2024/10/26 13:35:39 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include "../libft/libft.h"

char	*get_line(char *memory_buffer);
char	*read_and_fill(int fd, char *memory_buffer);
char	*clean_buffer(char *memory_buffer, int len);
char	*get_next_line(int fd);
char	*ft_strjoin_free(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t count, size_t size);

#endif