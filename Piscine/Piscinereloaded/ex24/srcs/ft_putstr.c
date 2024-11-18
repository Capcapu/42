/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:43:16 by csolari           #+#    #+#             */
/*   Updated: 2024/06/28 09:57:39 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

/*
int	main()
{
	char	*p;
//	char	ch;

//	ch = "r";
//	p = &ch;
	
	p = "hey";



//        char 	*pc;
//	char 	c[];

//	c[0] = 'H';
//	c[1] = 'e';
//	c[2] = 'y';
//       pc = &c;


//	ft_putstr(pc);

	ft_putstr(p);
	ft_putstr("bonjour");
	return(0);
}
*/

/*        int index;

        ...

        str[i] + 1;
        p + 1;
        *(p + 1)
*/
