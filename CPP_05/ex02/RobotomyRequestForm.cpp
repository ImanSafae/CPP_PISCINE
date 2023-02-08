/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 02:20:30 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/31 02:20:31 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : Form("robotomy", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form("robotomy", 72, 45)
{
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &src ) : Form("robotomy", 72, 45)
{
    this->_target = src.getTarget();
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
    std::cout << "Robotomy request closed." << std::endl;
}

void    RobotomyRequestForm::beSigned( Bureaucrat &employee )
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

// ************************************************************************** //
//                                 Accessors                                  //
// ************************************************************************** //

std::string RobotomyRequestForm::getTarget( void ) const
{
    return  (this->_target);
}

// ************************************************************************** //
//                                  Actions                                   //
// ************************************************************************** //

void    RobotomyRequestForm::action( void ) const
{
    srand(time(0));
    int randint = rand();

    std::cout << "VRRRRRRRRRRRRRRRRRR..." << std::endl;

    if (randint %2 == 0)
        std::cout << this->_target << " has been successfully robotomized." << std::endl;
    else
        std::cout << "Robotomy attempt on " << this->_target << " has failed..." << std::endl;
}
