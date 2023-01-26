/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:01:45 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/26 18:35:41 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	Patrick(150, "Patrick");
	Patrick.incrementGrade();

	std::cout << std::endl;
	Bureaucrat	Bob(1, "Bob");
	Bob.incrementGrade();

	std::cout << std::endl;
	Bureaucrat	Plankton(150, "Plankton");
	Plankton.decrementGrade();

	std::cout << std::endl;
	Bureaucrat	Sandy(160, "Sandy");
	std::cout << Sandy << std::endl;

	std::cout << std::endl;
	Form	formi("Tax", 50, 50);
	Patrick.signForm(formi);

	std::cout << std::endl;
	Bob.signForm(formi);
	std::cout << formi << std::endl;

	std::cout << std::endl;
}