/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:14:45 by otolmach          #+#    #+#             */
/*   Updated: 2024/01/07 15:58:06 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_occur(char *str, char c)
{
	int	indx;
	int	count;

	indx = 0;
	count = 0;
	if (!str)
	{
		return (-1);
	}
	while (str[indx] != '\0')
	{
		if (str[indx] == c)
			count++;
		indx++;
	}
	return (count);
}

void	check_borders(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < (d->size_y / IMG_Y))
	{
		x = 0;
		if (ft_sostrlen(d->map->map_str[y]) != d->size_x / IMG_X)
			ft_exit(d, "Map is not rectangular");
		while (x < (d->size_x / IMG_X))
		{
			if (d->map->map_str[y][x] != '0'
				&& d->map->map_str[y][x] != '1'
				&& d->map->map_str[y][x] != 'C' && d->map->map_str[y][x] != 'P'
				&& d->map->map_str[y][x] != 'E')
				ft_exit(d, "Invalid map!");
			if ((y == 0 || x == 0) && d->map->map_str[y][x] != '1')
				ft_exit(d, "Map is not surronded by walls");
			if ((y == (d->size_y / IMG_Y - 1) || x == (d->size_x / IMG_X - 1))
				&& d->map->map_str[y][x] != '1')
				ft_exit(d, "Map is not surronded by walls!");
			x++;
		}
		y++;
	}
}

void	check_epc(t_data *data)
{
	int	player;
	int	y;
	int	exit;

	y = 0;
	exit = 0;
	player = 0;
	data->map->cake = 0;
	while (data->map->map_str[y] != NULL)
	{
		player += count_occur(data->map->map_str[y], 'P');
		exit += count_occur(data->map->map_str[y], 'E');
		data->map->cake += count_occur(data->map->map_str[y], 'C');
		y++;
	}
	if (player != 1)
		ft_exit(data, "There should be 1 Player on the map!");
	if (exit != 1)
		ft_exit(data, "There should be 1 Exit on the map!");
	if (data->map->cake == 0)
		ft_exit(data, "There should be  at least 1 collectable!");
	check_borders(data);
}

void	convert_ber(t_data *d, char **argv)
{
	int		fd;
	int		i;
	int		bytes;
	char	buffer[2];

	i = 0;
	bytes = 1;
	buffer[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
		{
			d->map->map_str[i] = ft_sostrjoin(d->map->map_str[i], buffer);
			d->map->map_copy[i] = ft_sostrjoin(d->map->map_copy[i], buffer);
		}
		else
			i++;
	}
	close(fd);
	check_epc(d);
	check_path(d);
}
