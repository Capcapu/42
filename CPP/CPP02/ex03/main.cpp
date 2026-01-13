/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:49:36 by csolari           #+#    #+#             */
/*   Updated: 2025/10/27 16:39:20 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);




int main( void )
{
	Point	a=Point(3, 6);
	Point	b=Point(1, 2);
	Point	c=Point(5, 4);
	Point	test=Point(3, 5);
	Point	test2=Point(3, 7);

	//IN
	if (bsp(a, b, c, test))
		std::cout << "le point x=" << test.getX().toInt() << " et y=" << test.getY().toInt() << " est dans le triangle " <<std::endl;
	else
		std::cout << "le point x=" << test.getX().toInt() << " et y=" << test.getY().toInt() << " est en dehors du triangle " <<std::endl;

	//OUT
	if (bsp(a, b, c, test2))
		std::cout << "le point x=" << test2.getX().toInt() << " et y=" << test2.getY().toInt() << " est dans le triangle " <<std::endl;
	else
		std::cout << "le point x=" << test2.getX().toInt() << " et y=" << test2.getY().toInt() << " est en dehors du triangle " <<std::endl;

	Point	d=Point(0, 10);
	Point	e=Point(0, 0);
	Point	f=Point(5, 0);
	Point	test3=Point(1, 1);
	Point	test4=Point(3, 9);

	//IN
	if (bsp(d, e, f, test3))
		std::cout << "le point x=" << test3.getX().toInt() << " et y=" << test3.getY().toInt() << " est dans le triangle " <<std::endl;
	else
		std::cout << "le point x=" << test3.getX().toInt() << " et y=" << test3.getY().toInt() << " est en dehors du triangle " <<std::endl;

	//OUT
	if (bsp(d, e, f, test4))
		std::cout << "le point x=" << test4.getX().toInt() << " et y=" << test4.getY().toInt() << " est dans le triangle " <<std::endl;
	else
		std::cout << "le point x=" << test4.getX().toInt() << " et y=" << test4.getY().toInt() << " est en dehors du triangle " <<std::endl;

	return(0);
}
