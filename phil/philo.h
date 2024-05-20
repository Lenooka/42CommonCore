/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:13:09 by otolmach          #+#    #+#             */
/*   Updated: 2024/05/20 14:43:45 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stddef.h>
# include <unistd.h>
# include "libftall/libft.h"
# include "limits.h"
# include <sys/time.h>
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
	size_t			start_time;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	*left_f;
	int				dm;
	pthread_t		thread;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	print_lock;
}		t_philo;

typedef struct s_data
{
	int				gnum;
	pthread_mutex_t	meal_lock;
	int				death_monitor;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}		t_data;

#endif