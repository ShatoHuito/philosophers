/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:13:27 by gbrittan          #+#    #+#             */
/*   Updated: 2021/08/15 19:13:28 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	errors(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (1);
}

int	argv_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] - 48 >= 0 && argv[i][j] - 48 <= 9)
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	first_pars(int argc, char **argv, t_strc *strc)
{
	if (!(argc == 5 || argc == 6))
		return (errors("Wrong number of arguments.\n"));
	if (argv_check(argv))
		return (errors("Wrong characters in argumets.\n"));
	strc->philo_count = ft_atoi(argv[1]);
	if (strc->philo_count == 0)
		return (errors("Wrong number of philosophers.\n"));
	strc->die_time = ft_atoi(argv[2]);
	strc->eat_time = ft_atoi(argv[3]);
	strc->sleep_time = ft_atoi(argv[4]);
	strc->died = 0;
	if (argv[5])
	{
		strc->eat_count = ft_atoi(argv[5]);
		if (strc->eat_count < 0)
			return (errors("Wrong number of times each philo must eat.\n"));
	}
	else
		strc->eat_count = -1;
	return (0);
}
