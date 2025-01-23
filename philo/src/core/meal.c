/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:58:22 by albillie          #+#    #+#             */
/*   Updated: 2025/01/23 06:39:41 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	dinner_running(t_table *table)
{
	bool	state;

	pthread_mutex_lock(&table->mutex_update);
	state = table->state == HAVE_A_NICE_DINNER;
	pthread_mutex_unlock(&table->mutex_update);
	return (state);
}

void	*philosophing(void *param)
{
	t_philo	*philo;

	philo = (t_philo *) param;
	if (philo->id % 2 == 0)
	{
		ms_sleep(philo->args->time_to_eat / 2);
	}
	while (dinner_running(philo->table))
	{
		eating_dinner(philo);
		sleep_and_think(philo);
	}
	return (NULL);
}

static void	check_if_feeded(t_philo *philo, t_table *table, t_args *args)
{
	pthread_mutex_lock(&table->mutex_update);
	if (philo->nb_time_ate == args->nb_time_must_eat)
	{
		table->feeded_philos_count++;
	}
	if (args->nb_time_must_eat >= 0
		&& table->feeded_philos_count >= args->philos_count)
	{
		table->state = THEY_ATE_TOO_MUCH;
	}
	pthread_mutex_unlock(&table->mutex_update);
}

static void	check_if_dead(t_philo *philo, t_table *table, t_args *args)
{
	pthread_mutex_lock(&table->mutex_update);
	if ((get_time_in_ms() - philo->last_meal_time) > args->time_to_die)
	{
		pthread_mutex_lock(&philo->table->mutex_display);
		printf("%10ld %3d died \a\n", get_time_since_launch(table), philo->id);
		pthread_mutex_unlock(&philo->table->mutex_display);
		table->state = WONT_THINK_ANYMORE;
	}
	pthread_mutex_unlock(&table->mutex_update);
}

void	*monitoring(void *param)
{
	t_philo	**philos;
	t_table	*table;
	t_args	*args;
	int		i;

	philos = (t_philo **) param;
	table = philos[0]->table;
	args = philos[0]->args;
	while (dinner_running(table))
	{
		i = 0;
		while (i < args->philos_count && dinner_running(table))
		{
			check_if_feeded(philos[i], table, args);
			check_if_dead(philos[i], table, args);
			i++;
		}
	}
	return (NULL);
}
