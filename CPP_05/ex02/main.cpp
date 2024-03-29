/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:01:45 by itaouil           #+#    #+#             */
/*   Updated: 2023/02/07 15:18:47 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << std::endl;
	Bureaucrat	Bob(1, "Bob");
	Bob.incrementGrade(); // shouldn't work because Bob's grade is already the highest

	std::cout << std::endl;
	ShrubberyCreationForm	gardenry("garden");

	Bob.signForm(gardenry);
	Bob.executeForm(gardenry); // should create "garden_shrubbery"
	std::cout << std::endl;
}
