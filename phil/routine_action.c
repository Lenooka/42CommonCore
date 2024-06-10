/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:05:52 by otolmach          #+#    #+#             */
/*   Updated: 2024/06/10 18:10:06 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_check(t_data *data)
{
	pthread_mutex_lock(&data->death_chek);
	if (data->death == 1)
	{
		pthread_mutex_unlock(&data->death_chek);
		return (1);
	}
	pthread_mutex_unlock(&data->death_chek);
	return (0);
}

int	eat(t_philo *philo)
{
	print_messege(philo, "is eating");
	if (ft_set_time_last_meal(philo) && dead_check(philo->data) == 1)
		return (1);
	pass_time(philo->data->time_to_eat);
	return (0);
}

void	*put_forks(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_f);
		pthread_mutex_unlock(philo->right_f);
	}
	else
	{
		pthread_mutex_unlock(philo->right_f);
		pthread_mutex_unlock(philo->left_f);
	}
	return (NULL);
}

void	think(t_philo *philo)
{
	print_messege(philo, "is thinking");
}

void	ft_sleep(t_philo *philo)
{
	print_messege(philo, "is sleeping");
	pass_time(philo->data->time_to_sleep);
}
