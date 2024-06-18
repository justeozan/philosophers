/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sei <sei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:00:30 by ozasahin          #+#    #+#             */
/*   Updated: 2024/06/14 21:24:04 by sei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// void	free_data(t_law **law, t_philos **philos, t_mutex **forks)
// {
// 	if (*forks)
// 		free(*forks);
// 	if (*law)
// 		free(*law);
// 	if (*philos)
// 		free(*philos);
// }

void	free_data(t_law **law, t_philos **philos)
{
	if ((*law)->forks)
		free((*law)->forks);
	if ((*law)->forks_mtx)
		free((*law)->forks_mtx);
	if (*law)
		free(*law);
	if (*philos)
		free(*philos);
}