/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:12:15 by rwassim           #+#    #+#             */
/*   Updated: 2025/05/28 10:58:03 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	app_exit_code(t_fractol *app, int exit_code)
{
	if (app->img_ptr)
		mlx_destroy_image(app->mlx_ptr, app->img_ptr);
	if (app->win_ptr)
		mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	if (app->mlx_ptr)
	{
		mlx_destroy_display(app->mlx_ptr);
		free(app->mlx_ptr);
		app->mlx_ptr = NULL;
	}
	exit(exit_code);
}

int	app_exit_success(t_fractol *app)
{
	app_exit_code(app, EXIT_SUCCESS);
	return (0);
}
