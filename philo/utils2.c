/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:23:17 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/05 16:25:03 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	exit_philo(t_table *table, pthread_t *thread)
{
	int	i;

	i = -1;
	while (++i < table->nbr_of_philo)
		pthread_join(thread[i], NULL);
	i = -1;
	while (++i < table->nbr_of_philo)
		pthread_mutex_destroy(&table->philo[i].fork);
	pthread_mutex_destroy(&table->check);
	pthread_mutex_destroy(&table->statut);
	free(table->philo);
	free(thread);
}

void	waiting_statut(t_table *table, size_t time_to_dead)
{
	size_t	time;

	time = get_time();
	while (!(table->dead))
	{
		if (get_time() - time >= time_to_dead)
			break ;
	}
}
