/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:31:50 by ttrave            #+#    #+#             */
/*   Updated: 2023/11/05 16:34:49 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	l_str;
	char	*new_str;

	i = 0;
	l_str = ft_strlen(s);
	new_str = malloc((l_str + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s, l_str + 1);
	while (new_str[i])
	{
		new_str[i] = f(i, new_str[i]);
		i++;
	}
	return (new_str);
}
