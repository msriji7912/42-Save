/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:44:38 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/21 05:42:18 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct file
{
	void	*mlx_connection;
	void	*mlx_window;
}			file;

int	main(void)
{
	file *fractol;

	fractol = malloc(sizeof(file));
	if (!fractol)
		return (1);
	fractol->mlx_connection = mlx_init();
	if (fractol->mlx_connection == NULL)
		return (1);
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, 900, 700,
			"My window <3");
    if (!fractol->mlx_window)
    {
        mlx_destroy_display(fractol->mlx_connection);
	    free(fractol->mlx_connection);
        free(fractol);
	    return (1);
    }
	// mlx_loop(mlx_connection);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
    free(fractol);
	return (0);
}
