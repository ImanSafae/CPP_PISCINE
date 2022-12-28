/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:20:27 by itaouil           #+#    #+#             */
/*   Updated: 2022/12/03 23:27:33 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	std::string input;
	PhoneBook	repertory;

	while (1)
	{
		std::cout << "What do you want to do? Please only enter ADD, SEARCH or EXIT. " << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cin.clear();
			clearerr(stdin);
		}
		if (!input.compare("ADD"))
			repertory.add();
		if (!input.compare("EXIT"))
			repertory.exit_PhoneBook();
		if (!input.compare("SEARCH"))
			repertory.search();
	}
}
