/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:01:22 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/09 17:51:42 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

void	clear_img(t_mlx mlx)
{
	size_t	height;
	size_t	width;
	size_t	i_lin;
	size_t	i_col;

	height = HEIGHT - 1;
	width = WIDTH - 1;
	i_lin = 1;
	while (i_lin < height)
	{
		i_col = 1;
		while (i_col < width)
		{
			mlx_set_image_pixel(mlx.mlx, mlx.img, i_col, i_lin, BLACK);
			i_col++;
		}
		i_lin++;
	}
}
