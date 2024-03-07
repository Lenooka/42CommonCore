/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:54:26 by otolmach          #+#    #+#             */
/*   Updated: 2024/01/07 13:54:27 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_esc(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		ft_free_noerror(data, "You gave up!");
		exit(0);
	}
	return (0);
}

int	close_mouse(t_data *data)
{
	ft_free_noerror(data, "You gave up!");
	exit(0);
	return (0);
}
