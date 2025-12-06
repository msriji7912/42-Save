/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:20:09 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/28 06:39:15 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_putnbr(long nbr);
int	ft_print_adress(void *ptrr);
int	ft_print_positf_putnbr(unsigned int nbr);
int	ft_print_hexa(long nbr);
int	ft_print_up_hexa(long nbr);
int	ft_hexa_ptr(uintptr_t nbr);

#endif