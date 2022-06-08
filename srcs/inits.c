/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 08:49:32 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/26 03:27:54 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_a_philo(t_philo *philo, t_data *data, t_args *args, size_t i)
{
	philo->indx = i;
	philo->nmeals = 0;
	philo->args = args;
	if (philo->indx % 2 == 0)
	{
		philo->fork1 = &(data->forks[i]);
		philo->fork2 = &(data->forks[(i + 1) % data->args->nphilos]);
		philo->flag = 0;
		if (philo->indx + 1 == args->nphilos)
			philo->flag = 5;
	}
	else
	{
		philo->fork2 = &(data->forks[i]);
		philo->fork1 = &(data->forks[(i + 1) % data->args->nphilos]);
		philo->flag = 1;
	}
	philo->data = data;
	if (pthread_mutex_init(&(philo->eating_mutex), NULL))
		return (-2);
	return (0);
}

int	init_philos(t_data *data, t_args *args)
{
	long		i;

	if (args == NULL || data == NULL)
		return (-1);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->args->nphilos);
	if (data->philos == NULL)
		return (-1);
	i = 0;
	while (i < data->args->nphilos)
	{
		init_a_philo(&(data->philos[i]), data, args, i);
		i++;
	}
	return (0);
}

int	init_forks(t_data *data)
{
	long	i;

	data->forks = (t_fork *)malloc(sizeof(t_fork) * data->args->nphilos);
	if (data->forks == NULL)
		return (-1);
	i = 0;
	while (i < data->args->nphilos)
	{
		if (pthread_mutex_init(&(data->forks[i].fork_mutex), NULL))
			return (-2);
		data->forks[i].indx = i;
		data->forks[i].flag = -1;
		i++;
	}
	return (0);
}
