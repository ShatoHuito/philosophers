/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:13:50 by gbrittan          #+#    #+#             */
/*   Updated: 2021/08/15 19:13:52 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	watching_2(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph->strc->philo_count)
	{
		if (ph[i].eat_status != FULL)
			return (1);
		i++;
	}
	return (0);
}

int	watching(t_philo *ph)
{
	int	time;
	int	i;

	while (!ph->strc->died)
	{
		i = 0;
		while (i < ph->strc->philo_count)
		{
			if (ph[i].eat_status != FULL)
			{
				time = ft_get_time() - ph[i].eat_time;
				if (time >= ph[i].strc->die_time + 1)
				{
					print_status(&ph[i], DIE);
					ph->strc->died = 1;
					return (1);
				}
				i++;
			}
			else
				if (!watching_2(ph))
					return (1);
		}
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = -1;
	c = 0;
	while (str[a] && (str[a] == ' ' || str[a] == '\t' || str[a] == '\n'
			|| str[a] == '\v' || str[a] == '\f' || str[a] == '\r'))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			b = b * -1;
		a++;
	}
	while (str[a] && str[a] >= '0' && str[a] <= '9')
	{
		c = (c * 10) + (str[a] - '0');
		a++;
	}
	if (b < 0)
		return (c);
	else
		return (-c);
}

long	ft_get_time(void)
{
	struct timeval	t;
	long			gt;

	gettimeofday(&t, NULL);
	gt = (long)t.tv_sec * 1000 + t.tv_usec / 1000;
	return (gt);
}

void	ft_sleep(uint64_t ms)
{
	uint64_t	time;

	time = ft_get_time();
	while (ft_get_time() - time < ms)
		usleep(500);
}
