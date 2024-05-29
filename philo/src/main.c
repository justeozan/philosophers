/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:04:44 by ozasahin          #+#    #+#             */
/*   Updated: 2024/05/28 13:15:58 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	mutex_handle(t_mutex *mutex, t_code mutex_code)
{
	if (LOCK == mutex_code)
		pthread_mutex_lock(mutex);
	else if (UNLOCK == mutex_code)
		pthread_mutex_unlock(mutex);
	else if (INIT == mutex_code)
		pthread_mutex_init(mutex, NULL);
	else if (DESTROY == mutex_code)
		pthread_mutex_destroy(mutex);
}

int	main(int ac, char **av)
{
	t_law		*law;
	t_philos	*philos;
	t_mutex		*forks;

	if (args_no_valid(ac, av))
		return (EXIT_FAILURE);
	if (!init_structs(&law, &philos, &forks, ft_atol(av[1])))
		return (print_err(ERR_MALLOC), EXIT_FAILURE);
	init_law(law, philos, av);
	init_forks(forks, law->nbr_philos);
	init_philos(philos, law, forks);
	do_simulation(law, philos, forks);
	return (0);
}
