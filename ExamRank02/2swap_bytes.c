/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2swap_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:15:37 by csolari           #+#    #+#             */
/*   Updated: 2025/01/14 14:37:28 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void    print_bits(unsigned char c)
{
    int nb;
    int i;
    int divider;
    
    nb = (int)c;
    i = 0;
    divider = 128;
    while (i < 8)
    {
        if (nb / divider == 1)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        nb = nb % divider;
        divider = divider / 2;
        i++;
    }
}

unsigned char swap_bits(unsigned char octet)
{
    return (octet << 4 | octet >> 4);
}
/*
unsigned char   reverse_bits(unsigned char octet)
{
    int nb;
    int i;
    int divider;
    int bits[8];
    int result;
        
    nb = (int)octet;
    i = 0;
    divider = 128;
    result = 0;
    while (i < 8)
    {
        if (nb / divider == 1)
            bits[7 - i] = 1;
        else
            bits[7 - i] = 0;
        nb = nb % divider;
        divider = divider / 2;
        i++;
    }
    i = 0;
    divider = 128;
    while (i < 8)
    {
        result += divider * bits[i];
        i++;
        divider = divider / 2;
    }
    return ((unsigned char)result);
}
*/

unsigned char reverse_bits(unsigned char b)
{
	unsigned char	r = 0;
	unsigned		byte_len = 8;

	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}


int main(int argc, char *argv[])
{
    unsigned char c;
    (void)argc;

    c = argv[1][0];
    print_bits(c);
    printf("\n_________\n");
    print_bits(swap_bits(c));
    printf("\n_________\n");
    print_bits(reverse_bits(c));

}