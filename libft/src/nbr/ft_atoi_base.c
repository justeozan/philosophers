/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:24:56 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/28 15:39:07 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	verif(char *b, int lb)
{
	int	i;
	int	j;

	if (lb < 2)
		return (1);
	i = 0;
	while (b[i])
	{
		j = 0;
		while (b[j])
		{
			if ((b[i] == b[j] && i != j)
				|| b[j] == '+' || b[j] == '-'
				|| !(b[j] >= 32 && b[j] <= 126))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	char_in_base(char c, char *b)
{
	int	i;

	i = -1;
	while (b[++i])
		if (b[i] == c)
			return (1);
	return (0);
}

int	ft_pow(int lb, int p)
{
	int	nbr;

	nbr = lb;
	if (p == 0)
		return (1);
	while (p > 1)
	{
		lb *= nbr;
		p--;
	}
	return (lb);
}

int	change_base(char *str, char *b, int i, int j)
{
	int	index;
	int	power;
	int	nb;
	int	lb;

	lb = 0;
	while (b[lb])
		lb++;
	power = 0;
	nb = 0;
	while (j >= i)
	{
		index = 0;
		while (str[j] != b[index])
			index++;
		nb += index * ft_pow(lb, power);
		power++;
		j--;
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	if (!str)
		return (-1);
	while (base[i])
		i++;
	if (verif(base, i) == 1)
		return (0);
	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	j = 0;
	while (char_in_base(str[i + j], base) == 1)
		j++;
	return (change_base(str, base, i, i + j - 1) * sign);
}
