/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:58:08 by csolari           #+#    #+#             */
/*   Updated: 2026/02/06 14:57:42 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
T const		&min(T const &x, T const &y)
{
	return (x <= y ? x : y);
}

template <typename T>
T const		&max(T const &x, T const &y)
{
	return (x >= y ? x : y);
}

#endif