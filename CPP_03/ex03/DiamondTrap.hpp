#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "FragTrap.hpp"
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

class   DiamondTrap : public ScavTrap, public FragTrap
{

public:
	DiamondTrap( void );
	DiamondTrap( std::string name );
	DiamondTrap( DiamondTrap const &copy );
	~DiamondTrap( void );


	DiamondTrap & operator=( DiamondTrap const &src );

	void	whoAmI( void );
	using 	ScavTrap::attack;

	void	setHitPoints( void );
	void	setEnergy( void );
	void	setDamage( void );


private:
	std::string		_name;
};

#endif