/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:26:57 by ttrave            #+#    #+#             */
/*   Updated: 2023/10/30 15:04:50 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	size_t	lim;

	i = 0;
	lim = n / sizeof(size_t);
	while (i < lim)
	{
		((size_t *)s)[i] = 0;
		i++;
	}
	i *= sizeof(size_t);
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
