/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:40:10 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/02 15:55:25 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table		table;
	pthread_t	*thread;
	int			i;

	i = -1;
	if (parsing_argument(argc, argv, &table))
		exit(EXIT_FAILURE);
	thread = malloc(sizeof(pthread_t) * table.number_of_philo);
	table.start_time = get_time();
	while (++i < table.number_of_philo)
	{
		if (pthread_create(&thread[i], NULL, &routine_philo, &table.philo[i]))
		{
			write(1, "error with thread's create", 26);
			free(thread);
			free(table.philo);
			return (EXIT_FAILURE);
		}
		pthread_mutex_lock(&table.check);
		table.philo[i].last_eat = table.start_time;
		pthread_mutex_unlock(&table.check);
	}
	main_toolong(&table, thread);
	return (EXIT_SUCCESS);
}

int	parsing_argument(int argc, char **argv, t_table *table)
{
	if ((argc == 5 || argc == 6) && argv_is_digit(argv) && argv_is_int(argv))
	{
		table->number_of_philo = ft_atoi(argv[1]);
		table->time_to_die = ft_atoi(argv[2]);
		table->time_to_eat = ft_atoi(argv[3]);
		table->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			table->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		create_table(table);
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

int	argv_is_int(char **argv)
{
	int			i;
	long int	nbr;

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
