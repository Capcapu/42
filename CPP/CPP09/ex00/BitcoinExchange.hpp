/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:18:10 by csolari           #+#    #+#             */
/*   Updated: 2026/03/09 12:13:48 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <exception>

class BitcoinExchange
{
	private :
		std::string						_dataCsv;
		std::map<std::string, float>	_dataBase;
		BitcoinExchange();

	public :
		BitcoinExchange(char const * dataCsv);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &cpy);
		BitcoinExchange &operator=(BitcoinExchange const &src);

		void	loadingData();
		bool	isValidDate(const std::string &date);
		bool	isValidValue(const std::string &value);
		float	strToFloat(const std::string &str);
		
		void	processInput(char *inputFile, BitcoinExchange &btc);

		class OpenCsvException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
};

#endif