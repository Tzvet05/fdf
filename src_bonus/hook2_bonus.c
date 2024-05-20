/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:46:25 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/20 15:47:07 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	window_hook(int event, void *fdf_ptr)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf_ptr;
	if (event == WIN_LEAVE)
		fdf->inputs &= DRAG_ROTATE_RELEASE;
	else if (event == WIN_CROSS)
		mlx_loop_end(fdf->mlx.mlx);
	return (0);
}
