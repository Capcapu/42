/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:21:47 by csolari           #+#    #+#             */
/*   Updated: 2025/10/23 18:28:07 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "HumanA.h"


class HumanA {

	private:
	
	HumanA( void );	
	std::string	_name;
	Weapon		&_weapon;

	public:

	HumanA( std::string name, Weapon& weapon);
	~HumanA( void );
	std::string	getName(void)const;
	std::string	getWeaponType(void)const;
	void		setName(std::string name);
	void		setWeapon(Weapon &weapon);
	void		attack(void)const;

};

#endif