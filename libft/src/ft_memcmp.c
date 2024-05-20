/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:42:28 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/26 15:52:12 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	size_t	lim;

	i = 0;
	lim = n / sizeof(size_t);
	while (i < lim && ((size_t *)s1)[i] == ((size_t *)s2)[i])
		i++;
	i *= sizeof(size_t);
	while (i < n - 1
		&& ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
