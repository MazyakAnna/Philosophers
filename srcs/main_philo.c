/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 08:49:32 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/22 08:55:51 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	errors(int i)
{
	write(1, "Error!\n ", 7);
	if (i == 1)
		write(1, "Wrong args!\n", 12);
	else if (i == 2)
		write(1, "Memory troubles (malloc)\n", 24);
	else if (i == 3)
		write(1, "Pthread problems\n", 17);
	else if (i == 4)
		write(1, "Unknown error!\n", 15);
	return (i);
}

int	check_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) && j < 10)
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (1);
}

int	fill_args(t_args *args, int argc, char **argv)
{
	args->nphilos = ft_atosizet(argv[1]);
	args->tt_die = ft_atosizet(argv[2]);
	args->tt_eat = ft_atosizet(argv[3]);
	args->tt_sleep = ft_atosizet(argv[4]);
	if (argc == 6)
		args->min_meals = ft_atosizet(argv[5]);
	else
		args->min_meals = -1;
	if (args->nphilos > 200 || args->nphilos < 1
		|| args->tt_die < 60 || args->tt_eat < 60
		|| args->tt_sleep < 60)
		return (-1);
	return (0);
}

int	philo(t_args *args)
{
	t_data	data;

	data.args = args;
	if (init_forks(&data) != 0)
		return (errors(2));
	if (init_philos(&data, args) != 0)
	{
		free(data.forks);
		return (errors(2));
	}
	start_simulation(&data);
	clear_all(&data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc < 5 || argc > 6)
		return (errors(1));
	if (check_params(argc, argv) == -1)
		return (errors(1));
	if (fill_args(&args, argc, argv) == -1)
		return (errors(1));
	return (philo(&args));
}
