/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:18:00 by csolari           #+#    #+#             */
/*   Updated: 2026/03/13 21:06:45 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Colors.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(char const *dataCsv) : _dataCsv(dataCsv)
{
	// std::cout << ORANGE << "BitcoinExchange constructor called" <<  RESET << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << ORANGE << "BitcoinExchange destructor called" RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy)
{
	// std::cout << ORANGE << "BitcoinExchange copy constructor called" RESET << std::endl;
    *this = cpy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	// std::cout << ORANGE << "BitcoinExchange assignation operator called" RESET << std::endl;
	if (this != &src)
	{
		this->_dataCsv = src._dataCsv;
		this->_dataBase = src._dataBase;
	}
	return *this;
}

void	BitcoinExchange::loadingData()
{
	std::ifstream file(this->_dataCsv.c_str());
	if (!file.is_open())
		throw OpenCsvException();

	std::string line;
	bool firstLine = true;

	this->_dataBase.clear();
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date;
		std::string value;

		if (firstLine == true && line == "date,exchange_rate")
		{
			firstLine = false;
			continue;
		}

		if (!std::getline(ss, date, ',') || !std::getline(ss, value))
		{
			std::cerr << RED << "Error: invalid line format in data.csv: " << line << RESET << std::endl;
			continue;
		}
		if (!isValidDate(date))
		{
			std::cerr << RED << "Error: invalid date format in data.csv: " << date << RESET << std::endl;
			continue;
		}
		if (!isValidValue(value))
		{
			std::cerr << RED << "Error: invalid value format in data.csv: " << value << RESET << std::endl;
			continue;
		}
		else
			this->_dataBase[date] = strToFloat(value);
	}
}

bool	BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year > 2026)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2)
	{
		bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > 29 || (day == 29 && !isLeapYear))
			return false;
	}
	return true;
}

bool	BitcoinExchange::isValidValue(const std::string &value)
{
	if (value.empty())
		return false;
	std::stringstream ss(value);
	float val;
	
	if (!(ss >> val) || !ss.eof())
		return false;
	return true;
}

float	BitcoinExchange::strToFloat(const std::string &str)
{
	std::istringstream ss(str);
	float value;
	ss >> value;
	if (ss.fail())
		return -1;
	return value;
}

void	BitcoinExchange::processInput(char *inputFile, BitcoinExchange &btc)
{
	std::ifstream file(inputFile);
	std::string line;
	bool firstLine = true;

	if (!file.is_open())
	{
		std::cerr << RED << "Error: could not open file." << RESET << std::endl;
		return;
	}

	while (std::getline(file, line))
	{	
		if (firstLine && line == "date | value")
		{
			firstLine = false;
			continue;
		}

		size_t pipe_pos = line.find('|');
		if (pipe_pos == std::string::npos || line.find('|', pipe_pos + 1) != std::string::npos)
		{
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
			continue;
		}
		std::string date = line.substr(0, pipe_pos);
		std::string value = line.substr(pipe_pos + 1);
		size_t dateStart = date.find_first_not_of(" \t");
		size_t dateEnd = date.find_last_not_of(" \t");
		if (dateStart == std::string::npos )
		{
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
			continue;
		}
		date = date.substr(dateStart, dateEnd - dateStart + 1);
		if (date.find(' ') != std::string::npos || date.find('\t') != std::string::npos)
		{
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
			continue;
		}
		size_t valueStart = value.find_first_not_of(" \t");
		size_t valueEnd = value.find_last_not_of(" \t");
		if (valueStart == std::string::npos )
		{
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
			continue;
		}
		value = value.substr(valueStart, valueEnd - valueStart + 1);
		if (value.find(' ') != std::string::npos || value.find('\t') != std::string::npos)
		{
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
			continue;
		}
		if (!isValidDate(date))
		{
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
			continue;
		}
		if (!isValidValue(value))
		{
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
			continue;
		}
		float inputValue = strToFloat(value);
		if (inputValue < 0)
		{
			std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
			continue;
		}
		if (inputValue > 1000)
		{
			std::cerr << RED << "Error: too large a number." << RESET << std::endl;
			continue;
		}


		std::map<std::string, float>::iterator it = btc._dataBase.lower_bound(date);
		if (it != btc._dataBase.end() && it->first == date)
		{
			std::cout << date << " => " << value << " = "  << strToFloat(value) * it->second << std::endl;
		}
		else if (it != btc._dataBase.begin())
		{
			--it;
			std::cout << date << " => " << value << " = "  << strToFloat(value) * it->second << std::endl;
		}
		else
		{
			std::cerr << RED << "Error: no exchange rate available for date " << date << RESET << std::endl;
		}
	}
	file.close();
}

const char* BitcoinExchange::OpenCsvException::what() const throw()
{
	return "Error: could not open data base file.";
}