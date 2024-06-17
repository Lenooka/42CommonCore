/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:52:44 by otolmach          #+#    #+#             */
/*   Updated: 2024/06/17 18:50:17 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_arguments(char *s, char *mess)
{
	printf("Invalid argument [%s]!", s);
	printf("%s!\n", mess);
	return (1);
}

int	malloc_error(char *mes)
{
	printf("Allocation of %s error!\n", mes);
	return (1);
}

void	clean_free(t_data *data)
{
	int	i;

	i = 0;
	pthread_join(data->thread_death, NULL);
	if (data->num_of_meals > 0 && data->num_of_philo > 1)
		pthread_join(data->thread_meals, NULL);
	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philo[i].eat_count);
		pthread_mutex_destroy(&data->philo[i].last_meal);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death_chek);
	free(data->philo);
	free(data->thread);
	free(data->forks);
}
