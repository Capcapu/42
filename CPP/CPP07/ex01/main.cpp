/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:32:27 by csolari           #+#    #+#             */
/*   Updated: 2026/02/17 10:54:24 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cstdio>

// Functions for char
void	ft_toupper(char &arr)
{
	arr = std::toupper(arr);
}

void	ft_printf_char(char const &arr)
{
	std::cout << arr << " ";
}

// Functions for int
void	ft_increment(int &arr)
{
	arr += 10;
}
void	ft_print_int(int &arr)
{
	std::cout << arr << " ";
}

void	ft_print_int_const(int const &arr)
{
	std::cout << arr << " ";
}

// Functions for float
void	ft_multiply(float &arr)
{
	arr *= 2.0f;
}

void	ft_print_float(float const &arr)
{
	std::cout << arr << " ";
}

// Functions for string
void	ft_append(std::string &arr)
{
	arr += "!";
}

// Template function that can work with any type
template <typename S>
void	ft_print_generic(S const &arr)
{
	std::cout << arr << " ";
}


//-------------------------------------------------------------------------------------------------------------


int	main(void)
{
	std::cout << LIGHT_BLUE << std::endl << "========== TEST 1: CHAR ARRAY (non-const) ==========" << RESET << std::endl;
	char tabChar[] = {'a', 'b', 'c', 'd'};
	std::cout << "Before: ";
	for (size_t i = 0; i < 4; i++)
		std::cout << tabChar[i] << " ";
	std::cout << std::endl;

	::iter(tabChar, 4, ft_toupper);
	
	std::cout << "After toupper: ";
	for (size_t i = 0; i < 4; i++)
		std::cout << tabChar[i] << " ";
	std::cout << "\n\n";

	//--------------------------------------


	std::cout << LIGHT_BLUE << std::endl << "========== TEST 2: CHAR ARRAY (const) ==========" << RESET << std::endl;
	char const tabCharConst[] = {'x', 'y', 'z'};
	std::cout << "Const array: ";
	::iter(tabCharConst, 3, ft_printf_char);
	std::cout << "\n\n";

	//--------------------------------------


	std::cout << LIGHT_BLUE << std::endl << "========== TEST 3: INT ARRAY (non-const) ==========" << RESET << std::endl;
	int tabInt[] = {1, 2, 3, 4, 5};
	std::cout << "Before: ";
	::iter(tabInt, 5, ft_print_int);
	std::cout << std::endl;

	::iter(tabInt, 5, ft_increment);
	
	std::cout << "After increment (+10): ";
	::iter(tabInt, 5, ft_print_int_const); //will work, implicit conversion from int to int const
	std::cout << "\n\n";

	//--------------------------------------


	std::cout << LIGHT_BLUE << std::endl << "========== TEST 4: INT ARRAY (const) ==========" << RESET << std::endl;
	int const tabIntConst[] = {10, 20, 30, 40};
	std::cout << "Const array: ";
	::iter(tabIntConst, 4, ft_print_int_const);
	// ::iter(tabIntConst, 4, ft_print_int); // shouldn't work, non-const function on const array -> error compilation
	std::cout << "\n\n";

	//--------------------------------------


	std::cout << LIGHT_BLUE << std::endl << "========== TEST 5: FLOAT ARRAY (non-const) ==========" << RESET << std::endl;
	float tabFloat[] = {1.5f, 2.5f, 3.5f};
	std::cout << "Before: ";
	::iter(tabFloat, 3, ft_print_float); // print float const fct
	std::cout << std::endl;

	::iter(tabFloat, 3, ft_multiply);
	
	std::cout << "After multiply (*2): ";
	::iter(tabFloat, 3, ft_print_float);
	std::cout << "\n\n";

	//--------------------------------------


	std::cout << LIGHT_BLUE << std::endl << "========== TEST 6: FLOAT ARRAY (const) ==========" << RESET << std::endl;
	float const tabFloatConst[] = {5.5f, 6.5f, 7.5f};
	std::cout << "Const array: ";
	::iter(tabFloatConst, 3, ft_print_float);
	std::cout << "\n\n";

	//--------------------------------------


	std::cout << LIGHT_BLUE << std::endl << "========== TEST 7: STRING ARRAY (non-const) ==========" << RESET << std::endl;
	std::string tabString[] = {"Hello", "World", "Test"};
	std::cout << "Before: ";
	::iter(tabString, 3, ft_print_generic<std::string>); //using an instanciated function template
	std::cout << std::endl;

	::iter(tabString, 3, ft_append);
	
	std::cout << "After append (!): ";
	::iter(tabString, 3, ft_print_generic<std::string>);
	std::cout << std::endl << std::endl;

	//--------------------------------------


	std::cout << LIGHT_BLUE << std::endl << "========== TEST 8: STRING ARRAY (const) ==========" << RESET << std::endl;
	std::string const tabStringConst[] = {"Const", "String", "Array"};
	std::cout << "Const array: ";
	::iter(tabStringConst, 3, ft_print_generic<std::string>); // again function template
	std::cout << "\n";

	return 0;
}