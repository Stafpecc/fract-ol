/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:20:56 by tarini            #+#    #+#             */
/*   Updated: 2025/03/03 14:33:04 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"

# include <math.h>
# include <stdlib.h>

# define ESC 65307
# define SPACE 32
# define DEL 65288
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define PLUS 65451
# define MINUS 65453

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END "\033[0m"
# define BLACK 0x000000

# define ULTRA_WIDTH 800
# define ULTRA_HEIGHT 800
# define ZOOM_MIN 0.0001
# define ZOOM_MAX 1000
# define MAX_ITER 80

typedef struct s_data	t_data;

typedef struct s_complex
{
	double	zr;
	double	zi;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_julia
{
	t_complex	c;
	t_complex	z;
}	t_julia;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_img		img;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			(*ft_draw_fractal)(t_data *data);
	t_complex	julia_constant;
}	t_data;

typedef struct s_fractal
{
	int			x;
	int			y;
	int			iterations;
	double		scale;
	double		center_x;
	double		center_y;
}	t_fractal;

/* ============================
	(ft_init.c)
============================ */

t_data			ft_init_data(void);
void			ft_free_data(t_data *data);
void			ft_init_fractal(t_fractal *fract, t_data *data);
int				ft_fractal_formula(t_complex *z, t_complex *c);

/* ============================
	(ft_window.c)
============================ */

t_data			ft_init_window(void);

/* ============================
	(ft_graphics.c)
============================ */

void			ft_my_mlx_pixel_put(t_img *img, int x, int y, int color);
int				ft_get_color(int iterations);

/* ============================
	(ft_render.c)
============================ */

int				ft_render(t_data *data, int (*ft_draw_fractal)(t_data *data));

/* ============================
	(ft_hook.c)
============================ */

int				ft_key_hook(int keysym, t_data *data);
int				ft_mouse_hook(int button, int x, int y, t_data *data);
int				ft_close_hook(t_data *data);
int				ft_loop_hook(t_data *data);

/*==========================================
============================================
				FRACTALS	
============================================
==========================================*/

/* ============================
	(ft_mandelbrot.c)
	============================ */

int				ft_mandelbrot(t_data *data);

/* ============================
	(ft_julia.c)
	============================ */

int				ft_julia(t_data *data);

#endif
