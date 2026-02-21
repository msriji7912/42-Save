/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pollock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:44:38 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/21 03:31:18 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(void)
{
    void *mlx_connection;
    void *mlx_window;
    int x;
    int y;

    y = 0;
    x = 0;
    srand(time(NULL));
    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, 900, 700, "My window <3");
    while (y < 500)
    {
        x = 0;
        while(x < 700)
        {
            mlx_pixel_put(mlx_connection, mlx_window, 100+x, 100+y, rand() % 0x1000000);
            x++;
        }
        y++;
    }
    mlx_string_put(mlx_connection, mlx_window, 800, 645, rand() % 0x1000000, "My polloc <3");
    mlx_loop(mlx_connection);
}

//srand(time(NULL)); actually makes sure that the rand() function is actually random