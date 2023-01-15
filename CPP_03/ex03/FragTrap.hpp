#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap( void );
    FragTrap( std::string name );
    FragTrap( FragTrap const &src );
    ~FragTrap( void );

    FragTrap & operator=( FragTrap const &src );

    void    highFivesGuys( void );
};

#endif