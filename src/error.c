/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:19:23 by rwassim           #+#    #+#             */
/*   Updated: 2025/05/28 10:56:24 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	guide(void)
{
	ft_printf("************************************************************\n");
	ft_printf("                 \033[1;36mBienvenu sur Fract'ol!\033[0m\n");
	ft_printf("************************************************************\n");
	ft_printf("  \033[1;38;5;142mFractals:\033[0m\n");
	ft_printf("    M - Mandelbrot\n");
	ft_printf("    J - Julia\n");
	ft_printf("  \033[38;5;98mUsage example:\t./fractol M\033[0m\n");
	ft_printf("                        \033[38;5;98m./fractol J\033[0m\n");
	ft_printf("\n");
	ft_printf("  Pour Julia, utilise des valeurs entres\n");
	ft_printf("  -2.0 and 2.0, (c'est un points pour les decimales) \033[0m\n");
	ft_printf("  \033[38;5;98mUsage example:\t./fractol J 0.25 -0.55\033[0m\n");
	ft_printf("\n");
	ft_printf("  \033[1;38;5;142mControls:\033[0m\n");
	ft_printf("    - \033[38;5;43mMouvement:\033[0m Arrow keys\n");
	ft_printf("    - \033[38;5;43mZoom:\033[0m Mouse wheel up / down\n");
	ft_printf("    - \033[38;5;43mAjouter des iterations:\033[0m +\n");
	ft_printf("    - \033[38;5;43mEnlever des iterations:\033[0m -\n");
	ft_printf("    - \033[38;5;43mChange color scheme:\033[0m Space\n");
	ft_printf("    - \033[38;5;43mChanger les couleurs de Julia\
        :\033[0m Mouse clique gauche\n");
	ft_printf("    - \033[38;5;43mExit:\033[0m ESC\n");
	ft_printf("************************************************************\n");
}

void	wrong_arg_num(void)
{
	ft_printf("\033[1;31mError: Invalid number of arguments.\033[0m,\n");
	guide();
	exit(EXIT_FAILURE);
}

void	invalid_arg(void)
{
	ft_printf("\033[1;31mError: Invalid argument.\033[0m\n");
	guide();
	exit(EXIT_FAILURE);
}

void	allocation_error(t_fractol *app, const char *message)
{
	perror(message);
	app_exit_code(app, EXIT_FAILURE);
}
