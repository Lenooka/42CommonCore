/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:23:52 by otolmach          #+#    #+#             */
/*   Updated: 2024/02/22 15:41:34 by otolmach         ###   ########.fr       */
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

void	init_philostruct(t_philo *philo, t_data data, char **argv)
{
	int	i;

	i = 0;
	while (i < data.gnum)
	{
		philo[i].num_ph = data.gnum;
		philo[i].index_ph = i + 1;
		philo[i].start_time = get_current_time();
		philo[i].t_last_meal = get_current_time();
		init_argv(philo[i], argv);
		philo[i].dm = 0;
		philo[i].left_f = &data.forks[i];
		if (i == 0)
			philo[i].right_f = &data.forks[philo[i].num_ph - 1];
		else
			philo[i].right_f = &data.forks[i - 1];
		pthread_mutex_init(&philo[i].death_lock, NULL);
		pthread_mutex_init(&philo[i].meal_lock, NULL);	
		i++;
	}
}

void	init_mutex(t_data *data, int nph)
{
	int	i;

	i = 0;
	while (i < nph)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->meal_lock, NULL);
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
		if (value > INT_MAX || value < INT_MIN || fft_strlen(argv[i]) > 10)
		{
			printf("Integer overflow in argument: %s\n", argv[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	dead_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->death_lock);
	if (philo->dm == 1)
	{
		pthread_mutex_unlock(&philo->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->death_lock);
	return (0);
}

void	*routine(void *ph)
{
	t_philo *philo = (t_philo *)ph;
	
	while (dead_check(philo) != 1)
	{
		pthread_mutex_lock(&philo->meal_lock);
/*		if (get_current_time() - philo->t_last_meal >= philo->time_to_die)
		{
			philo->dm = 1;
			printf("%d died bye bye\n", philo->index_ph);
			pthread_mutex_unlock(&philo->meal_lock);
			break ;
		}SEPARATE THREAD */
		pthread_mutex_lock(philo->right_f);
		pthread_mutex_lock(philo->left_f);
		printf("%d eats\n", philo->index_ph);
		usleep(philo->time_to_eat);
		philo->t_last_meal = get_current_time();
		pthread_mutex_unlock(philo->right_f);
		pthread_mutex_unlock(philo->left_f);
		pthread_mutex_unlock(&philo->meal_lock);
	}
	return (NULL);
}

void	*monitor(void *ph)
{
	int	i;
	t_philo *philo = (t_philo *)ph;
	
	i = 0;
	while (i < philo[0].num_ph)
	{
		pthread_mutex_lock(&philo->meal_lock);
		if (get_current_time() - philo[i].t_last_meal >= philo[i].time_to_die)
		{
			philo->dm = 1;
			printf("%d died bye bye\n", philo[i].index_ph);
			pthread_mutex_unlock(&philo->meal_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->meal_lock);
		i++;
	}
	return (NULL);
}

void	create_start(t_philo *philo)
{
	int			i;
	pthread_t	mthread;
	i = 0;
	pthread_create(&mthread, NULL, monitor, (void *)&philo[i]); //protect this
	while (i < philo[0].num_ph)
	{
		pthread_create(&philo[i].thread, NULL, routine, (void *)&philo[i]); //protect this
		i++;
	}
	i = 0;
	while (i < philo[0].num_ph)
	{
		pthread_join(philo[i].thread, NULL); //protect this
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo			*phil;
	t_data			data;

	if (argument_check(argc, argv) == 1 || check_atoi(argv) == 1)
		return (0);
	data.gnum = ft_atoi(argv[1]);
	phil = (t_philo *)malloc(data.gnum * sizeof(t_philo)); /*FREE*/
	data.philo = phil;
	data.forks = (pthread_mutex_t *)malloc
		(data.gnum * sizeof(pthread_mutex_t)); /*FREE*/
	init_mutex(&data, data.gnum);
	init_philostruct(phil, data, argv);
	create_start(phil);
	if (!argc)
		return (0);
	//write free destroy function
	return (0);
}