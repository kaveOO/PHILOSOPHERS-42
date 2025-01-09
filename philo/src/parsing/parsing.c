/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:48:21 by albillie          #+#    #+#             */
/*   Updated: 2025/01/09 01:06:04 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_args(char **av)
{
	if (!check_chars(av))
		return (false);
	else if (!check_limits(av))
		return (false);
	else if (!check_len(av))
		return (false);
	else if (!check_values(av))
		return (false);
	return (true);
}


