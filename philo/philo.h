/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:28:05 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/05 16:35:10 by qbonvin          ###   ########.fr       */
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

typedef struct s_philo {
	int							philo_id;
	struct s_philo				*philo_left;
	struct s_philo				*philo_right;
	struct s_table				*tab;
	pthread_mutex_t				fork;
	size_t						last_eat;
	int							eat_count;
}	t_philo;

typedef struct s_table {
	int				dead;
	int				eaten_all;
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_max_eat;
	size_t			start_time;
	t_philo			*philo;
	pthread_mutex_t	statut;
	pthread_mutex_t	check;
}	t_table;

int			parsing_argument(int argc, char **argv, t_table *table);
void		create_table(t_table *table);
void		*routine_philo(void *arg);
void		order_argument(char **argv, int i, t_table *parsing);
int			argv_is_digit(char **argv);
int			argv_is_int(char **argv);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
long int	ft_atol(const char *str);
size_t		get_time(void);
void		philo_eat(t_philo *philo);
void		display_statut(t_philo *philo, int message);
char		*display_message(int message);
void		waiting_statut(t_table *table, size_t time_to_dead);
void		checker_dead(t_table *tab);
void		exit_philo(t_table *tab, pthread_t *thread);
void		dead_and_exit(t_table *tab, pthread_t *tid);

enum	e_message
{
	FORK = 0,
	EAT,
	SLEEP,
	DIED,
	THINK
};

#endif