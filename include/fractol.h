/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:43:22 by rwassim           #+#    #+#             */
/*   Updated: 2025/05/26 11:30:18 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "defines.h"
# include "libft.h"
# include "math.h"
# include "mlx.h"
# include "stdbool.h"
# include "stdio.h"
# include <X11/keysym.h>

void	fractal_init(t_fractol *app, t_fractal_type type);
void	wrong_arg_num(void);
void	invalid_arg(void);
void	allocation_error(t_fractol *app, const char *message);
void	put_pixel(t_fractol *app, int x, int y, int color);
void	fractal_render(t_fractol *app);
void	app_exit_code(t_fractol *app, int exit_code);
void	set_complex_values(t_fractol *app, int x, int y, t_complex *complex);
void	julia_shift(int x, int y, t_fractol *app);
bool	ft_isdouble(const char *str);
double	ft_atof(const char *str);
int		app_exit_success(t_fractol *app);
int		handle_keypress(int keysym, t_fractol *app);
int		get_color(t_fractol *app, int iteration);
int		handle_mouse_events(int button, int x, int y, t_fractol *app);

#endif