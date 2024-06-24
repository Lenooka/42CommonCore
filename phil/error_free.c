/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:52:44 by otolmach          #+#    #+#             */
/*   Updated: 2024/06/22 18:39:41 by otolmach         ###   ########.fr       */
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
	while (i < data->num_of_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philo[i].eat_count);
		pthread_mutex_destroy(&data->philo[i].last_meal);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death_chek);
	pthread_mutex_destroy(&data->destroy_mutex);
	free(data->philo);
	free(data->thread);
	free(data->forks);
}

void	freeing(t_data *data)
{
	free(data->philo);
	free(data->thread);
	free(data->forks);
}

void	free_back(t_philo *philo, int i, int j)
{
	int	k;

	k = i;
	if (j >= 1)
		while (--k >= 0)
			pthread_mutex_destroy(&philo[i].eat_count);
	if (j >= 2)
		while (--i >= 0)
			pthread_mutex_destroy(&philo[i].last_meal);
}
