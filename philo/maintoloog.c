/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintoloog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:19:30 by quentin           #+#    #+#             */
/*   Updated: 2022/09/02 15:56:18 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	main_toolong(t_table *tab, pthread_t *tid)
{
	checker_dead(tab);
	exit_philo(tab, tid);
}

void	checker_dead(t_table *table)
{
	int	i;

	while (!table->eaten_all)
	{
		i = -1;
		while (!table->dead && ++i < table->number_of_philo)
		{
			pthread_mutex_lock(&table->check);
			if (get_time() - table->philo[i].last_eat > (size_t)table->time_to_die)
			{
				display_statut(&table->philo[i], DIED);
				table->dead = 1;
			}
			pthread_mutex_unlock(&table->check);
			usleep(90);
		}
		if (table->dead)
			break ;
		i = 0;
		while (table->number_of_times_each_philosopher_must_eat != -1
			&& i < table->number_of_philo && table->philo[i].eat_count
			>= table->number_of_times_each_philosopher_must_eat)
			i++;
		if (i == table->number_of_philo)
			table->number_of_times_each_philosopher_must_eat = 1;
	}
}

void		exit_philo(t_table *table, pthread_t *thread)
{
	int	i;

	i = -1;
	while (++i < table->number_of_philo)
		pthread_join(thread[i], NULL);
	i = -1;
	while (++i < table->number_of_philo)
		pthread_mutex_destroy(&table->philo[i].fork);
	pthread_mutex_destroy(&table->check);
	pthread_mutex_destroy(&table->statut);
	free(table->philo);
	free(thread);
}
