/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:54:16 by csolari           #+#    #+#             */
/*   Updated: 2026/02/27 18:00:14 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include<vector>
#include<iterator>

class Span
{
	private:
		std::vector<int>	_span;
		unsigned int	_size;
		unsigned int	_pos;
		Span();

	public :
		Span(unsigned int N);
		Span(Span const &cpy);
		~Span();
		Span &operator=(Span const &src);

		void	addNumber(int number);
		void	addNumber(std::vector<int>::iterator rangeStart, std::vector<int>::iterator rangeEnd);
		int	shortestSpan();
		int	longestSpan();

		unsigned int	getPos();
		unsigned int	getSize();
		std::vector<int>	getSpan();	

		class FullSpanException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

		class NoSpanPossibleException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
};

#endif