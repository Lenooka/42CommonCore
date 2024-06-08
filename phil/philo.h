/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:13:09 by otolmach          #+#    #+#             */
/*   Updated: 2024/06/08 22:57:12 by olena            ###   ########.fr       */
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
    pthread_mutex_t *left_f;
    int           numphilo;
    pthread_mutex_t *right_f;
    pthread_mutex_t eat_count;
    pthread_mutex_t last_meal;
    int             index;
    int             eaten_meals;
    u_int64_t       last_meal_time;
    struct s_data *data;
}		t_philo;

typedef struct s_data
{
    u_int64_t     start_time;
    int     num_of_philo;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     num_of_meals;
    t_philo  *philo;
    pthread_t *thread;
    pthread_t thread_death;
    pthread_t thread_meals;
    pthread_mutex_t *forks;
    pthread_mutex_t print;
    pthread_mutex_t death_chek;
    int    death;
}		t_data;


int ft_atoi(const char *str);
size_t st_atoi(const char *str);
long ft_strtol(const char *str, char **endptr);
size_t fft_strlen(char *s);
int check_atoi(char **argv);
int argument_check(int argc, char **argv);
int	error_arguments(char *s, char *mess);
int	dead_check(t_data *data);
u_int64_t	get_current_time(u_int64_t relative);
void	clean_free(t_data *data);
#endif

