/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:00:11 by itaouil           #+#    #+#             */
/*   Updated: 2023/02/07 14:00:11 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

PresidentialPardonForm::PresidentialPardonForm( void ) : Form("presidential pardon", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form("presidential pardon", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &src ) : Form("presidential pardon", 25, 5)
{
	this->_target = src.getTarget();
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "Pardon request done, file closed." << std::endl;
}

// ************************************************************************** //
//                              Operator Overload                             //
// ************************************************************************** //

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm const &src )
{
	this->_target = src.getTarget();
	return (*this);
}

// ************************************************************************** //
//                                 Accessors                                  //
// ************************************************************************** //

void	PresidentialPardonForm::beSigned( Bureaucrat &employee )
{
	if (employee.getGrade() > this->_gradeToSign)
	{
		std::string s = "Employee's grade is too low to sign this form. Required grade : ";
		std::stringstream	out;
		out << this->_gradeToSign;
		s.append(out.str());
		throw Bureaucrat::GradeTooLowException(s);
	}
	else
		this->_isSigned = true;
}

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

// ************************************************************************** //
//                                  Actions                                   //
// ************************************************************************** //

void	PresidentialPardonForm::action( void ) const
{
	std::cout << "President Zaphod BeebleBrox has granted pardon to " << this->_target << "." << std::endl;
}
