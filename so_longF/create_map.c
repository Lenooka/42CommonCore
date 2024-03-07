/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:38:59 by otolmach          #+#    #+#             */
/*   Updated: 2024/02/25 22:02:07 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->map_str[y])
	{
		x = 0;
		while (data->map->map_str[y][x])
		{
			if (data->map->map_str[y][x] == 'P')
				put_image(data, data->img->player, x, y);
			if (data->map->map_str[y][x] == '1')
				put_image(data, data->img->walls, x, y);
			if (data->map->map_str[y][x] == '0')
				put_image(data, data->img->background, x, y);
			if (data->map->map_str[y][x] == 'E')
				put_image(data, data->img->e_obj, x, y);
			if (data->map->map_str[y][x] == 'E' && data->map->cake == 0)
				put_image(data, data->img->c_obj, x, y);
			if (data->map->map_str[y][x] == 'C')
				put_image(data, data->img->c_obj, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	put_image(t_data *d, void *img, int x, int y)
{
	int	r;

	r = mlx_put_image_to_window(d->mlx, d->win, img, (x * IMG_X), (y * IMG_Y));
	if (r == 1)
	{
		ft_exit(d, "image fail!");
	}
}

void	valid_path(t_data *data, int x, int y)
{
	if (x < 0 || x > data->size_x || y < 0
		|| y > data->size_y || data->map->map_copy[y][x] == '1'
		|| data->map->map_copy[y][x] == 'V')
		return ;
	data->map->map_copy[y][x] = 'V';
	valid_path(data, x - 1, y);
	valid_path(data, x, y - 1);
	valid_path(data, x, y + 1);
	valid_path(data, x + 1, y);
}
