/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   againstart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:23:52 by otolmach          #+#    #+#             */
/*   Updated: 2024/06/08 16:00:45 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#ifndef PHILOO_H
# define PHILOO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stddef.h>
# include <unistd.h>
# include "limits.h"
# include <sys/time.h>
# include <sys/types.h>
# include <stdlib.h>
# define MAX_INT 2147483647

typedef struct s_philo
{
	int				index_ph;
	int				num_ph;
	int				n_meals;
	size_t			t_last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	u_int64_t		start_time;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	*left_f;
	int				dm;
	pthread_t		*thread;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	print_lock;
	struct s_data	*data;
}		t_philo;

typedef struct s_data
{
	int				gnum;
	pthread_mutex_t	meal_lock;
	int				death_monitor;
	pthread_mutex_t	dlock;
	t_philo			*philo;
	u_int64_t		s_time;
	pthread_mutex_t	*forks;
	pthread_t		monitor;
	pthread_mutex_t	meal_count_lock;
	pthread_mutex_t	print_lock;
}		t_data;

#endif

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

size_t	get_current_time(u_int64_t spec_time)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Get time error!\n");
	return ((time.tv_sec * (u_int64_t)1000) + (time.tv_usec / 1000) - spec_time);
}
/*argv[1]number_of_philosophers
argv[2] time_to_die
argv[3] time_to_eat
argv[4]time_to_sleep
argv[5]number_of_times_each_philosopher_must_eat(op)*/

void	init_argv(t_philo philo, char **argv)
{
	philo.num_ph = ft_atoi(argv[1]);
	philo.time_to_die = st_atoi(argv[2]);
	philo.time_to_eat = st_atoi(argv[3]);
	philo.time_to_sleep = st_atoi(argv[4]);
	if (argv[5])
		philo.n_meals = ft_atoi(argv[5]);
	else
		philo.n_meals = -1;
}

void	init_philostruct(t_philo *philo, t_data *data, char **argv)
{
	int	i;

	i = 0;
	while (i < data->gnum)
	{
		philo[i].num_ph = data->gnum;
		philo[i].index_ph = i + 1;
		philo[i].t_last_meal = get_current_time(0);
		init_argv(philo[i], argv);
		philo[i].dm = 0;
		philo[i].left_f = &data->forks[i];
		if (i == 0)
			philo[i].right_f = &data->forks[philo[i].num_ph - 1];
		else
			philo[i].right_f = &data->forks[i - 1];
		pthread_mutex_init(&philo[i].death_lock, NULL);
		pthread_mutex_init(&philo[i].meal_lock, NULL);
		pthread_mutex_init(&philo[i].print_lock, NULL);
		i++;
		philo->data = data;
	}
}

void	init_mutex(t_data *data, int nph)
{
	int	i;
	
	data->death_monitor = 0;
	data->philo->thread = (pthread_t )malloc(nph * sizeof(pthread_t));
	i = 0;
	while (i < nph)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->dlock, NULL);
	pthread_mutex_init(&data->meal_count_lock, NULL);
	pthread_mutex_init(&data->print_lock, NULL);
	
}

int	argument_check(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	if (argc != 5 && argc != 6)
	{
		printf("Wrong amount of argv!\n");
		return (1);
	}
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
			{
				printf("Invalid argument : %s\n", argv[j]);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

long	ft_strtol(const char *str, char **endptr)
{
	long	result;

	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
		{
			if (endptr != NULL)
			{
				*endptr = (char *)str;
			}
			return (LONG_MAX);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	if (endptr != NULL)
	{
		*endptr = (char *)str;
	}
	return (result);
}

size_t	fft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	check_atoi(char **argv)
{
	int			i;
	char		*endptr;
	long long	value;

	i = 1;
	while (argv[i])
	{
		value = ft_strtol(argv[i], &endptr);
		if (ft_atoi(argv[1]) > 1000000)
		{
			return (printf("To many philosophers for my program!") && 1);
		}
		if (*endptr != '\0')
		{
			printf("Error converting argument to integer: %s\n", argv[i]);
			return (1);
		}
		if (value > INT_MAX || value < INT_MIN)
		{
			printf("Integer overflow in argument: %s\n", argv[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	dead_check(t_data *data)
{
	if (data == NULL)
	{
		printf("Data is NULL\n");
		return (1);
	}
	pthread_mutex_lock(&data->dlock);
	if (data->death_monitor == 1)
	{	
		pthread_mutex_unlock(&data->dlock);
		return (1);
	}
	pthread_mutex_unlock(&data->dlock);
	return (0);
}

void	print_messege(t_philo *phil, char *mess)
{
	u_int64_t	time;

	time = get_current_time(phil->start_time);
	pthread_mutex_lock(&phil->print_lock);
	if (phil->dm == 0)
		printf("%llu %d %s\n", time, phil->index_ph, mess);
	pthread_mutex_unlock(&phil->print_lock);
}

void	*forks_take_lock(t_philo *philo)
{
	if (philo->index_ph % 2 == 0)
	{
		pthread_mutex_lock(philo->right_f);
		print_messege(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_f);
		print_messege(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_f);
		print_messege(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_f);
		print_messege(philo, "has taken a fork");
	}
	return (NULL);
}

int	last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	philo->t_last_meal = get_current_time(0);
	pthread_mutex_unlock(&philo->meal_lock);
	return (0);
}

int 	eat_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meal_count_lock);
	philo->n_meals--;
	pthread_mutex_unlock(&philo->data->meal_count_lock);
	if (dead_check(philo->data) == 1)
		return (1);
	return (0);
}
/*
	do we need to print state?
*/
void	*forks_put_lock(t_philo *philo)
{
	if (philo->index_ph % 2 == 0)
	{
		pthread_mutex_unlock(philo->right_f);
		print_messege(philo, "has put down a fork");
		pthread_mutex_unlock(philo->left_f);
		print_messege(philo, "has put down a fork");
	}
	else
	{
		pthread_mutex_unlock(philo->left_f);
		print_messege(philo, "has put down a fork");
		pthread_mutex_unlock(philo->right_f);
		print_messege(philo, "has put down a fork");
	}
	return (NULL);
}

void	take_action_time(u_int64_t time)
{
	u_int64_t	start_time;

	start_time = get_current_time(0);
	while (get_current_time(start_time) < time)
		usleep(500);
}

void	*one_phil_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->left_f);
	print_messege(philo, "has taken a fork");
	//while (!dead_check(philo->data))
		//usleep(10);
	pthread_mutex_unlock(philo->left_f);
	return (NULL);
}
/*
Stager multyplyin time_to_eat by 2
to compensate for usleep in the beginning of the function
*/
void	*routine(void *ph)
{
	t_philo *philo;
	
	philo = (t_philo *)ph;
	if (philo->num_ph == 1)
	{
		one_phil_routine(philo);
		return (NULL);
	}
	if (philo->index_ph % 2 == 0)
		usleep(100);
	while (dead_check(philo->data) != 1 && philo->n_meals != 0)
	{
		print_messege(philo, "is eating");
		last_meal_time(philo);
		if (dead_check(philo->data) == 1)
			return (forks_take_lock(philo), NULL);
		take_action_time(philo->time_to_eat); 
		forks_put_lock(philo); 
		if (eat_count(philo) == 1)
			return (NULL);
		print_messege(philo, "is sleeping");
		take_action_time(philo->time_to_sleep);
		print_messege(philo, "is thinking");
		if ((philo->num_ph % 2) && dead_check(philo->data) == 1)
			take_action_time(philo->time_to_eat * 2 - philo->time_to_sleep);
	}
	return (NULL);
}

// 		pthread_mutex_lock(&philo->meal_lock);
// /*		if (get_current_time() - philo->t_last_meal >= philo->time_to_die)
// 		{
// 			philo->dm = 1;
// 			printf("%d died bye bye\n", philo->index_ph);
// 			pthread_mutex_unlock(&philo->meal_lock);
// 			break ;
// 		}SEPARATE THREAD */

void	*monitor(void *ph)
{
	int	i;
	t_data *data = (t_data *)ph;
	
	i = 0;
	while (!dead_check(data))
	{
		i = 0;
		while (i < data->gnum)
		{
			if (get_current_time(last_meal_time(&data->philo[i])) > (u_int64_t)data->philo[i].time_to_die)
			{
				print_messege(&data->philo[i], "died");
				pthread_mutex_lock(&data->dlock);
				data->death_monitor = 1;
				pthread_mutex_unlock(&data->dlock);
			}
			i++;
		}
		usleep(100);
	}
	return (NULL);
}

void	create_start(t_philo *philo, t_data *data)
{
	int			i;

	i = 0;
	data->s_time = get_current_time(0);
	while (i < data->gnum)
	{
		philo[i].t_last_meal = data->s_time;
		 if (pthread_create(&philo[i].thread, NULL, &routine, (void *)&philo[i]))
		 		exit(1);//protect this
		i++;
	}
	i = 0;
	while (i < philo[0].num_ph)
	{
		pthread_join(philo[i].thread, NULL); //protect this
		i++;
	}
	i = 0;
	if (pthread_create(&data->monitor, NULL, &monitor, (void *)data))
	{
		printf("Monitor thread created\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_philo			*phil;
	t_data			*data;

	if (argument_check(argc, argv) == 1 || check_atoi(argv) == 1)
		return (0);
	data = (t_data *)malloc(sizeof(t_data)); /*FREE*/
	data->gnum = ft_atoi(argv[1]);
	phil = (t_philo *)malloc(data->gnum * sizeof(t_philo)); /*FREE*/
	data->philo = phil;
	data->forks = (pthread_mutex_t *)malloc(data->gnum * sizeof(pthread_mutex_t)); /*FREE*/
	init_mutex(data, data->gnum);
	init_philostruct(phil, data, argv);
	create_start(phil, data);
	if (!argc)
		return (0);
	//write free destroy function
	return (0);
}