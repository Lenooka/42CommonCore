/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:55:01 by otolmach          #+#    #+#             */
/*   Updated: 2024/06/10 18:10:30 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	argument_check(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	check_meals(argc, argv);
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

int	check_meals(int argc, char **argv)
{
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) < 0)
		{
			printf("Philosophers can't eat absence of meals!\n");
			printf("Ammount of meals : %s\n", argv[5]);
			return (1);
		}
	}
	return (0);
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_join(data->thread[i], NULL);
		i++;
	}
}
