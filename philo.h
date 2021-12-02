/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:17:34 by gbrittan          #+#    #+#             */
/*   Updated: 2021/08/15 19:17:35 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define FORK	1
# define EAT	2
# define SLEEP	3
# define THINK	4
# define DIE	5
# define FULL 	6

typedef struct s_strc
{
	int				philo_count;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_count;
	int				start;
	int				died;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	flag;
}		t_strc;

typedef struct s_philo
{
	int				num;
	int				eat_status;
	pthread_t		thr;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*flag;
	t_strc			*strc;
	long			eat_time;
	long			start_time;
}		t_philo;

int		first_pars(int argc, char **argv, t_strc *strc);
int		ft_atoi(const char *str);
int		first_inicial(t_strc *strc);
long	ft_get_time(void);
int		threads_init(t_philo *philo);
void	ft_sleep(uint64_t ms);
int		print_status(t_philo *ph, int status);
int		watching(t_philo *ph);

#endif //MY_PHILO_PHILO_H
