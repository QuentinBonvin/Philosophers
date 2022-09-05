/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:57:57 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/02 15:48:23 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_table(t_table *table)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * table->number_of_philo);
	table->dead = 0;
	table->eaten_all = 0 ;
	while (i < table->number_of_philo)
	{
		table->philo[i].tab = table;
		table->philo[i].philo_id = i + 1;
		table->philo[i].eat_count = 0;
		if (table->number_of_philo == i + 1)
			table->philo->philo_right = &table->philo[0];
		else
			table->philo->philo_right = &table->philo[i + 1];
		if (i == 0)
			table->philo->philo_left = &table->philo[table->number_of_philo - 1];
		else
			table->philo->philo_left = &table->philo[i - 1];
		pthread_mutex_init(&table->philo[i].fork, NULL);
		i++;
	}
	pthread_mutex_init(&table->statut, NULL);
	pthread_mutex_init(&table->check, NULL);
}

void	*routine_philo(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = philo->tab;
	if (philo->philo_id % 2 == 0)
		usleep (1000);
	while (!table->dead && !table->eaten_all)
	{
		philo_eat(philo);
		display_statut(philo, SLEEP);
		waiting_statut(table, table->time_to_sleep);
		display_statut(philo, THINK);
	}
	return (NULL);
}

void	waiting_statut(t_table *table, size_t time_to_dead)
{
	size_t	time;

	time = get_time();
	while (!(table->dead))
	{
		if (get_time() - time >= time_to_dead)
			break ;
		usleep(100);
	}
}
