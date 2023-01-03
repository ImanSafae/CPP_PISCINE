/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:04:43 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/03 23:20:47 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

A                          B
         M
AM = k * AB
0 < k < 1

int	main()
{
	// Point	A(0.0, 0.0);
	// Point	B(10.0, 20.0);
	// Point	C(20.0, 0.0);
	// Point	M(10.0, 5.0);
	Point	A(0.0, 0.0);
	Point	B(1.0, 2.0);
	Point	C(2.0, 0.0);
	Point	M(0.0, 0.5);

	if ()
	{
		
	}
	if (bsp(A, B, C, M) == true)
		std::cout << "Point M is inside the triangle." << std::endl;
	else
		std::cout << "Point M is outside the triangle." << std::endl;
}