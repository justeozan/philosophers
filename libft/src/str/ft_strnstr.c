/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:20:43 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/28 15:40:39 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	ls2;
	size_t	i;
	size_t	j;

	ls2 = ft_strlen(s2);
	if (ls2 == 0)
		return ((char *)s1);
	j = 0;
	while (s1[j] && j < len)
	{
		i = 0;
		while (s1[j + i] == s2[i] && s1[j + i] && i < ls2 && j + i < len)
			i++;
		if (i == ls2)
			return ((char *)&s1[j]);
		j++;
	}
	return (NULL);
}

char	*ft_strnstr_2(char *s1, char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_s1;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	if (!s2[j])
		return ((char *)s1);
	while (s1[i] && i < len_s1)
	{
		j = 0;
		while (s2[j] == s1[i + j] && j < len && i + j < len_s1)
			j++;
		if (j == len)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
