/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   living.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 08:49:32 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/22 08:55:51 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_fork(t_philo *philo, t_fork *fork)
{
	while (philo->flag == fork->flag)
		;
	pthread_mutex_lock(&(fork->fork_mutex));
	printf_status(philo, 1, (get_time() - philo->data->bigbang_time));
	fork->flag = philo->flag;
}

void	ft_eat(t_philo *philo)
{
	while (philo->fork1->flag == philo->flag)
		;
	lock_fork(philo, philo->fork1);
	philo->fork1->flag = philo->flag;
	lock_fork(philo, philo->fork2);
	philo->fork2->flag = philo->flag;
	pthread_mutex_lock(&(philo->eating_mutex));
	printf_status(philo, 2, (philo->mealtime - philo->data->bigbang_time));
	philo->mealtime = get_time();
	pthread_mutex_unlock(&(philo->eating_mutex));
	philo->nmeals++;
	ms_sleep(philo->args->tt_eat);
	pthread_mutex_unlock(&(philo->fork1->fork_mutex));
	pthread_mutex_unlock(&(philo->fork2->fork_mutex));
}

void	ft_sleep(t_philo *philo)
{
	printf_status(philo, 3, (get_time() - philo->data->bigbang_time));
	ms_sleep(philo->args->tt_sleep);
}

void	*ft_live(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	philo->mealtime = get_time();
	while (1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		printf_status(philo, 4, (get_time() - philo->data->bigbang_time));
	}
	return ((void *)0);
}
