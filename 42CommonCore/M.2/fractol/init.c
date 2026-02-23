/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 21:30:31 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/23 00:54:08 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	file	*fractol;

	fractol = malloc(sizeof(file));
	if (!fractol)
		return (1);
	fractol->mlx_connection = mlx_init();
	if (fractol->mlx_connection == NULL)
	{
		free (fractol);
		return (1);
	}	
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, 900, 800,
			"My fractal<3");
	if (!fractol->mlx_window)
	{
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		free(fractol);
		return (1);
	}
	mlx_loop(fractol->mlx_connection); // leak bc of the damn loop...
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
	free(fractol);
	return (0);
}
