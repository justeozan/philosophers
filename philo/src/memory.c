/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:00:30 by ozasahin          #+#    #+#             */
/*   Updated: 2024/06/11 13:53:34 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	free_data(t_law **law, t_philos **philos, t_mutex **forks)
{
	if (*forks)
		free(*forks);
	if (*law)
		free(*law);
	if (*philos)
		free(*philos);
}
