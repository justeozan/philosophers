/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:30:19 by ozasahin          #+#    #+#             */
/*   Updated: 2024/05/29 15:42:06 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	thread_handler(t_philos *philos, t_code code)
{
	if (CREATE == code)
		pthread_create(&(philos->thread), NULL, &diner_loop, philos);
	else if (CREATE == code)
		pthread_create(&(philos->thread), NULL, &lone_philo, philos);
	else if (CREATE == code)
		pthread_join(philos->thread, NULL);
	else if (CREATE == code)
		pthread_detach(philos->thread);
}

void	wait_all_threads(t_law *law)
{
	while (!get_mtxbool(&law->law_mutex, &law->thread_ready))
		;
}
