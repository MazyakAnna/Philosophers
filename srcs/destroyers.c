/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 08:49:32 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/22 08:55:51 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_data *data)
{
	long	i;

	i = 0;
	while (i < data->args->nphilos)
	{
		pthread_mutex_destroy(&(data->forks[i].fork_mutex));
		pthread_mutex_destroy(&(data->philos[i].eating_mutex));
		i++;
	}
}

void	clear_all(t_data *data)
{
	destroy_mutexes(data);
	free(data->philos);
	free(data->forks);
	pthread_mutex_destroy(&data->output_mutex);
}
