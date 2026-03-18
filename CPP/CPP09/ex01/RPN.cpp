/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 21:04:18 by csolari           #+#    #+#             */
/*   Updated: 2026/03/13 22:12:58 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(char *input) : _input(input) {}

RPN::~RPN() {}

RPN::RPN(RPN const &cpy)
{
    *this = cpy;
}

RPN &RPN::operator=(RPN const &src)
{
    // std::cout << ORANGE << "RPN assignation operator called" RESET << std::endl;
    if (this != &src)
    {
        _input = src._input;
        _list = src._list;
    }
    return *this;
}

int    RPN::calculate()
{
    if (_input.empty())
        throw   ErrorException("Empty input");

    size_t start = 0;
    while (start < _input.size())
    {
        while (start < _input.size() && _input[start] == ' ')
            start++;
        if (start >= _input.size())
            break;

        size_t end = _input.find_first_of(' ', start);
        std::string token;
        if (end == std::string::npos)
            token = _input.substr(start);
        else
            token = _input.substr(start, end - start);

        if (token.size() != 1)
            throw ErrorException("Invalid token, must be a single character");
        if (std::isdigit(token[0]))
            _list.push_back(static_cast<int>(token[0] - '0'));
        else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
        {
            if (_list.size() < 2)
                throw ErrorException("Not enough operands");
            int result = 0;
            int a = _list.back();
            _list.pop_back();
            int b = _list.back();
            _list.pop_back();
            switch (token[0])
            {
                case '+':
                    result = b + a;
                    break;
                case '-':
                    result = b - a;
                    break;
                case '*':
                    result = b * a;
                    break;
                case '/':
                    if (a == 0)
                        throw ErrorException("Division by zero");
                    result = b / a;
                    break;
            }
            _list.push_back(result); 
        }
        else 
            throw ErrorException("Invalid token");

        if (end == std::string::npos)
            break;
        start = end + 1;
    }

    if (_list.size() != 1)
        throw ErrorException("Invalid input");

    return _list.back();
}



RPN::ErrorException::ErrorException() : _message("Error") {}

RPN::ErrorException::ErrorException(std::string const &detail)
    : _message("Error: " + detail) {}

RPN::ErrorException::~ErrorException() throw() {}

const char* RPN::ErrorException::what() const throw()
{
    return _message.c_str();
}

