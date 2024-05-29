/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:38:24 by ozasahin          #+#    #+#             */
/*   Updated: 2024/05/28 13:07:34 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*lone_philo(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	wait_all_threads(philos->law);
	set_mtxlong(&philos->philo_lock, &philos->law->nbr_threads_runnings);
	print_message(philos->law, "has taken a fork", philos->id);
	while (!dead_loop(philos->law))
		precise_sleep(philos->law, 200);
	return (NULL);
}

bool	dead_loop(t_law *law)
{
	return (get_mtxbool(&law->law_mutex, &law->dead_flag));
}

static void	pre_synchronize(t_philos *philo)
{
	if (philo->id % 2 == 0)
		precise_sleep(philo->law, 0.9 * philo->law->time_to_sleep);
}

void	*diner_loop(void *pointer)
{
	t_philos	*philos;
	t_law		*law;

	philos = (t_philos *)pointer;
	law = philos->law;
	wait_all_threads(law);
	increase_long(&law->law_mutex, &law->nbr_threads_runnings);
	set_mtxlong(&philos->philo_lock, &philos->last_meal, law->start_time);
	pre_desynchronize(philos);
	while (!dead_loop(law))
	{
		eat(philos);
		dream(philos, law);
		think(philos, law, false);
	}
	return (pointer);
}

void	do_simulation(t_law *law, t_philos *philos, t_mutex *forks)
{
	pthread_t	observator;
	int			i;

	if (law->max_meals == 0)
		return (close_program(law, forks, philos));
	else if (law->nbr_philos == 1)
		thread_handle(&law->philos[i], LONE_PHILO);
	else
	{
		while (i < law->nbr_philos)
		{
			thread_handle(&law->philos[i], CREATE);
			i++;
		}
	}
	phtread_create(&observator, NULL, monitor, law);
	set_mtxlong(&law->law_mutex, &law->start_time, get_time());
	set_mtxbool(&law->law_mutex, &law->thread_ready, true);
	pthread_join(observator, NULL);
	close_program(law, forks, philos);
}
