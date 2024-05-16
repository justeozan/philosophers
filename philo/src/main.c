/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:04:44 by ozasahin          #+#    #+#             */
/*   Updated: 2024/05/16 16:45:48 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	args_no_valid(int ac, char **av)
{
	
}

void	init_law(t_law *law, t_philos *philos, char **av)
{
	law->time_to_die = ft_atol(av[2]);
	law->time_to_eat = ft_atol(av[3]);
	law->time_to_sleep = ft_atol(av[4]);
	law->nbr_philos = av[1];
	law->philos = philos;
	if (av[5])
		law->max_meals = av[5];
	
}

void	init_forks(t_mutex *forks, int nbr_philos)
{
	
}

void	init_philos(t_philos *philos, t_law *law, t_mutex *forks)
{
	
}

void	do_simulation(t_law *law, t_philos *philos, t_mutex *forks)
{
	
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
