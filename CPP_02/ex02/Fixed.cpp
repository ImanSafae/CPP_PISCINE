#include "Fixed.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

Fixed::Fixed( void )
{
	// std::cout << "Default constructor called." << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed( Fixed const &src )
{
	// std::cout << "Copy constructor called." << std::endl;
	*this = src;
}

Fixed::~Fixed( void )
{
	// std::cout << "Destructor called." << std::endl;
}

Fixed::Fixed( int const number )
{
	// std::cout << "Int constructor called." << std::endl;
	this->_value = number << this->_precision;
}

Fixed::Fixed( float const number )
{
	// std::cout << "Float constructor called." << std::endl;
	this->_value = roundf(number * (1 << this->_precision));
}

// ************************************************************************** //
//                           Operator overload                                //
// ************************************************************************** //

std::ostream	&operator<<( std::ostream &output, Fixed const &number )
{
	output << number.toFloat();
	return (output);
}

Fixed &	Fixed::operator=( Fixed const &newValue )
{
	// std::cout << "Copy assignment operator called." << std::endl;
	this->_value = newValue.getRawBits();
	return (*this);
}

bool			Fixed::operator==( Fixed const &compared ) const
{
	if (this->_value == compared.getRawBits())
		return (true);
	else
		return (false);
}

bool			Fixed::operator!=( Fixed const &compared ) const
{
	if (this->_value != compared.getRawBits())
		return (true);
	else
		return (false);
}

bool			Fixed::operator<( Fixed const &compared ) const
{
	if (this->_value < compared.getRawBits())
		return (true);
	else
		return (false);
}

bool			Fixed::operator>( Fixed const &compared ) const
{
	if (this->_value > compared.getRawBits())
		return (true);
	else
		return (false);
}

bool			Fixed::operator<=( Fixed const &compared ) const
{
	if (this->_value <= compared.getRawBits())
		return (true);
	else
		return (false);
}

bool			Fixed::operator>=( Fixed const &compared ) const
{
	if (this->_value >= compared.getRawBits())
		return (true);
	else
		return (false);
}

Fixed			Fixed::operator+( Fixed const &to_add ) const
{
	Fixed	sum;

	sum.setRawBits(this->_value + to_add.getRawBits());
	return (sum);
}

Fixed			Fixed::operator-( Fixed const &to_remove ) const
{
	Fixed	substraction;

	substraction.setRawBits(this->_value - to_remove.getRawBits());
	return (substraction);
}

Fixed			Fixed::operator*( Fixed const &to_multiply ) const
{
	float	 _product;

	_product = this->toFloat() * to_multiply.toFloat();
	Fixed result(_product);
	return (result);
}

Fixed			Fixed::operator/( Fixed const &to_divide ) const
{
	float	divided;

	divided = this->toFloat() / to_divide.toFloat();
	Fixed result(divided);
	return (result);
}

Fixed		&Fixed::operator++( void )
{
	++(this->_value);
	return (*this);
}

Fixed		Fixed::operator++( int )
{
	Fixed	copy(*this);
	(this->_value)++;
	return (copy);
}

Fixed			&Fixed::operator--( void )
{
	--(this->_value);
	return (*this);
}

Fixed		Fixed::operator--( int )
{
	Fixed	copy(*this);
	(this->_value)--;
	return (copy);
}

// ************************************************************************** //
//                                 Min & Max                                  //
// ************************************************************************** //

Fixed			&Fixed::min( Fixed &n1, Fixed &n2 )
{
	if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed			&Fixed::max( Fixed &n1, Fixed &n2 )
{
	if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
}

const Fixed	&Fixed::min( Fixed const &n1, Fixed const &n2 )
{
	if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}

const Fixed	&Fixed::max( Fixed const &n1, Fixed const &n2 )
{
	if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
}

// ************************************************************************** //
//                                 Accessors                                  //
// ************************************************************************** //

int		Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int raw )
{
	this->_value = raw;
}

// ************************************************************************** //
//                                 Converters                                 //
// ************************************************************************** //

float	Fixed::toFloat( void ) const
{
	float	floatVersion;

	// floatVersion = (this->_value) * pow(2, this->_precision * (-1));
	floatVersion = ((float) this->_value) / (1 << (this->_precision));
	return (floatVersion);
}

int		Fixed::toInt( void ) const
{
	int	intVersion;

	// intVersion = (this->_value) * pow(2, this->_precision * (-1));
	intVersion = ((this->_value) >> (this->_precision));
	return (intVersion);
}
