/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:49:44 by albillie          #+#    #+#             */
/*   Updated: 2025/01/23 05:22:45 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	serving_all_plates(t_args *args, t_table *table, t_philo **philos,
	pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < args->philos_count)
	{
		if (pthread_create(threads + i, NULL, dinner_running, philos[i]) != 0)
		{
			return (handle_pthread_error(table));
		}
		i++;
	}
	if (pthread_create(threads + i + 1, NULL, MO)
	{
		/* code */
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
}
