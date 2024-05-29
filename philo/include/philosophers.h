/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:03:58 by ozasahin          #+#    #+#             */
/*   Updated: 2024/05/28 15:56:09 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
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

/*=== Enumerations ===*/

/* define status code to manage mutex and thread errors */
typedef enum e_code
{
	JOIN,
	CREATE,
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
	DETACH,
	LONE_PHILO
}	t_code;

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
	bool		is_full;
	long		last_meal;
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
	bool		dead_flag;
	bool		thread_ready;
	t_mutex		law_mutex;
	t_mutex		write_lock;
	t_philos	*philos;
}	t_law;

/*=== Functions ===*/

/*---------- check_args ----------*/

int	args_no_valid(int ac, char **av);

/*---------- closing ----------*/

void	close_program(t_law *law, t_mutex *forks, t_philos *philos);

/*---------- do_simulation ----------*/

void	*lone_philo(void *arg);
bool	dead_loop(t_law *law);
void	*diner_loop(void *pointer);
void	do_simulation(t_law *law, t_philos *philos, t_mutex *forks);

/*---------- init ----------*/

void	init_law(t_law *law, t_philos *philos, char **av);
void	init_forks(t_mutex *forks, int nbr_philos);
void	init_philos(t_philos *philos, t_law *law, t_mutex *forks);

/*---------- main ----------*/

int		main(int ac, char **av);

/*---------- memory ----------*/

void	free_data(t_law **law, t_philos **philos, t_mutex **forks);
void	*ft_calloc(size_t nmemb, size_t size);
int		init_structs(t_law **law, t_philos **philos, t_mutex **forks, \
	int nbr_philo);

/*---------- monitor ----------*/

void	last_print(t_law *law, int id);
bool	is_end_condition(t_law *law);
bool	all_threads_running(t_mutex *mutex, long *threads, long nbr_philos);
void	*monitor(void *pointer);

/*---------- monitor ----------*/

void	thread_handler(t_philos *philos, t_code code);
void	wait_all_threads(t_law *law);

#endif
