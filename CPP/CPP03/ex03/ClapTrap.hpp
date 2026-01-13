/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:58:56 by csolari           #+#    #+#             */
/*   Updated: 2025/10/28 15:04:30 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#include <stdlib.h>

class ClapTrap {

	protected:
	
	std::string	_name;
	int			_hitPts;
	int			_energyPts;
	int			_attackDamage;
	bool		_isDead;

	public:

	ClapTrap( void );
	ClapTrap(const ClapTrap& copy);
	ClapTrap(std::string name);
	ClapTrap &operator=(const ClapTrap& other);
	~ClapTrap( void );
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif