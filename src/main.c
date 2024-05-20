/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:10:09 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/07 18:25:58 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

inline static char	valid_filename(char *filename)
{
	size_t	len;
	size_t	i_filename;
	size_t	i_format;

	len = ft_strlen(filename);
	if (len < ft_strlen(FILE_FORMAT))
	{
		puterr(ERROR_FILENAME, filename);
		return (1);
	}
	i_format = 0;
	i_filename = len - ft_strlen(FILE_FORMAT);
	while (i_filename < len)
	{
		if (FILE_FORMAT[i_format] != filename[i_filename])
		{
			puterr(ERROR_FILENAME, filename);
			return (1);
		}
		i_filename++;
		i_format++;
	}
	return (0);
}

inline static void	setup_mlx_hooks(t_mlx mlx, t_matrix map)
{
	t_position	pos;

	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_down_hook, &mlx);
	init_pos(&pos, map);
	display(mlx, map, pos);
	mlx_loop(mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_matrix	map;

	if (argc != 2)
	{
		puterr(ERROR_ARGS, NULL);
		exit(1);
	}
	if (valid_filename(argv[1]))
		exit(1);
	if (parse(&map, argv[1]))
		exit(1);
	if (init_mlx(&mlx))
	{
		free_arr_dim((void **)map.matrix, map.h, free);
		exit(1);
	}
	setup_mlx_hooks(mlx, map);
	free_arr_dim((void **)map.matrix, map.h, free);
	mlx_destroy_image(mlx.mlx, mlx.img);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
	return (0);
}
