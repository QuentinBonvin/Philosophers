/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:57:57 by qbonvin           #+#    #+#             */
/*   Updated: 2022/07/01 10:39:37 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_table *table)
{
	int	i;
	t_philo	philo;
	
	i = 0;
	philo.philo_id = malloc(sizeof(t_philo) * table->number_of_philo);
	while (i < table->number_of_philo)
	{
		link_table_with_philo() 
		pthread_create(&philo.philo_id[i], NULL, routine_philo, NULL);
		sleep(2);
		//pthread_join(philo.philo_id[i], NULL);
		i++;
	}
}

void	*routine_philo(void *philo_id)
{
	int	i;

	i = 0;

	return (NULL);
}