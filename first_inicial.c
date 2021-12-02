/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_inicial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:13:18 by gbrittan          #+#    #+#             */
/*   Updated: 2021/08/15 19:13:20 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_strc *strc, t_philo *philo)
{
	pthread_mutex_destroy(strc->mutex);
	pthread_mutex_destroy(&strc->flag);
	free(strc->mutex);
	free(philo);
}

int	mutex_inicial(t_strc *strc)
{
	int	i;

	i = 0;
	strc->mutex = malloc(sizeof (pthread_mutex_t) * strc->philo_count);
	if (!strc->mutex)
		return (1);
	while (i < strc->philo_count)
	{
		pthread_mutex_init(&strc->mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&strc->flag, NULL);
	return (0);
}

t_philo	*philo_inicial(t_strc *strc)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof (t_philo) * strc->philo_count);
	if (!philo)
		return (NULL);
	while (i < strc->philo_count)
	{
		philo[i].strc = strc;
		philo[i].flag = &strc->flag;
		philo[i].num = i + 1;
		philo[i].l_fork = &(strc->mutex[i]);
		philo[i].start_time = ft_get_time();
		philo[i].eat_time = ft_get_time();
		philo[i].eat_status = 0;
		if (philo[i].num == strc->philo_count)
			philo[i].r_fork = &(strc->mutex[0]);
		else
			philo[i].r_fork = &(strc->mutex[i + 1]);
		i++;
	}
	return (philo);
}

int	first_inicial(t_strc *strc)
{
	t_philo	*philo;

	if (mutex_inicial(strc))
		return (1);
	philo = philo_inicial(strc);
	if (!philo)
		return (1);
	if (threads_init(philo))
		return (1);
	if (watching(philo))
		return (1);
	free_all(strc, philo);
	return (0);
}
