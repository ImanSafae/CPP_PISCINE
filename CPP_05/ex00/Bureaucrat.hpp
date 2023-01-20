#pragma once "BUREAUCRAT_HPP"

#include <iostream>
#include <exception>

class Bureaucrat
{

public:
	Bureaucrat( void );
	Bureaucrat( Bureaucrat const &src );
	Bureaucrat( unsigned int grade, std::string name );
	~Bureaucrat( void );

	Bureaucrat 		&operator=( Bureaucrat const &src );

	std::string		getName( void ) const;
	unsigned int	getGrade( void ) const;
	void			setGrade( unsigned int grade );
	void			incrementGrade( void );
	void			decrementGrade( void );

private:
	const std::string	_name;
	unsigned int		_grade;
};

	std::ostream	&operator<<( std::ostream &o, Bureaucrat const &output );