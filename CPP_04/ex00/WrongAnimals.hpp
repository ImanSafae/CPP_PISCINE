#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal( void );
	WrongAnimal( std::string name );
	WrongAnimal( WrongAnimal const &src );
	virtual ~WrongAnimal();

	WrongAnimal &operator=( WrongAnimal const &src );

	virtual std::string	getType( void ) const;

	void makeSound( void ) const;

protected:
	std::string type;
};

class WrongCat : public WrongAnimal
{
 public:
	WrongCat( void );
	WrongCat( WrongCat const &src );
	~WrongCat( void );

	WrongCat &operator=( WrongCat const &src );

	void makeSound( void ) const;
};
