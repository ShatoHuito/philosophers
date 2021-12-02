/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:15:42 by gbrittan          #+#    #+#             */
/*   Updated: 2021/08/15 19:17:29 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_strc	strc;

	if (first_pars(argc, argv, &strc))
		return (1);
	if (first_inicial(&strc))
		return (1);
	return (0);
}
