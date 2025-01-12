/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:49:44 by albillie          #+#    #+#             */
/*   Updated: 2025/01/12 04:51:08 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philo_profile(int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = &id;
	return (philo);
}

t_philo	**create_all_philos(t_philo *philos)
{
	t_philo	**array;
	int		i;

	array = malloc(sizeof(t_philo *) * philos->num_of_philos);
	if (!array)
		return (NULL);
	i = 0;
	while (i < philos->num_of_philos)
	{
		array[i] = create_philo_profile(i);
		i++;
	}
	return (array);
}

void	print_philos_ids(t_philo **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("%d\n", *array[i]->id);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_program *program;

	if (ac < 5 || ac > 6)
		format();
	if (!check_args(av))
		exit(1);
	program = malloc(sizeof(t_program));
	program->philos = init_philo_struct(av);
	t_philo **array = create_all_philos(program->philos);
	print_philos_ids(array);
	free(program->philos);
	free(program);
}
