/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:25:59 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/05 16:35:46 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	display_statut(t_philo *philo, int message)
{
	size_t	time;

	time = get_time() - philo->tab->start_time;
	pthread_mutex_lock(&philo->tab->statut);
	if (!philo->tab->dead && !philo->tab->eaten_all)
	{
		printf("%ld ms ", time);
		printf("%d ", philo->philo_id);
		printf("%s", display_message(message));
		if (message == EAT)
			printf(" %d", philo->eat_count);
		printf("\n");
	}
	pthread_mutex_unlock(&philo->tab->statut);
}
