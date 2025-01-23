/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:19:49 by albillie          #+#    #+#             */
/*   Updated: 2025/01/23 03:23:36 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_and_free_table(t_table *table)
{
	pthread_mutex_destroy(&table->mutex_display);
	pthread_mutex_destroy(&table->mutex_update);
	free(table);
}

void	free_single_philo(t_philo *philo)
{
	pthread_mutex_destroy(&philo->r_fork);
	free(philo);
}

void	free_all_philos(t_philo **philos, int philos_count)
{
	while (philos_count--)
	{
		free_single_philo(philos[philos_count]);
	}
	free(philos);
}
