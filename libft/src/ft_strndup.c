/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:53:30 by ttrave            #+#    #+#             */
/*   Updated: 2024/01/19 16:55:35 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dst;
	size_t	lim;
	size_t	i;

	dst = malloc((n + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	dst[n] = '\0';
	lim = n / sizeof(size_t);
	i = 0;
	while (i < lim)
	{
		((size_t *)dst)[i] = ((size_t *)s)[i];
		i++;
	}
	i *= sizeof(size_t);
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	return (dst);
}
