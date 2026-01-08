/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:07:22 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 14:40:23 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;
    int sign = 1;

    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - 48);
        i++;
    }
    return(res * sign);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(unsigned int n)
{
    if(n > 9)
        ft_putnbr(n / 10);
    ft_putchar(n % 10 + '0');
}

int is_prime(unsigned int n)
{
     unsigned int i;

    i = 2;
    if (n < 2)
        return 0;
    while(i <= n)     //!!!!!
    {
        if(n % i == 0)
            return(0);
        i++;
    }                 //!!!!!!!
    return(1);
}


int	main(int ac, char **av)
{
	int	nb = 0;
	int	sum = 0;

	if (ac == 2)
	{
		nb = ft_atoi(av[1]); // atoi le av[1]                           //!!!!!!!!!!
		while (nb) // tant que nb existe on verifie si il est premier
		{
			if (is_prime(nb)) // si il est un nombres premiers on l'ajoute a la somme
				sum += nb;
			nb--;
		}
		ft_putnbr(sum); // on affiche la somme des nombres premiers      ////!!!!!!
	}
	else
		write(1, "0", 1); // sinon on affiche 0 puis \n
	write(1, "\n", 1);
}
