/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:48:15 by eloymart          #+#    #+#             */
/*   Updated: 2025/01/12 13:44:07 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_columns(char *line)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = line;
	while (*ptr)
	{
		if ((*ptr != ' ' && (*ptr == '\n' || *(ptr + 1) == ' ' || *(ptr
						+ 1) == '\0')))
			count++;
		ptr++;
	}
	return (count);
}

void	get_map_size(char *file, int *rows, int *cols)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	*rows = 0;
	*cols = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (*rows == 0)
			*cols = count_columns(line);
		(*rows)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	normalize_rgb_to_rgba(int color)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	if (color & 0xFF0000)
		r = (color >> 16) & 0xFF;
	if (color & 0xFF00)
		g = (color >> 8) & 0xFF;
	if (color & 0xFF)
		b = color & 0xFF;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

t_punto	*allocate_row(int cols)
{
	t_punto	*row;

	row = malloc(sizeof(t_punto) * cols);
	if (!row)
	{
		perror("Error allocating row");
		exit(1);
	}
	return (row);
}
