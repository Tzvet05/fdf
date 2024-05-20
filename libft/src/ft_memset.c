/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:56:51 by ttrave            #+#    #+#             */
/*   Updated: 2023/11/23 18:35:00 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	size_t	lim;
	size_t	constant;

	c = (unsigned char)c;
	constant = (size_t)c + ((size_t)c << 8) + ((size_t)c << 16)
		+ ((size_t)c << 24) + ((size_t)c << 32) + ((size_t)c << 40)
		+ ((size_t)c << 48) + ((size_t)c << 56);
	i = 0;
	lim = n / sizeof(size_t);
	while (i < lim)
	{
		((size_t *)s)[i] = constant;
		i++;
	}
	i *= sizeof(size_t);
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}
