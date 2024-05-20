/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hooks1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:06:25 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/20 15:40:43 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	zoom(t_fdf *fdf, float zoom_factor, char zoom_mode)
{
	int		cursor_x;
	int		cursor_y;
	float	zoom;

	mlx_mouse_get_pos(fdf->mlx.mlx, &cursor_x, &cursor_y);
	if (zoom_mode == ZOOM_IN)
		zoom = 1 + zoom_factor;
	else
		zoom = 1 - zoom_factor;
	fdf->pos.scale *= zoom;
	if (zoom_mode == ZOOM_IN)
	{
		fdf->pos.x += (fdf->pos.x - cursor_x) * zoom_factor;
		fdf->pos.y += (fdf->pos.y - cursor_y) * zoom_factor;
	}
	else
	{
		fdf->pos.x -= (fdf->pos.x - cursor_x) * zoom_factor;
		fdf->pos.y -= (fdf->pos.y - cursor_y) * zoom_factor;
	}
	fdf->actualize = 1;
}

void	translation(t_fdf *fdf)
{
	int	cursor_x;
	int	cursor_y;

	mlx_mouse_get_pos(fdf->mlx.mlx, &cursor_x, &cursor_y);
	if (cursor_x == fdf->cursor_prev_x && cursor_y == fdf->cursor_prev_y)
		return ;
	fdf->pos.x += cursor_x - fdf->cursor_prev_x;
	fdf->pos.y += cursor_y - fdf->cursor_prev_y;
	fdf->cursor_prev_x = cursor_x;
	fdf->cursor_prev_y = cursor_y;
	fdf->actualize = 1;
}

inline static float	floor_radian(float radian)
{
	if (radian < 0)
		radian += M_2PI;
	else if (radian >= M_2PI)
		radian -= M_2PI;
	return (radian);
}

inline static void	update_thetas_x_y(t_fdf *fdf, float cursor_y)
{
	float	offset;
	float	theta_z;
	float	ratio_x;
	float	direction_x;
	float	direction_y;

	offset = ((cursor_y - fdf->cursor_prev_y) / (float)HEIGHT) * M_2PI;
	theta_z = fdf->pos.theta_z + M_PI_4;
	while (theta_z >= M_PI)
		theta_z -= M_PI;
	direction_x = 1;
	if (fdf->pos.theta_z >= M_3PI_4 && fdf->pos.theta_z < M_7PI_4)
		direction_x = -1;
	direction_y = 1;
	if (fdf->pos.theta_z >= M_5PI_4 || fdf->pos.theta_z < M_PI_4)
		direction_y = -1;
	ratio_x = theta_z / M_PI_2;
	if (ratio_x > 1)
		ratio_x = 2 - ratio_x;
	fdf->pos.theta_x += offset * ratio_x * direction_x;
	fdf->pos.theta_y += offset * (1 - ratio_x) * direction_y;
	fdf->pos.theta_x = floor_radian(fdf->pos.theta_x);
	fdf->pos.theta_y = floor_radian(fdf->pos.theta_y);
}

void	rotation(t_fdf *fdf)
{
	int	cursor_x;
	int	cursor_y;

	mlx_mouse_get_pos(fdf->mlx.mlx, &cursor_x, &cursor_y);
	if (cursor_x == fdf->cursor_prev_x && cursor_y == fdf->cursor_prev_y)
		return ;
	update_thetas_x_y(fdf, (float)cursor_y);
	fdf->pos.theta_z += ((float)(cursor_x - fdf->cursor_prev_x)
			/ (float)WIDTH) * M_2PI;
	if (fdf->pos.theta_z < 0)
		fdf->pos.theta_z += M_2PI;
	else if (fdf->pos.theta_z >= M_2PI)
		fdf->pos.theta_z -= M_2PI;
	fdf->cursor_prev_x = cursor_x;
	fdf->cursor_prev_y = cursor_y;
	fdf->actualize = 1;
}
