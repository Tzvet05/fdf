/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook1_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:05:35 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/20 15:48:06 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	key_down_hook(int event, void *fdf_ptr)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf_ptr;
	if (event == KEY_W || event == KEY_UP)
		fdf->inputs |= UP_HOLD;
	else if (event == KEY_A || event == KEY_LEFT)
		fdf->inputs |= LEFT_HOLD;
	else if (event == KEY_S || event == KEY_DOWN)
		fdf->inputs |= DOWN_HOLD;
	else if (event == KEY_D || event == KEY_RIGHT)
		fdf->inputs |= RIGHT_HOLD;
	else if (event == KEY_R || event == KEY_PLUS)
		fdf->inputs |= ZOOM_IN_HOLD;
	else if (event == KEY_F || event == KEY_MINUS)
		fdf->inputs |= ZOOM_OUT_HOLD;
	else if (event == KEY_P)
		change_projection(fdf);
	else if (event == KEY_H)
		reinit_pos(fdf);
	else if (event == KEY_ESC)
		mlx_loop_end(fdf->mlx.mlx);
	return (0);
}

int	key_up_hook(int event, void *fdf_ptr)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf_ptr;
	if (event == KEY_W || event == KEY_UP)
		fdf->inputs &= UP_RELEASE;
	else if (event == KEY_A || event == KEY_LEFT)
		fdf->inputs &= LEFT_RELEASE;
	else if (event == KEY_S || event == KEY_DOWN)
		fdf->inputs &= DOWN_RELEASE;
	else if (event == KEY_D || event == KEY_RIGHT)
		fdf->inputs &= RIGHT_RELEASE;
	else if (event == KEY_R || event == KEY_PLUS)
		fdf->inputs &= ZOOM_IN_RELEASE;
	else if (event == KEY_F || event == KEY_MINUS)
		fdf->inputs &= ZOOM_OUT_RELEASE;
	return (0);
}

int	mouse_wheel_hook(int event, void *fdf_ptr)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf_ptr;
	if (event == MOUSE_WHEEL_UP)
		zoom(fdf, ZOOM_MOUSE, ZOOM_IN);
	else if (event == MOUSE_WHEEL_DOWN)
		zoom(fdf, ZOOM_MOUSE, ZOOM_OUT);
	return (0);
}

int	mouse_down_hook(int event, void *fdf_ptr)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf_ptr;
	if (event == MOUSE_LEFT)
	{
		fdf->inputs |= DRAG_HOLD;
		mlx_mouse_get_pos(fdf->mlx.mlx,
			&fdf->cursor_prev_x, &fdf->cursor_prev_y);
	}
	else if (event == MOUSE_RIGHT)
	{
		fdf->inputs |= ROTATE_HOLD;
		mlx_mouse_get_pos(fdf->mlx.mlx,
			&fdf->cursor_prev_x, &fdf->cursor_prev_y);
	}
	else if (event == MOUSE_MIDDLE)
	{
		init_pos(fdf);
		fdf->actualize = 1;
	}
	return (0);
}

int	mouse_up_hook(int event, void *fdf_ptr)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf_ptr;
	if (event == MOUSE_LEFT)
		fdf->inputs &= DRAG_RELEASE;
	else if (event == MOUSE_RIGHT)
		fdf->inputs &= ROTATE_RELEASE;
	return (0);
}
