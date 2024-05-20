/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:39:00 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/05 18:38:28 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

inline static void	init_dcolor(float *dcolor, unsigned int start,
	unsigned int end, float step)
{
	dcolor[0] = (float)((short)((end & 0xFF000000) >> 24)
			- (short)((start & 0xFF000000) >> 24)) / step;
	dcolor[1] = (float)((short)((end & 0x00FF0000) >> 16)
			- (short)((start & 0x00FF0000) >> 16)) / step;
	dcolor[2] = (float)((short)((end & 0x0000FF00) >> 8)
			- (short)((start & 0x0000FF00) >> 8)) / step;
	dcolor[3] = (float)((short)(end & 0x000000FF)
			- (short)(start & 0x000000FF)) / step;
}

inline static void	update_color(float *color, float *dcolor)
{
	color[0] += dcolor[0];
	color[1] += dcolor[1];
	color[2] += dcolor[2];
	color[3] += dcolor[3];
}

inline static unsigned int	rd_color(float *color)
{
	return ((((unsigned int)(color[0])) << 24)
		| (((unsigned int)(color[1])) << 16)
		| (((unsigned int)(color[2])) << 8)
		| ((unsigned int)(color[3])));
}

inline static void	init_color(float *color, unsigned int color_start)
{
	color[0] = (float)((color_start & 0xFF000000) >> 24);
	color[1] = (float)((color_start & 0x00FF0000) >> 16);
	color[2] = (float)((color_start & 0x0000FF00) >> 8);
	color[3] = (float)(color_start & 0x000000FF);
}

void	put_line(t_mlx mlx, t_pixel start, t_pixel end)
{
	float	step;
	float	dpos[2];
	float	dcolor[4];
	float	pos[2];
	float	color[4];

	dpos[0] = end.x - start.x;
	dpos[1] = end.y - start.y;
	step = fabsf(dpos[1]);
	if (fabsf(dpos[0]) >= fabsf(dpos[1]))
		step = fabsf(dpos[0]);
	dpos[0] /= step;
	dpos[1] /= step;
	pos[0] = start.x;
	pos[1] = start.y;
	init_dcolor(dcolor, start.color, end.color, step);
	init_color(color, start.color);
	while (step-- > 0)
	{
		mlx_set_image_pixel(mlx.mlx, mlx.img, pos[0], pos[1], rd_color(color));
		pos[0] += dpos[0];
		pos[1] += dpos[1];
		update_color(color, dcolor);
	}
	mlx_set_image_pixel(mlx.mlx, mlx.img, end.x, end.y, end.color);
}
