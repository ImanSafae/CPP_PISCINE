#include "Form.hpp"

Form::FormNotSignedException::FormNotSignedException( void ) throw () {}

Form::FormNotSignedException::FormNotSignedException( std::string message ) throw() : _message(message) {}

const char	*Form::FormNotSignedException::what( void ) const throw()
{
	return (this->_message.c_str());
}

Form::FormNotSignedException::~FormNotSignedException( void ) throw () {}
