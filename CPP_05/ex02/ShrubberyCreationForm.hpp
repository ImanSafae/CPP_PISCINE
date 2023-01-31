#pragma once

#include "Form.hpp"
#include <cstdio>
#include <fstream>

class   ShrubberyCreationForm : public Form
{
public:
    ShrubberyCreationForm( void );
    ShrubberyCreationForm( ShrubberyCreationForm const &src );
    ShrubberyCreationForm( std::string target );
    ~ShrubberyCreationForm( void );

    ShrubberyCreationForm &operator=( ShrubberyCreationForm const &src );

    virtual void    beSigned( Bureaucrat &employee );

    std::string getTarget( void ) const;

private:
    void        _drawTrees( std::ofstream &file );
    std::string _target;
};
