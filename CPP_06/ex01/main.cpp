/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:10:51 by itaouil           #+#    #+#             */
/*   Updated: 2023/02/08 20:56:49 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	main()
{
	Data	*myData = new Data;
	myData->myInt = 27;
	myData->myString = "Iman";


	uintptr_t	tmp;
	tmp = serialize(myData);

	Data	*gotMyDataBack;
	gotMyDataBack = deserialize(tmp);

	std::cout << "My int : " << myData->myInt << std::endl;
	std::cout << "My string : " << myData->myString << std::endl;

	delete (myData);
}
