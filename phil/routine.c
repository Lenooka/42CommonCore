/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:55:19 by otolmach          #+#    #+#             */
/*   Updated: 2024/06/10 18:07:59 by otolmach         ###   ########.fr       */
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

void	*philo_life(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->numphilo == 1)
		return (lonely_philo(ph));
	if (ph->index % 2)
		usleep(50);
	while ((dead_check(ph->data) != 1 && ph->data->num_of_meals < 0)
		|| eat_count(ph) < ph->data->num_of_meals)
	{
		take_forks(ph);
		print_messege(ph, "is eating");
		if (ft_set_time_last_meal(philo) && dead_check(ph->data) == 1)
			return (take_forks(ph), NULL);
		pass_time(ph->data->time_to_eat);
		put_forks(ph);
		if (incr_eaten_meals(ph) && dead_check(ph->data))
			break ;
		print_messege(philo, "is sleeping");
		pass_time(ph->data->time_to_sleep);
		print_messege(ph, "is thinking");
		if ((ph->numphilo % 2) && dead_check(ph->data) != 1)
			pass_time(ph->data->time_to_eat * 2 - ph->data->time_to_sleep);
	}
	return (NULL);
}
