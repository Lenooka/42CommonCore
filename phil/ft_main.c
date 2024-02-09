/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:23:52 by otolmach          #+#    #+#             */
/*   Updated: 2024/02/09 19:02:29 by otolmach         ###   ########.fr       */
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
		philo[i].index_ph = i + 1;
		philo[i].start_time = get_current_time();
		philo[i].t_last_meal = get_current_time();
		init_argv(philo[i], argv);
		philo[i].dm = 0;
		printf("%d\n", philo[i].index_ph);
		philo[i].left_f = &data.forks[i];
		if (i == 0)
			philo[i].right_f = &data.forks[philo[i].num_ph - 1];
		else
			philo[i].right_f = &data.forks[i - 1];
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
	pthread_mutex_init(&data->death_lock, NULL);
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
	if (!argc)
		return (0);
	return (0);
}
