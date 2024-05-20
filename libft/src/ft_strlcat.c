/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:33:10 by ttrave            #+#    #+#             */
/*   Updated: 2023/11/01 11:33:26 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l_dst;
	size_t	l_src;
	size_t	l_dst_origin;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	l_dst = ft_strlen(dst);
	l_dst_origin = l_dst;
	l_src = ft_strlen(src);
	if (size <= l_dst)
		return (l_src + size);
	while (src[i] && size - 1 > l_dst)
	{
		dst[l_dst] = src[i];
		i++;
		l_dst++;
	}
	dst[l_dst] = '\0';
	return (l_src + l_dst_origin);
}
