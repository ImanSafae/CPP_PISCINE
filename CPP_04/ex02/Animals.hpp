#ifndef ANIMALS_HPP

# define ANIMALS_HPP

# include <iostream>
# include "Brain.hpp"

class AAnimal
{
public:
	AAnimal( void );
	AAnimal( AAnimal const &src );
	virtual ~AAnimal();

	AAnimal &operator=( AAnimal const &src );

	virtual std::string	getType( void ) const = 0;

	virtual void makeSound( void ) const = 0;

protected:
	std::string type;
};

class Dog : public AAnimal
{
public:
	Dog( void );
	Dog( Dog const &src );
	~Dog( void );

	Dog &operator=( Dog const &src );

	virtual void makeSound( void ) const;
	Brain	&getBrain( void ) const;
	virtual std::string	getType( void ) const;

private:
	Brain	*_brain;
};

class Cat : public AAnimal
{
public:
	Cat( void );
	Cat( Cat const &src );
	~Cat( void );

	Cat &operator=( Cat const &src );

	virtual void makeSound( void ) const;
	Brain	&getBrain( void ) const;
	virtual std::string	getType( void ) const;

private:
	Brain	*_brain;
};

#endif