#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class	Brain
{
public:
	Brain( void );
	Brain( Brain const &src );
	~Brain( void );

	Brain	&operator=( Brain const &src );

	std::string	getIdeas( int index ) const;

private:
	std::string	_ideas[100];
};

#endif