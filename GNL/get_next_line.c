/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:42:24 by eloymart          #+#    #+#             */
/*   Updated: 2024/10/26 13:37:06 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *memory_buffer)
{
	char	*line;
	int		len;
	char	*newline_pos;
	int		i;

	if (!memory_buffer || *memory_buffer == '\0')
		return (NULL);
	newline_pos = ft_strchr(memory_buffer, '\n');
	if (newline_pos)
		len = newline_pos - memory_buffer + 1;
	else
		len = ft_strlen(memory_buffer);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = memory_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	size_t	i;
	char	*ptr;

	total_size = count * size;
	if (count != 0 && total_size / count != size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

char	*read_until_enter(int fd, char *save)
{
	int		n_of_chars;
	char	*tmp;

	if (!save)
		save = ft_calloc(1, 1);
	tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	n_of_chars = 1;
	while (n_of_chars > 0)
	{
		n_of_chars = read(fd, tmp, BUFFER_SIZE);
		if (n_of_chars == -1)
		{
			free(tmp);
			free(save);
			return (NULL);
		}
		tmp[n_of_chars] = '\0';
		save = ft_strjoin_free(save, tmp);
		if (ft_strchr(save, '\n'))
			break ;
	}
	free(tmp);
	return (save);
}

char	*clean_buffer(char *memory_buffer, int len)
{
	char	*new_buffer;
	int		buffer_len;

	buffer_len = ft_strlen(memory_buffer);
	if (len >= buffer_len)
	{
		free(memory_buffer);
		return (NULL);
	}
	new_buffer = ft_substr(memory_buffer, len, buffer_len - len);
	if (!new_buffer)
		return (NULL);
	free(memory_buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*memory_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memory_buffer = read_until_enter(fd, memory_buffer);
	if (!memory_buffer)
		return (NULL);
	line = get_line(memory_buffer);
	if (!line)
	{
		free(memory_buffer);
		memory_buffer = NULL;
		return (NULL);
	}
	memory_buffer = clean_buffer(memory_buffer, ft_strlen(line));
	return (line);
}
