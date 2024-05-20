/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:50:14 by ttrave            #+#    #+#             */
/*   Updated: 2024/04/09 15:48:12 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long	get_number(char *line, size_t *i_start)
{
	long	nbr;
	size_t	i;
	char	sign;
	char	c;

	i = 0;
	sign = 1;
	nbr = 0;
	c = line[0];
	while (c == '-' || c == '+')
	{
		if (c == '-')
			sign = -sign;
		i++;
		c = line[i];
	}
	while (ft_isdigit(c))
	{
		nbr = 10 * nbr + c - 48;
		i++;
		c = line[i];
	}
	*i_start += i;
	return (nbr * sign);
}

inline static size_t	get_index(char c, char *set)
{
	size_t	i;
	char	c_set;

	i = 0;
	c_set = set[0];
	while (c_set)
	{
		if (c_set == c)
			return (i);
		i++;
		c_set = set[i];
	}
	return (i);
}

inline static unsigned int	calculate_color(char *line)
{
	unsigned int	color;
	size_t			i;
	size_t			len;

	color = 0;
	i = 0;
	len = 0;
	while (ft_in(ft_tolower(line[len]), HEXA_LOW))
		len++;
	while (i < len && i < 8)
	{
		color |= (get_index(ft_tolower(line[len - i - 1]),
					HEXA_LOW) << (4 * i));
		i++;
	}
	if (len < 7)
		color |= MAX_AA;
	return (color);
}

unsigned int	get_color(char *line, size_t *i_start)
{
	unsigned int	color;
	size_t			i;

	if (!ft_strncmp(line, ",0x", 3) && !ft_strncmp(line, ",0X", 3))
		return (WHITE);
	i = 3;
	color = calculate_color(&line[i]);
	while (ft_in(ft_tolower(line[i]), HEXA_LOW))
		i++;
	*i_start += i;
	return (color);
}

size_t	count_points(char *line)
{
	size_t	count;
	size_t	i;

	if (!line)
		return (0);
	count = 0;
	i = 0;
	while (line[i])
	{
		if (is_point(&line[i], &i))
			count++;
		i++;
	}
	return (count);
}
