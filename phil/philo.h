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
	pthread_t	id;
	int		nph;
	size_t	num_ph;
	int		s_lmeal;
	pthread_mutex_t right_f;
	pthread_mutex_t	left_f;
	int		d;
	size_t	td;
	size_t	te;
}		t_philo;

typedef struct s_data
{

	pthread_t id;
	size_t	n_phil;
	size_t	n_forks;
	size_t	t_die;
	size_t	t_eat;
	int		t_sleep;
	int	n_must_eat;
	size_t	phil_temp;
	int		t;
	t_philo *philo;
	
}		t_data;

# endif