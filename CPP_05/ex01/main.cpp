/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:01:45 by itaouil           #+#    #+#             */
/*   Updated: 2023/02/07 14:15:02 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	Patrick(150, "Patrick");
	Patrick.incrementGrade(); // Should work and promote Patrick to grade 149.

	std::cout << std::endl;
	Bureaucrat	Bob(1, "Bob");
	Bob.incrementGrade(); // Shouldn't work because Bob's grade is already the highest.

	std::cout << std::endl;
	Bureaucrat	Plankton(150, "Plankton");
	Plankton.decrementGrade(); // Shouldn't work because Plankton's grade is already the lowest.

	std::cout << std::endl;
	Bureaucrat	Sandy(160, "Sandy");
	std::cout << Sandy << std::endl; // Should throw an exception because grade can't be lower than 150.

	std::cout << std::endl;
	Form	formi("Tax", 50, 50);
	Patrick.signForm(formi); // Shouldn't work because Patrick's grade is too low to sign it.

	std::cout << std::endl;
	Bob.signForm(formi); // Should work.
	std::cout << formi << std::endl;

	std::cout << std::endl;
}