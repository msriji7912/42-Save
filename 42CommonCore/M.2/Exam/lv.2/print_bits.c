/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:29:44 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/31 12:31:54 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_bits(unsigned char octet)
{
    unsigned int i;
    char bit;
    
    i = 8;
    while(i--)
    {
        bit = (octet >> i & 1) + '0';
        write(1, &bit, 1);
    }
}

void	print_bits(unsigned char octet)
{
if (octet - 128 >= 0 && octet - 128 <= 128)
{    
    write (1 , "1", 1);
    octet -= 128;
}
else 
    write (1, "0", 1);
}
