/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:58:49 by ozasahin          #+#    #+#             */
/*   Updated: 2024/06/18 11:40:03 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	last_print(t_law *law, int id)
{
	long long	time;

	mutex_handle(&law->write_lock, LOCK);
	time = get_time() - law->start_time;
	printf(RED"%lld %d died\n"RESET, time, id);
	mutex_handle(&law->write_lock, UNLOCK);
}

bool	is_end_condition(t_law *law)
{
	t_philos	*philos;
	bool		is_dead;
	int			nb_full;
	int			i;

	i = -1;
	philos = law->philos;
	nb_full = 0;
	is_dead = false;
	while (++i < law->nbr_philos && is_dead == false)
	{
		set_mtxbool(&(philos[i].philo_lock), &is_dead,
			get_elapsed_time_ms(get_mtxlong(&(philos[i].philo_lock),
					&philos[i].last_meal)) >= law->time_to_die);
		if (get_mtxbool(&(philos[i].philo_lock), &philos[i].is_full))
			nb_full++;
		if (is_dead == true || nb_full == law->nbr_philos)
		{
			set_mtxbool(&law->law_mutex, &law->dead_flag, true);
			if (is_dead)
				last_print(law, philos[i].id);
		}
	}
	return (is_dead || (nb_full == law->nbr_philos));
}

bool	all_threads_running(t_mutex *mutex, long *threads, long nbr_philos)
{
	bool	ret;

	ret = false;
	mutex_handle(mutex, LOCK);
	if (*threads == nbr_philos)
		ret = true;
	mutex_handle(mutex, UNLOCK);
	return (ret);
}

void	*monitor(void *pointer)
{
	t_law	*law;

	law = (t_law *)pointer;
	while (!all_threads_running(&law->law_mutex, &law->nbr_threads_runnings,
			law->nbr_philos))
		usleep(1000);
	usleep(5000);
	while (!is_end_condition(law))
	{
		usleep(3000);
	}
	return (NULL);
}
