/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:32:31 by csolari           #+#    #+#             */
/*   Updated: 2025/10/23 18:28:29 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "HumanB.h"

class HumanB {

	private:
	
	HumanB( void );
	std::string	_name;
	Weapon		*_weapon;

	public:

	HumanB( std::string name );
	~HumanB( void );
	std::string	getName(void)const;
	std::string	getWeaponType(void)const;
	void		setName(std::string name);
	void		setWeapon(Weapon &weapon);
	void		attack(void)const;

};

#endif