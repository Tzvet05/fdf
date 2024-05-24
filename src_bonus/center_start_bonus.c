/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_start_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:46:10 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/20 15:26:57 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

inline static t_pixel	point_isometric_projection(float x, float y, float z,
		float *projection)
{
	t_pixel	pixel;

	pixel.x = projection[1] * (x - y);
	pixel.y = -((projection[2] * z) - (projection[3] * (x + y)));
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

inline static void	calculate_pos(t_fdf *fdf, float *extremities)
{
	float	hor_len;
	float	ver_len;
	float	scale;

	hor_len = extremities[0] - extremities[1];
	ver_len = extremities[2] - extremities[3];
	if ((WIDTH * START_SCALE / hor_len) < (HEIGHT * START_SCALE / ver_len))
		scale = WIDTH * START_SCALE / hor_len;
	else
		scale = HEIGHT * START_SCALE / ver_len;
	fdf->pos.scale = scale;
	fdf->pos.x = (WIDTH / 2)
		- ((hor_len * scale) / 2 + (extremities[1] * scale));
	fdf->pos.y = (HEIGHT / 2)
		- ((ver_len * scale) / 2 + (extremities[3] * scale));
	fdf->pos.theta_x = START_THETA_X;
	fdf->pos.theta_y = START_THETA_Y;
	fdf->pos.theta_z = START_THETA_Z;
}

inline static void	init_extremities(float *extremities, t_fdf *fdf)
{
	t_pixel	pixel;

	if (!fdf->map.h || !fdf->map.w)
	{
		extremities[0] = 0;
		extremities[1] = 0;
		extremities[2] = 0;
		extremities[3] = 0;
	}
	else
	{
		pixel = point_isometric_projection(-fdf->pos.origin_x,
				-fdf->pos.origin_y,
				((t_point **)(fdf->map.matrix))[0][0].z, fdf->projection);
		extremities[0] = pixel.x;
		extremities[1] = pixel.x;
		extremities[2] = pixel.y;
		extremities[3] = pixel.y;
	}
}

void	init_pos(t_fdf *fdf)
{
	float	extremities[4];
	t_pixel	pixel;
	size_t	i;
	size_t	j;

	fdf->pos.origin_x = fdf->map.w / 2;
	fdf->pos.origin_y = fdf->map.h / 2;
	init_extremities(extremities, fdf);
	i = 0;
	while (i < fdf->map.h)
	{
		j = 0;
		while (j < fdf->map.w)
		{
			pixel = point_isometric_projection((float)j - fdf->pos.origin_x,
					(float)i - fdf->pos.origin_y,
					((t_point **)(fdf->map.matrix))[i][j].z, fdf->projection);
			update_extremities(extremities, pixel);
			j++;
		}
		i++;
	}
	calculate_pos(fdf, extremities);
}
