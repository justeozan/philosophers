/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:59:37 by ozasahin          #+#    #+#             */
/*   Updated: 2024/05/29 14:59:51 by ozasahin         ###   ########.fr       */
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
