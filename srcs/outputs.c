/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 08:49:32 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/22 08:55:51 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
void	fill_timestamp(size_t ms, char *msg)
{
	int	i;

	i = 10;
	if (ms == 0)
		msg[i] = '0';
	else
	{
		while (ms > 0 && i > 0)
		{
			msg[i] = '0' + (ms % 10);
			ms /= 10;
			i--;
		}
	}
}

void	fill_indx(size_t indx, char *msg)
{
	int	i;

	i = 15;
	while (indx > 0)
	{
		msg[i] = '0' + (indx % 10);
		indx /= 10;
		i--;
	}
}

void	fill_msg(char *msg, char *status)
{
	while (*status != '\0')
	{
		*msg = *status;
		msg++;
		status++;
	}
}

void	fill_status(int status, char *msg)
{
	int	i;

	i = 16;
	if (status == 1)
		fill_msg(msg + 16, " has taken a fork\n");
	else if (status == 2)
		fill_msg(msg + 16, " is eating\n");
	else if (status == 3)
		fill_msg(msg + 16, " is sleeping\n");
	else if (status == 4)
		fill_msg(msg + 16, " is thinking\n");
	else if (status == 5)
		fill_msg(msg + 16, " died\n");
}

void	msg(t_philo *philo, int status, size_t ms)
{
	size_t	msg_len;
	char	*msg;

	pthread_mutex_lock(&(philo->data->output_mutex));
	msg_len = 18;
	if (status == 1)
		msg_len += 21;
	else if (status == 2)
		msg_len += 10;
	else if (status == 3 || status == 4)
		msg_len += 12;
	else if (status == 5)
		msg_len += 5;
	msg = (char *)malloc(sizeof(char) * msg_len);
	ft_memset(msg, ' ', msg_len);
	fill_timestamp(ms, msg);
	fill_indx(philo->indx + 1, msg);
	fill_status(status, msg);
	write(1, msg, msg_len);
	free(msg);
	pthread_mutex_unlock(&(philo->data->output_mutex));
}
*/

// void	printf_status(t_philo *philo, int status, long time)
// {
// 	pthread_mutex_lock(&(philo->data->output_mutex));
// 	if (time < 100000 && time >= 0)
// 	{
// 		if (status == 1)
// 			printf("%7ld %3ld has taken a fork\n", time, philo->indx + 1);
// 		else if (status == 2)
// 			printf("%7ld %3ld is eating\n", time, philo->indx + 1);
// 		else if (status == 3)
// 			printf("%7ld %3ld is sleeping\n", time, philo->indx + 1);
// 		else if (status == 4)
// 			printf("%7ld %3ld is thinking\n", time, philo->indx + 1);
// 		else if (status == 5)
// 			printf("%7ld %3ld died\n", time, philo->indx + 1);
// 	}
// 	pthread_mutex_unlock(&(philo->data->output_mutex));
// }

int	get_numlen(long n)
{
	int	size;

	size = 0;
	while (n > 9)
	{
		size++;
		n = n / 10;
	}
	size++;
	return (size);
}

void	add_status(char *str, char *s2)
{
	while (*s2 != '\0')
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = '\0';
}

void	fill_status(int status, char *str)
{
	if (status == 1)
		add_status(str, " has taken a fork\n");
	else if (status == 2)
		add_status(str, " is eating\n");
	else if (status == 3)
		add_status(str, " is sleeping\n");
	else if (status == 4)
		add_status(str, " is thinking\n");
	else if (status == 5)
		add_status(str, " is died\n");
}

int	get_len(int status, int len1)
{
	int	len;

	len = 0;
	if (status == 1)
		len = 20 + len1;
	else if (status == 2)
		len = 13 + len1;
	else if (status == 3)
		len = 15 + len1;
	else if (status == 4)
		len = 15 + len1;
	else if (status == 5)
		len = 9 + len1;
	return (len);
}

int	printf_status(t_philo *philo, int status, long time)
{
	int		len1;
	int		len2;
	char	*str;
	int		len;

	pthread_mutex_lock((&philo->data->output_mutex));
	if (time < 9000000 && time >= 0)
	{
		len1 = get_numlen(time);
		len2 = get_numlen(philo->indx + 1);
		len = get_len(status, len1 + len2);
		str = (char *)malloc(sizeof(char) * len);
		if (str == NULL)
			return (errors(2));
		{
			ft_ltoa(time, str, len1);
			ft_ltoa(philo->indx + 1, str + len1 + 1, len2);
			fill_status(status, str + len1 + len2 + 2);
			write(1, str, len);
			free(str);
		}
	}
	pthread_mutex_unlock(&(philo->data->output_mutex));
	return (0);
}
