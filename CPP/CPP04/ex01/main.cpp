/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:32:32 by csolari           #+#    #+#             */
/*   Updated: 2025/10/29 18:13:31 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include "colors.h"

int main()
{
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

///////////////////////////////////////////////////////////////////////////////////////////
	
	
	std::cout << std::endl;
	std::cout << "test copie profonde" << std::endl ;
	
	Dog* originalDog = new Dog();
	originalDog->setIdeas(0, "yeeees des croquettes!");
	originalDog->setIdeas(1, "on peut jouer! on peut jouer!??");
	
	std::cout << "Dog original - Idée 0: " << originalDog->getIdeas(0) << std::endl;
	std::cout << "Dog original - Idée 1: " << originalDog->getIdeas(1) << std::endl << std::endl;
	




	Dog* copiedDog = new Dog(*originalDog);
	std::cout << "\nAprès copie par constructeur:" << std::endl;
	std::cout << "Dog copié - Idée 0: " << copiedDog->getIdeas(0) << std::endl;
	std::cout << "Dog copié - Idée 1: " << copiedDog->getIdeas(1) << std::endl;
	
	originalDog->setIdeas(0, "trop bon repas thxx pour la pate");
	
	std::cout << "\nAprès modification de l'original:" << std::endl;
	std::cout << "Dog original - Idée 0: " << originalDog->getIdeas(0) << std::endl;
	std::cout << "Dog copié - Idée 0: " << copiedDog->getIdeas(0) << " (ne doit PAS changer)" << std::endl << std::endl;
	






	Dog* assignedDog = new Dog();
	*assignedDog = *originalDog;
	
	std::cout << "\nTest opérateur d'assignation:" << std::endl;
	std::cout << "Dog assigné - Idée 0: " << assignedDog->getIdeas(0) << std::endl;
	
	originalDog->setIdeas(0, "J AI FAIMMMMMM");
	std::cout << "Après nouvelle modification de l'original:" << std::endl;
	std::cout << "Dog original - Idée 0: " << originalDog->getIdeas(0) << std::endl;
	std::cout << "Dog assigné - Idée 0: " << assignedDog->getIdeas(0) << " (ne doit PAS changer)" << std::endl << std::endl;
	
	delete originalDog;
	delete copiedDog;
	delete assignedDog;


	return 0;
}