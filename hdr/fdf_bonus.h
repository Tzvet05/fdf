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

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

/* ----- INCLUDES ----- */

// Headers
# include "../libft/hdr/libft.h"
# include "../MacroLibX/includes/mlx.h"

// Libraries
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

/* ----- STRUCTURES ----- */

// Point
typedef struct s_point
{
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
	float	origin_x;
	float	origin_y;
	float	theta_x;
	float	theta_y;
	float	theta_z;
}	t_position;

// Global data storage
typedef struct s_fdf
{
	t_mlx		mlx;
	t_position	pos;
	t_matrix	map;
	t_matrix	dis;
	float		projection[4];
	char		inputs;
	int			cursor_prev_x;
	int			cursor_prev_y;
	char		actualize;
}	t_fdf;

/* ----- MACROS ----- */

// MLX window parameters
# define WIN_TITLE	"FDF"
# define WIDTH		1440
# define HEIGHT		810
# define FPS_CAP	60

// Starting projection parameters
# define START_SCALE	0.9f
# define START_THETA_X	0
# define START_THETA_Y	0
# define START_THETA_Z	0

// Parsing
# define FILE_FORMAT	".fdf"
# define HEXA_LOW	"0123456789abcdef"

// Colors & transparency
# define BLACK	0x00000000
# define MAX_AA	0xFF000000
# define WHITE	0xFFFFFFFF

// Projections
# define ISOMETRIC		0
# define WONKY			1

// Projection constants
# define ISOMETRIC_PROJECTION_1	0.707106781187f
# define ISOMETRIC_PROJECTION_2	0.816496580928f
# define ISOMETRIC_PROJECTION_3	0.408248290464f
# define WONKY_PROJECTION_1	1.0f
# define WONKY_PROJECTION_2	0.8f
# define WONKY_PROJECTION_3	0.1f

// Radians
# define M_2PI		6.283185307179f
# define M_PI_3		1.047197551196f
# define M_2PI_3	2.094395102393f
# define M_4PI_3	4.188790204786f
# define M_5PI_3	5.235987755982f
# define M_3PI_4	2.356194490192f
# define M_5PI_4	3.926990816987f
# define M_6PI_4	4.712388980384f
# define M_7PI_4	5.497787143782f

// Movements
//	Zoom
# define ZOOM_KEY	0.03f
# define ZOOM_MOUSE	0.05f
# define ZOOM_IN	1
# define ZOOM_OUT	0
//	Translation
# define TRANSLATION	10

// Hooks
//	Window
# define WIN_CROSS		0
# define WIN_LEAVE		6
//	Keyboard
# define KEY_ESC		41
# define KEY_R			21
# define KEY_F			9
# define KEY_PLUS		87
# define KEY_MINUS		86
# define KEY_W			26
# define KEY_A			4
# define KEY_S			22
# define KEY_D			7
# define KEY_UP			82
# define KEY_LEFT		80
# define KEY_DOWN		81
# define KEY_RIGHT		79
# define KEY_P			19
# define KEY_H			11
//	Mouse
# define MOUSE_WHEEL_UP		1
# define MOUSE_WHEEL_DOWN	2
# define MOUSE_LEFT		1
# define MOUSE_MIDDLE		2
# define MOUSE_RIGHT		3

// User controls
//	Release
# define UP_RELEASE		127
# define LEFT_RELEASE		191
# define DOWN_RELEASE		223
# define RIGHT_RELEASE		239
# define ZOOM_IN_RELEASE	247
# define ZOOM_OUT_RELEASE	251
# define DRAG_RELEASE		253
# define ROTATE_RELEASE		254
# define DRAG_ROTATE_RELEASE	252
//	Hold
# define UP_HOLD		128
# define LEFT_HOLD		64
# define DOWN_HOLD		32
# define RIGHT_HOLD		16
# define ZOOM_IN_HOLD		8
# define ZOOM_OUT_HOLD		4
# define DRAG_HOLD		2
# define ROTATE_HOLD		1

// Error strings
# define ERROR_ARGS	"exactly one argument is required (the path to the map)"
# define ERROR_OPEN	"open : failed to open file"
# define ERROR_MALLOC	"malloc : failed memory allocation"
# define ERROR_FILENAME	"the file provided as argument is not in format '*.fdf'"
# define ERROR_WRITE	"write : failed to write on standard output"
# define ERROR_MLX_INIT	"mlx_init : failed to initialize MLX"
# define ERROR_MLX_WIN	"mlx_new_window : failed to create new window"
# define ERROR_MLX_IMG	"mlx_new_image : failed to create new image"

// User controls string
# define USER_CONTROLS	"Controls :\n\
\n\
W,A,S,D,LMB : Move the camera.\n\
R,F,MMU,MMD : Zoom in and out, centered on the mouse cursor.\n\
LRB : Rotate the model.\n\
H,MMB : Restore the starting projection.\n\
P : Alternate between projections.\n\
ESC : Close the window and exit the program.\n"

/* ----- PROTOTYPES ----- */

// main_bonus.c
int				main(int argc, char **argv);

// check_args_bonus.c
char			valid_filename(char *filename);
void			check_params(int argc);

// parsing1_bonus.c
char			parse(t_matrix *map, char *filename);

// parsing2_bonus.c
long			get_number(char *line, size_t *i_start);
unsigned int	get_color(char *line, size_t *i_start);
size_t			count_points(char *line);

// parsing3_bonus.c
char			is_point(char *line, size_t *i_start);

// center_start_bonus.c
void			init_pos(t_fdf *fdf);

// projection1_bonus.c
void			project_display(t_mlx mlx, t_matrix display, char start_dir);

// projection2_bonus.c
void			get_browse(t_matrix display, long *browsing_data,
					char start_dir);

// calculate_display_bonus.c
void			projection(t_fdf *fdf);

// draw_bonus.c
void			put_line(t_mlx mlx, t_pixel start, t_pixel end);

// hook1_bonus.c
int				key_down_hook(int event, void *fdf_ptr);
int				key_up_hook(int event, void *fdf_ptr);
int				mouse_wheel_hook(int event, void *fdf_ptr);
int				mouse_down_hook(int event, void *fdf_ptr);
int				mouse_up_hook(int event, void *fdf_ptr);

// hook2_bonus.c
int				window_hook(int event, void *fdf_ptr);

// apply_hooks1_bonus.c
void			zoom(t_fdf *fdf, float zoom_factor, char zoom_mode);
void			translation(t_fdf *fdf);
void			rotation(t_fdf *fdf);

// apply_hooks2_bonus.c
void			apply_offset(t_fdf *fdf, float *origin_offset, long offset);
void			reinit_pos(t_fdf *fdf);
void			change_projection(t_fdf *fdf);

// utils_bonus.c
void			puterr(char *str1, char *str2);
void			free_arr_dim(void **arr, size_t len, void (*del)(void *));
void			clear_img(t_mlx mlx);

#endif
