/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:59:18 by csolari           #+#    #+#             */
/*   Updated: 2026/02/27 17:18:29 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << ORANGE << "MutantStack constructor called" << RESET << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << ORANGE << "MutantStack destructor called" << RESET << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &cpy) : std::stack<T>(cpy)
{
	std::cout << ORANGE << "MutantStack copy constructor called" << RESET << std::endl;
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack const &src)
{
	std::cout << ORANGE << "MutantStack assignment operator called" << RESET << std::endl;
	if (this != &src)
		std::stack<T>::operator=(src);
	return(*this);
};


//---------------------------------------------------------------------------


template <typename T> // on definit une fonction de template pour n'importe quel type T
// on doit mettre typename devant le type de retour car iterator est defini dans
// la classe et c'est un type dependant du template
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin()); 
}
// "c" est le membre protege de std::stack qui represente le conteneur sous jacent (deque)
// ".begin()" on renvoie l iterateur de ce conteneur sous jacent
// -> on expose les iterateurs du conteneur interne de std::stack, ce que lui meme ne fait pas

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return (std::stack<T>::c.end());
}


//---------------------------------------------------------------------------


template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin()
{
	return (std::stack<T>::c.rbegin());
}


template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend()
{
	return (std::stack<T>::c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend() const
{
	return (std::stack<T>::c.rend());
}
