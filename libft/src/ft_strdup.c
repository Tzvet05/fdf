/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:59:39 by ttrave            #+#    #+#             */
/*   Updated: 2023/10/31 18:04:47 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	i;
	size_t	lim;

	i = 0;
	while (s[i])
		i++;
	dst = malloc((i + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	dst[i] = '\0';
	lim = i / sizeof(size_t);
	i = 0;
	while (i < lim)
	{
		((size_t *)dst)[i] = ((size_t *)s)[i];
		i++;
	}
	i *= sizeof(size_t);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	return (dst);
}
