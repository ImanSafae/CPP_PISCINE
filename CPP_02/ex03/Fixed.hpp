#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{

public:

	Fixed( void );
	Fixed( Fixed const &src );
    Fixed( int const number );
    Fixed( float const number );
	~Fixed( void );

	Fixed &		        operator=( Fixed const &newValue );

    bool                operator==( Fixed const &compared ) const ;
    bool                operator!=( Fixed const &compared ) const ;
    bool                operator<( Fixed const &compared ) const ;
    bool                operator>( Fixed const &compared ) const ;
    bool                operator<=( Fixed const &compared ) const ;
    bool                operator>=( Fixed const &compared ) const ;

    Fixed               operator+( Fixed const &to_add ) const ;
    Fixed               operator-( Fixed const &to_remove ) const ;
    Fixed               operator*( Fixed const &to_multiply ) const ;
    Fixed               operator/( Fixed const &to_divide ) const ;

    Fixed               &operator++( void );
    Fixed               &operator--( void );
    Fixed               &operator++( int dummy );
    Fixed               &operator--( int dummy );

    static Fixed         &min( Fixed &n1, Fixed &n2 );
    static Fixed         &max( Fixed &n1, Fixed &n2 );
    static const Fixed   &min( Fixed const &n1, Fixed const &n2 );
    static const Fixed   &max( Fixed const &n1, Fixed const &n2 );

	int			         getRawBits( void ) const;
	void		         setRawBits( int const raw );

    float                toFloat( void ) const;
    int                  toInt( void ) const;


private:

	int					_value;
	static const int	_precision = 8;
};

std::ostream    &operator<<( std::ostream &o, Fixed const &number );

#endif