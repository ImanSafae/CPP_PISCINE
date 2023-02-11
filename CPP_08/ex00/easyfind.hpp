#pragma once

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <deque>

template< typename T >
int	easyfind( T container, int toFind )
{
	typename T::iterator	it = container.begin();
	typename T::iterator	ite = container.end();

	typename T::iterator found = std::find(it, ite, toFind);
	// for (it = container.begin(); it!= ite; it++)
	// {
	// 	if (*it ==  toFind)
	// 		return (*it);
	// }
	if (found == container.end())
	{
		std::cout << "Occurrence not found." << std::endl;
		return (0);
	}
	return (*found);
};
