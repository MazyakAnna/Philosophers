/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 08:38:22 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/22 08:49:25 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_args
{
	long	nphilos;
	long	tt_eat;
	long	tt_die;
	long	tt_sleep;
	long	min_meals;
}			t_args;

typedef struct s_fork
{
	pthread_mutex_t	fork_mutex;
	size_t			indx;
	int				flag;
}				t_fork;

typedef struct s_philo
{
	long			indx;
	long			nmeals;
	int				flag;
	t_args			*args;
	t_fork			*fork1;
	t_fork			*fork2;
	pthread_t		thread;
	struct s_data	*data;
	pthread_mutex_t	eating_mutex;
	long			mealtime;
}			t_philo;

typedef struct s_data
{
	t_args			*args;
	t_philo			*philos;
	t_fork			*forks;
	int				allgood;
	pthread_t		theGod;
	pthread_mutex_t	output_mutex;
	long			bigbang_time;
}			t_data;

int		ft_isdigit(int c);
int		ft_atoi(const char *s);
long	ft_atol(const char *s);
size_t	ft_atosizet(const char *s);

t_fork	*create_fork(int index);
t_philo	*create_philo(t_args *args, int index);
int		init_philos(t_data *data, t_args *args);
int		init_forks(t_data *data);
void	destroy_fork(t_fork *fork);

void	sort_philos(t_data *data);
int		start_simulation(t_data *data);

void	ms_sleep(long ms);
long	get_time(void);
void	msg(t_philo *philo, int status, size_t ms);
int		printf_status(t_philo *philo, int status, long time);
void	gettime_sizet(size_t *time_sizet);
void	my_usleep(unsigned int n);

//------THE LIVING---------
void	*ft_live(void	*args);
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);
void	lock_fork(t_philo *philo, t_fork *fork);

void	*theGod_process(void	*args);
void	ft_memset(char *str, char c, size_t size);
void	ft_ltoa(long n, char *str, int size);

void	clear_all(t_data *data);
int		errors(int i);

#endif
