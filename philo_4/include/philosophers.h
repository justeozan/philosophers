/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:03:58 by ozasahin          #+#    #+#             */
/*   Updated: 2024/06/21 11:11:24 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
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
	int			meals_eaten;
	bool		is_full;
	long		last_meal;
	t_mutex		philo_lock;
	t_mutex		*first_fork;
	t_mutex		*second_fork;
	int			*right_fork;
	int			*left_fork;
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
	int			*forks;
	t_mutex		*forks_mtx;
	t_mutex		law_mutex;
	t_mutex		write_lock;
	t_philos	*philos;
}	t_law;

/*=== Functions ===*/

/*---------- do_simulation ----------*/

void	print_message(t_law *law, char *msg, int id);
void	think(t_law *law, t_philos *philos, bool pre_sim);
void	dream(t_law *law, t_philos *philos);
void	eat(t_philos *philos);

/*---------- do_simulation ----------*/

void	*lone_philo(void *arg);
bool	dead_loop(t_law *law);
void	*diner_loop(void *pointer);
void	do_simulation(t_law *law, t_philos *philos, t_mutex *forks);

/*---------- init ----------*/

void	init_law(t_law *law, t_philos *philos, char **av);
void	init_forks(t_mutex *forks, int nbr_philos);
// void	init_philos(t_philos *philos, t_law *law, t_mutex *forks);
void	init_philos(t_philos *philos, t_law *law, int *forks);
int		init_structs(t_law **law, t_philos **philos, t_mutex **forks, \
	int nbr_philo);

/*---------- lft ----------*/

int		is_digit(const char *s);
int		ft_isspace(char c);
int		ft_strlen(char *str);
long	ft_atol(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);

/*---------- main ----------*/

void	close_program(t_law *law, t_mutex *forks, t_philos *philos);
int		main(int ac, char **av);

/*---------- memory ----------*/

void	free_data(t_law **law, t_philos **philos, t_mutex **forks);

/*---------- monitor ----------*/

void	last_print(t_law *law, int id);
bool	is_end_condition(t_law *law);
bool	all_threads_running(t_mutex *mutex, long *threads, long nbr_philos);
void	*monitor(void *pointer);

/*---------- mutex_access ----------*/

void	set_mtxlong(t_mutex *mutex, long *to_set, long value);
void	set_mtxbool(t_mutex *mutex, bool *to_set, bool value);
long	get_mtxlong(t_mutex *mutex, long *to_get);
bool	get_mtxbool(t_mutex *mutex, bool *to_get);
void	increase_long(t_mutex *mutex, long *value);

/*---------- mutex_handler ----------*/

void	mutex_handle(t_mutex *mutex, t_code mutex_code);

/*---------- thread_handler ----------*/

void	thread_handler(t_philos *philos, t_code code);
void	wait_all_threads(t_law *law);

/*---------- time ----------*/

long	get_elapsed_time_ms(long timestamp_start);
long	get_time(void);
void	precise_sleep(t_law *law, long ms);
void	ms_sleep(long ms);

#endif
