/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 05:22:04 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/12 04:22:51 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philos_routine(void *param)
{
	t_program	*program;

	program = (t_program *) param;
	return 0;
}

// void	create_all_threads(t_program *program)
// {
// 	int			i;

// 	i = 0;
// 	while (i < philos->num_of_philos)
// 	{
// 		pthread_create(philos->thread[i], NULL, &philos_routine, NULL);
// 		i++;
// 	}
// 	join_all_threads(program);
// }

void	join_all_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philos->num_of_philos + 1)
	{
		pthread_join(program->philos->thread[i], NULL);
		i++;
	}
}
