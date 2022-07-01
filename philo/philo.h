/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:28:05 by qbonvin           #+#    #+#             */
/*   Updated: 2022/06/30 15:21:15 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>


typedef struct s_table {
	int		number_of_philo;
	int 	time_to_die;
	int 	time_to_eat;
	int 	time_to_sleep;
	int 	number_of_times_each_philosopher_must_eat;
	size_t	get_time;
	struct s_philo	
}	t_table;

typedef struct s_philo {
	t_table		*philo;
	pthread_t	*philo_id;
} 	t_philo;

int			parsing_argument(int argc, char **argv, t_table *parsing);
void		order_argument(char **argv, int i, t_table *parsing);
int			argv_is_digit(char **argv);
int			argv_is_int(char **argv);
int			ft_isdigit(int c);
int 		ft_atoi(const char *str);
long int 	ft_atol(const char *str);
void		init_philo(t_table *philo);
void		*routine_philo(void *philo_id);
size_t		get_time(void);


#endif