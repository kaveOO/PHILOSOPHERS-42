/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:15:55 by albillie          #+#    #+#             */
/*   Updated: 2025/01/09 00:57:48 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <unistd.h>
# include <stdio.h>
# include <threads.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct			s_philo
{
	pthread_t			thread;
	bool				is_eating;
	bool				is_dead;
	size_t				id;
	size_t				meals_eaten;
	size_t				num_of_philos;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				num_time_to_eat;
	pthread_mutex_t		r_fork;
	pthread_mutex_t		l_fork;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		meal_lock;
}						t_philo;

// ? HANDLING FUNCTIONS

void	format();

// ? PARSING FUNCTIONS

bool	check_args(char **av);
bool	check_chars(char **av);

// ? UTILS FUNCTIONS

bool	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	args_error(char *str);
bool	check_limits(char **av);
long	ft_atol(const char *str);
bool	ft_isspace(int c);
bool	check_len(char **av);
bool	check_values(char **av);



