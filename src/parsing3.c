/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:55:58 by ttrave            #+#    #+#             */
/*   Updated: 2024/04/09 13:56:24 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	is_point(char *line, size_t *i_start)
{
	size_t	i;
	long	nbr;

	i = 0;
	nbr = 0;
	if (!ft_isdigit(line[i]) && line[i] != '-' && line[i] != '+')
		return (0);
	while (line[i] == '-' || line[i] == '+')
		i++;
	if (!ft_isdigit(line[i]))
		return (0);
	while (ft_isdigit(line[i]))
		i++;
	if (ft_strncmp(&line[i], ",0x", 3) || ft_strncmp(&line[i], ",0X", 3))
		i += 3;
	else
	{
		*i_start += i - 1;
		return (1);
	}
	while (ft_in(ft_tolower(line[i]), HEXA_LOW))
		i++;
	*i_start += i - 1;
	return (1);
}
