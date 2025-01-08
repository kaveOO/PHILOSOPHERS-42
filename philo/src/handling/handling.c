/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:51:11 by albillie          #+#    #+#             */
/*   Updated: 2025/01/08 16:06:08 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	format()
{
	printf("Format -> <number_of_philosophers> <time_to_die> ");
	printf("<time_to_eat> <time_to_sleep> ");
	printf("<number_of_times_each_philosopher_must_eat>\n");
	exit(0);
}
