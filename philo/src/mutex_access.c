/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:36:31 by ozasahin          #+#    #+#             */
/*   Updated: 2024/05/29 16:13:22 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	set_mtxlong(t_mutex *mutex, long *to_set, long value)
{
	mutex_handle(mutex, LOCK);
	*to_set = value;
	mutex_handle(mutex, UNLOCK);
}

void	set_mtxbool(t_mutex *mutex, bool *to_set, bool value)
{
	mutex_handle(mutex, LOCK);
	*to_set = value;
	mutex_handle(mutex, UNLOCK);
}

long	get_mtxlong(t_mutex *mutex, long *to_get)
{
	long	ret;

	mutex_handle(mutex, LOCK);
	ret = *to_get;
	mutex_handle(mutex, UNLOCK);
	return (ret);
}

bool	get_mtxbool(t_mutex *mutex, bool *to_get)
{
	bool	ret;

	mutex_handle(mutex, LOCK);
	ret = *to_get;
	mutex_handle(mutex, UNLOCK);
	return (ret);
}

void	increase_long(t_mutex *mutex, long *value)
{
	mutex_handle(mutex, LOCK);
	(*value)++;
	mutex_handle(mutex, UNLOCK);
}
