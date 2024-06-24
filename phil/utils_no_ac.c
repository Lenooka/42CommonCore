/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_no_ac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:08:38 by otolmach          #+#    #+#             */
/*   Updated: 2024/06/18 15:29:34 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pass_time(u_int64_t time, t_data *data)
{
	u_int64_t	start_time;

	start_time = get_current_time(0);
	while (get_current_time(start_time) < time && dead_check(data) != 1)
		usleep(500);
}

int	ft_set_time_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal);
	philo->last_meal_time = get_current_time(0);
	pthread_mutex_unlock(&philo->last_meal);
	return (0);
}

int	eat_count(t_philo *philo)
{
	int	count;

	pthread_mutex_lock(&philo->eat_count);
	count = philo->eaten_meals;
	pthread_mutex_unlock(&philo->eat_count);
	return (count);
}

int	incr_eaten_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_count);
	philo->eaten_meals++;
	pthread_mutex_unlock(&philo->eat_count);
	return (0);
}

void	*take_forks(t_philo *philo)
{
	if (philo->index % 2)
	{
		pthread_mutex_lock(philo->left_f);
		print_messege(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_f);
		print_messege(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_f);
		print_messege(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_f);
		print_messege(philo, "has taken a fork");
	}
	return (NULL);
}
