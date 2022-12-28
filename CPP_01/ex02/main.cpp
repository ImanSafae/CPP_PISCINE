/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:18:30 by itaouil           #+#    #+#             */
/*   Updated: 2022/12/06 19:01:35 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::string;

int	main()
{
	string	str = "HI THIS IS BRAIN";

	string	*stringPTR = &str;
	string	&stringREF = str;

	std::cout << "Address of string str is " << &str << std::endl;
	std::cout << "Address stored in pointer stringPTR is " << stringPTR << std::endl;
	std::cout << "Address stored in reference stringREF is " << &stringREF << std::endl << std::endl;

	std::cout << "str is " << str << std::endl;
	std::cout << "content of stringPTR is " << *stringPTR << std::endl;
	std::cout << "content of stringREF is " << stringREF << std::endl;
}
