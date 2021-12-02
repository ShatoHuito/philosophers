/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:13:43 by gbrittan          #+#    #+#             */
/*   Updated: 2021/08/15 19:13:45 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_print(char *str, t_philo *ph)
{
	if (ph->strc->died)
		return (1);
	printf("%ld %d ", (ft_get_time() - ph->start_time), ph->num);
	printf("%s", str);
	return (0);
}

int	print_status(t_philo *ph, int status)
{
	pthread_mutex_lock(ph->flag);
	if (status == FORK)
		ft_print("take a fork\n", ph);
	else if (status == EAT)
		ft_print("eating\n", ph);
	else if (status == SLEEP)
		ft_print("sleeping\n", ph);
	else if (status == THINK)
		ft_print("thinking\n", ph);
	else if (status == DIE)
	{
		ft_print("died\n", ph);
		return (1);
	}
	else if (status == FULL)
		ft_print("full\n", ph);
	pthread_mutex_unlock(ph->flag);
	return (0);
}

int	eat_proc(t_philo *ph)
{
	pthread_mutex_lock(ph->l_fork);
	print_status(ph, FORK);
	pthread_mutex_lock(ph->r_fork);
	print_status(ph, FORK);
	ph->eat_time = ft_get_time();
	print_status(ph, EAT);
	ft_sleep(ph->strc->eat_time);
	pthread_mutex_unlock(ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
	return (1);
}

void	*start(void *phil)
{
	t_philo	*ph;
	int		i;

	i = 0;
	ph = phil;
	if (!(ph->num % 2))
		ft_sleep(ph->strc->sleep_time / 2);
	while (!ph->strc->died)
	{
		eat_proc(ph);
		if (ph->strc->eat_count)
		{
			i++;
			if (ph->strc->eat_count == i)
			{
				ph->eat_status = FULL;
				print_status(ph, FULL);
				return (NULL);
			}
		}
		print_status(ph, SLEEP);
		ft_sleep(ph->strc->sleep_time);
		print_status(ph, THINK);
	}
	return (NULL);
}

int	threads_init(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->strc->philo_count)
	{
		if (pthread_create(&philo[i].thr, NULL, start, (void *)&philo[i]))
			return (1);
		if (pthread_detach(philo[i].thr))
			return (1);
		i++;
	}
	return (0);
}
