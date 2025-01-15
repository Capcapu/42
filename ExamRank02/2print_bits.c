/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2print_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:52:34 by csolari           #+#    #+#             */
/*   Updated: 2025/01/15 14:09:47 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void print_bits(unsigned char octet)
{
    int i = 8;
    unsigned char   bit;

    while(i--)
    {
        bit = (octet >> i & 1) + '0';
        write(1, &bit, 1);
    }

    
}

int main(void)
{

    print_bits(8);
}