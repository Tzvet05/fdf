/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:23:19 by ttrave            #+#    #+#             */
/*   Updated: 2023/10/31 16:42:03 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	void			*ptr;
	unsigned char	c_comp;
	unsigned char	*s_comp;

	i = 0;
	ptr = 0;
	c_comp = (unsigned char)c;
	s_comp = (unsigned char *)s;
	while (s_comp[i] != c_comp && i < n - 1)
		i++;
	if (n > 0 && s_comp[i] == c_comp)
		ptr = (void *)&s[i];
	return (ptr);
}
