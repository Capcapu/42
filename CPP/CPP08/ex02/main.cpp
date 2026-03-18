/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:59:05 by csolari           #+#    #+#             */
/*   Updated: 2026/02/27 17:25:36 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "MutantStack.tpp"
#include <iostream>
#include <list>
#include <string>

static void subjectTest()
{
	std::cout << BOLD_BLUE << "================ SUBJECT TEST ================" << RESET << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << ITALIC_GREEN << "Forward iteration:" << RESET << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	(void)s;
}

//----------------------------------------------------------------------------------------------------------------

static void listComparisonTest()
{
	std::cout << BOLD_BLUE << "================ LIST COMPARISON TEST ================" << RESET << std::endl;

	MutantStack<int> mstack;
	std::list<int>   lst;

	for (int i = 0; i < 10; ++i)
	{
		mstack.push(i * 10);
		lst.push_back(i * 10);
	}

	std::cout << ITALIC_GREEN << "MutantStack iteration:" << RESET << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << ITALIC_GREEN << "std::list iteration:" << RESET << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

//----------------------------------------------------------------------------------------------------------------

static void reverseAndConstTest()
{
	std::cout << BOLD_BLUE << "================ REVERSE & CONST TEST ================" << RESET << std::endl;

	MutantStack<std::string> mstack;
	mstack.push("first");
	mstack.push("second");
	mstack.push("third");
	mstack.push("fourth");

	std::cout << ITALIC_GREEN << "Reverse iteration:" << RESET << std::endl;
	for (MutantStack<std::string>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	const MutantStack<std::string> cstack(mstack);
	std::cout << ITALIC_GREEN << "Const forward iteration:" << RESET << std::endl;
	for (MutantStack<std::string>::const_iterator it = cstack.begin(); it != cstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

//----------------------------------------------------------------------------------------------------------------

static void copyAndAssignTest()
{
	std::cout << BOLD_BLUE << "================ COPY / ASSIGN TEST ================" << RESET << std::endl;

	MutantStack<int> original;
	for (int i = 1; i <= 5; ++i)
		original.push(i);

	MutantStack<int> copy(original);
	MutantStack<int> assigned;
	assigned = original;

	std::cout << ITALIC_GREEN << "Original:" << RESET << std::endl;
	for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << ITALIC_GREEN << "Copy:" << RESET << std::endl;
	for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << ITALIC_GREEN << "Assigned:" << RESET << std::endl;
	for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

//----------------------------------------------------------------------------------------------------------------

int main()
{
	subjectTest();
	std::cout << std::endl;

	listComparisonTest();
	std::cout << std::endl;

	reverseAndConstTest();
	std::cout << std::endl;

	copyAndAssignTest();
	return 0;
}