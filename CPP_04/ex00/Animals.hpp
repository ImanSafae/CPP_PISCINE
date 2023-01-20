#include <iostream>

class Animal
{
public:
	Animal( void );
	Animal( Animal const &src );
	virtual ~Animal();

	Animal &operator=( Animal const &src );

	virtual std::string	getType( void ) const;

	virtual void makeSound( void ) const;

protected:
	std::string type;
};

class Dog : public Animal
{
public:
	Dog( void );
	Dog( Dog const &src );
	~Dog( void );

	Dog &operator=( Dog const &src );

	void makeSound( void ) const;

};

class Cat : public Animal
{
public:
	Cat( void );
	Cat( Cat const &src );
	~Cat( void );

	Cat &operator=( Cat const &src );

	void makeSound( void ) const;
};
