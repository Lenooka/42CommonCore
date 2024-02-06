/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:49:46 by otolmach          #+#    #+#             */
/*   Updated: 2024/02/06 15:31:30 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_str(t_data *data)
{
	int	i;

	i = 0;
	if (data->map->map_str != NULL)
	{
		while (data->map->map_str[i] != NULL)
		{
			free(data->map->map_str[i]);
			i++;
		}
		free(data->map->map_str);
	}
	i = 0;
	if (data->map->map_copy != NULL)
	{
		while (data->map->map_copy[i])
		{
			free(data->map->map_copy[i]);
			i++;
		}
		free(data->map->map_copy);
	}
	return ;
}

void	img_free_destroy(t_data *data)
{
	if (data->img->background != NULL)
		mlx_destroy_image(data->mlx, data->img->background);
	if (data->img->c_obj != NULL)
		mlx_destroy_image(data->mlx, data->img->c_obj);
	if (data->img->e_obj != NULL)
		mlx_destroy_image(data->mlx, data->img->e_obj);
	if (data->img->p_down != NULL)
		mlx_destroy_image(data->mlx, data->img->p_down);
	if (data->img->p_up != NULL)
		mlx_destroy_image(data->mlx, data->img->p_up);
	if (data->img->p_right != NULL)
		mlx_destroy_image(data->mlx, data->img->p_right);
	if (data->img->p_left != NULL)
		mlx_destroy_image(data->mlx, data->img->p_left);
	if (data->img->walls != NULL)
		mlx_destroy_image(data->mlx, data->img->walls);
	free(data->img);
	return ;
}

void	free_img_list(t_data *data)
{
	if (data->img != NULL)
		free(data->img);
	return ;
}

void	ft_exit(t_data *data, char *str)
{
	if (data->map != NULL)
		free_map_str(data);
	if (data->img != NULL)
		img_free_destroy(data);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(0);
}

void	ft_free_noerror(t_data *data, char *str)
{
	if (data->map != NULL)
		free_map_str(data);
	if (data->img != NULL)
		img_free_destroy(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->mlx != NULL)
		free(data->mlx);
	ft_printf("%s", str);
	exit (0);
	return ;
}
