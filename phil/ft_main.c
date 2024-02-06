/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:23:52 by otolmach          #+#    #+#             */
/*   Updated: 2024/02/06 19:51:54 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int	ft_atoi(const char *str)
{
	unsigned int	i;
	long			mc;
	long			g;

	i = 0;
	g = 0;
	mc = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mc *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		g = g * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(g * mc));
}

size_t	st_atoi(const char *str)
{
	unsigned int	i;
	long			mc;
	long			g;

	i = 0;
	g = 0;
	mc = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mc *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		g = g * 10 + (str[i] - '0');
		i++;
	}
	return ((size_t)(g * mc));
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Get time error!\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
/*argv[1]number_of_philosophers
argv[2] time_to_die
argv[3] time_to_eat
argv[4]time_to_sleep
argv[5]number_of_times_each_philosopher_must_eat(op)*/

void	init_argv(t_philo *philo, char **argv)
{
		philo->num_ph = ft_atoi(argv[1]);
		philo->time_to_die = st_atoi(argv[2]);
		philo->time_to_eat = st_atoi(argv[3]);
		philo->time_to_sleep = st_atoi(argv[4]);
		if (argv[5])
			philo->n_meals = ft_atoi(argv[5]);
		else
			philo->n_meals = -1;
}

void	init_philostruct(t_philo *philo, t_data *data, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].index_ph = i + 1;
		philo[i].start_time = get_current_time();
		philo[i].t_last_meal = get_current_time();

	}
	
}

int	main(int argc, char **argv)
{
	int	i = 0; 
	t_philo	philo[ft_atoi(argv[1])];
	t_data	data;
	pthread_mutex_t	forks[ft_atoi(argv[1])];
	if (!argc)
		return (0);
	
	return (0);
}