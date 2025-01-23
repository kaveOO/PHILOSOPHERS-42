/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:49:44 by albillie          #+#    #+#             */
/*   Updated: 2025/01/23 06:23:17 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	serving_all_plates(t_args *args, t_table *table, t_philo **philos,
	pthread_t *threads)
{
	int	i;

	i = -1;
	while (++i < args->philos_count)
	{
		if (pthread_create(threads + i, NULL, philosophing, philos[i]) != 0)
		{
			return (handle_pthread_error(table));
		}
	}
	if (pthread_create(threads + i++, NULL, monitoring, philos) != 0)
	{
		handle_pthread_error(table);
	}
}

void	waiting_all_philos(t_args *args, t_table *table, pthread_t *threads)
{
	int	i;

	i = args->philos_count + 1;
	while (--i >= 0)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			return (handle_pthread_error(table));
		}
	}
}

static void	have_a_nice_dinner(t_args *args, t_table *table)
{
	t_philo		**philos;
	pthread_t	*threads;

	philos = create_all_philos(args, table);
	if (!philos)
		return (free(args), destroy_and_free_table(table));
	threads = malloc(sizeof(pthread_t) * (args->philos_count + 1));
	pthread_mutex_lock(&table->mutex_update);
	serving_all_plates(args, table, philos, threads);
	if (table->state != PTHREAD_FAILED)
	{
		pthread_mutex_unlock(&table->mutex_update);
		waiting_all_philos(args, table, threads);
	}
	else
	{
		pthread_mutex_unlock(&table->mutex_update);
	}
	free(threads);
	free_all_philos(philos, args->philos_count);

}

int	main(int ac, char **av)
{
	t_args	*args;
	t_table	*table;

	if (ac < 5 || ac > 6)
		format();
	if (!check_args(av))
		exit(1);
	args = init_args(av);
	table = init_table();
	if (!table)
		return (free(args), EXIT_FAILURE);
	have_a_nice_dinner(args, table);
	free(args);
	if (table->state == PTHREAD_FAILED)
	{
		return (destroy_and_free_table(table), EXIT_FAILURE);
	}
	destroy_and_free_table(table);
	exit(EXIT_SUCCESS);
}
