/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_display_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:44:14 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/20 15:24:50 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

inline static void	rotate(float *x_ptr, float *y_ptr, float *z_ptr,
		t_position pos)
{
	float	cos;
	float	sin;
	float	x;
	float	y;
	float	z;

	y = *y_ptr;
	z = *z_ptr;
	cos = cosf(pos.theta_x);
	sin = sinf(pos.theta_x);
	*y_ptr = (y * cos) + (z * sin);
	*z_ptr = (y * -sin) + (z * cos);
	x = *x_ptr;
	z = *z_ptr;
	cos = cosf(pos.theta_y);
	sin = sinf(pos.theta_y);
	*x_ptr = (x * cos) + (z * -sin);
	*z_ptr = (x * sin) + (z * cos);
	x = *x_ptr;
	y = *y_ptr;
	cos = cosf(pos.theta_z);
	sin = sinf(pos.theta_z);
	*x_ptr = (x * cos) + (y * sin);
	*y_ptr = (x * -sin) + (y * cos);
}

inline static t_pixel	calculate_pixel(float i, float j, t_point point,
		t_fdf *fdf)
{
	t_pixel	pixel;
	float	x;
	float	y;
	float	z;

	x = i;
	y = j;
	z = point.z;
	rotate(&x, &y, &z, fdf->pos);
	pixel.x = fdf->projection[1] * (x - y);
	pixel.y = -((fdf->projection[2] * z) - (fdf->projection[3] * (x + y)));
	pixel.color = point.color;
	pixel.x *= fdf->pos.scale;
	pixel.y *= fdf->pos.scale;
	pixel.x += fdf->pos.x;
	pixel.y += fdf->pos.y;
	return (pixel);
}

inline static void	cover_borders(t_mlx mlx)
{
	size_t	i;

	i = 0;
	while (i < WIDTH)
	{
		mlx_set_image_pixel(mlx.mlx, mlx.img, i, 0, BLACK);
		mlx_set_image_pixel(mlx.mlx, mlx.img, i, HEIGHT - 1, BLACK);
		i++;
	}
	i = 0;
	while (i < HEIGHT)
	{
		mlx_set_image_pixel(mlx.mlx, mlx.img, 0, i, BLACK);
		mlx_set_image_pixel(mlx.mlx, mlx.img, WIDTH - 1, i, BLACK);
		i++;
	}
}

inline static char	get_start_dir(t_position pos)
{
	char	dir;

	if (pos.theta_z >= M_PI && pos.theta_z < M_6PI_4)
		dir = 1;
	else if (pos.theta_z >= M_6PI_4 && pos.theta_z < M_2PI)
		dir = 2;
	else if (pos.theta_z >= 0 && pos.theta_z < M_PI_2)
		dir = 3;
	else
		dir = 4;
	if (dir == 1 && (pos.theta_x >= M_2PI_3 && pos.theta_x < M_5PI_3))
		dir = 3;
	else if (dir == 3 && (pos.theta_x >= M_PI_3 && pos.theta_x < M_4PI_3))
		dir = 1;
	if (dir == 2 && (pos.theta_y >= M_2PI_3 && pos.theta_y < M_5PI_3))
		dir = 4;
	else if (dir == 4 && (pos.theta_y >= M_PI_3 && pos.theta_y < M_4PI_3))
		dir = 2;
	return (dir);
}

void	projection(t_fdf *fdf)
{
	char	start_dir;
	size_t	i;
	size_t	j;
	t_pixel	**pixels;
	t_point	**points;

	pixels = (t_pixel **)(fdf->dis.matrix);
	points = (t_point **)(fdf->map.matrix);
	start_dir = get_start_dir(fdf->pos);
	i = 0;
	while (i < fdf->map.h)
	{
		j = 0;
		while (j < fdf->map.w)
		{
			pixels[i][j] = calculate_pixel((float)j - fdf->pos.origin_x,
					(float)i - fdf->pos.origin_y, points[i][j], fdf);
			j++;
		}
		i++;
	}
	project_display(fdf->mlx, fdf->dis, start_dir);
	cover_borders(fdf->mlx);
}
