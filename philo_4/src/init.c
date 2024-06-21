/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:50:44 by ozasahin          #+#    #+#             */
/*   Updated: 2024/06/21 11:11:54 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_law(t_law *law, t_philos *philos, char **av)
{
	law->dead_flag = 0;
	law->philos = philos;
	law->time_to_die = ft_atol(av[2]);
	law->time_to_eat = ft_atol(av[3]);
	law->time_to_sleep = ft_atol(av[4]);
	law->nbr_philos = (int)ft_atol(av[1]);
	law->thread_ready = false;
	if (av[5])
		law->max_meals = (int)ft_atol(av[5]);
	else
		law->max_meals = -1;
	mutex_handle(&law->write_lock, INIT);
	mutex_handle(&law->law_mutex, INIT);
	// mutex_handle(&law->forks_mtx, INIT);
}

void	init_forks(t_mutex *forks_mtx, int nbr_philos)
{
	int	i;

	i = -1;
	while (++i < nbr_philos)
		mutex_handle(&forks_mtx[i], INIT);
}

// void	init_philos(t_philos *philos, t_law *law, t_mutex *forks)
// {
// 	int	i;

// 	i = 0;
// 	while (i < law->nbr_philos)
// 	{
// 		philos[i].id = i + 1;
// 		philos[i].law = law;
// 		if (philos[i].id % 2 == 0)
// 		{
// 			philos[i].second_fork = &forks[i];
// 			philos[i].first_fork = &forks[(i + 1) % law->nbr_philos];
// 		}
// 		else
// 		{
// 			philos[i].first_fork = &forks[i];
// 			philos[i].second_fork = &forks[(i + 1) % law->nbr_philos];
// 		}
// 		i++;
// 	}
// }

void	init_philos(t_philos *philos, t_law *law, int *forks)
{
	int	i;

	i = 0;
	while (i < law->nbr_philos)
	{
		philos[i].id = i + 1;
		philos[i].law = law;
		philos[i].left_fork = &law->forks[i];
		if (i != law->nbr_philos - 1)
		{
			philos[i].right_fork = &forks[i + 1];
		}
		else
		{
			philos[i].right_fork = &forks[0];
		}
		i++;
	}
}

int	init_structs(t_law **law, t_philos **philos, t_mutex **forks_mtx, int nbr_philo)
{
	*law = (t_law *)ft_calloc(1, sizeof(t_law));
	if (!*law)
		return (false);
	*philos = (t_philos *)ft_calloc(nbr_philo, sizeof(t_philos));
	if (!*philos)
		return (free_data(law, philos, forks_mtx), false);
	*forks_mtx = (t_mutex *)ft_calloc(nbr_philo, sizeof(t_mutex));
	if (!*forks_mtx)
		return (free_data(law, philos, forks_mtx), false);
	(*law)->forks = (int *)ft_calloc(nbr_philo, sizeof(int));
	if (!(*law)->forks)
		return (free_data(law, philos, forks_mtx), false);
	return (true);
}
