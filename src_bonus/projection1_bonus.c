/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:31:35 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/20 15:52:44 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

inline static void	bring_back(t_pixel *pixel, float slope, float offset)
{
	if (pixel->x < 0)
	{
		pixel->x = 0;
		pixel->y = offset;
	}
	else if (pixel->x >= WIDTH)
	{
		pixel->x = WIDTH - 1;
		pixel->y = slope * (WIDTH - 1) + offset;
	}
	if (pixel->y < 0)
	{
		if (slope != 0)
			pixel->x = -offset / slope;
		pixel->y = 0;
	}
	else if (pixel->y >= HEIGHT)
	{
		if (slope != 0)
			pixel->x = (HEIGHT - offset - 1) / slope;
		pixel->y = HEIGHT - 1;
	}
}

inline static void	project_line(t_mlx mlx, t_pixel pixel_start,
		t_pixel pixel_end)
{
	float	slope;
	float	offset;

	if (pixel_start.x == pixel_end.x)
	{
		slope = 0;
		offset = 0;
	}
	else
	{
		slope = (pixel_end.y - pixel_start.y) / (pixel_end.x - pixel_start.x);
		offset = pixel_start.y - (slope * pixel_start.x);
	}
	if (pixel_start.x < 0 || pixel_start.x >= WIDTH
		|| pixel_start.y < 0 || pixel_start.y >= HEIGHT)
		bring_back(&pixel_start, slope, offset);
	if (pixel_end.x < 0 || pixel_end.x >= WIDTH
		|| pixel_end.y < 0 || pixel_end.y >= HEIGHT)
		bring_back(&pixel_end, slope, offset);
	put_line(mlx, pixel_start, pixel_end);
}

inline static void	browse_display_column(t_mlx mlx, t_pixel **pixels,
		long *browse)
{
	long	col;
	long	lin;
	long	end_col;
	long	end_lin;
	long	offset_lin;

	end_col = browse[4] + browse[5];
	end_lin = browse[1] + browse[2];
	offset_lin = browse[2];
	col = browse[3];
	while (col != end_col)
	{
		lin = browse[0];
		while (lin != end_lin)
		{
			if (lin != browse[1])
				project_line(mlx,
					pixels[lin][col], pixels[lin + offset_lin][col]);
			if (col != browse[4])
				project_line(mlx,
					pixels[lin][col], pixels[lin][col + browse[5]]);
			lin += offset_lin;
		}
		col += browse[5];
	}
}

inline static void	browse_display_line(t_mlx mlx, t_pixel **pixels,
		long *browse)
{
	long	lin;
	long	col;
	long	end_lin;
	long	end_col;
	long	offset_col;

	end_lin = browse[1] + browse[2];
	end_col = browse[4] + browse[5];
	offset_col = browse[5];
	lin = browse[0];
	while (lin != end_lin)
	{
		col = browse[3];
		while (col != end_col)
		{
			if (lin != browse[1])
				project_line(mlx,
					pixels[lin][col], pixels[lin + browse[2]][col]);
			if (col != browse[4])
				project_line(mlx,
					pixels[lin][col], pixels[lin][col + offset_col]);
			col += offset_col;
		}
		lin += browse[2];
	}
}

void	project_display(t_mlx mlx, t_matrix display, char start_dir)
{
	long	browse[6];
	t_pixel	**pixels;

	get_browse(display, browse, start_dir);
	pixels = (t_pixel **)display.matrix;
	if (start_dir == 1 || start_dir == 3)
		browse_display_line(mlx, pixels, browse);
	else
		browse_display_column(mlx, pixels, browse);
}
