#include "Animals.hpp"

// **************************** AAnimal CLASS ***************************** //

AAnimal::AAnimal( void )
{
	std::cout << "An AAnimal is born!" << std::endl;
}

AAnimal::AAnimal( AAnimal const &src )
{
	this->type = src.getType();
}

AAnimal::~AAnimal( void )
{
	std::cout << "The AAnimal is leaving." << std::endl;
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

std::string Dog::getType( void ) const
{
	return (this->type);
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

std::string Cat::getType( void ) const
{
	return (this->type);
}