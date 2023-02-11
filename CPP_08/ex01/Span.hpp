#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <algorithm>
#include <numeric>

class	Span
{
private:
	std::vector<int>	_mySpan;
	unsigned int		_spanSize;
public:
	Span( void );
	Span( unsigned int N );
	Span( Span const &src );
	~Span( void );

	Span &operator=( Span const &src );

	void	addNumber( int number );
	void	addLotsOfNbrs( void );

	int		shortestSpan( void ) ;
	int		longestSpan( void ) ;

	class	fullSpanException : public std::exception
	{
	public:
		virtual const char* what( void ) const throw()
		{
			return("Span is already full, can't add another number.");
		}
	};

	class	notEnoughNbrsException : public std::exception
	{
	public:
		virtual const char* what( void ) const throw()
		{
			return ("Not enough numbers storaged to calculate a span.");
		}
	};
};
