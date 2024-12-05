/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_outils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:47:14 by csolari           #+#    #+#             */
/*   Updated: 2024/12/04 10:40:23 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_putstr_fd(char *s)
{
	int	len_s;

	len_s = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (len_s);
}

static char	*ft_convert_base(unsigned long int n, char *base)
{
	int					i;
	char				*s;
	unsigned long int	nb;

	nb = n;
	i = 0;
	while (nb / 16 > 0)
	{
		i++;
		nb = nb / 16;
	}
	s = (char *)malloc(sizeof(char) * (i + 2));
	ft_bzero(s, i + 2);
	if (!s)
		return (NULL);
	s[i] = 0;
	while (i >= 0)
	{
		s[i] = base[n % 16];
		n = n / 16;
		i--;
	}
	return (s);
}

int	ft_print_hex(unsigned int n, char *base)
{
	char	*s;
	int		len;

	s = ft_convert_base((unsigned long int)n, base);
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

int	ft_print_putptr(unsigned long int p)
{
	int		len;
	char	*s;

	len = 0;
	if (!p)
		return (ft_print_putstr_fd("(nil)"));
	s = ft_convert_base(p, "0123456789abcdef");
	len = ft_strlen(s);
	len += ft_print_putstr_fd("0x");
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

// int	main()
// {
// 	char	*p;
// 	p = ft_convert_base(2671, "0123456789abcdef");
// 	printf("%s", p);
// 	free(p);
// 	return(0);
// }