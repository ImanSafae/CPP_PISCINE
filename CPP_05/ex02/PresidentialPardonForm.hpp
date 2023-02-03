#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
    std::string	_target;
public:
    PresidentialPardonForm( void );
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( PresidentialPardonForm const &src );
    ~PresidentialPardonForm( void );

	PresidentialPardonForm	&operator=( PresidentialPardonForm const &src );

	void		beSigned( Bureaucrat &employee );

	std::string	getTarget( void ) const;

	virtual void		action( void ) const;
};