#pragma once

#include <iostream>

template< typename type >
void	operate( type &element ) 
{
	std::cout << element << std::endl;
};

template< typename type >
void	iter( type *array, size_t size, void operate(type &element))
{
	for (size_t i = 0; i < size; i++)
	{
		operate(array[i]);
	}
};
