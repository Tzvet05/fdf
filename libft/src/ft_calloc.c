/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:05:49 by ttrave            #+#    #+#             */
/*   Updated: 2023/11/02 16:19:35 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	len_total;
	size_t	i;
	size_t	lim;

	len_total = nmemb * size;
	if (len_total / size != nmemb)
		return (0);
	mem = malloc(len_total);
	if (!mem)
		return (NULL);
	i = 0;
	lim = len_total / sizeof(size_t);
	while (i < lim)
	{
		((size_t *)mem)[i] = 0;
		i++;
	}
	i *= sizeof(size_t);
	while (i < len_total)
	{
		((char *)mem)[i] = 0;
		i++;
	}
	return (mem);
}
