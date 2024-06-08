/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:00:31 by olena             #+#    #+#             */
/*   Updated: 2024/06/08 22:57:24 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

u_int64_t	get_current_time(u_int64_t relative)
{
		struct timeval	now;

	if (gettimeofday(&now, NULL) == -1)
	{
		printf("Error: gettimeofday\n");
		exit(1);
	}
	return ((now.tv_sec * (u_int64_t)1000) + (now.tv_usec / 1000) - relative);
}
