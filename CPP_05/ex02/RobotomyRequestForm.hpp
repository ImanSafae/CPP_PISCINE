#pragma once

#include "Form.hpp"

class   RobotomyRequestForm : public Form
{
public:
    RobotomyRequestForm( void );
    RobotomyRequestForm( std::string target );
    RobotomyRequestForm( RobotomyRequestForm const &src );
    ~RobotomyRequestForm( void );

    RobotomyRequestForm &operator=( RobotomyRequestForm const &src );

    virtual void    beSigned( Bureaucrat &employee );

    std::string getTarget( void ) const;

   virtual void    action( void ) const;

private:
    std::string _target;
};
