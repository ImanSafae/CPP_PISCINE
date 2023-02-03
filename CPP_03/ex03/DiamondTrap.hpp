#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "FragTrap.hpp"
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

class	DiamondTrap : virtual public ScavTrap, virtual public FragTrap
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

	std::string	getName( void ) const;

private:
	std::string		_name;
};

#endif