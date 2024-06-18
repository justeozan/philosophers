/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:00:30 by ozasahin          #+#    #+#             */
/*   Updated: 2024/06/18 15:50:34 by ozasahin         ###   ########.fr       */
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

// void	free_data2(t_law **law, t_philos **philos)
// {
// 	if ((*law)->forks)
// 		free((*law)->forks);
// 	if ((*law)->forks_mtx)
// 		free((*law)->forks_mtx);
// 	if (*law)
// 		free(*law);
// 	if (*philos)
// 		free(*philos);
// }

void	free_data(t_law *law)
{
	if (law->forks)
		free(law->forks);
	if (law->forks_mtx)
		free(law->forks_mtx);
	if (law->philos)
		free(law->philos);
	if (law)
		free(law);
}