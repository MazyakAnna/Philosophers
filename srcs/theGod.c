/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theGod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 08:49:32 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/22 08:55:51 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_dead(t_data *data, long i)
{
	long	time;

	pthread_mutex_lock(&(data->philos[i].eating_mutex));
	time = get_time();
	if (data->philos[i].mealtime + data->args->tt_die < time)
	{
		pthread_mutex_lock(&(data->output_mutex));
		printf("%7ld %3ld died\n", (time - data->bigbang_time), i + 1);
		data->allgood = 0;
		sleep(30000);
		return (1);
	}
	pthread_mutex_unlock(&(data->philos[i].eating_mutex));
	return (0);
}

int	check_if_staffed(int *full, t_data *data, int i)
{
	if (data->philos[i].nmeals >= data->args->min_meals)
		*full = *full + 1;
	if (*full >= (int)data->args->nphilos)
	{
		pthread_mutex_lock(&(data->output_mutex));
		data->allgood = 0;
		sleep(30000);
		return (1);
	}
	return (0);
}

void	*theGod_process(void	*args)
{
	t_data	*data;
	long	i;
	int		full;

	data = (t_data *)args;
	i = 0;
	while (i <= data->args->nphilos)
	{
		i = 0;
		full = -5;
		if (data->args->min_meals > 0)
			full = 0;
		while (i < data->args->nphilos)
		{
			if (check_if_staffed(&full, data, i) == 1)
				return ((void *)0);
			if (check_if_dead(data, i) == 1)
				return ((void *)0);
			i++;
		}
	}
	return ((void *)0);
}
