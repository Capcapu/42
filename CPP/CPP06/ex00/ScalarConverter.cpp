/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:08:11 by csolari           #+#    #+#             */
/*   Updated: 2026/02/05 10:53:36 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default ScalarConverter constructor" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &cpy)
{
	std::cout << "ScalarConverter copy constructor" << std::endl;
	*this = cpy;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor" << std::endl;
}

ScalarConverter const ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)src;
	std::cout << "ScalarConverter copy assignment operator" << std::endl;
	//nothing to copy
	return *this;
}

//-----------------------------------------

static void	printChar(char c, bool possible = true)
{
	if (!possible)
		std::cout << "char: impossible" << std::endl;
	else if (c <= 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

static void	printInt(int i, bool possible = true)
{
	if (!possible)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

static void	printFloat(float f, bool possible = true)
{
	if (!possible)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl; //revoir
}

static void	printDouble(double d, bool possible = true)
{
	if (!possible)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
}

//-----------------------------------------

static void	toChar(std::string &str)
{
	char c = str[0];

	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

static void	toInt(std::string &str)
{
	char *endptr;
	errno = 0;
	long l = strtol(str.c_str(), &endptr, 10);
	
	if (errno == ERANGE || l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
	{
		printChar('w', false);
		printInt(0, false);
		printFloat(0, false);
		printDouble(0, false);
		return;
	}
	
	int i = static_cast<int>(l);
	
	printChar(static_cast<char>(i));
	printInt(i);
	printFloat(static_cast<float>(i));
	printDouble(static_cast<double>(i));
}

static void	toFloat(std::string &str)
{
	char *endptr;
	errno = 0;
	float f = strtof(str.c_str(), &endptr);
	
	if (errno == ERANGE || *endptr != 'f')
	{
		printChar('w', false);
		printInt(0, false);
		printFloat(0, false);
		printDouble(0, false);
		return;
	}
	
	printChar(static_cast<char>(f));
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		printInt(0, false);
	else
		printInt(static_cast<int>(f));
	printFloat(f);
	printDouble(static_cast<double>(f));
}

static void	toDouble(std::string &str)
{
	char *endptr;
	errno = 0;
	double d = strtod(str.c_str(), &endptr);
	
	if (errno == ERANGE || *endptr != '\0')
	{
		printChar('w', false);
		printInt(0, false);
		printFloat(0, false);
		printDouble(0, false);
		return;
	}
	
	printChar(static_cast<char>(d));
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		printInt(0, false);
	else
		printInt(static_cast<int>(d));
	if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		printFloat(0, false);
	else
		printFloat(static_cast<float>(d));
	printDouble(d);
}

static void	toPseudoLiteral(std::string &str)
{
	printChar('c', false);
	printInt(0, false);
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
	}
	else 
	{
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
}

//-----------------------------------------

static bool	isPseudoLiteral(std::string &str)
{
	std::string pseudo[6] = {"-inff", "+inff", "nanf", "nan", "-inf", "+inf"};

	for (int i = 0; i < 6; i++)
	{
		if (str == pseudo[i])
			return true;
	}
	return false;
}

static bool	isValid(std::string &str)
{
	if (str.empty())
		return (false);	
	int	nbDot = 0;
	int	nbF = 0;
	int nbSigns = 0;
	int	caracter = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			nbDot++;
		else if (str[i] == 'f')
			nbF++;
		else if (str[i] == '-' || str[i] == '+')
			nbSigns++;
		else if (isalpha(str[i]))
			caracter++;
	}

	if (nbDot > 1 || nbSigns > 1 || nbF > 1 || caracter > 1)
		return (false);

	return (true);
}

//-----------------------------------------

void	ScalarConverter::convert(std::string &str)
{
	if (!isValid(str))
	{
		if (isPseudoLiteral(str))
		{
			toPseudoLiteral(str);
			return ;
		}
		printChar('w', false);
		printInt(0, false);
		printFloat(0, false);
		printDouble(0, false);
		return;
	}

	if (str.length() == 1 && !isdigit(str[0]))
		toChar(str);
	else if (str[str.length() - 1] == 'f')
		toFloat(str);
	else if (str.find('.') != std::string::npos)
		toDouble(str);
	else
		toInt(str);
}
