/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 08:14:18 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 15:32:16 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int result = 0;
    int sign = 1;
    int digit;
    
    if (str_base < 2 || str_base > 16)
        return (0);
    
    // Gestion du signe
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    
    // Conversion
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            digit = str[i] - '0';                                       // - 0
        else if (str[i] >= 'a' && str[i] <= 'f')
            digit = str[i] - 'a' + 10;                                  // 'a' + 10
        else if (str[i] >= 'A' && str[i] <= 'F')
            digit = str[i] - 'A' + 10;                                  // 'A' + 10
        else
            digit = str_base; // Valeur invalide pour arrêter           // str_base
        
        if (digit >= str_base)
            return (result * sign); // Arrêt si caractère invalide         BASE ON TOP
        
        result = result * str_base + digit;                               // res * base + digit 
        i++;
    }
    return (result * sign);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		printf("%d", ft_atoi_base(av[1], atoi(av[2])));                 // base est le av[2] !!!
	write(1, "\n", 1);
	return (0);
}