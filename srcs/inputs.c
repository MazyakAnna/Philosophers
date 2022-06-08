/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 08:49:32 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/22 08:55:51 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '\x30' && c <= '\x39')
		return (1);
	else
		return (0);
}

long	ft_atol(const char *s)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\r' || *s == '\v' || *s == '\f')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= 48 && *s <= 57)
	{
		res = res * 10 + (*s - 48);
		s++;
	}
	return (res * sign);
}

size_t	ft_atosizet(const char *s)
{
	size_t	res;

	res = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\r' || *s == '\v' || *s == '\f')
		s++;
	while (*s >= 48 && *s <= 57)
	{
		res = res * 10 + (*s - 48);
		s++;
	}
	return (res);
}

void	*ft_calloc(size_t number, size_t size)
{
	void			*ptr;

	ptr = malloc(number * size);
	if (ptr != NULL)
		memset(ptr, 0, number * size);
	return (ptr);
}
