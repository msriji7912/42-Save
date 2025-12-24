/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:40:03 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/16 20:50:37 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write (fd, &str[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
/*
int	main(void)
{
	char	*str = "Ye suis nul";
	ft_putendl_fd(str, 1);
	return 0;
}
*/