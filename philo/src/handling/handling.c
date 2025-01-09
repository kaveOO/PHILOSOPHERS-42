/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:51:11 by albillie          #+#    #+#             */
/*   Updated: 2025/01/09 02:26:52 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	format()
{
	printf("philoArgs -> Invalid args format\n\n");
	printf("int ->		<number_of_philos>\n");
	printf("int ->		<time_to_die>		(in milliseconds)\n");
	printf("int ->		<time_to_eat>		(in milliseconds)\n");
	printf("int ->		<time_to_sleep>		(in milliseconds)\n");
	printf("int ->		<num_time_to_eat>	(optional)\n\n");
	exit(0);
}

void	args_error(char *str)
{
	int	i;
	i = 0;

	write(2, "philoArgs -> ", 14);
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}
