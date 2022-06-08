/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 08:49:32 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/25 07:37:08 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ms_sleep(long ms)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(ms / 10);
}

long	get_time(void)
{
	struct timeval	tv_time;

	gettimeofday(&tv_time, NULL);
	return (tv_time.tv_sec * 1000 + tv_time.tv_usec / 1000);
}

void	ft_memset(char *str, char c, size_t size)
{
	while (size-- > 0)
	{
		str[size] = c;
	}
}

void	ft_ltoa(long n, char *str, int size)
{
	str[size] = ' ';
	while (n > 9)
	{
		str[size - 1] = '0' + (n % 10);
		size--;
		n = n / 10;
	}
	str[size - 1] = '0' + (n % 10);
}
