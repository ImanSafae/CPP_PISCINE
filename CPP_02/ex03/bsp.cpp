/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:42:12 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/03 22:46:20 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <stdlib.h>



Fixed	area( Point const a, Point const b, Point const c )
{
	Fixed	area;

	Fixed	x1 = a.getX();
	Fixed	y1 = a.getY();
	Fixed	x2 = b.getX();
	Fixed	y2 = b.getY();
	Fixed	x3 = c.getX();
	Fixed	y3 = c.getY();
	Fixed	two(2.0f);

	area = (((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))) / two);
	return (area);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	triangle_area = area(a, b, c);
	Fixed	first_third = area(a, point, b);
	Fixed	second_third = area(b, point, c);
	Fixed	third_third = area(c, point, a);
	Fixed	total = first_third + second_third + third_third;

	total = total * total;
	triangle_area = triangle_area * triangle_area;

	// std::cout << "triangle area = " << triangle_area << std::endl;
	// std::cout << "total = " << total << std::endl;
	if (total == triangle_area)
		return (true);
	return (false);
}
