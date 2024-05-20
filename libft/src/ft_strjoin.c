/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:03:29 by ttrave            #+#    #+#             */
/*   Updated: 2023/11/04 14:19:07 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	l_s1;
	size_t	l_s2;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	new_str = malloc((l_s1 + l_s2 + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[l_s1 + l_s2] = '\0';
	ft_memcpy(new_str, s1, l_s1);
	ft_memcpy(&new_str[l_s1], s2, l_s2);
	return (new_str);
}
