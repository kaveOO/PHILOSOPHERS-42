/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:49:44 by albillie          #+#    #+#             */
/*   Updated: 2025/01/09 06:40:49 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_program *program;

	if (ac < 5 || ac > 6)
		format();
	if (!check_args(av))
		exit(1);
	program = malloc(sizeof(t_program));
	program->philos = init_philo_struct(av);
	create_all_threads(program);
	free(program->philos);
	free(program);
}
