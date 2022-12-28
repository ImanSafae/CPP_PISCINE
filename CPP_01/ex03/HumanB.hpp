#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.h"

class HumanB
{
public:
	HumanB( std::string name );
	~HumanB( void );

	void		setName( std::string name );
	std::string	getName( void );
	void		setWeapon( Weapon &type );
	Weapon		getWeapon( void );

	void	attack( void );

private:
	std::string	_name;
	Weapon		*_my_weapon;
};

#endif