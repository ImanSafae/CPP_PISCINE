/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:15:44 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/03 01:16:12 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{

public:
	Fixed( void );
	~Fixed( void );
	Fixed( Fixed const &src );

	Fixed &		operator=( Fixed const &newValue );

	int			getRawBits( void ) const;
	void		setRawBits( int const raw );

private:
	int					_value;
	static const int	_precision = 8;
};

#endif