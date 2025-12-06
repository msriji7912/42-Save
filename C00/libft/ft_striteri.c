/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:39:58 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/19 11:28:40 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!str || !f)
		return ;
	while (str[i])
	{
		f(i, &str[i]);
		i++;
	}
}
/*
int main(void)
{
	char str[] = "hello world";

	ft_striteri(str, test_func);
	printf ("%s\n", str);
	return (0);
}
*/
