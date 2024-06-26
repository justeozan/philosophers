/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:00:30 by ozasahin          #+#    #+#             */
/*   Updated: 2024/06/26 13:58:22 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	free_data(t_law **law, t_philos **philos)
{
	if ((*law)->forks_mtx)
		free((*law)->forks_mtx);
	if (*philos)
		free(*philos);
	if ((*law)->forks)
		free((*law)->forks);
	if (*law)
		free(*law);
}
