/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:23:31 by csolari           #+#    #+#             */
/*   Updated: 2025/10/23 17:56:19 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include "Weapon.h"

class Weapon {

	private:

	Weapon( void );
	std::string		_type;

	public:

	Weapon( std::string type );
	~Weapon( void );
	std::string		getType(void)const;
	void			setType(std::string type);
};

#endif