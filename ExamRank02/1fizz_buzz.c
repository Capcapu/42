/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1fizz_buzz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:00:03 by csolari           #+#    #+#             */
/*   Updated: 2025/01/14 11:14:17 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void    ft_write_number(int n)
{
    char    str[10]= "0123456789";

    if (n > 9)
        ft_write_number(n / 10);
    write(1, &str[n % 10], 1);
}


int main(void)
{
    int i;
    char c;

    c = '0';
    i = 1;
    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_write_number(i);
        write(1, "\n", 1);
        i++;
    }
    return(0);
}