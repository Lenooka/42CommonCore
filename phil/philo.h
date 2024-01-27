#ifndef PHIL_H
# define PHIL_H

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "libftall/libft.h"

typedef struct s_data
{
	pthread_mutex_t right_f;
	pthread_mutex_t	left_f;
	pthread_t id;
	size_t	n_phil;
	size_t	n_forks;
	size_t	t_die;
	size_t	t_eat;
	int		t_sleep;
	int	n_must_eat;
	size_t	phil_temp;
	int		t;

} t_data;

# endif