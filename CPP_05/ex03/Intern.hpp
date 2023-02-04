#pragma once

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern( void );
	Intern( Intern const &src );
	~Intern( void );

	Intern	&operator=( Intern const &src );

	std::string	getStatus( void ) const;



	Form	*makeForm( std::string name, std::string target );
private:
	std::string	_status;
};
