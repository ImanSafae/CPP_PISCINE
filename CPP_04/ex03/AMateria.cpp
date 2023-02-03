/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:46:08 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/17 19:42:26 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// ************************************************************************** //
//                                AMATERIA CLASS                              //
// ************************************************************************** //

AMateria::AMateria( void )
{
	std::cout << "New material spawned." << std::endl;
}

AMateria::AMateria( std::string const &type ) : type(type)
{
	std::cout << "New material of " << type << " type spawned." << std::endl;
}

AMateria::~AMateria( void )
{
	std::cout << "Material disappeared." << std::endl;
}

std::string const	&AMateria::getType( void ) const
{
	return (this->type);
}

void	AMateria::setType( std::string type )
{
	this->type = type;
}

AMateria	&AMateria::operator=( AMateria const &src )
{
	this->type = src.getType();
	return (*this);
}

// ************************************************************************** //
//                                   ICE CLASS                                //
// ************************************************************************** //

Ice::Ice( void )
{
	std::cout << "Material type is ice." << std::endl;
	this->setType("ice");
}

Ice::Ice( Ice const &src )
{
	std::cout << "Material type is ice." << std::endl;
	this->setType("ice");
}

Ice::~Ice( void )
{
	std::cout << "Ice melted." << std::endl;
}

Ice	&Ice::operator=( Ice const &src )
{
	this->type = src.getType();
	return (*this);
}

Ice	*Ice::clone( void ) const
{
	Ice	*new_ice = new Ice;
	return (new_ice);
}

void	Ice::use( ICharacter &target )
{
	std::cout << "*shoots an ice bolt at " << target.getName << "*" << std::endl;
}

// ************************************************************************** //
//                                  CURE CLASS                                //
// ************************************************************************** //

Cure::Cure( void )
{
	std::cout << "Material type is cure." << std::endl;
	this->setType("cure");
}

Cure::Cure( Cure const &src )
{
	std::cout << "Material type is cure." << std::endl;
	this->setType("cure");
}

Cure::~Cure( void )
{
	std::cout << "Cure is thrown away." << std::endl;
}

Cure	&Cure::operator=( Cure const &src )
{
	this->type = src.getType();
	return (*this);
}

Cure	*Cure::clone( void ) const
{
	Cure	*new_cure = new Cure;
	return (new_cure);
}

void	Cure::use( ICharacter &target )
{
	std::cout << "heals " << target.getName << "'s wounds" << std::endl;
}
