/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:15:55 by albillie          #+#    #+#             */
/*   Updated: 2025/01/24 05:10:28 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdio.h>
#include <threads.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <sys/time.h>
#include "ft_printf_fd.h"

#define MUTEX_T pthread_mutex_t

typedef enum s_table_state
{
	HAVE_A_NICE_DINNER,
	WONT_THINK_ANYMORE,
	THEY_ATE_TOO_MUCH,
	PTHREAD_FAILED
}			t_table_state;

typedef struct s_args
{
	int				philos_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_must_eat;
}	t_args;

typedef struct s_table
{
	pthread_mutex_t	mutex_update;
	pthread_mutex_t	mutex_display;
	t_table_state	state;
	int				feeded_philos_count;
	long			dinner_start;
}	t_table;

typedef struct s_philo
{
	t_args			*args;
	t_table			*table;
	int				id;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
	int				nb_time_ate;
	long			last_meal_time;
}	t_philo;

bool	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
long	ft_atol(const char *str);
bool	ft_isspace(int c);
bool	check_args(char **av);
void	format(void);
void	args_error(char *str);
t_args	*init_args(char **av);
long	get_time_in_ms(void);
long	get_time_since_launch(t_table *table);
t_table	*init_table(void);
void	destroy_and_free_table(t_table *table);
void	free_single_philo(t_philo *philo);
void	free_all_philos(t_philo **philos, int philos_count);
t_philo	**create_all_philos(t_args *args, t_table *table);
void	ms_sleep(long ms);
bool	dinner_running(t_table *table);
void	sleep_and_think(t_philo *philo);
void	handle_pthread_error(t_table *table);
void	*monitoring(void *param);
void	*philosophing(void *param);
void	eating_dinner(t_philo *philo);
