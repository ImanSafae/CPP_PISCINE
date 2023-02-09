/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:37:24 by itaouil           #+#    #+#             */
/*   Updated: 2023/02/09 15:50:19 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

// int	main()
// {
// 	float	a, b;
// 	a = 4.2f;
// 	b = 42.0f;
// 	std::cout << "Biggest value between " << a << " and " << b << " is " << max<float>(a , b) << std::endl << std::endl;

// 	int	c, d;
// 	c = 42;
// 	d = 420;
// 	std::cout << "Biggest value between " << c << " and " << d << " is " << max<int>(c , d) << std::endl << std::endl;

// 	std::cout << "Current value of a: " << a << std::endl;
// 	std::cout << "Current value of b: " << b << std::endl;
// 	swap<float>(a, b);
// 	std::cout << "Swapping a and b." << std::endl;
// 	std::cout << "New value of a: " << a << std::endl;
// 	std::cout << "New value of b: " << b << std::endl << std::endl;
	
// 	std::cout << "Current value of c: " << c << std::endl;
// 	std::cout << "Current value of d: " << d << std::endl;
// 	swap<int>(c, d);
// 	std::cout << "Swapping c and d." << std::endl;
// 	std::cout << "New value of c: " << c << std::endl;
// 	std::cout << "New value of d: " << d << std::endl << std::endl;
// }

int main( void )
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}