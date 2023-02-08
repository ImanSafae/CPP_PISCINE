#pragma once

#include <stdint.h>
#include <iostream>

typedef struct s_data
{
	int			myInt;
	std::string	myString;
}				Data;

uintptr_t	serialize(Data* ptr);
Data		*deserialize(uintptr_t raw);
