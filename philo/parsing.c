/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:14:04 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/05 16:26:21 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing_argument(int argc, char **argv, t_table *table)
{
	if ((argc == 5 || argc == 6) && argv_is_digit(argv) && argv_is_int(argv))
	{
		table->nbr_of_philo = ft_atoi(argv[1]);
		table->time_to_die = ft_atoi(argv[2]);
		table->time_to_eat = ft_atoi(argv[3]);
		table->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			table->nbr_max_eat = ft_atoi(argv[5]);
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
				return (0);
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
			return (0);
		}
		i++;
	}
	return (1);
}

void	create_table(t_table *table)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * table->nbr_of_philo);
	table->dead = 0;
	table->eaten_all = 0 ;
	while (i < table->nbr_of_philo)
	{
		table->philo[i].philo_id = i + 1;
		table->philo[i].tab = table;
		table->philo[i].eat_count = 0;
		if (table->nbr_of_philo == i + 1)
			table->philo[i].philo_right = &table->philo[0];
		else
			table->philo[i].philo_right = &table->philo[i + 1];
		if (i == 0)
			table->philo[i].philo_left = &table->philo[table->nbr_of_philo - 1];
		else
			table->philo[i].philo_left = &table->philo[i - 1];
		pthread_mutex_init(&table->philo[i].fork, NULL);
		i++;
	}
	pthread_mutex_init(&table->statut, NULL);
	pthread_mutex_init(&table->check, NULL);
}
