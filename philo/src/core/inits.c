/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:48:49 by albillie          #+#    #+#             */
/*   Updated: 2025/01/23 01:01:19 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*init_args(char **av)
{
	t_args	*args;

	args = malloc(sizeof(args));
	args->philos_count = ft_atol(av[1]);
	args->time_to_die = ft_atol(av[2]);
	args->time_to_eat = ft_atol(av[3]);
	args->time_to_sleep = ft_atol(av[4]);
	if (av[5])
	{
		args->nb_time_must_eat = ft_atol(av[5]);
	}
	else
	{
		args->nb_time_must_eat = -1;
	}
	return (args);
}

t_table	*init_table()
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (pthread_mutex_init(&table->mutex_update, NULL) != 0)
	{
		free(table);
		
	}

}
