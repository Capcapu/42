/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:16:53 by csolari           #+#    #+#             */
/*   Updated: 2025/10/27 15:17:52 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	Eab;
	float	Ebc;
	float	Eca;

	Eab = (a.getX().toFloat() - point.getX().toFloat()) * (b.getY().toFloat() - point.getY().toFloat()) -
		((a.getY().toFloat() - point.getY().toFloat()) * (b.getX().toFloat() - point.getX().toFloat()));
	Ebc = (b.getX().toFloat() - point.getX().toFloat()) * (c.getY().toFloat() - point.getY().toFloat()) -
		((b.getY().toFloat() - point.getY().toFloat()) * (c.getX().toFloat() - point.getX().toFloat()));
	Eca = (c.getX().toFloat() - point.getX().toFloat()) * (a.getY().toFloat() - point.getY().toFloat()) -
		((c.getY().toFloat() - point.getY().toFloat()) * (a.getX().toFloat() - point.getX().toFloat()));	
	if (Eab > 0 && Ebc > 0 && Eca > 0)
		return (true);
	else if (Eab < 0 && Ebc < 0 && Eca < 0)
		return (true);
	else
		return (false);
}