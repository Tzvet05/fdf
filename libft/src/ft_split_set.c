/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:00:21 by ttrave            #+#    #+#             */
/*   Updated: 2023/11/07 13:32:31 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_cut_set(char **splitted, char const *s, char *set,
	size_t i_split)
{
	size_t	i;

	i = 0;
	while (s[i] && !ft_in(s[i], set))
		i++;
	splitted[i_split] = malloc((i + 1) * sizeof(char));
	if (!splitted[i_split])
	{
		ft_free_arr((void **)splitted);
		return (NULL);
	}
	splitted[i_split][i] = '\0';
	i = 0;
	while (s[i] && !ft_in(s[i], set))
	{
		splitted[i_split][i] = s[i];
		i++;
	}
	return (splitted);
}

static size_t	ft_count_strs_set(char const *s, char *set)
{
	size_t	i;
	size_t	n_strs;

	i = 0;
	n_strs = 0;
	while (s[i])
	{
		if (s[i] && !ft_in(s[i], set) && (i == 0 || ft_in(s[i - 1], set)))
			n_strs++;
		i++;
	}
	return (n_strs);
}

char	**ft_split_set(char const *s, char *set)
{
	char	**splitted;
	size_t	i;
	size_t	i_split;
	size_t	n_strs;

	i = 0;
	i_split = 0;
	n_strs = ft_count_strs_set(s, set);
	splitted = malloc((n_strs + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	splitted[n_strs] = NULL;
	while (s[i])
	{
		if (s[i] && !ft_in(s[i], set) && (i == 0 || ft_in(s[i - 1], set)))
		{
			splitted = ft_cut_set(splitted, &s[i], set, i_split);
			if (!splitted)
				return (NULL);
			i_split++;
		}
		i++;
	}
	return (splitted);
}
