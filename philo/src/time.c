/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:10:25 by ozasahin          #+#    #+#             */
/*   Updated: 2024/06/18 11:29:41 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	get_elapsed_time_ms(long timestamp_start)
{
	return (get_time() - timestamp_start);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	precise_sleep(t_law *law, long ms)
{
	long	start_time;

	start_time = get_time();
	(void)law;
	while ((get_time() - start_time) < ms)
		usleep(100);
}

void	ms_sleep(long ms)
{
	fflush(stdout);
	usleep(ms * 1000);
}
