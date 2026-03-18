/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:03:39 by csolari           #+#    #+#             */
/*   Updated: 2026/02/25 14:30:09 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>

class NoOccuranceException : public std::exception
{
	public :
		virtual const char *what() const throw()
		{
			return "No occurence found in the container";
		}
};

template <typename T>
typename T::iterator	easyfind(T &lhs, int rhs)
{
	typename T::iterator it;
	it = find(lhs.begin(), lhs.end(), rhs);
	if (it == lhs.end())
		throw NoOccuranceException();
	return (it);
}

#endif