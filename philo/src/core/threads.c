/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 05:22:04 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/09 06:14:41 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philos_routine()
{
	printf("hello from thread !\n");
	return 0;
}


void	create_all_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philos->num_of_philos)
	{
		pthread_create(&program->philos->thread, NULL, &philos_routine, NULL);
		i++;
	}
}
