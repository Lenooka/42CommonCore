/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:47:58 by otolmach          #+#    #+#             */
/*   Updated: 2024/01/07 14:46:08 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_data *data)
{
	data->img->player = data->img->p_down;
	mlx_get_screen_size(data->mlx, &data->screen_x, &data->screen_y);
	if (data->size_x > data->screen_x || data->size_y > data->screen_y)
	{
		ft_exit(data, "Map is too big!");
	}
	data->win = mlx_new_window(data->mlx,
			data->size_x, data->size_y, "so_long");
	if (data->win == NULL)
		ft_exit(data, "Window fail");
	mlx_hook(data->win, 2, (1L << 0), hook_keyboard, data);
	mlx_hook(data->win, 17, 0, close_mouse, data);
	mlx_loop_hook(data->mlx, &put_map, data);
	mlx_loop(data->mlx);
	mlx_do_sync(data->mlx);
}
