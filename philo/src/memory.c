/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:00:30 by ozasahin          #+#    #+#             */
/*   Updated: 2024/05/16 16:06:30 by ozasahin         ###   ########.fr       */
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size != 0 && nmemb > (size_t)(-1) / size)
	{
		return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	return ((void *)memset(ptr, 0, nmemb * size));
}

int	init_structs(t_law **law, t_philos **philos, t_mutex **forks, int nbr_philo)
{
	*law = (t_law *)ft_calloc(1, sizeof(t_law));
	if (!*law)
		return (false);
	*philos = (t_philos *)ft_calloc(nbr_philo, sizeof(t_philos));
	if (!*philos)
		return (free_data(law, philos, forks), false);
	*forks = (t_mutex *)ft_calloc(nbr_philo, sizeof(forks));
	if (!*forks)
		return (free_data(law, philos, forks), false);
	return (true);
}
