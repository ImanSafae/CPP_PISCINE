/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:58:14 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/17 13:58:14 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

// **************************** ANIMAL CLASS ***************************** //

Animal::Animal( void )
{
	std::cout << "An animal is born!" << std::endl;
}

Animal::Animal( std::string name )
{
	this->name = name;
	std::cout << "An animal named " << name << " is born!" << std::endl;
}

Animal::Animal( Animal const &src )
{
	this->name = src.getName();
}

Animal::~Animal( void )
{
	std::cout << "The animal is leaving." << std::endl;
}

std::string	Animal::getName( void ) const
{
	return (this->name);
}

std::string	Animal::getType( void ) const
{
	return (this->type);
}

void	Animal::makeSound( void ) const
{
	std::cout << "[ANIMAL SOUNDS]" << std::endl;
}

// **************************** DOG CLASS ***************************** //

Dog::Dog( void )
{
	std::cout << "It's a doggo!" << std::endl;
	this->type = "Dog";
}

Dog::Dog( std::string name )
{
	std::cout << "It's a doggo named " << name << "!" << std::endl;
	this->name = name;
	this->type = "Dog";
}

Dog::Dog( Dog const &src )
{
	std::cout << "Your other dog now has a twin." << std::endl;
	this->type = "Dog";
	this->name = src.getName();

}

Dog::~Dog( void )
{
	std::cout << "Goodbye doggo!" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Dog: <BARK! BARK!>" << std::endl;
}


// **************************** Cat CLASS ***************************** //

Cat::Cat( void )
{
	std::cout << "It's a kitty!" << std::endl;
	this->type = "Cat";
}

Cat::Cat( std::string name )
{
	std::cout << "It's a kitty named " << name << "!" << std::endl;
	this->name = name;
	this->type = "Cat";
}

Cat::Cat( Cat const &src )
{
	std::cout << "Your other Cat now has a twin." << std::endl;
	this->type = "Cat";
	this->name = src.getName();
}

Cat::~Cat( void )
{
	std::cout << "Goodbye kitty!" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "The kitty meows cutely." << std::endl;
}
