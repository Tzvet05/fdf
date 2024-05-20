/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 02:52:40 by ttrave            #+#    #+#             */
/*   Updated: 2024/01/13 02:52:45 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_arr_arr(void ***array_of_arrays)
{
	void	**array;
	size_t	i_array;

	i_array = 0;
	array = array_of_arrays[0];
	while (array)
	{
		ft_free_arr(array);
		i_array++;
		array = array_of_arrays[i_array];
	}
	free(array_of_arrays);
}
