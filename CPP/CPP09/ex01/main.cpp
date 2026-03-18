/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 21:04:10 by csolari           #+#    #+#             */
/*   Updated: 2026/03/13 21:04:16 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED << "Error: invalid number of arguments." << RESET << std::endl;
        return 1;
    }
    RPN rpn(argv[1]);
    try
    {
       std::cout << rpn.calculate() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    return 0;
}