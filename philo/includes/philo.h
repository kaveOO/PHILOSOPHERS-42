/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:15:55 by albillie          #+#    #+#             */
/*   Updated: 2025/01/09 06:27:27 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <unistd.h>
# include <stdio.h>
# include <threads.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <string.h>

typedef struct			s_philo
{
	pthread_t			thread;
	bool				is_eating;
	bool				is_dead;
	int					id;
	int					meals_eaten;
	int					num_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_time_to_eat;
	pthread_mutex_t		r_fork;
	pthread_mutex_t		l_fork;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		meal_lock;
}						t_philo;

typedef struct			s_program
{
	t_philo				*philos;
} 						t_program;


void	format();
bool	check_args(char **av);
bool	check_chars(char **av);
t_philo	*init_philo_struct(char **av);
bool	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	args_error(char *str);
bool	check_limits(char **av);
long	ft_atol(const char *str);
bool	ft_isspace(int c);
bool	check_len(char **av);
bool	check_values(char **av);
void	*philos_routine();
void	create_all_threads(t_program *program);



