/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_size_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:59:51 by otolmach          #+#    #+#             */
/*   Updated: 2024/01/07 15:54:29 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_line_length(int fd)
{
	char	buffer[2];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}

int	ft_count_lines(int fd)
{
	int		linecount;
	char	buffer[2];
	int		bytes;

	buffer[0] = '\0';
	linecount = 2;
	while (1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes < 1)
			break ;
		if (buffer[0] == '\n')
			linecount++;
	}
	return (linecount);
}

void	check_path(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	map_copy(data);
	while (data->map->map_str[y])
	{
		x = 0;
		while (data->map->map_str[y][x] != '\0')
		{
			if (data->map->map_str[y][x] == 'P')
				check_sur_walls(data, y, x, 'P');
			if (data->map->map_str[y][x] == 'C')
				check_sur_walls(data, y, x, 'C');
			if (data->map->map_str[y][x] == 'E')
				check_sur_walls(data, y, x, 'E');
			x++;
		}
		y++;
	}
}

void	check_sur_walls(t_data *data, int y, int x, char c)
{
	char	*str;

	if ((data->map->map_str[y][x + 1] == '1'
		|| data->map->map_str[y][x + 1] == 'E')
		&& (data->map->map_str[y][x - 1] == '1'
		|| data->map->map_str[y][x - 1] == 'E')
		&& (data->map->map_str[y + 1][x] == '1'
		|| data->map->map_str[y + 1][x] == 'E')
		&& (data->map->map_str[y - 1][x] == '1'
		|| data->map->map_str[y - 1][x] == 'E'))
	{
		if (c == 'P')
			str = "Player surrounded by walls";
		if (c == 'C')
			str = "Collect surrounded by walls";
		if (c == 'E')
			str = "Exit surrounded by walls";
		ft_exit(data, str);
	}
}

void	map_copy(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	previos_ppos(data);
	valid_path(data, data->ppos_x, data->ppos_y);
	while (y < (data->size_y / IMG_Y))
	{
		x = 0;
		while (x < (data->size_x / IMG_X))
		{
			if (data->map->map_copy[y][x] == 'C' ||
				data->map->map_copy[y][x] == 'P' ||
				data->map->map_copy[y][x] == 'E')
				ft_exit(data, "Not valid path in the map!");
			x++;
		}
		y++;
	}
}
