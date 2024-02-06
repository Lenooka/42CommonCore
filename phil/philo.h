#ifndef PHIL_H
# define PHIL_H

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "libftall/libft.h"
#include <sys/time.h>


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
	pthread_mutex_t *right_f;
	pthread_mutex_t	*left_f;
	pthread_t	thread;
}		t_philo;

typedef struct s_data
{
	pthread_mutex_t death_lock;
	pthread_mutex_t	meal_lock;
	t_philo *philo;
	
}		t_data;

# endif