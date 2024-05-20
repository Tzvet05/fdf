/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:10:09 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/20 15:19:00 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

inline static char	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		puterr(ERROR_MLX_INIT, NULL);
		return (1);
	}
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, WIN_TITLE);
	if (!mlx->win)
	{
		mlx_destroy_display(mlx->mlx);
		puterr(ERROR_MLX_WIN, NULL);
		return (1);
	}
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img)
	{
		mlx_destroy_display(mlx->mlx);
		mlx_destroy_window(mlx->mlx, mlx->win);
		puterr(ERROR_MLX_IMG, NULL);
		return (1);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_set_fps_goal(mlx->mlx, FPS_CAP);
	return (0);
}

inline static int	actualize(void *fdf_ptr)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf_ptr;
	if (fdf->inputs & UP_HOLD)
		apply_offset(fdf, &(fdf->pos.y), TRANSLATION);
	if (fdf->inputs & LEFT_HOLD)
		apply_offset(fdf, &(fdf->pos.x), TRANSLATION);
	if (fdf->inputs & DOWN_HOLD)
		apply_offset(fdf, &(fdf->pos.y), -TRANSLATION);
	if (fdf->inputs & RIGHT_HOLD)
		apply_offset(fdf, &(fdf->pos.x), -TRANSLATION);
	if ((fdf->inputs & ZOOM_IN_HOLD) && !(fdf->inputs & ZOOM_OUT_HOLD))
		zoom(fdf, ZOOM_KEY, ZOOM_IN);
	if ((fdf->inputs & ZOOM_OUT_HOLD) && !(fdf->inputs & ZOOM_IN_HOLD))
		zoom(fdf, ZOOM_KEY, ZOOM_OUT);
	if (fdf->inputs & DRAG_HOLD)
		translation(fdf);
	if (fdf->inputs & ROTATE_HOLD)
		rotation(fdf);
	if (!fdf->actualize)
		return (0);
	fdf->actualize = 0;
	clear_img(fdf->mlx);
	projection(fdf);
	return (0);
}

inline static char	setup_mlx_hooks(t_mlx mlx, t_matrix map, t_matrix display)
{
	t_fdf		fdf;

	if (write(1, USER_CONTROLS, ft_strlen(USER_CONTROLS)) == -1)
		return (1);
	fdf.mlx = mlx;
	fdf.map = map;
	fdf.dis = display;
	fdf.inputs = 0;
	fdf.actualize = 1;
	fdf.projection[0] = WONKY;
	change_projection(&fdf);
	init_pos(&fdf);
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, &fdf);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_down_hook, &fdf);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYUP, key_up_hook, &fdf);
	mlx_on_event(mlx.mlx, mlx.win, MLX_MOUSEWHEEL, mouse_wheel_hook, &fdf);
	mlx_on_event(mlx.mlx, mlx.win, MLX_MOUSEDOWN, mouse_down_hook, &fdf);
	mlx_on_event(mlx.mlx, mlx.win, MLX_MOUSEUP, mouse_up_hook, &fdf);
	mlx_loop_hook(mlx.mlx, actualize, &fdf);
	mlx_loop(mlx.mlx);
	return (0);
}

inline static char	alloc_display(t_matrix *display, t_matrix map)
{
	size_t	i;

	display->matrix = malloc(map.h * sizeof(t_pixel *));
	if (!display->matrix)
	{
		ft_free_arr(map.matrix);
		puterr(ERROR_MALLOC, NULL);
		return (1);
	}
	i = 0;
	while (i < map.h)
	{
		display->matrix[i] = malloc(map.w * sizeof(t_pixel));
		if (!display->matrix[i])
		{
			ft_free_arr(map.matrix);
			ft_free_arr(display->matrix);
			puterr(ERROR_MALLOC, NULL);
			return (1);
		}
		i++;
	}
	display->h = map.h;
	display->w = map.w;
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_matrix	map;
	t_matrix	display;

	check_params(argc);
	if (valid_filename(argv[1]))
		exit(1);
	if (parse(&map, argv[1]))
		exit(1);
	if (alloc_display(&display, map))
		exit(1);
	if (init_mlx(&mlx))
	{
		free_arr_dim(map.matrix, map.h, free);
		free_arr_dim(display.matrix, display.h, free);
		exit(1);
	}
	if (setup_mlx_hooks(mlx, map, display))
		puterr(ERROR_WRITE, NULL);
	free_arr_dim(map.matrix, map.h, free);
	free_arr_dim(display.matrix, display.h, free);
	mlx_destroy_image(mlx.mlx, mlx.img);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
	return (0);
}
