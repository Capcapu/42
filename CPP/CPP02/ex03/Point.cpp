/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:16:59 by csolari           #+#    #+#             */
/*   Updated: 2025/10/27 17:15:04 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

Point::Point(void): _x(0), _y(0)
{
	// std::cout << "Default constructor called" <<std::endl;
	return;
}

Point::~Point(void)
{
	// std::cout << "Destructor called" <<std::endl;
	return ;
}

Point::Point(const float f1, const float f2) : _x(f1), _y(f2)
{
	return ;
}

Point::Point(const Point &copy) : _x(copy.getX()), _y(copy.getY())
{
	// std::cout << "Copy constructor called" <<std::endl;
}

Point	&Point::operator=(const Point& other)
{
	// std::cout << "Copy assignement operator called" <<std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

const Fixed	&Point::getX(void)const
{
	return (_x);
}	

const Fixed	&Point::getY(void)const
{
	return(_y);
}