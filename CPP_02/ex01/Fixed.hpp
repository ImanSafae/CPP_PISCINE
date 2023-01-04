/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:15:15 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/04 04:53:29 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	Fixed &		operator=( Fixed const &newValue );

	int			getRawBits( void ) const;
	void		setRawBits( int const raw );

	float		toFloat( void ) const;
	int			toInt( void ) const;

private:
	int					_value;
	static const int	_precision = 8;
};

std::ostream	&operator<<( std::ostream &o, Fixed const &number );

#endif