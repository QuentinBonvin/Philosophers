/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:37:33 by quentin           #+#    #+#             */
/*   Updated: 2022/09/02 15:29:32 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	t_table	*table;

	table = philo->tab;
	pthread_mutex_lock(&philo->fork);
	display_statut(philo, FORK);
	if (philo->tab->number_of_philo == 1)
	{
		waiting_statut(table, table->time_to_die);
		display_statut(philo, DIED);
		pthread_mutex_unlock(&philo->fork);
		philo->tab->dead = 1;
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

char	*display_message(int message)
{
	if (message == FORK)
		return ("has taken a fork");
	if (message == EAT)
		return ("is eating");
	if (message == SLEEP)
		return ("is sleeping");
	if (message == THINK)
		return ("is thinking");
	if (message == DIED)
		return ("is dead");
	return ("error");
}
