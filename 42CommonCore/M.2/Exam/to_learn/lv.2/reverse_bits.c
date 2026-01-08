/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:30:17 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/30 13:30:26 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char res = 0;
    unsigned int i = 8;
    while(i--)
    {
        res = (res << 1) | (octet & 1);
        octet = octet >> 1;
    }
    return(res);
}
