#include <iostream>

class Fixed
{

public:
	Fixed( void );
	~Fixed( void );
	Fixed( Fixed const &src );

	Fixed &		operator=( Fixed const &newValue );

	int			getRawBits( void );
	void		setRawBits( int const raw );

private:
	int					_value;
	static const int	_precision = 8;
};
