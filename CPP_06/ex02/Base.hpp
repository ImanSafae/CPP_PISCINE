#pragma once

#include <iostream>
#include <math.h>

class	Base
{

public:
	virtual ~Base( void );
};

Base	*generate( void );
void	identify(Base *p);
void	identify(Base &p);
