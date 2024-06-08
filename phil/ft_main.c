/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:54:05 by olena             #+#    #+#             */
/*   Updated: 2024/06/08 23:00:12 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	error_arguments(char *s, char *mess)
{
	printf("Invalid argument [%s]!", s);
	printf("%s!\n", mess);
	return (1);
}

int	set_input_numbers(t_data *data, char **s)
{
	data->num_of_philo = ft_atoi(s[1]);
	if (data->num_of_philo < 1)
		return (error_arguments(s[1], "There is no life without philosophers"));
	data->time_to_die = ft_atoi(s[2]);
	if (data->time_to_die < 0)
		return (error_arguments(s[2], 
			"We all eventually die, even philosophers!\n"));
	data->time_to_eat = ft_atoi(s[3]);
	if (data->time_to_eat < 0)
		return (error_arguments(s[3], "Philosophers need time to eat too"));
	data->time_to_sleep = ft_atoi(s[4]);
	if (data->time_to_sleep < 0)
		return (error_arguments(s[4], "Philosophers need time to sleep too!\n"));
	if (s[5])
		data->num_of_meals = ft_atoi(s[5]);
	else
		data->num_of_meals = -1;
	if (data->num_of_meals == 0)
		return (error_arguments(s[5], "Philosophers need to eat at least once"));
	return (0);
}

int malloc_error(char *mes)
{
	printf("Allocation of %s error!\n", mes);
	return (1);
}
int	init_struct(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->num_of_philo);
	if (!data->philo)
		return (malloc_error("philo struct"));
	data->thread = malloc(sizeof(pthread_t) * data->num_of_philo);
	if (!data->thread)
	{
			free(data->philo);
			return (malloc_error("thread struct"));
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	if (!data->forks)
	{
		free(data->philo);
		free(data->thread);
		return (malloc_error("forks struct"));
	}
	data->death = 0;
	return (0);
}

void	serve_forks(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}
void	serve_table(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	serve_forks(data);
	data->start_time = get_current_time(0);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->death_chek, NULL);
	while (i < data->num_of_philo)
	{
		philo[i].index = i + 1;
		philo[i].data = data;
		philo[i].eaten_meals = 0;
		philo[i].numphilo = data->num_of_philo;
		philo[i].left_f = &data->forks[i];
		philo[i].right_f
			= &data->forks[(i + 1) % data->num_of_philo];
		pthread_mutex_init(&philo[i].eat_count, NULL);
		pthread_mutex_init(&philo[i].last_meal, NULL);
		i++;
	}
}

void	print_messege(t_philo *phil, char *mess)
{
	u_int64_t	time;

	time = get_current_time(phil->data->start_time);
	pthread_mutex_lock(&phil->data->print);
	if (dead_check(phil->data) != 1)
		printf("%llu %d %s\n", time, phil->index, mess);
	pthread_mutex_unlock(&phil->data->print);
}

void	*lonely_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_f);
	print_messege(philo, "has taken a fork");
	pthread_mutex_unlock(philo->left_f);
	return (NULL);
}

int	dead_check(t_data *data)
{
	pthread_mutex_lock(&data->death_chek);
	if (data->death == 1)
	{	
		pthread_mutex_unlock(&data->death_chek);
		return (1);
	}
	pthread_mutex_unlock(&data->death_chek);
	return (0);
}

void	*take_forks(t_philo *philo)
{
	if (philo->index % 2)
	{
		pthread_mutex_lock(philo->left_f);
		print_messege(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_f);
		print_messege(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_f);
		print_messege(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_f);
		print_messege(philo, "has taken a fork");
	}
	return (NULL);
}

void	pass_time(u_int64_t time)
{
	u_int64_t	start_time;

	start_time = get_current_time(0);
	while (get_current_time(start_time) < time)
		usleep(500);
}

int	ft_set_time_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal);
	philo->last_meal_time = get_current_time(0);
	pthread_mutex_unlock(&philo->last_meal);
	return (0);
}

int	eat(t_philo *philo)
{
	print_messege(philo, "is eating");
	if (ft_set_time_last_meal(philo) && dead_check(philo->data) == 1)
			return (1);
	pass_time(philo->data->time_to_eat);
	return (0);
}

void	*put_forks(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_f);
		pthread_mutex_unlock(philo->right_f);
	}
	else
	{
		pthread_mutex_unlock(philo->right_f);
		pthread_mutex_unlock(philo->left_f);
	}
	return (NULL);
}


int	eat_count(t_philo *philo)
{
	int	count;

	pthread_mutex_lock(&philo->eat_count);
	count = philo->eaten_meals;
	pthread_mutex_unlock(&philo->eat_count);
	return (count);
}

int	incr_eaten_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_count);
	philo->eaten_meals++;
	pthread_mutex_unlock(&philo->eat_count);
	return (0);
}

void	think(t_philo *philo)
{
	print_messege(philo, "is thinking");
}

void	ft_sleep(t_philo *philo)
{
	print_messege(philo, "is sleeping");
	pass_time(philo->data->time_to_sleep);
}
void	*philo_life(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->numphilo == 1)
		return (lonely_philo(ph));
	if (ph->index % 2)
		usleep(50);
	while ((dead_check(ph->data) != 1 && ph->data->num_of_meals < 0)
		|| eat_count(ph) < ph->data->num_of_meals)
	{
		take_forks(ph);
		print_messege(ph, "is eating");
	if (ft_set_time_last_meal(philo) && dead_check(ph->data) == 1)
			return (take_forks(ph), NULL);
		pass_time(ph->data->time_to_eat);
		put_forks(ph);
		if (incr_eaten_meals(ph) && dead_check(ph->data))
			break ;
		print_messege(philo, "is sleeping");
		pass_time(ph->data->time_to_sleep);
		print_messege(ph, "is thinking");
		if ((ph->numphilo % 2) && dead_check(ph->data) != 1) 
			pass_time(ph->data->time_to_eat * 2 - ph->data->time_to_sleep);
	}
	return (NULL);
}

u_int64_t	last_meal_time(t_philo *philo)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->last_meal);
	time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->last_meal);
	return (time);
}

void force_exit(t_data *data)
{
	pthread_mutex_lock(&data->death_chek);
	data->death = 1;
	pthread_mutex_unlock(&data->death_chek);
}

void	*monitor(void *dat)
{
	t_data	*data;
	int		i;

	data = (t_data *)dat;
	while (dead_check(data) != 1)
	{
		i = 0;
		while (i < data->num_of_philo)
		{
			if (get_current_time(last_meal_time(&data->philo[i])) > (u_int64_t)data->time_to_die)
			{
				return (print_messege(&data->philo[i], "died"), force_exit(data), NULL);
			}
			i++;
		}
	usleep(1000);
	}
	return (NULL);
}

void	*meals_monitor(void *dat)
{
	t_data	*data;
	int		i;

	data = (t_data *)dat;
	while (dead_check(data) != 1)
	{
		i = 0;
		while (i < data->num_of_philo)
		{
			if (eat_count(&data->philo[i]) < data->num_of_meals)
				break ;
			i++;
		}
		if (i == data->num_of_philo)
		{

			return (force_exit(data), NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

int	start_threads(t_data *data)
{
	int i;

	i = 0;
	data->start_time = get_current_time(0);
	while (i < data->num_of_philo)
	{
		data->philo[i].last_meal_time = data->start_time;
		i++;
	}
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_create(&data->thread[i], NULL, &philo_life, (void *)&data->philo[i]))
			return (1);
		i++;
	}
	if (pthread_create(&data->thread_death, NULL, &monitor, (void *)data) || (data->num_of_meals > 0 && data->num_of_philo > 1 && pthread_create(&data->thread_meals, NULL, &meals_monitor, (void *)data)))
		return (1);
	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_join(data->thread[i], NULL);
		i++;
	}
	return (0);
}

void	clean_free(t_data *data)
{
	int i;

	i = 0;
	pthread_join(data->thread_death, NULL);
	if (data->num_of_meals > 0 && data->num_of_philo > 1)
		pthread_join(data->thread_meals, NULL);
	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philo[i].eat_count);
		pthread_mutex_destroy(&data->philo[i].last_meal);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death_chek);
	free(data->philo);
	free(data->thread);
	free(data->forks);
}

int	main(int argc, char **argv)
{
	t_data			data;

	if (argument_check(argc, argv) == 1 || check_atoi(argv) == 1)
		return (0);
	if (set_input_numbers(&data, argv) == 1)
		return (0);
	if (init_struct(&data) == 1)
		return (0);
	serve_table(&data, data.philo);
	if (start_threads(&data) == 1)
	{
		printf("Creating threads failed!\n");
		clean_free(&data);
		return (1);
	}
	clean_free(&data);
	return (0);
}