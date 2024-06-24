/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:33:39 by otolmach          #+#    #+#             */
/*   Updated: 2024/06/22 18:39:36 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleaning_mutex(t_data *data, int i)
{
	if (i >= 1)
		pthread_mutex_destroy(&data->print);
	if (i >= 2)
		pthread_mutex_destroy(&data->death_chek);
	if (i >= 3)
		pthread_mutex_destroy(&data->destroy_mutex);
}

void	free_forks(t_data *data, int i)
{
	while (--i >= 0)
		pthread_mutex_destroy(&data->forks[i]);
}

void	we_done(t_data *data)
{
	pthread_mutex_lock(&data->destroy_mutex);
	data->done = 0;
	pthread_mutex_unlock(&data->destroy_mutex);
}

int	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->print, NULL) != 0)
	{
		cleaning_mutex(data, 1);
		return (1);
	}
	if (pthread_mutex_init(&data->death_chek, NULL) != 0)
	{
		cleaning_mutex(data, 2);
		return (1);
	}
	if (pthread_mutex_init(&data->destroy_mutex, NULL) != 0)
	{
		cleaning_mutex(data, 3);
		return (1);
	}
	if (init_forks(data) == 1)
	{
		cleaning_mutex(data, 3);
		return (1);
	}
	return (0);
}

int	mutex_init_in(t_philo *philo, int i)
{
	if (pthread_mutex_init(&philo[i].eat_count, NULL) != 0)
	{
		free_back(philo, i, 1);
		cleaning_mutex(philo->data, 3);
		return (1);
	}
	if (pthread_mutex_init(&philo[i].last_meal, NULL) != 0)
	{
		free_back(philo, i, 2);
		cleaning_mutex(philo->data, 3);
		return (1);
	}
	return (0);
}
