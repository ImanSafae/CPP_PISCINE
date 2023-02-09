#pragma once

#include <iostream>

template< typename type >
void	swap( type &a, type &b )
{
	type	tmp;
	tmp = a;
	a = b;
	b = tmp;
};

template< typename type >
type	const &max( type const &a, type const &b )
{
	if (a >= b)
		return (a);
	return (b);
};

template< typename type >
type	const &min( type const &a, type const &b )
{
	if (a <= b)
		return (a);
	return (b);
};
