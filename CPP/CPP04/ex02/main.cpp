/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:32:32 by csolari           #+#    #+#             */
/*   Updated: 2025/10/30 11:46:35 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include "colors.h"

int main()
{
	//Animal test; //toute seule pas de sens, via l heritage oui.

	int	i = 0;
	const	Animal	*meta[20];

	while (i < 10)
	{
		meta[i] = new Dog();
		if (meta[i] == NULL)
		{
			for (int j = 0; j < i; j++)
				delete meta[j];
			return(1);
		}
		i++;
	}
	while (i < 20)
	{
		meta[i] = new Cat();
		if (meta[i] == NULL)
		{
			for (int j = 0; j < i; j++)
				delete meta[j];
			return(1);
		}
		i++;
	}


	Dog* dog = (Dog*)meta[4];
	dog->setIdeas(0, "Je veux jouer avec une balle !");
	std::cout << "Idée du chien (index 4) : " << dog->getIdeas(0) << std::endl;
	

	Cat* cat = (Cat*)meta[15];
	cat->setIdeas(0, "J'aimerais dormir au soleil");
	std::cout << "Idée du chat (index 15) : " << cat->getIdeas(0) << std::endl;
	

	for (int j = 0; j < i; j++)
		delete meta[j];



	return 0;
}