/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 21:33:12 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/23 03:00:14 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>

typedef struct file
{
	void	*mlx_connection;
	void	*mlx_window;
}			file;

typedef struct as_complex
{
	double	real;
	double	imaginary;
}			t_complex;

/*        UTILS      */
void		error_mess(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/*    FRACTOL MOUHAHA */


#endif