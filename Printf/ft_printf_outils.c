/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:10:02 by csolari           #+#    #+#             */
/*   Updated: 2024/12/04 11:17:56 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_putchar_fd(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_putstr_void_fd(void *s)
{
	int	len_s;

	if (s == NULL)
	{
		len_s = ft_print_putstr_fd("(null)");
		return (len_s);
	}
	len_s = ft_strlen((char *)s);
	ft_putstr_fd((char *)s, 1);
	return (len_s);
}

int	ft_print_putnbr_fd(int nbr)
{
	int		len;
	char	*n;

	n = ft_itoa(nbr);
	ft_putstr_fd(n, 1);
	len = ft_strlen(n);
	free(n);
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				i;
	unsigned long	nbr;

	nbr = n;
	i = 0;
	while (nbr / 10 > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	nbr = n;
	i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i > 0)
	{
		str[i - 1] = (nbr % 10) + 48;
		nbr = nbr / 10;
		i--;
	}
	return (str);
}

int	ft_print_uns_dec(unsigned int nbr)
{
	int		len;
	char	*n;

	n = ft_uitoa(nbr);
	ft_putstr_fd(n, 1);
	len = ft_strlen(n);
	free(n);
	return (len);
}
