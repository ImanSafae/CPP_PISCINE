#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.h"

class HumanA
{

public:
	HumanA( std::string name, Weapon &weapon );
	~HumanA();


	void		setName( std::string name );
	std::string	getName( void );
	void		setWeapon( Weapon type );
	Weapon		getWeapon( void );

	void		attack( void );

private:
	std::string	_name;
	Weapon		&_my_weapon;

};


#endif