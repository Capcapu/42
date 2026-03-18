/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 21:53:40 by csolari           #+#    #+#             */
/*   Updated: 2026/03/13 21:53:46 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <list>
#include <string>
#include <exception>


class RPN
{
    public :
        RPN(char *input);
        ~RPN();
        RPN(RPN const &cpy);
        RPN &operator=(RPN const &src);

        int calculate();

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

    private :
        RPN();
        std::string _input;
        std::list<int> _list;
    
        
};


#endif