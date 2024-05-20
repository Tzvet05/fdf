/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:11:44 by ttrave            #+#    #+#             */
/*   Updated: 2023/10/31 17:51:48 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	ptr = 0;
	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		while (big[i + j] == little[j]
			&& little[j] && big[i + j] && i + j < len)
			j++;
		if (little[j] == '\0')
		{
			ptr = (char *)&big[i];
			return (ptr);
		}
		j = 0;
		i++;
	}
	return (ptr);
}
