/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:04:44 by ozasahin          #+#    #+#             */
/*   Updated: 2024/06/18 15:54:28 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	close_program(t_law *law, t_mutex *forks_mtx, t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < law->nbr_philos)
	{
		thread_handler(&philos[i], JOIN);
		mutex_handle(&philos[i].philo_lock, DESTROY);
	}
	mutex_handle(&law->write_lock, DESTROY);
	mutex_handle(&law->law_mutex, DESTROY);
	i = -1;
	while (++i < law->nbr_philos)
		mutex_handle(&forks_mtx[i], DESTROY);
	// free_data(&law, &philos, &forks);
	free_data(law);
}

static bool	is_over_max_or_empty(char *content)
{
	int		len;
	long	value;

	len = ft_strlen(content);
	if (len > 10 || len == 0)
		return (true);
	value = ft_atol(content);
	if (value > INT_MAX || value < INT_MIN)
		return (true);
	return (false);
}

static bool	check_content(char *content)
{
	if (is_over_max_or_empty(content))
		return (false);
	if (!is_digit(content))
		return (false);
	return (true);
}

static bool	check_syntax_and_size(char **av)
{
	if (ft_atol(av[1]) > PHILO_MAX || ft_atol(av[1]) <= 0
		|| !check_content(av[1]))
		return (printf(RED ERR_PHILO_NBR RESET), false);
	if (!check_content(av[2]))
		return (printf(RED ERR_TIME_DIE RESET), false);
	if (!check_content(av[3]))
		return (printf(RED ERR_TIME_EAT RESET), false);
	if (!check_content(av[4]))
		return (printf(RED ERR_TIME_SLEEP RESET), false);
	if (av[5] && !check_content(av[5]))
		return (printf(RED ERR_TIME_EAT_PER_PHILO RESET), false);
	return (true);
}

// static void	initialize_ptr_to_null(t_law *law, t_philos *philos)
// {
// 	philos->first_fork = NULL;
// 	philos->second_fork = NULL;
// 	philos->right_fork = NULL;
// 	philos->left_fork = NULL;
// 	law->forks = NULL;
// 	law->forks_mtx = NULL;
// 	law->philos = NULL;
// }

// int	main2(int ac, char **av)
// {
// 	t_law		*law;
// 	t_philos	*philos;
// 	// t_mutex		*forks;

// 	law = NULL;
// 	philos = NULL;
// 	initialize_ptr_to_null(law, philos);
// 	if (ac != 5 && ac != 6)
// 		return (printf(RED ERR_ARG_NBR RESET), EXIT_FAILURE);
// 	if (!check_syntax_and_size(av))
// 		return (EXIT_FAILURE);
// 	// if (!init_structs(&law, &philos, &forks, ft_atol(av[1])))
// 	// if (!init_structs(&law, &philos, &law->forks, ft_atol(av[1])))
// 	if (!init_law3(&law, &philos, av, ft_atol(av[1])))
// 		return (printf(RED ERR_MALLOC RESET), EXIT_FAILURE);
// 	// init_law(law, philos, av);
// 	init_forks(law->forks, law->nbr_philos);
// 	init_philos(philos, law, law->forks);
// 	// do_simulation(law, philos, law->forks_mtx, law->forks);
// 	do_simulation(law, philos, law->forks_mtx);
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_law	law;

	if (ac != 5 && ac != 6)
		return (printf(RED ERR_ARG_NBR RESET), EXIT_FAILURE);
	if (!check_syntax_and_size(av))
		return (EXIT_FAILURE);
	if (!initialize_data(&law, ft_atol(av[1]), av))
		return (printf(RED ERR_MALLOC RESET), EXIT_FAILURE);
	
	// free_data(&law);
	return (0);
}