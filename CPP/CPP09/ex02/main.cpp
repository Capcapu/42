/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 21:07:44 by csolari           #+#    #+#             */
/*   Updated: 2026/03/18 17:39:06 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Colors.hpp"
#include <iomanip>

int	main(int argc, char **argv)
{
	PmergeMe	sort;

	try
	{
		sort.parseInput(argc, argv);
		
		std::cout << "Before: " << ORANGE;
		sort.printVector();
		std::cout << RESET;
		
		double startTime = sort.getTime();
		sort.execSortVector();
		double timeVector = sort.getTime() - startTime;

		startTime = sort.getTime();
		sort.execSortDeque();
		double timeDeque = sort.getTime() - startTime;

		std::cout << "After: " << PINK;
		sort.printVector();

		std::cout << RESET;
		std::cout << "Time t process a range of " << sort.getVectorSize() << " elements with std::vector : " << GREEN << timeVector << " us" << RESET << std::endl;
		std::cout << "Time t process a range of " << sort.getDequeSize() << " elements with std::deque : " << GREEN << timeDeque << " us" << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

}


/* *********************************************************
 
Vector:
- provides insertion and deletion methods at middle and end
- bad performances for deleting and inserting at the beginning of the vector,
  as it requires shifting all elements to the right or left
- stores ekements contiguously in memory, which allows for efficient access and iteration
- good performance for addition and deletion of elements at the end
- its time complexity of insertion in front or in the middle is O(n) because it requires shifting all elements to the right
- its time complexity of deletion at the end is O(n)

Deque:
- provides insertion and deletion methods at middle, end and beginning
- good performances for deleting and inserting at the beginning of the deque
- stores elements in non-contiguous memory locations, which can lead to less efficient access and iteration compared to a vector
  itcontains lists of chunks where elements are stored contiguously, but the chunks themselves may not be contiguous in memory. 
- good performance for addition and deletion of elements at the end
- its time complexity of insertion in front and end is O(1) 
- its time complexity of deletion at the end is O(1)


-> We must choose deque when we need to perform frequent insertions and deletions at both ends of the container
   We must choose vector when we need to perform frequent insertions and deletions in the middle of the container

./PmergeMe $(shuf -i 1-1000 -n 100 | tr '\n' ' ')

********************************************************** */