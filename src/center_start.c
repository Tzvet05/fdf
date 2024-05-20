/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:46:10 by ttrave            #+#    #+#             */
/*   Updated: 2024/04/09 16:29:35 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

inline static t_pixel	point_isometric_projection(float x, float y, float z)
{
	t_pixel	pixel;

	pixel.x = PROJECTION_1 * (x - y);
	pixel.y = -((PROJECTION_2 * z) - (PROJECTION_3 * (x + y)));
	return (pixel);
}

inline static void	update_extremities(float *extremities, t_pixel pixel)
{
	if (pixel.x > extremities[0])
		extremities[0] = pixel.x;
	if (pixel.x < extremities[1])
		extremities[1] = pixel.x;
	if (pixel.y > extremities[2])
		extremities[2] = pixel.y;
	if (pixel.y < extremities[3])
		extremities[3] = pixel.y;
}

inline static void	calculate_pos(t_position *pos, float *extremities)
{
	float	hor_len;
	float	ver_len;
	float	scale;

	hor_len = extremities[0] - extremities[1];
	ver_len = extremities[2] - extremities[3];
	scale = (WIDTH * START_SCALE) / hor_len;
	if (scale > (HEIGHT * START_SCALE) / ver_len)
		scale = (HEIGHT * START_SCALE) / ver_len;
	hor_len *= scale;
	ver_len *= scale;
	pos->scale = scale;
	pos->x = (WIDTH / 2.f) - (hor_len / 2.f + (extremities[1] * scale));
	pos->y = (HEIGHT / 2.f) - (ver_len / 2.f + (extremities[3] * scale));
}

inline static void	init_extremities(float *extremities, t_point point)
{
	t_pixel	pixel;

	pixel = point_isometric_projection(point.x, point.y, point.z);
	extremities[0] = pixel.x;
	extremities[1] = pixel.x;
	extremities[2] = pixel.y;
	extremities[3] = pixel.y;
}

void	init_pos(t_position *pos, t_matrix map)
{
	float	extremities[4];
	t_pixel	pixel;
	size_t	i;
	size_t	j;

	if (!map.w && !map.h)
		return ;
	init_extremities(extremities, ((t_point **)map.matrix)[0][0]);
	i = 0;
	while (i < map.h)
	{
		j = 0;
		while (j < map.w)
		{
			pixel = point_isometric_projection(((t_point **)map.matrix)[i][j].x,
					((t_point **)map.matrix)[i][j].y,
					((t_point **)map.matrix)[i][j].z);
			update_extremities(extremities, pixel);
			j++;
		}
		i++;
	}
	calculate_pos(pos, extremities);
}
