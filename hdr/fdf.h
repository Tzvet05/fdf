/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:04:56 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/05 18:38:52 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* ----- INCLUDES ----- */

# include "../MacroLibX/includes/mlx.h"
# include "../libft/hdr/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/* ----- STRUCTURES ----- */

// MLX pointers
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_mlx;

// Display parameters
typedef struct s_position
{
	float	scale;
	float	x;
	float	y;
}	t_position;

// Point
typedef struct s_point
{
	size_t			x;
	size_t			y;
	long			z;
	unsigned int	color;
}	t_point;

// Pixel
typedef struct s_pixel
{
	float			x;
	float			y;
	unsigned int	color;
}	t_pixel;

// Matrix
typedef struct s_matrix
{
	void	**matrix;
	size_t	w;
	size_t	h;
}	t_matrix;

/* ----- MACROS ----- */

// MLX window parameters
# define WIN_TITLE	"FDF"
# define WIDTH		1440
# define HEIGHT		810
# define FPS_CAP	60

// Projection parameter
# define START_SCALE	0.9f

// Parsing
# define FILE_FORMAT	".fdf"
# define HEXA_LOW	"0123456789abcdef"

// Colors & transparency
# define MAX_AA		0xFF000000
# define WHITE		0xFFFFFFFF

// Projection constants
# define PROJECTION_1	0.707106781187f
# define PROJECTION_2	0.816496580928f
# define PROJECTION_3	0.408248290464f

// Hooks
//	Window
# define WIN_CROSS	0
//	Keyboard
# define KEY_ESC	41

// Error strings
# define ERROR_ARGS	"exactly one argument is required"
# define ERROR_OPEN	"open : failed to open file"
# define ERROR_MALLOC	"malloc : failed memory allocation"
# define ERROR_FILENAME	"the file provided as argument is not in format '*.fdf'"
# define ERROR_MLX_INIT	"mlx_init : failed to initialize MLX"
# define ERROR_MLX_WIN	"mlx_new_window : failed to create new window"
# define ERROR_MLX_IMG	"mlx_new_image : failed to create new image"

/* ----- PROTOTYPES ----- */

// main.c
int				main(int argc, char **argv);

// parsing1.c
char			parse(t_matrix *map, char *filename);

// parsing2.c
long			get_number(char *line, size_t *i_start);
unsigned int	get_color(char *line, size_t *i_start);
size_t			count_points(char *line);

// parsing3.c
char			is_point(char *line, size_t *i_start);

// center_start.c
void			init_pos(t_position *pos, t_matrix map);

// projection.c
void			display(t_mlx mlx, t_matrix map, t_position pos);

// draw.c
void			put_line(t_mlx mlx, t_pixel start, t_pixel end);

// hook.c
int				window_hook(int event, void *mlx_ptr);
int				key_down_hook(int event, void *mlx_ptr);

// utils.c
void			puterr(char *str1, char *str2);
void			free_arr_dim(void **arr, size_t len, void (*del)(void *));

#endif
