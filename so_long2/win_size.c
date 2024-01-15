/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:57:13 by otolmach          #+#    #+#             */
/*   Updated: 2024/01/07 14:46:49 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_size(t_data *data, char **argv)
{
	int	fd;

	data->map = NULL;
	data->img = NULL;
	data->win = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_exit(data, "Invalid Path!");
	}
	if (ft_strnstr(argv[1], ".ber", ft_sostrlen(argv[1])) == NULL)
	{
		ft_exit(data, "Extension should be .ber!");
	}
	data->size_x = (ft_line_length(fd) * IMG_X);
	data->size_y = (ft_count_lines(fd) * IMG_Y);
	close(fd);
}

void	put_background(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < d->size_y)
	{
		x = 0;
		while (x < d->size_x)
		{
			mlx_put_image_to_window(d->mlx, d->win, d->img->background, x, y);
			x = x + IMG_X;
		}
		y = y + IMG_Y;
	}
}
