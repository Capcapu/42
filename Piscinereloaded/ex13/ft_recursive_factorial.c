/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:18:51 by csolari           #+#    #+#             */
/*   Updated: 2024/11/05 16:04:55 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	res;

	if (nb < 0)
		return (0);
	if (nb == 0)
		res = 1;
	else
		res = nb * ft_recursive_factorial(nb - 1);
	return (res);
}

/*
int main(void)
{
	printf("%d", ft_recursive_factorial(3));
	return(0);
}
*/
