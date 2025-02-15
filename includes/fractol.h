/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:20:56 by tarini            #+#    #+#             */
/*   Updated: 2025/02/15 20:38:07 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include "libft.h"

# define ESC 65307
# define SPACE 32
# define ENTER 65293
# define DEL 65535
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define PLUS 65451
# define MINUS 65453

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END "\033[0m"

# define ULTRA_WIDTH 1242
# define ULTRA_HEIGHT 1242
# define MAX_ITER 100

typedef struct s_img 
{
	void    *img;
	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
} t_img;

typedef struct s_complex
{
	double  zr;
	double  zi;
} t_complex;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_img		img;
	double	zoom;
	double	offset_x;
	double 	offset_y;
} t_data;


/* ============================
	(ft_init.c)
============================ */
	
t_data			ft_init_data(void);
void        	ft_free_data(t_data *data);

/* ============================
	(ft_window.c)
============================ */
	
t_data 			ft_init_window(void);

/* ============================
	(ft_graphics.c)
============================ */
	
void			ft_myMlxPixelPut(t_img *img, int x, int y, int color);
void			ft_putLine(t_data *data, int x1, int y1, int x2, int y2);
int 			ft_get_color(int iterations);

/* ============================
	(ft_render.c)
============================ */
	
int				ft_render(t_data *data, int (*ft_draw_fractal)(t_data *data));


/* ============================
	(ft_hook.c)
============================ */

int				ft_key_hook(int keysym, t_data *data, int (*ft_draw_fractale)(t_data *data));
int				ft_mouse_hook(int button, int x, int y, t_data *data, int (*ft_draw_fractale)(t_data *data));
int				ft_close_hook(t_data *data);


/*==========================================
============================================
				FRACATLES	
============================================
==========================================*/ 

/* ============================
	(ft_mandelbrot.c)
	============================ */
	
int				ft_mandelbrot(t_data *data);

/* ============================
	(ft_burning_ship.c)
	============================ */

int 			ft_burning_ship(t_data *data);

/* ============================
	(ft_julia.c)
	============================ */

int				ft_julia(t_data *data);

#endif
