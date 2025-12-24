/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:50:20 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/16 21:09:13 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd ('-', fd);
	}
	if (nbr >= 10)
		ft_putnbr_fd((nbr / 10), fd);
	ft_putchar_fd(((nbr % 10) + '0'), fd);
}
/*
int	main(void)
{
	int	n = 7912;
	ft_putnbr_fd(n, 1);
	return 0;
}
*/