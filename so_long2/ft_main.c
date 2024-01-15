/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:55:05 by otolmach          #+#    #+#             */
/*   Updated: 2024/01/07 14:38:37 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	if (argc != 2)
		exit(0);
	win_size(&data, argv);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		ft_exit(&data, "MLX init Error");
	init_imgs(&data, &map);
	map.map_str = ft_calloc(data.size_y + 1, sizeof(char *));
	if (map.map_str == NULL)
		ft_exit(&data, "Map string Allocation Fail");
	map.map_copy = ft_calloc(data.size_y + 1, sizeof(char *));
	if (map.map_copy == NULL)
		printf("Map string Allocation Fail");
	convert_ber(&data, argv);
	start_game(&data);
	free(data.mlx);
	exit (0);
}
