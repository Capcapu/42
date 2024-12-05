/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:58:38 by csolari           #+#    #+#             */
/*   Updated: 2024/12/04 11:14:57 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <ctype.h>
# include "Libft/libft.h"

int	ft_printf(const char *arg0, ...);
int	ft_print_putchar_fd(char c);
int	ft_print_putstr_fd(char *s);
int	ft_print_putstr_void_fd(void *s);
int	ft_print_putnbr_fd(int nbr);
int	ft_print_uns_dec(unsigned int nbr);
int	ft_print_hex(unsigned int n, char *base);
int	ft_print_putptr(unsigned long int nbr);

#endif