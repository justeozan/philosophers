/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:03:58 by ozasahin          #+#    #+#             */
/*   Updated: 2024/05/27 11:27:27 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*=== Color ===*/

# define RED	"\e[0;31m"
# define WHITE	"\x1b[37;1m"
# define RESET	"\x1b[0m"
# define GREEN	"\e[0;32m"

/*=== Error messages ===*/

# define ERR_MALLOC "Error: Memory allocation failed with malloc.\n"
# define ERR_PHILO_NBR "Invalid philosophers number\n"
# define ERR_TIME_DIE "Invalid time to die\n"
# define ERR_TIME_EAT  "Invalid time to eat\n"
# define ERR_TIME_SLEEP "Invalid time to sleep\n"
# define ERR_TIME_EAT_PER_PHILO "Invalid number of times \
each philosopher must eat\n"
# define ERR_ARG_NBR "Error: Invalid number of arguments\n"

/*=== Initial values ===*/

# define PHILO_MAX 200

/*=== Structures prototypes ===*/

typedef struct s_philos	t_philos;
typedef struct s_law	t_law;
typedef pthread_mutex_t	t_mutex;

/*=== Structures ===*/

/* this structure create philos and store information for each philos.*/
typedef struct s_philos
{
	pthread_t	thread;
	int			id;
	t_mutex		philo_lock;
	t_mutex		*first_fork;
	t_mutex		*second_fork;
	t_law		*law;
}	t_philos;

/* This structure contain all laws of this projects.*/
typedef struct s_law
{
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_philos;
	long		max_meals;
	long		start_time;
	long		nbr_threads_runnings;
	t_mutex		law_mutex;
	t_mutex		write_lock;
	t_philos	*philos;
}	t_law;

/*=== Functions ===*/

/*---------- main ----------*/

int		main(int ac, char **av);

/*---------- memory ----------*/

void	free_data(t_law **law, t_philos **philos, t_mutex **forks);
void	*ft_calloc(size_t nmemb, size_t size);
int		init_structs(t_law **law, t_philos **philos, t_mutex **forks, \
	int nbr_philo);

#endif
