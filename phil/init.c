/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:54:31 by otolmach          #+#    #+#             */
/*   Updated: 2024/06/22 19:25:35 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_input_numbers(t_data *data, char **s)
{
	data->num_of_philo = ft_atoi(s[1]);
	if (data->num_of_philo < 1)
		return (error_arguments(s[1], "There is no life without philosophers"));
	data->time_to_die = ft_atoi(s[2]);
	if (data->time_to_die < 0)
		return (error_arguments(s[2],
				"We all eventually die, even philosophers!\n"));
	data->time_to_eat = ft_atoi(s[3]);
	if (data->time_to_eat < 0)
		return (error_arguments(s[3], "Philosophers need time to eat too"));
	data->time_to_sleep = ft_atoi(s[4]);
	if (data->time_to_sleep < 0)
		return (error_arguments(s[4], "Philosophers need to sleep too!\n"));
	if (s[5])
		data->num_of_meals = ft_atoi(s[5]);
	else
		data->num_of_meals = -1;
	if (data->num_of_meals == 0)
		return (error_arguments(s[5],
				"Philosophers need to eat at least once"));
	return (0);
}

int	init_struct(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->num_of_philo);
	if (!data->philo)
		return (malloc_error("philo struct"));
	data->thread = malloc(sizeof(pthread_t) * data->num_of_philo);
	if (!data->thread)
	{
		free(data->philo);
		return (malloc_error("thread struct"));
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	if (!data->forks)
	{
		free(data->philo);
		free(data->thread);
		return (malloc_error("forks struct"));
	}
	data->death = 0;
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			free_forks(data, i);
			return (1);
		}
		i++;
	}
	return (0);
}

void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	if (init_mutex(data) == 1)
	{
		freeing(data);
		return ;
	}
	data->start_time = get_current_time(0);
	while (i < data->num_of_philo)
	{
		philo[i].index = i + 1;
		philo[i].data = data;
		philo[i].eaten_meals = 0;
		philo[i].left_f = &data->forks[i];
		philo[i].right_f
			= &data->forks[(i + 1) % data->num_of_philo];
		if (mutex_init_in(philo, i) == 1)
		{
			freeing(data);
			return ;
		}
		i++;
	}
}

int	start_threads(t_data *data)
{
	int	i;

	i = 0;
	start_time_init(data);
	data->done = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_create(&data->thread[i], NULL,
				&philo_life, (void *)&data->philo[i]))
		{
			return (1);
		}
		i++;
	}
	we_done(data);
	if (pthread_create(&data->thread_death, NULL, &monitor, (void *)data)
		|| (data->num_of_meals > 0 && data->num_of_philo > 1
			&& pthread_create(&data->thread_meals, NULL,
				&meals_monitor, (void *)data)))
	{
		return (1);
	}
	join_threads(data);
	return (0);
}
