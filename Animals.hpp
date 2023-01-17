#include <iostream>

class Animal
{
public:
    Animal( void );
    Animal( std::string name );
    Animal( Animal const &src );
    ~Animal();

    Animal &operator=( Animal const &src );

	virtual std::string	getName( void ) const;
	virtual std::string	getType( void ) const;

    virtual void makeSound( void ) const;

protected:
    std::string type;
    std::string name;
};

class Dog : public Animal
{
public:
    Dog( void );
    Dog( std::string name );
    Dog( Dog const &src );
    ~Dog( void );

    Dog &operator=( Dog const &src );

    void makeSound( void ) const;

};

class Cat : public Animal
{
public:
	Cat( void );
	Cat( std::string name );
	Cat( Cat const &src );
	~Cat( void );

	Cat &operator=( Cat const &src );

	void makeSound( void ) const;
};
