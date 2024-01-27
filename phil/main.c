/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:11:55 by otolmach          #+#    #+#             */
/*   Updated: 2024/01/26 16:31:48 by otolmach         ###   ########.fr       */
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

void	eat(t_data *dat)
{
	pthread_mutex_lock(&dat->right_f);
	pthread_mutex_lock(&dat->left_f);
	usleep(dat->t_eat);
	printf("phil %lu eating\n", dat->phil_temp);
	pthread_mutex_unlock(&dat->right_f);
	pthread_mutex_unlock(&dat->left_f);
}

void	*phil(void *data)
{
	t_data *dat = (t_data *)data;
	if (dat->t == 0)
	{
		dat->t = -1;
		pthread_mutex_unlock(&dat->right_f);
		pthread_mutex_unlock(&dat->left_f);
		return NULL;		
	}
	while (dat->t != 0)
	{
		usleep(20);
		printf("phil %lu sleeping\n", dat->phil_temp);
		eat(dat);
		dat->t--;
		dat->phil_temp++;
	}
	return NULL;
}

int	main(int argc, char **argv)
{
	t_data data;
	size_t	temp;

	if (argc != 6 && argc != 5)
		return (0);
	pthread_mutex_init(&data.right_f, NULL);
	pthread_mutex_init(&data.left_f, NULL);
	data.n_phil = st_atoi(argv[1]);
	data.n_forks = st_atoi(argv[1]);
	data.t_die = st_atoi(argv[2]);
	data.t_eat = ft_atoi(argv[3]);
	data.t_sleep = st_atoi(argv[4]);
	data.n_must_eat = -1;
	temp = data.n_phil;
	data.phil_temp = 1;
	data.t = data.n_phil;
	if (argc == 6)
		data.n_must_eat = ft_atoi(argv[5]);
	ft_printf("%d\n", data.n_must_eat);
	while (data.t != -1)
	{
		pthread_create(&data.id, NULL, phil, (void *)&data);
		pthread_join(data.id, NULL);
		temp--;
	}
	pthread_mutex_destroy(&data.right_f);
	pthread_mutex_destroy(&data.left_f);
	return (0);
}