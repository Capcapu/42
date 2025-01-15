/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1rev_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:43:12 by csolari           #+#    #+#             */
/*   Updated: 2025/01/14 12:15:07 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char *   rev_print(char *str)
{
    int i;
    
    i = 0;
    while(str[i] && str)
        i++;
    while(i >= 0)
    {
        write(1, &str[i], 1);
        i--;
    }
    write(1, "\n",1);
    return (str);
}

int main(void)
{
  rev_print("Hello world");

  rev_print("tnirp esreveR");

  rev_print("");

}