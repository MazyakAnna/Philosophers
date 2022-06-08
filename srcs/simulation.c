/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 08:49:32 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/25 22:35:09 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_threads(t_data *data, long i, long us)
{
	t_philo	*philo;

	while (i < data->args->nphilos)
	{
		philo = &data->philos[i];
		pthread_create(&(philo->thread), NULL, &ft_live, (void *)philo);
		i = i + 2;
		usleep(us);
	}
}

int	start_simulation(t_data *data)
{
	long	i;
	t_philo	*philo;

	data->allgood = 1;
	pthread_mutex_init(&(data->output_mutex), NULL);
	data->bigbang_time = get_time();
	start_threads(data, 0, 100);
	start_threads(data, 1, 0);
	i = 0;
	while (i < data->args->nphilos)
	{
		philo = &data->philos[i];
		pthread_detach(philo->thread);
		i++;
	}
	pthread_create(&(data->theGod), NULL, theGod_process, data);
	pthread_detach(data->theGod);
	while (data->allgood)
		;
	return (0);
}
