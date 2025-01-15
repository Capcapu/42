/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1repeat_alpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:22:47 by csolari           #+#    #+#             */
/*   Updated: 2025/01/14 11:41:13 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	main(int argc, char **argv)
{
	int	i;
	int	dif;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 65 && argv[1][i] <= 90)
            {
                dif = argv[1][i] - 65;
                while (dif > 0)
                {
                    write(1, &argv[1][i],1);
                    dif--;
                }
            }
            if (argv[1][i] >= 97 && argv[1][i] <= 122)
            {
                dif = argv[1][i] - 97;
                while (dif > 0)
                {
                    write(1, &argv[1][i],1);
                    dif--;
                }
            }
            write(1, &argv[1][i],1);
            i++;
		}
	}
    write(1, "\n", 1);
    return(0);
}