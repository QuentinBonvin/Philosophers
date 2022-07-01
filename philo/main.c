/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:40:10 by qbonvin           #+#    #+#             */
/*   Updated: 2022/07/01 11:23:17 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	parsing;

	if (parsing_argument(argc, argv, &parsing))
	{
		printf("error\n");
		exit(EXIT_FAILURE);
	}
	init_philo(&parsing);
	printf("get time = %zu", get_time());
	return (EXIT_SUCCESS);
}

int	parsing_argument(int argc, char **argv, t_table *parsing)
{
	if ((argc == 5 || argc == 6) && argv_is_digit(argv) && argv_is_int(argv))
	{
		parsing->number_of_philo = ft_atoi(argv[1]);
		parsing->time_to_die = ft_atoi(argv[2]);
		parsing->time_to_eat = ft_atoi(argv[3]);
		parsing->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			parsing->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		return (0);
	}
	return (1);
}

int	argv_is_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("not a digit number\n");
				exit (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int			argv_is_int(char **argv)
{
	int			i;
	long int 	nbr;

	nbr = 0;
	i = 1;
	while (argv[i])
	{
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX)
		{
			printf("not an integer\n");
			exit (0);
		}
		i++;
	}
	return (1);
}