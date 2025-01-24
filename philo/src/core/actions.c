/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 04:05:47 by albillie          #+#    #+#             */
/*   Updated: 2025/01/24 03:17:00 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_while_not_dead(t_philo *philo, char *state)
{
	if (dinner_running(philo->table))
	{
		pthread_mutex_lock(&philo->table->mutex_display);
		printf("%10ld %3d %s \n", get_time_since_launch(philo->table),
			philo->id, state);
		pthread_mutex_unlock(&philo->table->mutex_display);
	}
}

void	eating_dinner(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork);
	display_while_not_dead(philo, "has taken a fork");
	if (philo->l_fork == NULL)
	{
		ms_sleep(philo->args->time_to_die + 100);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		display_while_not_dead(philo, "has taken a fork");
		display_while_not_dead(philo, "is eating");
		ms_sleep(philo->args->time_to_eat);
		pthread_mutex_lock(&philo->table->mutex_update);
		philo->last_meal_time = get_time_in_ms();
		philo->nb_time_ate++;
		pthread_mutex_unlock(&philo->table->mutex_update);
		pthread_mutex_unlock(philo->l_fork);
	}
	pthread_mutex_unlock(&philo->r_fork);
}

void	sleep_and_think(t_philo *philo)
{
	display_while_not_dead(philo, "is sleeping");
	ms_sleep(philo->args->time_to_sleep);
	display_while_not_dead(philo, "is thinking");
}
