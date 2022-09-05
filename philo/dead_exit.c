/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintoloog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:19:30 by quentin           #+#    #+#             */
/*   Updated: 2022/09/05 16:35:28 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dead_and_exit(t_table *tab, pthread_t *tid)
{
	checker_dead(tab);
	exit_philo(tab, tid);
}
