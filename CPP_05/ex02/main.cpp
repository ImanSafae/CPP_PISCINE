/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:01:45 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/31 01:51:53 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::cout << std::endl;
	Bureaucrat	Bob(1, "Bob");
	std::cout << std::endl;
	Bureaucrat	Patrick(150, "Patrick");

	std::cout << std::endl;
	ShrubberyCreationForm	gardenry("garden");
	Bob.signForm(gardenry);
	Bob.executeForm(gardenry); // should work
	std::cout << std::endl;

	RobotomyRequestForm	robotomy("that one robot");
	std::cout << std::endl;
	Bob.executeForm(robotomy); // should send error cause form is not signed
	Bob.signForm(robotomy);
	Bob.executeForm(robotomy); // should work
	std::cout << std::endl;


	PresidentialPardonForm	pardon("Plankton");
	std::cout << std::endl;
	Patrick.signForm(pardon); // should send error cause Patrick's grade is too low
	Bob.signForm(pardon);
	Bob.executeForm(pardon); // should work
	std::cout << std::endl;

	std::cout << std::endl;
}
