/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:33:26 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/03 14:25:49 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_arg(int ac, char *av[])
{
	int		i;
	char	*tmp_str;

	i = 1;
	tmp_str = ft_strdup("");
	while (i < ac)
	{
		tmp_str = ft_strjoin(tmp_str, av[i]);
		i++;
	}
	return (tmp_str);
}


// initialize and join all the arguments into a tmp string

// Split everything into an array + make sure to get the size for the stack fill

// validatae the string (check if all digits)

int not_nbr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

// check integers rang> put them into long int using atol, 
//check for int min/max and display an error if not right

// check for duplicates

// clean everything up

// overall use function to check and verify 
//everything => is_not_digit, check_dup, error cases etc.