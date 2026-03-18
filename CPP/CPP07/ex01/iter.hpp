/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:57:04 by csolari           #+#    #+#             */
/*   Updated: 2026/02/06 14:57:15 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>
#include "Colors.hpp"

template <typename T, typename U>
void	iter(T *array, size_t const length, U (*function)(T&))
{
	std::cout << ORANGE << "Uses default template" << RESET << std::endl;
	if (array == NULL || function == NULL)
		return;
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

template <typename T, typename U> //specialization partial for const array
void	iter(T const *array, size_t const length, U (*function)(T const &))
{
	std::cout << ORANGE << "Uses template const" << RESET << std::endl;
	if (function == NULL)
		return;
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

#endif