#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{

public:
	Harl( void );
	~Harl( void );

	void	complain( std::string level );

private:
	std::string	*string_tab;
	void		(Harl::*complaints[4])( void );

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
};

void	tolower_str( std::string *str );

void	debug_level(Harl *some_guy);
void	info_level(Harl *some_guy);
void	warning_level(Harl *some_guy);
void	error_level(Harl *some_guy);
void	nonsense_level(void);

#endif