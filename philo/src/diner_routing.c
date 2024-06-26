/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_routing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:53:19 by ozasahin          #+#    #+#             */
/*   Updated: 2024/06/26 13:14:03 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_message(t_law *law, char *msg, int id)
{
	long	time;

	mutex_handle(&law->write_lock, LOCK);
	time = get_time() - law->start_time;
	if (!get_mtxbool(&law->law_mutex, &law->dead_flag))
		printf(GREEN"%ld %d %s\n"RESET, time, id, msg);
	mutex_handle(&law->write_lock, UNLOCK);
}

void	think(t_law *law, t_philos *philos, bool pre_sim)
{
	long	time_eat;
	long	time_sleep;
	long	time_think;

	if (pre_sim == false)
		print_message(law, "is thinking", philos->id);
	if (law->nbr_philos % 2 == 0)
		return ;
	time_eat = law->time_to_eat;
	time_sleep = law->time_to_sleep;
	time_think = (time_eat * 2) - time_sleep;
	if (time_think < 0)
		time_think = 0;
	precise_sleep(law, time_think * 0.10);
}

void	dream(t_law *law, t_philos *philos)
{
	print_message(law, "is sleeping", philos->id);
	precise_sleep(law, law->time_to_sleep);
}

void	eat(t_law *law, t_philos *philos)
{
	while (get_mtxbool(&law->forks_mtx[philos->f_fork_id], philos->first_fork)
		|| get_mtxbool(&law->forks_mtx[philos->s_fork_id], philos->second_fork))
		usleep(100);
	set_mtxbool(&law->forks_mtx[philos->f_fork_id], philos->first_fork, true);
	set_mtxbool(&law->forks_mtx[philos->s_fork_id], philos->second_fork, true);
	print_message(philos->law, "has taken a fork", philos->id);
	print_message(philos->law, "has taken a fork", philos->id);
	philos->meals_eaten++;
	set_mtxlong(&philos->philo_lock, &philos->last_meal, get_time());
	print_message(philos->law, "is eating", philos->id);
	precise_sleep(philos->law, philos->law->time_to_eat);
	if (philos->meals_eaten == philos->law->max_meals)
		set_mtxbool(&philos->philo_lock, &philos->is_full, true);
	set_mtxbool(&law->forks_mtx[philos->f_fork_id], philos->first_fork, false);
	set_mtxbool(&law->forks_mtx[philos->s_fork_id], philos->second_fork, false);
}
