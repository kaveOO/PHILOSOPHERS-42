/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:48:49 by albillie          #+#    #+#             */
/*   Updated: 2025/01/23 05:32:54 by albillie         ###   ########.fr       */
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
		ft_printf_fd(2, "Mutex update init failed\n");
		exit(EXIT_FAILURE);
	}
	if (pthread_mutex_init(&table->mutex_display, NULL) != 0)
	{
		free(table);
		ft_printf_fd(2, "Mutex display init failed\n");
		exit(EXIT_FAILURE);
	}
	table->state = HAVE_A_NICE_DINNER;
	table->feeded_philos_count = 0;
	table->dinner_start = get_time_in_ms();
	return (table);
}

t_philo	*init_philo(t_args *args, t_table *table, int id, MUTEX_T *l_fork)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->args = args;
	philo->table = table;
	philo->id = id;
	if (pthread_mutex_init(&philo->r_fork, NULL) != 0)
	{
		free(philo);
		ft_printf_fd(2, "Mutex r_fork init failed\n");
		return (NULL);
	}
	philo->l_fork = l_fork;
	philo->nb_time_ate = 0;
	philo->last_meal_time = get_time_in_ms();
	return (philo);
}

t_philo	**create_all_philos(t_args *args, t_table *table)
{
	t_philo	**philos;
	int		i;

	philos = malloc(sizeof(t_philo *) * args->philos_count);
	philos[0] = init_philo(args, table, 1, NULL);
	if (!philos[0])
		return (free_all_philos(philos, 1), NULL);
	i = 1;
	while (i < args->philos_count)
	{
		philos[i] = init_philo(args, table, i + 1, &philos[i + 1]->r_fork);
		if (!philos[i])
			return (free_all_philos(philos, i + 1), NULL);
		i++;
	}
	if (args->philos_count > 1)
		philos[0]->l_fork = &philos[i - 1]->r_fork;
	return (philos);
}
