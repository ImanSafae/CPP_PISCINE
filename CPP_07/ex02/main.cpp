/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:38:03 by itaouil           #+#    #+#             */
/*   Updated: 2023/02/09 18:33:48 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main()
{
	Array<std::string>	strArray = Array<std::string>(5);
	Array<int>			intArray = Array<int>(5);

	try 
	{
		std::cout << strArray.arrayElement(4) << std::endl; // should work but print nothing
		std::cout << strArray.arrayElement(6) << std::endl; // should throw exception
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try 
	{
		std::cout << intArray.arrayElement(4) << std::endl; // should work and print random number
		std::cout << intArray.arrayElement(6) << std::endl; // should throw exception
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}