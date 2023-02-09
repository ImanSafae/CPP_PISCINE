#pragma once

#include <iostream>
#include <exception>

template< typename type >
class	Array
{
private:
	type			*_array;
	unsigned int	_size;
public:
	Array( unsigned int n = 0)
	{
		this->_size = n;
		this->_array = new type[_size];
	}

	Array( Array<type> const &src )
	{
		this->_array = new type[src._size];
		for (unsigned int i = 0; i < src._size; i++)
		{
			try
			{
				this->_array[i] = src.arrayElement(i);
			}
			catch (std::exception &e)
			{
				std::cout << "Couldn't access this array index." << std::endl;
			}
		}
		this->_size = src._size;
	}

	~Array( void )
	{
		delete[] (this->_array);
	};

	Array<type>		&operator=( Array<type> const &src )
	{
		for (unsigned int i = 0; i < src.size(); i++)
		{
			this->_array[i] = src.arrayElement(i);
		}
		this->_size = src.size();
		return (*this);
	}

	unsigned int	size( void ) const { return (this->_size); }

	type			arrayElement( unsigned int index ) const 
	{
		if (index >= this->_size)
			throw (std::exception());
		return this->_array[index];
	}
};
