/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:00:14 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/26 15:47:59 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_in(const char c, const char *set)
{
	size_t	i;
	char	c_set;

	i = 0;
	c_set = set[0];
	while (c_set)
	{
		if (c_set == c)
			return (1);
		i++;
		c_set = set[i];
	}
	return (0);
}
