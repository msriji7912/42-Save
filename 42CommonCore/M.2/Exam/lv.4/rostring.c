/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:32:54 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 14:14:37 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>

void	rostring(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] && str[i] == ' ' || str[i] == '\t') // skip spaces
		i++;
	j = i; // flag le j
	while (str[i])
	{
		while (str[i] && str[i] != ' ' && str[i] != '\t') // skip first word
			i++;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))  // skip spaces
			i++;
		while ((str[i] && (str[i] != ' ' && str[i] != '\t')) && (str[i- 1] == ' ' || str[i - 1] == '\t')) // letter et avant un espace
		{
			while (str[i] && (str[i] != ' ' && str[i] != '\t')) // print next word
			{
				write(1, &str[i], 1);
				i++;
			}
			write(1, " ", 1);
			i++;
		}
	}
	while (str[j] && (str[j] != ' ' && str[j] != '\t')) // print flag word
	{
		write(1, &str[j], 1);
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		rostring(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}