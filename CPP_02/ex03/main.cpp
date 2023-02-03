/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:04:43 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/04 20:10:39 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	check_points_alignment( Point A, Point B, Point C, Point M )
{
	Fixed	firstCrossProduct;
	Fixed	secondCrossProduct;
	Fixed	thirdCrossProduct;

	Fixed	xA = A.getX();
	Fixed	yA = A.getY();
	Fixed	xB = B.getX();
	Fixed	yB = B.getY();
	Fixed	xC = C.getX();
	Fixed	yC = C.getY();
	Fixed	xM = M.getX();
	Fixed	yM = M.getY();

	firstCrossProduct = ((yM - yA) * (xB - xA) - (xM - xA) * (yB - yA));
	if (firstCrossProduct == 0)
		return (true);
	secondCrossProduct = ((yC - yM) * (xB - xM) - (xC - xM) * (yB - yM));
	if (secondCrossProduct == 0)
		return (true);
	thirdCrossProduct = ((yM - yA) * (xC - xA) - (xM - xA) * (yC - yA));
	if (thirdCrossProduct == 0)
		return (true);
	return (false);
}

int	main()
{
	// TEST : INSIDE
	//      B
	//
	//
	//
	//
	// 
	// 
	//      M
	// 
	//      
	// A          C
	//
	Point	A(0.0, 0.0);
	Point	B(10.0, 20.0);
	Point	C(20.0, 0.0);
	Point	M(10.0, 5.0);
	
	// TEST : OUTSIDE - ON THE LINE
	// Point	A(0.0, 0.0);
	// Point	B(1.0, 2.0);
	// Point	C(2.0, 0.0);
	// Point	M(0.0, 0.0);

	// TEST : OUTSIDE
	// Point	A(0.0, 0.0);
	// Point	B(1.0, 2.0);
	// Point	C(2.0, 0.0);
	// Point	M(5.0, 1.0);

	// if (check_points_alignment(A, B, C, M))
	// {
	// 	std::cout << "Point M is on the outline of the triangle." << std::endl;
	// 	return (0);
	// }
	if (bsp(A, B, C, M) == true)
		std::cout << "Point M is inside the triangle." << std::endl;
	else
		std::cout << "Point M is outside the triangle." << std::endl;
	return (1);
}
