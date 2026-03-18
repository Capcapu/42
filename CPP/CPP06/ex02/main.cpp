/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:00:14 by csolari           #+#    #+#             */
/*   Updated: 2026/02/05 10:51:03 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include "Colors.hpp"

Base	*generate(void)
{
	Base *one;
	// initialize random seed
	srand(time(NULL)); 

	// generate number between 0 and 2
	int	i = rand() % 3;
	
	if (i == 0)
	{
		std::cout << ORANGE << "New A generated" << RESET << std::endl;
		one = new A;
	}
	else if (i == 1)
	{
		std::cout << ORANGE << "New B generated" << RESET << std::endl;
		one = new B;
	}
	else
	{
		std::cout << ORANGE << "New C generated" << RESET << std::endl;
		one = new C;
	}
	return one;
}

void	identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	if (a != NULL)
	{
		std::cout << GREEN << "Pointer p is a A type" << RESET << std::endl ;
		return ;
	}
	B *b = dynamic_cast<B *>(p);
	if (b != NULL)
	{
		std::cout << GREEN << "Pointer p is a B type" << RESET << std::endl ;
		return ;
	}
	C *c = dynamic_cast<C *>(p);
	if (c != NULL)
	{
		std::cout << GREEN << "Pointer p is a C type" << RESET << std::endl ;
		return ;
	}
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << PINK << "object referenced by p is a A type" << RESET << std::endl ;
		return ;
	}
	catch(std::exception &bc) {}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << PINK << "object referenced by p is a B type" << RESET << std::endl ;
		return ;
	}
	catch(std::exception &bc) {}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << PINK << "object referenced by p is a C type" << RESET << std::endl ;
		return ;
	}
	catch(std::exception &bc) {}
}

int	main()
{
	Base * ptr = generate();

	identify(ptr);
	identify(*ptr);

	delete ptr;
	return 0;
}
