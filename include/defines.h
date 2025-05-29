/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:12:07 by rwassim           #+#    #+#             */
/*   Updated: 2025/05/26 09:38:22 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_TITLE "Fractol"
# define WIN_WIDTH 900
# define WIN_HEIGHT 900

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define MOUSE_LEFT_BUTTON 1

# define MOVE_DISTANCE 0.1

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA
}					t_fractal_type;

typedef enum e_color_scheme
{
	ELECTRIC,
	NEON,
	PSYCHEDELIC
}					t_color_scheme;

typedef struct s_complex
{
	double			real;
	double			imag;
}					t_complex;

typedef struct s_fractol
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				bits_per_pixel;
	int				line_size;
	int				endian;
	int				iterations;
	t_fractal_type	fractal_type;
	t_color_scheme	color_scheme;
	double			zoom;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	double			julia_cx;
	double			julia_cy;
}					t_fractol;

#endif