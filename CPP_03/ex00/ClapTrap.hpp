#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{

public:
	ClapTrap( void );
	ClapTrap( ClapTrap const &src );
	ClapTrap( std::string name );
	~ClapTrap( void );

	ClapTrap &	operator=( ClapTrap const &src );

	void		attack( const std::string &target );
	void		takeDamage( unsigned int amount );
	void		beRepaired( unsigned int amount );

	std::string	getName( void ) const ;
	void		decreaseEnergy( void ) ;
	int			getEnergy( void ) const;
	int			getHitPoints( void ) const;
	int			getDamage( void ) const;

	void		setEnergy( unsigned int amount );
	void		setHitPoints( unsigned int amount );
	void		setDamage( unsigned int amount );

private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_damage;
};

#endif