/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:01:22 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/05 18:38:40 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	puterr(char *str1, char *str2)
{
	write(2, "fdf : ", 6);
	write(2, str1, ft_strlen(str1));
	if (str2)
	{
		write(2, " : ", 3);
		write(2, str2, ft_strlen(str2));
	}
	write(2, "\n", 1);
}

void	free_arr_dim(void **arr, size_t len, void (*del)(void *))
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		del(arr[i]);
		i++;
	}
	free(arr);
}
