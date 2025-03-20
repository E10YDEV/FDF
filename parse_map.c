/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:35:40 by eloymart          #+#    #+#             */
/*   Updated: 2025/01/08 20:55:52 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	parse_cell(t_punto *cell, char *value, int x, int y)
{
	char	**split_value;
	int		i;

	split_value = ft_split(value, ',');
	cell->x = x;
	cell->y = y;
	cell->z = ft_atoi(split_value[0]);
	if (split_value[1])
		cell->color = normalize_rgb_to_rgba(ft_atoi_base(split_value[1] + 2,
					16));
	else
		cell->color = 0xFFFFFFFF;
	i = 0;
	while (split_value[i])
	{
		free(split_value[i]);
		i++;
	}
	free(split_value);
}

static t_punto	*parse_row(char *line, int cols, int y)
{
	char	**values;
	t_punto	*row;
	int		x;

	values = ft_split(line, ' ');
	row = allocate_row(cols);
	x = 0;
	while (x < cols)
	{
		parse_cell(&row[x], values[x], x, y);
		free(values[x]);
		x++;
	}
	free(values);
	return (row);
}

static t_punto	**allocate_map(int rows)
{
	t_punto	**map;

	map = malloc(sizeof(t_punto *) * rows);
	if (!map)
	{
		perror("Error allocating map");
		exit(1);
	}
	return (map);
}

static int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	return (fd);
}

t_punto	**parse_map(char *file, int rows, int cols)
{
	int		fd;
	t_punto	**map;
	int		y;
	char	*line;

	fd = open_file(file);
	map = allocate_map(rows);
	y = 0;
	line = get_next_line(fd);
	while (line && y < rows)
	{
		map[y] = parse_row(line, cols, y);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
