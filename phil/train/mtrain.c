/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:10:20 by otolmach          #+#    #+#             */
/*   Updated: 2024/01/25 14:55:52 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	*singing(void *data)
{
	t_data *dat = (t_data *)data;
pthread_mutex_lock(&dat->lock);
	dat->c++;
	if (dat->ari == 0)
	{
		usleep(500000);
		printf("Thread %d singing the note %s\n", dat->c, dat->one);
	}
	else if (dat->ari == 1)
	{
		usleep(500000);
		printf("Thread %d singing the note %s\n", dat->c, dat->two);
	}
	else if (dat->ari == 2)
	{
		usleep(500000);
		printf("Thread %d singing the note Mi\n", dat->c);
	}
	else if (dat->ari == 3)
	{
		usleep(500000);
		printf("Thread %d singing the note Fa\n", dat->c);
	}
	else if (dat->ari == 4)
	{
		usleep(500000);
		printf("Thread %d singing the note So\n", dat->c);
	}
else if (dat->ari == 5)
	{
		usleep(500000);
		printf("Thread %d singing the note La\n", dat->c);
	}
	else if (dat->ari == 6)
	{
		usleep(500000);
		printf("Thread %d singing the note Si\n", dat->c);
	}
	dat->ari++;
	pthread_mutex_unlock(&dat->lock);
	return NULL;
}

int	main(int argc, char **argv)
{
	pthread_t id;
	//pthread_t id2;
	t_data data;

	if (!argc)
		return 0;
	int	sho = ft_atoi(argv[1]);
	int	i = 0;
	data.one = "DO";
	data.two = "RE";
	data.c = 0;
	data.ari = 0;
	
	pthread_mutex_init(&data.lock, NULL);
	while (sho != 0)
	{
		pthread_create(&id, NULL, singing, (void *)&data);
		pthread_join(id, NULL);
		sho--;
		i++;
	}
	//pthread_create(&id2, NULL, singing, (void *)&data);
	//pthread_join(id2, NULL);
	//pthread_detach(id1);
	i = 0;
	sho = ft_atoi(argv[1]);
	while (sho != 0)
	{
		pthread_detach(id);
		sho--;
		i++;
	}
	//pthread_detach(id2);
	pthread_mutex_destroy(&data.lock);
	printf("Done!\n");
	return (0);
}