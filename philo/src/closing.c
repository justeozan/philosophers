/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:08:44 by ozasahin          #+#    #+#             */
/*   Updated: 2024/05/29 15:06:10 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	close_program(t_law *law, t_mutex *forks, t_philos *philos)
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
		mutex_handle(&forks[i], DESTROY);
	free_data(&law, &philos, &forks);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	print_err(char *err_msg)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(err_msg, 2);
	ft_putstr_fd(RESET, 2);
}
