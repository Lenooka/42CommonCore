/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:32:13 by otolmach          #+#    #+#             */
/*   Updated: 2024/01/07 13:57:08 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	previos_ppos(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map->map_str[y] != NULL)
	{
		x = 0;
		while (data->map->map_str[y][x] != '\0')
		{
			if (data->map->map_str[y][x] == 'P')
			{
				data->ppos_y = y;
				data->ppos_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_move(t_data *data, int y, int x)
{
	int	new_x;
	int	new_y;
	int	walkex;
	int	cur_pos;

	previos_ppos(data);
	new_x = data->ppos_x + x;
	new_y = data->ppos_y + y;
	walkex = 0;
	cur_pos = data->map->map_str[new_y][new_x];
	if (cur_pos == '0' || cur_pos == 'C' )
	{
		data->map->map_str[new_y][new_x] = 'P';
		data->map->map_str[data->ppos_y][data->ppos_x] = '0';
		data->ppos_x = new_x;
		data->ppos_y = new_x;
		if (cur_pos == 'C')
			data->map->cake--;
		data->move_count++;
		printf("Move count : %d\n", data->move_count);
	}
	if (cur_pos == 'E' && data->map->cake == 0)
		ft_free_noerror(data, "You won!");
}

int	hook_keyboard(int keycode, t_data *data)
{
	close_esc(keycode, data);
	if (keycode == XK_a)
	{
		data->img->player = data->img->p_up;
		ft_move(data, 0, -1);
	}
	if (keycode == XK_d)
	{
		data->img->player = data->img->p_down;
		ft_move(data, 0, +1);
	}
	if (keycode == XK_s)
	{
		data->img->player = data->img->p_right;
		ft_move(data, +1, 0);
	}
	if (keycode == XK_w)
	{
		data->img->player = data->img->p_left;
		ft_move(data, -1, 0);
	}
	return (0);
}
