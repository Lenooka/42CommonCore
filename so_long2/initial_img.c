/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:57:27 by otolmach          #+#    #+#             */
/*   Updated: 2024/01/07 13:57:39 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs(t_data *data, t_map *map)
{
	t_img	*img;

	data->map = map;
	img = malloc(sizeof(t_img));
	if (!img)
	{
		ft_exit(data, "Img List Alloc Fail");
	}
	data->img = img;
	img->background = init_img_check(data, PATH_B, img->background);
	img->c_obj = init_img_check(data, PATH_C, img->c_obj);
	img->e_obj = init_img_check(data, PATH_E, img->e_obj);
	img->p_down = init_img_check(data, PATH_PD, img->p_down);
	img->p_up = init_img_check(data, PATH_PU, img->p_up);
	img->p_right = init_img_check(data, PATH_PR, img->p_right);
	img->p_left = init_img_check(data, PATH_PL, img->p_left);
	img->walls = init_img_check(data, PATH_W, img->walls);
	data->move_count = 0;
	data->collect = 0;
}

void	*init_img_check(t_data *data, char *path, void *img)
{
	int		ih;
	int		iw;

	img = mlx_xpm_file_to_image(data->mlx, path, &iw, &ih);
	if (!img)
	{
		ft_exit(data, "Failed to acsess xpm file!");
	}
	return (img);
}
