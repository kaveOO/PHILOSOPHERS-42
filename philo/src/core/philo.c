/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:49:44 by albillie          #+#    #+#             */
/*   Updated: 2025/01/08 22:44:25 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO Just create routine of each philo with mutex lock and unlock

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		format();
	if (!check_args(av))
		exit(1);
	
}
