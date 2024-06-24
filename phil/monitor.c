/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:56:40 by otolmach          #+#    #+#             */
/*   Updated: 2024/06/22 19:25:15 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

u_int64_t	last_meal_time(t_philo *philo)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->last_meal);
	time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->last_meal);
	return (time);
}

void	forcee_exit(t_data *data)
{
	pthread_mutex_lock(&data->death_chek);
	data->death = 1;
	pthread_mutex_unlock(&data->death_chek);
}

void	force_exit(t_data *data)
{
	pthread_mutex_lock(&data->death_chek);
	data->death = 1;
	pthread_mutex_unlock(&data->death_chek);
}

void	*monitor(void *dat)
{
	t_data	*data;
	int		i;

	data = (t_data *)dat;
	if (are_we_done(data) == 1)
	{
		while (dead_check(data) != 1)
		{
			i = 0;
			while (i < data->num_of_philo)
			{
				if (get_current_time(last_meal_time(&data->philo[i]))
					> (u_int64_t)data->time_to_die)
				{
					return (print_messege(&data->philo[i], "died"),
						forcee_exit(data), NULL);
				}
				i++;
			}
			usleep(1000);
		}
	}
	return (NULL);
}

void	*meals_monitor(void *dat)
{
	t_data	*data;
	int		i;

	data = (t_data *)dat;
	if (are_we_done(data) == 1)
	{
		while (dead_check(data) != 1)
		{
			i = 0;
			while (i < data->num_of_philo)
			{
				if (eat_count(&data->philo[i]) < data->num_of_meals)
					break ;
				i++;
			}
			if (i == data->num_of_philo)
			{
				return (force_exit(data), NULL);
			}
			usleep(1000);
		}
	}
	return (NULL);
}
