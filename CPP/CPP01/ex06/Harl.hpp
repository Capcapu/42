/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:18:56 by csolari           #+#    #+#             */
/*   Updated: 2025/10/23 19:40:53 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include "Harl.h"

class Harl {

	private:
	
	void	_debug( void );
	void	_info( void );
	void	_warning( void );
	void	_error( void );

	public:

	Harl( void );
	~Harl( void );
	void	complain( std::string level );

};

#endif