/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:11:55 by otolmach          #+#    #+#             */
/*   Updated: 2024/02/05 16:40:37 by otolmach         ###   ########.fr       */
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

void	eat(t_philo *dat)
{
	struct timeval time;
		
	pthread_mutex_lock(&dat->right_f);
	pthread_mutex_lock(&dat->left_f);
	usleep(300);
	printf("phil %d eating\n", dat->nph);
	pthread_mutex_unlock(&dat->right_f);
	pthread_mutex_unlock(&dat->left_f);
	if (gettimeofday(&time, NULL) - dat->te < dat->td)
		dat->d = -1;
}

void	*phil(void *philo)
{
	t_philo *p = (t_philo *)philo;
	//if (dat->t == 0)
	/*	{
		dat->t = -1;
		pthread_mutex_unlock(&dat->right_f);
		pthread_mutex_unlock(&dat->left_f);
		return NULL;		
	}*/
	while (p->d != -1)
	{
		usleep(20000);
		printf("phil %d sleeping\n", p->nph);
		eat(p);
	}
	return NULL;
}

int	main(int argc, char **argv)
{
	t_data data;
	size_t	temp;
	t_philo	*philo;
	int		i = 0;
	int		a = 0;

	if (argc != 6 && argc != 5)
		return (0);
	philo = (t_philo *)malloc(sizeof(t_philo));
	data.n_phil = st_atoi(argv[1]);
	data.n_forks = st_atoi(argv[1]);
	data.t_die = st_atoi(argv[2]);
	data.t_eat = ft_atoi(argv[3]);
	data.t_sleep = st_atoi(argv[4]);
	data.n_must_eat = -1;
	temp = data.n_phil;
	data.phil_temp = 1;
	philo->num_ph = data.n_phil;
	data.t = data.n_phil;
	if (argc == 6)
		data.n_must_eat = ft_atoi(argv[5]);
	while (a < ft_atoi(argv[1]))
	{
		philo[a].nph = a + 1;
		philo[a].d = data.t;
		philo[a].td = data.t_die;
		philo[a].te = data.t_eat;
		pthread_mutex_init(&philo[a].right_f, NULL);
		pthread_mutex_init(&philo[a].left_f, NULL);
		a++;
	}
	i = 0;
	while (philo->d != -1)
	{
	
		pthread_create(&philo[i].id, NULL, phil, (void *)&philo[i]);
		pthread_join(philo[i].id, NULL);
		temp--;
		i++;
	}
	pthread_mutex_destroy(&philo[i].right_f);
	pthread_mutex_destroy(&philo[i].left_f);
	free(philo);
	return (0);
}

