/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:26:28 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/19 11:28:54 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write (fd, &str[i], 1);
		i++;
	}
}
/*
int	main(void)
{
	char	*str = "Ye suis nul";
	ft_putstr_fd(str, 1);
	return 0;
}
*/
