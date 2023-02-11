/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:05:18 by itaouil           #+#    #+#             */
/*   Updated: 2023/02/11 16:05:33 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	std::list<int>	myList;

	myList.push_back(12);
	myList.push_back(13);
	myList.push_back(10);
	myList.push_back(4);

	std::cout << easyfind(myList, 13) << std::endl;
	std::cout << easyfind(myList, 5) << std::endl;
	std::cout << std::endl;

	std::vector<int>	myVector;
	
	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);
	myVector.push_back(4);

	std::cout << easyfind(myVector, 3) << std::endl;
	std::cout << easyfind(myVector, 5) << std::endl;
}