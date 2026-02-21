/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:44:38 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/20 21:30:37 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    void *mlx_connection;
    void *mlx_window;
    int x;
    int y;

    y = 0;
    x = 0;
    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, 900, 700, "My window <3");
    while (y < 700)
    {
        x = 0;
        while(x < 900)
        {
            mlx_pixel_put(mlx_connection, mlx_window, 0+x, 0+y, rand() % 0x1000000);
            x++;
        }
        y++;
    }
    mlx_loop(mlx_connection);
}