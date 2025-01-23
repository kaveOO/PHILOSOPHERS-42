/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:51:11 by albillie          #+#    #+#             */
/*   Updated: 2025/01/23 05:19:49 by albillie         ###   ########.fr       */
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

void	handle_pthread_error(t_table *table)
{
	ft_printf_fd(2, "Failed to create or join Pthread\n");
	pthread_mutex_lock(&table->mutex_update);
	table->state = PTHREAD_FAILED;
	pthread_mutex_unlock(&table->mutex_update);

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
