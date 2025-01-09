/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:48:21 by albillie          #+#    #+#             */
/*   Updated: 2025/01/09 01:03:15 by kaveo            ###   ########.fr       */
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

bool	check_chars(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				args_error("Expecting Digits\n");
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
bool	check_limits(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < -2147483648)
		{
			args_error("Check for MAX_INT or MIN_INT\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	check_len(char **av)
{
	int		i;
	size_t	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (ft_isdigit(av[i][j]))
			j++;
		if (j > ft_strlen("9223372036854775807"))
		{
			args_error("Check for LONG_MAX or LONG_MIN\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	check_values(char **av)
{
	if (av[1] && ft_atol(av[1]) < 1)
	{
		return (args_error("Philos count is less than 1\n"), false);
	}
	else if (av[2] && ft_atol(av[2]) < 1)
	{
		return (args_error("Time to die is less than 1\n"), false);
	}
	else if (av[3] && ft_atol(av[3]) < 1)
	{
		return (args_error("Time to eat is less than 1\n"), false);
	}
	else if (av[4] && ft_atol(av[4]) < 1)
	{
		return (args_error("Time to sleep is less than 1\n"), false);
	}
	else if (av[5] && ft_atol(av[5]) < 1)
	{
		return (args_error("Number of time to eat is less than 1\n")), false;
	}
	return (true);
}
