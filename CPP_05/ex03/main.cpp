/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:01:45 by itaouil           #+#    #+#             */
/*   Updated: 2023/02/07 15:30:55 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Bureaucrat	Bob(1, "Bob");
	std::cout << std::endl;

	Bureaucrat	Patrick(150, "Patrick");
	std::cout << std::endl;

	Intern someRandomIntern;
	Form* rrf;
	std::cout << std::endl;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender"); // should create Robotomy Form

	Bob.signForm(*rrf); // should work
	std::cout << std::endl;

	Bob.executeForm(*rrf); // has 50% chance of successful robotomy on "Bender"
	std::cout << std::endl;
}
