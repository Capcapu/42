/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 21:53:34 by csolari           #+#    #+#             */
/*   Updated: 2026/03/18 15:50:52 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include "Colors.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <limits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <sys/time.h>
#include <cstdlib>
#include <cerrno>

class	PmergeMe 
{
	private :
		std::vector<int>	_vectorData;
		std::deque<int>		_dequeData;

	public :
		PmergeMe(void);
		~PmergeMe(void);
		PmergeMe(PmergeMe const &cpy);
		PmergeMe &operator=(PmergeMe const &src);

		void	parseInput(int argc, char**argv);
		bool	isSortedVector(const std::vector<int> &vec);
		bool	isSortedDeque(const std::deque<int> &deq);

		void	execSortVector(void);
		void	execSortDeque(void);

		void	printVector(void);
		void	printDeque(void);

		size_t	getVectorSize(void) const;
		size_t	getDequeSize(void) const;

		double	getTime(void);

		class ErrorException : public std::exception
        {
            public :
                ErrorException();
                ErrorException(std::string const &detail);
                virtual ~ErrorException() throw();
                virtual const char* what() const throw();

            private :
                std::string _message;
        };
};

#endif