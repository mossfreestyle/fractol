/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:39:40 by rwassim           #+#    #+#             */
/*   Updated: 2025/05/28 10:57:11 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_julia_params(t_fractol *app, const char *arg, bool is_x)
{
	double	value;

	value = ft_atof(arg);
	if (value > 2.0 || value < -2.0)
		invalid_arg();
	if (is_x)
		app->julia_cx = value;
	else
		app->julia_cy = value;
}

static void	init_arg(t_fractol *app, int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "M"))
			fractal_init(app, MANDELBROT);
		else if (!ft_strcmp(av[1], "J"))
			fractal_init(app, JULIA);
		else
			invalid_arg();
	}
	else if (ac == 4 && !ft_strcmp(av[1], "J"))
	{
		if (!ft_isdouble(av[2]) || !ft_isdouble(av[3]))
			invalid_arg();
		fractal_init(app, JULIA);
		check_julia_params(app, av[2], true);
		check_julia_params(app, av[3], false);
	}
	else
		wrong_arg_num();
}

static void	init_window(t_fractol *app, char *title)
{
	app->mlx_ptr = mlx_init();
	if (!app->mlx_ptr)
		allocation_error(app, "ERROR: UNABLE TO INITIALZE MLX");
	app->win_ptr = mlx_new_window(app->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title);
	if (!app->win_ptr)
		allocation_error(app, "ERROR: UNABLE TO CREATE WINDOW");
	app->img_ptr = mlx_new_image(app->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!app->img_ptr)
		allocation_error(app, "ERROR: UNABLE TO CREATE IMAGE");
	app->img_data = mlx_get_data_addr(app->img_ptr, &app->bits_per_pixel,
			&app->line_size, &app->endian);
	if (!app->img_data)
		allocation_error(app, "ERROR: UNABLE TO GET IMAGE DATA ADRESS");
}

int	main(int ac, char **av)
{
	t_fractol	app;

	ft_bzero(&app, sizeof(t_fractol));
	init_arg(&app, ac, av);
	init_window(&app, WIN_TITLE);
	fractal_render(&app);
	mlx_mouse_hook(app.win_ptr, handle_mouse_events, &app);
	mlx_key_hook(app.win_ptr, handle_keypress, &app);
	mlx_hook(app.win_ptr, 17, 0, app_exit_success, &app);
	mlx_loop(app.mlx_ptr);
	return (EXIT_SUCCESS);
}
