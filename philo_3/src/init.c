/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:50:44 by ozasahin          #+#    #+#             */
/*   Updated: 2024/06/18 10:54:00 by ozasahin         ###   ########.fr       */
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
}

// void	init_forks(t_mutex *forks, int nbr_philos)
void	init_forks(int *forks, int nbr_philos)
{
	memset(forks, 0, nbr_philos * sizeof(int));
	// int	i;

	// i = -1;
	// while (++i < nbr_philos)
		// mutex_handle(&forks[i], INIT);
}

// void	init_philos(t_philos *philos, t_law *law, t_mutex *forks)
void	init_philos(t_philos *philos, t_law *law, int *forks)
{
	int	i;

	i = 0;
	while (i < law->nbr_philos)
	{
		philos[i].id = i + 1;
		philos[i].law = law;
		philos[i].left_fork = &law->forks[i];
		philos[i].second_fork = &law->forks_mtx[i];
		// if (philos[i].id % 2 == 0)
		if (i != law->nbr_philos - 1)
		{
			// philos[i].second_fork = &forks[i];
			// philos[i].first_fork = &forks[(i + 1) % law->nbr_philos];
			philos[i].right_fork = &forks[i + 1];
			philos[i].first_fork = &law->forks_mtx[i + 1];
		}
		else
		{
			// philos[i].first_fork = &forks[i];
			// philos[i].second_fork = &forks[(i + 1) % law->nbr_philos];
			philos[i].right_fork = &forks[0];
			philos[i].first_fork = &law->forks_mtx[0];
		}
		i++;
	}
}

int	init_structs(t_law **law, t_philos **philos, int **forks, int nbr_philo)
{
	*law = (t_law *)ft_calloc(1, sizeof(t_law));
	if (!*law)
		return (false);
	*philos = (t_philos *)ft_calloc(nbr_philo, sizeof(t_philos));
	if (!*philos)
		return (free_data(law, philos), false);
		// return (free_data(law, philos, forks), false);
	(*law)->forks_mtx = (t_mutex *)ft_calloc(nbr_philo, sizeof(t_mutex));
	if (!(*law)->forks_mtx)
		return (free_data(law, philos), false);
		// return (free_data(law, philos, forks), false);
	*forks = (int *)ft_calloc(nbr_philo, sizeof(int));
	if (!*forks)
		return (free_data(law, philos), false);
		// return (free_data(law, philos, **forks), false);
	return (true);
}

// bool	init_law2(t_law *law, t_philos *philos, char **av, int nbr_philo_tmp)
// {
// 	law = (t_law *)ft_calloc(1, sizeof(t_law));
// 	if (!law)
// 		return (false);
// 	philos = (t_philos *)ft_calloc(nbr_philo_tmp, sizeof(t_philos));
// 	if (!philos)
// 		return (free_data(&law, &philos), false);
// 	(law)->forks_mtx = (t_mutex *)ft_calloc(nbr_philo_tmp, sizeof(t_mutex));
// 	if (!law->forks_mtx)
// 		return (free_data(&law, &philos), false);
// 	law->forks = (int *)ft_calloc(nbr_philo_tmp, sizeof(int));
// 	if (!law->forks)
// 		return (free_data(&law, &philos), false);
// 	law->dead_flag = 0;
// 	law->philos = philos;
// 	law->time_to_die = ft_atol(av[2]);
// 	law->time_to_eat = ft_atol(av[3]);
// 	law->time_to_sleep = ft_atol(av[4]);
// 	law->nbr_philos = (int)ft_atol(av[1]);
// 	law->thread_ready = false;
// 	if (av[5])
// 		law->max_meals = (int)ft_atol(av[5]);
// 	else
// 		law->max_meals = -1;
// 	mutex_handle(&law->write_lock, INIT);
// 	mutex_handle(&law->law_mutex, INIT);
// 	return (true);
// }




static int	ft_malloc(void **ptr, size_t size)
{
	*ptr = malloc(size);
	if (!*ptr)
		return (write(2, ERR_MALLOC, 24), 1);
		// return (printf(law, ERR_MALLOC, ));
	return (0);
}


// bool	init_law3(t_law *law, t_philos *philos, char **av, int nbr_philo_tmp)
bool	init_law3(t_law **law, t_philos **philos, char **av, int nbr_philo_tmp)
{
	if (ft_malloc((void **)&law, sizeof(t_law *))
		|| ft_malloc((void **)&philos, sizeof(t_philos) * nbr_philo_tmp)
		|| ft_malloc((void **)&(*law)->forks_mtx, sizeof(t_mutex) * nbr_philo_tmp)
		|| ft_malloc((void **)&(*law)->forks, sizeof(int) * nbr_philo_tmp))
		return (free_data(law, philos), false);
	
	
	(*law)->dead_flag = 0;
	(*law)->philos = *philos;
	(*law)->time_to_die = ft_atol(av[2]);
	(*law)->time_to_eat = ft_atol(av[3]);
	(*law)->time_to_sleep = ft_atol(av[4]);
	(*law)->nbr_philos = (int)ft_atol(av[1]);
	(*law)->thread_ready = false;
	if (av[5])
		(*law)->max_meals = (int)ft_atol(av[5]);
	else
		(*law)->max_meals = -1;
	mutex_handle(&(*law)->write_lock, INIT);
	mutex_handle(&(*law)->law_mutex, INIT);
	return (true);
}



/* ===================== V3 =========================*/

void	init_philos(t_philos *philos, t_law *law, int *forks)
{
	int	i;

	i = 0;
	while (i < law->nbr_philos)
	{
		philos[i].id = i + 1;
		philos[i].law = law;
		philos[i].left_fork = &law->forks[i];
		philos[i].second_fork = &law->forks_mtx[i];
		if (i != law->nbr_philos - 1)
		{
			philos[i].right_fork = &forks[i + 1];
			philos[i].first_fork = &law->forks_mtx[i + 1];
		}
		else
		{
			philos[i].right_fork = &forks[0];
			philos[i].first_fork = &law->forks_mtx[0];
		}
		i++;
	}
}

static void	initialize_ptr_to_null(t_law *law)
{
	law->forks = NULL;
	law->forks_mtx = NULL;
	law->philos = NULL;
}

bool	initialize_data(t_law *law, int nb_philo)
{
	//first part : init ptrs
	initialize_ptr_to_null(law);
	//second part : init_law
	if (ft_malloc((void **)&law, sizeof(t_law *))
		|| ft_malloc((void **)law->forks_mtx, sizeof(t_mutex) * nb_philo)
		|| ft_malloc((void **)law->forks, sizeof(int) * nb_philo))
		return (free_data(law), false);
	// if (!init_philos(law->philos, law, init_forks))
	// 	return (free_data(law), false);
	init_philos(law->philos, law, init_forks);
	init_mutex(law);
	return 0 ;
	
}
