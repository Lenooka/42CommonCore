/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:54:05 by olena             #+#    #+#             */
/*   Updated: 2024/06/17 19:06:20 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data			data;

	if (argument_check(argc, argv) == 1 || check_atoi(argv) == 1)
		return (0);
	if (set_input_numbers(&data, argv) == 1)
		return (0);
	if (init_struct(&data) == 1)
		return (0);
	init_philo(&data, data.philo);
	if (start_threads(&data) == 1)
	{
		printf("Creating threads failed!\n");
		clean_free(&data);
		return (0);
	}
	clean_free(&data);
	return (0);
}
