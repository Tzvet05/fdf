/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:32:59 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/28 13:53:11 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_in_set(const char *set, const char *str)
{
	size_t	i_str;
	size_t	i_set;
	char	c_str;
	char	c_set;

	i_str = 0;
	c_str = str[0];
	while (c_str)
	{
		i_set = 0;
		c_set = set[0];
		while (c_set)
		{
			if (c_str == c_set)
				return (1);
			i_set++;
			c_set = set[i_set];
		}
		i_str++;
		c_str = str[i_str];
	}
	return (0);
}
