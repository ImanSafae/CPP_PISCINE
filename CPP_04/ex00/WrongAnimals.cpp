/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimals.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:58:17 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/17 13:58:17 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimals.hpp"

// **************************** WRONGANIMAL CLASS ***************************** //

WrongAnimal::WrongAnimal( void )
{
	std::cout << "An WrongAnimal is born!" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &src )
{
	this->type = src.getType();
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "The WrongAnimal is leaving." << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "[WRONG ANIMAL SOUNDS]" << std::endl;
}

// **************************** WrongCat CLASS ***************************** //

WrongCat::WrongCat( void )
{
	std::cout << "It's a Cat, but wrong!" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat( WrongCat const &src )
{
	std::cout << "Your other WrongCat now has a twin." << std::endl;
	this->type = src.getType();

}

WrongCat::~WrongCat( void )
{
	std::cout << "Goodbye Wrong Cat!" << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat: <BARK! BARK!>" << std::endl;
}
