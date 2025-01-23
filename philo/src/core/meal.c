/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:58:22 by albillie          #+#    #+#             */
/*   Updated: 2025/01/23 04:42:48 by albillie         ###   ########.fr       */
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
		dinner_running(philo);
		sleep_and_think(philo);
	}
	return (NULL);
}
