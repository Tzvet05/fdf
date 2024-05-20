/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:22:49 by ttrave            #+#    #+#             */
/*   Updated: 2023/11/05 16:43:51 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*src2;
	char		*dest2;

	i = 0;
	src2 = (const char *)src;
	dest2 = (char *)dest;
	if (src >= dest)
	{
		while (i < n)
		{
			dest2[i] = src2[i];
			i++;
		}
		return (dest);
	}
	i = n;
	while (i > 0)
	{
		dest2[i - 1] = src2[i - 1];
		i--;
	}
	return (dest);
}
