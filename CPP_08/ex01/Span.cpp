/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:17:44 by itaouil           #+#    #+#             */
/*   Updated: 2023/02/11 18:45:08 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int N ) : _spanSize(N)
{
	
}

Span::~Span() {}

Span::Span( Span const &src )
{
	_spanSize = src._spanSize;
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite = _mySpan.end();

	for (it = _mySpan.begin(); it != ite; *it++)
	{
		_mySpan[*it] = src._mySpan[*it];
	}
}

Span	&Span::operator=( Span const &src )
{
	_spanSize = src._spanSize;
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite = _mySpan.end();

	for (it = _mySpan.begin(); it != ite; *it++)
	{
		_mySpan[*it] = src._mySpan[*it];
	}
	return (*this);
}

void	Span::addNumber( int number )
{
	if (_mySpan.size() == _spanSize)
		throw (Span::fullSpanException());
	_mySpan.push_back(number);
}

int		Span::shortestSpan( void )
{
	if (_mySpan.size() <= 1)
		throw (Span::notEnoughNbrsException());

	std::sort(_mySpan.begin(), _mySpan.end());

	std::vector<int> spansVector;
	spansVector.resize(_spanSize);

	std::adjacent_difference(_mySpan.begin(), _mySpan.end(), spansVector.begin());
	return (*(std::min_element(spansVector.begin(), spansVector.end())));
}

int		Span::longestSpan( void )
{
	if (_mySpan.size() <= 1)
		throw (Span::notEnoughNbrsException());

	int biggestNbr = *(std::max_element(_mySpan.begin(), _mySpan.end()));
	int	smallestNbr = *(std::min_element(_mySpan.begin(), _mySpan.end()));

	return (biggestNbr - smallestNbr);
}

void	Span::addLotsOfNbrs( void )
{
	srand(time(0));
	for (unsigned int i = 0; i < _spanSize; i++)
	{
		unsigned int	randint = rand() % 10000;
		_mySpan.push_back(randint);
	}
}