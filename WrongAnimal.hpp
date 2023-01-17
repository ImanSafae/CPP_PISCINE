#include <iostream>

class WrongAnimal
{
public:
    WrongAnimal( void );
    WrongAnimal( std::string name );
    WrongAnimal( WrongAnimal const &src );
    ~WrongAnimal();

    WrongAnimal &operator=( WrongAnimal const &src );

	virtual std::string	getName( void ) const;
	virtual std::string	getType( void ) const;

    void makeSound( void ) const;

protected:
    std::string type;
    std::string name;
};

class WrongCat : public WrongAnimal
{
 public:
	WrongCat( void );
	WrongCat( std::string name );
	WrongCat( WrongCat const &src );
	~WrongCat( void );

	WrongCat &operator=( WrongCat const &src );

	void makeSound( void ) const;
};
