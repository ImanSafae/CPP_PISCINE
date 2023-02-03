#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{

public:
	Zombie( void );
	~Zombie( void );

	Zombie( std::string name );

	void	announce( void );
	void	setName( std::string name);

private:
	std::string	_name;

};

#endif