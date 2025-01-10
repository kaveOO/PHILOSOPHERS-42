/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 05:22:04 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/10 12:51:56 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philos_routine()
{
	printf("hello from thread !\n");
	return 0;
}

// TODO create loop to create 1 thread for each philo + 1 for the monitor of philos

void	create_all_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philos->num_of_philos)
	{
		pthread_create(&program[i].philos->thread, NULL, &philos_routine, NULL);
		i++;
	}
}

// TODO Create loop to join all the philos together
