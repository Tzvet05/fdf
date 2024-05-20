/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:31:35 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/07 18:14:48 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

inline static void	line_proj(t_mlx mlx, t_point point_start,
		t_point point_end, t_position pos)
{
	t_pixel	pixel_start;
	t_pixel	pixel_end;
	float	x;
	float	y;
	float	z;

	x = (float)point_start.x * pos.scale;
	y = (float)point_start.y * pos.scale;
	z = (float)point_start.z * pos.scale;
	pixel_start.x = PROJECTION_1 * (x - y) + pos.x;
	pixel_start.y = -((PROJECTION_2 * z) - (PROJECTION_3 * (x + y))) + pos.y;
	pixel_start.color = point_start.color;
	x = (float)point_end.x * pos.scale;
	y = (float)point_end.y * pos.scale;
	z = (float)point_end.z * pos.scale;
	pixel_end.x = PROJECTION_1 * (x - y) + pos.x;
	pixel_end.y = -((PROJECTION_2 * z) - (PROJECTION_3 * (x + y))) + pos.y;
	pixel_end.color = point_end.color;
	put_line(mlx, pixel_start, pixel_end);
}

void	display(t_mlx mlx, t_matrix map, t_position pos)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map.h)
	{
		j = 0;
		while (j < map.w)
		{
			if (j + 1 < map.w)
				line_proj(mlx, ((t_point **)map.matrix)[i][j],
					((t_point **)map.matrix)[i][j + 1], pos);
			if (i + 1 < map.h)
				line_proj(mlx, ((t_point **)map.matrix)[i][j],
					((t_point **)map.matrix)[i + 1][j], pos);
			j++;
		}
		i++;
	}
}
