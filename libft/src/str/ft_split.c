/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:51:39 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/26 14:19:21 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	count_subchain(char *s, char c)
{
	unsigned int	count;
	size_t			i;
	int				is_separator;

	is_separator = 1;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && is_separator)
			count++;
		is_separator = (c == s[i]);
		i++;
	}
	return (count);
}

static char	*create_subchain(char *s, char c)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = 0;
	str = NULL;
	while (s[len] && s[len] != c)
		len++;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	create_strs(char const *s, char **strs, char c)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			strs[j] = create_subchain((char *)&s[i], c);
			if (strs[j] == NULL)
				return (ft_free2d(strs), 0);
			j++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	strs[j] = NULL;
	return (1);
}

char	**ft_split(char *s, char c)
{
	char	**strs;
	size_t	len_subchain;

	if (s == NULL)
		return (NULL);
	len_subchain = count_subchain((char *)s, c);
	if (len_subchain < 1)
		return (NULL);
	strs = (char **)malloc((len_subchain + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	if (!create_strs(s, strs, c))
		ft_free2d(strs);
	return (strs);
}

// int	main(int ac, char **av)
// {
// 	char **split;

// 	if (ac == 3)
// 	{
// 		split = ft_split(av[1], av[2][0]);
// 	}
// 	ft_free2d(&split);
// 	return (0);
// }
