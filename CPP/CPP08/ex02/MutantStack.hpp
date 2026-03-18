/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:59:33 by csolari           #+#    #+#             */
/*   Updated: 2026/02/27 17:22:43 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

// std::stack n'est pas un vrai conteneur, c est une sorte d'adaptateur. Il utilise un 
// conteneur en dessous : deque. stack est un emballage autour d un deque. Ses operations
// push, pop, top, size etc sont redirigees vers celles de deque interne.
// stack n'a pas d iterateur, on va donc chercher ceux du conteneur interne deque, qui lui en a.


template <typename T>
class MutantStack : public std::stack<T>
{	
	public :

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		// on accede au conteneur interne de stack grace a container_type, c est lui qui contient les elements
		// on met typename car le type est dependant du template T
		// -> on recupere les types d iterateurs du conteneur interne de stack
		
		MutantStack();
		~MutantStack();
		MutantStack(MutantStack const &cpy);
		MutantStack &operator=(MutantStack const &src);
	
		iterator	begin();
		iterator	end();

		const_iterator	begin() const;
		const_iterator	end() const;

		reverse_iterator	rbegin();
		reverse_iterator	rend();

		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};

#endif