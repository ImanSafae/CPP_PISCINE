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

WrongAnimal::WrongAnimal( std::string name )
{
	this->name = name;
	std::cout << "An WrongAnimal named " << name << " is born!" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &src )
{
	this->name = src.getName();
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "The WrongAnimal is leaving." << std::endl;
}

std::string	WrongAnimal::getName( void ) const
{
	return (this->name);
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

WrongCat::WrongCat( std::string name )
{
	std::cout << "It's a Cat, but Wrong, and it's named " << name << "!" << std::endl;
	this->name = name;
	this->type = "WrongCat";
}

WrongCat::WrongCat( WrongCat const &src )
{
	std::cout << "Your other WrongCat now has a twin." << std::endl;
	this->type = "WrongCat";
	this->name = src.getName();

}

WrongCat::~WrongCat( void )
{
	std::cout << "Goodbye Wrong Cat!" << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat: <BARK! BARK!>" << std::endl;
}