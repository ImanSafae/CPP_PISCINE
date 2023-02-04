#include "Intern.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

Intern::Intern( void )
{
	std::cout << "New intern just joined the company." << std::endl;
	this->_status = "Intern";
}

Intern::Intern( Intern const &src )
{
	std::cout << "New intern just joined the company." << std::endl;
	this->_status = src.getStatus();
}

Intern::~Intern( void )
{
	std::cout << "An intern left the company." << std::endl;
}

// ************************************************************************** //
//                              Operator Overload                             //
// ************************************************************************** //

Intern	&Intern::operator=( Intern const &src )
{
	this->_status = src.getStatus();
	return (*this);
}

// ************************************************************************** //
//                                 Accessors                                  //
// ************************************************************************** //

std::string	Intern::getStatus( void ) const
{
	return (this->_status);
}

// ************************************************************************** //
//                                  Actions                                   //
// ************************************************************************** //

void	tolower_str( std::string &str )
{
	for (int i = 0; i < str.size(); i++)
	{
		str[i] = tolower(str[i]);
	}
}

Form	*Intern::makeForm( std::string formtype, std::string target )
{
	Form	*form;
	tolower_str(formtype);

	std::string	forms[3];
	forms[0] = "presidential pardon";
	forms[1] = "robotomy request";
	forms[2] = "shrubbery creation";

	void	(*functions[3])( std::string target );
	functions[0] = &ShrubberyCreationForm::ShrubberyCreationForm;
	functions[1] = &PresidentialPardonForm::PresidentialPardonForm;
	functions[2] = &RobotomyRequestForm::RobotomyRequestForm;


	int	index;
	for (int i = 0; i < 3; i++)
	{
		if (!formtype.compare(forms[i]))
		{
			index = i;
			break ;
		}
		else if (i == 2)
		{
			std::cout << "Unrecognized form name. Intern couldn't create form." << std::endl;
			return (NULL);
		}
	}

	form = new (functions[index](target));
	return (form);
}