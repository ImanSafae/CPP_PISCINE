/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:01:45 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/23 16:20:31 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

	std::cout << std::endl;
}