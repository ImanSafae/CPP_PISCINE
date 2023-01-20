#include "Animals.hpp"

// **************************** ANIMAL CLASS ***************************** //

Animal::Animal( void )
{
	std::cout << "An animal is born!" << std::endl;
}

Animal::Animal( Animal const &src )
{
	this->type = src.getType();
}

Animal::~Animal( void )
{
	std::cout << "The animal is leaving." << std::endl;
}

std::string	Animal::getType( void ) const
{
	return (this->type);
}

void	Animal::makeSound( void ) const
{
	std::cout << "[ANIMAL SOUNDS]" << std::endl;
}

Animal	&Animal::operator=( Animal const &src )
{
	this->type = src.getType();
	return (*this);
}

// **************************** DOG CLASS ***************************** //

Dog::Dog( void )
{
	std::cout << "It's a doggo!" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog( Dog const &src )
{
	std::cout << "Your other dog now has a twin." << std::endl;
	this->type = "Dog";
	this->_brain = new Brain(src.getBrain());
}

Dog::~Dog( void )
{
	std::cout << "Goodbye doggo!" << std::endl;
	delete _brain;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Dog: <BARK! BARK!>" << std::endl;
}

Brain	&Dog::getBrain( void ) const
{
	return (*(this->_brain));
}

Dog	&Dog::operator=( Dog const &src )
{
	this->type = src.getType();
	this->_brain = new Brain(src.getBrain());
	return (*this);
}

// **************************** CAT CLASS ***************************** //

Cat::Cat( void )
{
	std::cout << "It's a kitty!" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat( Cat const &src )
{
	std::cout << "Your other Cat now has a twin." << std::endl;
	this->type = "Cat";
	this->_brain = new Brain(src.getBrain());
}

Cat::~Cat( void )
{
	std::cout << "Goodbye kitty!" << std::endl;
	delete _brain;
}

void	Cat::makeSound( void ) const
{
	std::cout << "The kitty meows cutely." << std::endl;
}

Brain	&Cat::getBrain( void ) const
{
	return (*(this->_brain));
}

Cat	&Cat::operator=( Cat const &src )
{
	this->type = src.getType();
	this->_brain = new Brain(src.getBrain());
	return (*this);
}
