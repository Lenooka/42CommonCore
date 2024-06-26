/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:55:19 by otolmach          #+#    #+#             */
/*   Updated: 2024/06/22 19:25:28 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_messege(t_philo *phil, char *mess)
{
	u_int64_t	time;

	time = get_current_time(phil->data->start_time);
	pthread_mutex_lock(&phil->data->print);
	if (dead_check(phil->data) != 1)
		printf("%lu %d %s\n", time, phil->index, mess);
	pthread_mutex_unlock(&phil->data->print);
}

void	*lonely_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_f);
	print_messege(philo, "has taken a fork");
	pthread_mutex_unlock(philo->left_f);
	return (NULL);
}

int	philo_eat(t_philo *ph)
{
	take_forks(ph);
	print_messege(ph, "is eating");
	if (ft_set_time_last_meal(ph) && dead_check(ph->data) == 1)
	{
		take_forks(ph);
		return (1);
	}
	pass_time(ph->data->time_to_eat, ph->data);
	put_forks(ph);
	return (0);
}

int	are_we_done(t_data *data)
{
	pthread_mutex_lock(&data->destroy_mutex);
	if (data->done == 0)
	{
		pthread_mutex_unlock(&data->destroy_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->destroy_mutex);
	return (0);
}

void	*philo_life(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->data->num_of_philo == 1)
		return (lonely_philo(ph));
	if (ph->index % 2)
		usleep(50);
	if (are_we_done(ph->data) == 1)
	{
		while ((dead_check(ph->data) != 1 && ph->data->num_of_meals < 0)
			|| eat_count(ph) < ph->data->num_of_meals)
		{
			if (philo_eat(ph))
				break ;
			if (incr_eaten_meals(ph) && dead_check(ph->data))
				break ;
			print_messege(philo, "is sleeping");
			pass_time(ph->data->time_to_sleep, ph->data);
			print_messege(ph, "is thinking");
			if ((ph->data->num_of_philo % 2) && dead_check(ph->data) != 1)
				pass_time(ph->data->time_to_eat * 2 - ph->data->time_to_sleep,
					ph->data);
		}
	}
	return (NULL);
}
