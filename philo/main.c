/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:40:10 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/05 16:34:54 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table		table;
	pthread_t	*thread;
	int			i;

	if (parsing_argument(argc, argv, &table))
		return (EXIT_FAILURE);
	thread = malloc(sizeof(pthread_t) * table.nbr_of_philo);
	table.start_time = get_time();
	i = -1;
	while (++i < table.nbr_of_philo)
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
	dead_and_exit(&table, thread);
	return (EXIT_SUCCESS);
}
