/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:18:04 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/05 16:23:50 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	philo_eat(t_philo *philo)
{
	t_table	*table;

	table = philo->tab;
	pthread_mutex_lock(&philo->fork);
	display_statut(philo, FORK);
	if (philo->tab->nbr_of_philo == 1)
	{
		waiting_statut(table, table->time_to_die);
		display_statut(philo, DIED);
		pthread_mutex_unlock(&philo->fork);
		table->dead = 1;
		return ;
	}
	pthread_mutex_lock(&philo->philo_right->fork);
	display_statut(philo, FORK);
	pthread_mutex_lock(&table->check);
	philo->eat_count++;
	display_statut(philo, EAT);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&table->check);
	waiting_statut(table, table->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->philo_right->fork);
}

void	checker_dead(t_table *tab)
{
	int	i;

	while (!tab->eaten_all)
	{
		i = -1;
		while (!tab->dead && ++i < tab->nbr_of_philo)
		{
			pthread_mutex_lock(&tab->check);
			if (get_time() - tab->philo[i].last_eat > (size_t)tab->time_to_die)
			{
				display_statut(&tab->philo[i], DIED);
				tab->dead = 1;
			}
			pthread_mutex_unlock(&tab->check);
			usleep(90);
		}
		if (tab->dead)
			break ;
		i = 0;
		while (tab->nbr_max_eat != -1 && i < tab->nbr_of_philo
			&& tab->philo[i].eat_count >= tab->nbr_max_eat)
			i++;
		if (i == tab->nbr_of_philo)
			tab->eaten_all = 1;
	}
}
