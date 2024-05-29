/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:14:58 by ozasahin          #+#    #+#             */
/*   Updated: 2024/05/29 15:47:43 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static bool	is_over_max_or_empty(char *content)
{
	int		len;
	long	value;

	len = ft_strlen(content);
	if (len > 10 || len == 0)
		return (true);
	value = ft_atol(content);
	if (value > INT_MAX || value < INT_MIN)
		return (true);
	return (false);
}

static bool	check_content(char *content)
{
	if (is_over_max_or_empty(content))
		return (false);
	if (!is_digit(content))
		return (false);
	return (true);
}

static bool	check_syntax_and_size(char **av)
{
	if (ft_atol(av[1]) > PHILO_MAX || ft_atol(av[1]) <= 0
		|| !check_content(av[1]))
		return (print_err(ERR_PHILO_NBR), false);
	if (!check_content(av[2]))
		return (print_err(ERR_TIME_DIE), false);
	if (!check_content(av[3]))
		return (print_err(ERR_TIME_EAT), false);
	if (!check_content(av[4]))
		return (print_err(ERR_TIME_SLEEP), false);
	if (av[5] && !check_content(av[5]))
		return (print_err(ERR_TIME_EAT_PER_PHILO), false);
	return (true);
}

int	args_no_valid(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (print_err(ERR_ARG_NBR), false);
	if (!check_syntax_and_size(av))
		return (false);
	return (true);
}
