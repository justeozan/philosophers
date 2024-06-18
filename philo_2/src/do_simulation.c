/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:38:24 by ozasahin          #+#    #+#             */
/*   Updated: 2024/06/18 11:25:29 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*lone_philo(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	wait_all_threads(philos->law);
	set_mtxlong(&philos->philo_lock, &philos->last_meal, get_time());
	increase_long(&philos->law->law_mutex, &philos->law->nbr_threads_runnings);
	print_message(philos->law, "has taken a fork", philos->id);
	// while (!dead_loop(philos->law))get_mtxbool(&law->law_mutex, &law->dead_flag)
	while (!get_mtxbool(&philos->law->law_mutex, &philos->law->dead_flag))
		precise_sleep(philos->law, 200);
	return (NULL);
}

// bool	dead_loop(t_law *law)
// {
// 	return (get_mtxbool(&law->law_mutex, &law->dead_flag));
// }

static void	pre_desynchronize(t_philos *philo)
{
	if (philo->id % 2 == 0)
		precise_sleep(philo->law, 0.9 * philo->law->time_to_sleep);
}

static void	keep_desynchronize(t_philos *philos)
{
	long	t_die;
	long	t_loop;
	
	t_die = philos->law->time_to_die;
	t_loop = philos->law->time_to_eat + philos->law->time_to_sleep;
	// printf(" id : %d think %ld\n",philos->id, (t_die - t_loop) - 50 );
	// fflush(stdout);
	if (t_die > t_loop + 50)
		ms_sleep((t_die - t_loop) - 50);
	// printf(" id : %d do not think anymore\n",philos->id);
	// fflush(stdout);
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
	// while (!dead_loop(law))get_mtxbool(philos->law->law_mutex, philos->law->dead_flag)
	while (!get_mtxbool(&law->law_mutex, &law->dead_flag))
	{
		eat(philos);
		dream(law, philos);
		think(law, philos, false);
		if (law->nbr_philos % 2 != 0)
			keep_desynchronize(philos);
	}
	return (pointer);
}

void	do_simulation(t_law *law, t_philos *philos, t_mutex *forks)
{
	pthread_t	observator;
	int			i;

	i = 0;
	if (law->max_meals == 0)
		return (close_program(law, forks, philos));
	else if (law->nbr_philos == 1)
		thread_handler(&law->philos[i], LONE_PHILO);
	else
	{
		while (i < law->nbr_philos)
		{
			thread_handler(&law->philos[i], CREATE);
			i++;
		}
	}
	pthread_create(&observator, NULL, monitor, law);
	set_mtxlong(&law->law_mutex, &law->start_time, get_time());
	set_mtxbool(&law->law_mutex, &law->thread_ready, true);
	pthread_join(observator, NULL);
	close_program(law, forks, philos);
}
