#ifndef WEAPON_HPP
# define WEAPON_HPP

# include "Weapon.h"

class Weapon
{

public:
	Weapon( std::string weapon_type );
	~Weapon( void );

	std::string&	getType();
	void			setType( std::string );

private:
	std::string		_type;

};

#endif