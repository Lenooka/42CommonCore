/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:13:09 by otolmach          #+#    #+#             */
/*   Updated: 2024/06/08 15:48:58 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
	pthread_t		thread;
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