/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:38:54 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/31 02:15:12 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("shrubbery", 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("shrubbery", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &src ) : Form("shrubbery", 145, 137)
{
	this->_target = src.getTarget();
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "Shrubbery done." << std::endl;
}

// ************************************************************************** //
//						   Operator overload								  //
// ************************************************************************** //

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm const &src )
{
	this->_target = src.getTarget();
	return (*this);
}


// ************************************************************************** //
//                                  Actions                                   //
// ************************************************************************** //

void	ShrubberyCreationForm::action( void ) const
{
	std::string	filename = (this->_target);
	filename.append("_shrubbery");
	
	std::ofstream	file(filename.c_str());

	file << "	ccee88oo" << std::endl;
	file << "  C8O8O8Q8PoOb o8oo" << std::endl;
	file << " dOB69QO8PdUOpugoO9bD" << std::endl;
	file << "gggbU8OU qOp qOdoUOdcb" << std::endl;
	file << "    6OuU  /p u gcoUodpP" << std::endl;
	file << "      /\\/\\/\\////  /douUP" << std::endl;
	file << "        /\\/\\/\\/////" << std::endl;
	file << "         |||///\\/" << std::endl;
	file << "         |||\\/" << std::endl;
	file << "         |||||" << std::endl;
	file << "   .....//||||\\...." << std::endl << std::endl;
}

// ************************************************************************** //
//                                 Accessors                                  //
// ************************************************************************** //

std::string ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

void    ShrubberyCreationForm::beSigned( Bureaucrat &employee )
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
