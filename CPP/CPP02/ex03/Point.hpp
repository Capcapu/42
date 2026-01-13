/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:16:56 by csolari           #+#    #+#             */
/*   Updated: 2025/10/27 15:23:47 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <stdlib.h>
#include "Fixed.hpp"

class Point {

	private:

	const Fixed		_x;
	const Fixed		_y;

	public:

	Point( void );
	Point(const float f1, const float f2);
	Point(const Point &copy);
	Point &operator=(const Point& other);
	~Point( void );
	const Fixed	&getX(void)const;
	const Fixed	&getY(void)const;
};

#endif