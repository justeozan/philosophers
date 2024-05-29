/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:08:44 by ozasahin          #+#    #+#             */
/*   Updated: 2024/05/28 13:09:06 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	close_program(t_law *law, t_mutex *forks, t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < law->nbr_philos)
	{
		thread_handle(&philos[i], JOIN);
		mutex_handle(&philos[i].philo_lock, DESTROY);
	}
	mutex_handle(&law->write_lock, DESTROY);
	mutex_handle(&law->law_mutex, DESTROY);
	i = -1;
	while (++i < law->nbr_philos)
		mutex_handle(&forks[i], DESTROY);
	free_data(&law, &philos, &forks);
}
