/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:32:45 by itaouil           #+#    #+#             */
/*   Updated: 2023/02/09 15:53:12 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main()
{
	std::string	strArray[3] = {"string1", "string2", "string3"};
	int			intArray[3] = {1, 2, 3};
	float		floatArray[3] = {4.2, 42.0, 420.0};

	iter(strArray, 3, operate<std::string>); // should print all 3 strings of strArray in order
	std::cout << std::endl;
	iter(intArray, 3, operate<int>); // should print all 3 ints of intArray in order
	std::cout << std::endl;
	iter(floatArray, 3, operate<float>); // should print all 3 floats of floatArray in order
}
