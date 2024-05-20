/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hooks2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:39:41 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/20 15:40:17 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	apply_offset(t_fdf *fdf, float *origin_offset, long offset)
{
	*origin_offset += offset;
	fdf->actualize = 1;
}

void	reinit_pos(t_fdf *fdf)
{
	init_pos(fdf);
	fdf->actualize = 1;
}

void	change_projection(t_fdf *fdf)
{
	if (fdf->projection[0] == WONKY)
	{
		fdf->projection[0] = ISOMETRIC;
		fdf->projection[1] = ISOMETRIC_PROJECTION_1;
		fdf->projection[2] = ISOMETRIC_PROJECTION_2;
		fdf->projection[3] = ISOMETRIC_PROJECTION_3;
	}
	else
	{
		fdf->projection[0] = WONKY;
		fdf->projection[1] = WONKY_PROJECTION_1;
		fdf->projection[2] = WONKY_PROJECTION_2;
		fdf->projection[3] = WONKY_PROJECTION_3;
	}
	init_pos(fdf);
	fdf->actualize = 1;
}
