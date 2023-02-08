/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:03:03 by itaouil           #+#    #+#             */
/*   Updated: 2023/02/08 21:44:26 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base( void )
{

}

Base	*generate( void )
{
	srand(time(0));
	unsigned int	randint = rand() % 3;
	Base			*ret;

	switch (randint)
	{
		case 0:
			ret = new A; break;
		case 1:
			ret = new B; break;
		default:
			ret = new C; break;
	}
	return (ret);
}

void	identify(Base *p)
{
	std::cout << "<3 POINTER TESTS <3" << std::endl;
	std::cout << "__________________" << std::endl << std::endl;
	Base	*test = NULL;

	test = dynamic_cast<A *>(p);
	if (test != NULL)
	{
		std::cout << "Base is of type A" << std::endl;
		return ;
	}
	
	test = dynamic_cast<B *>(p);
	if (test != NULL)
	{
		std::cout << "Base is of type B" << std::endl;
		return ;
	}

	test = dynamic_cast<C *>(p);
	if (test != NULL)
		std::cout << "Base is of type C" << std::endl;
}

void	identify( Base &p )
{
	std::cout << "<3 REFERENCE TESTS <3" << std::endl;
	std::cout << "__________________" << std::endl << std::endl;
	try
	{
		Base &test = dynamic_cast<A &>(p);
		(void)test;
		std::cout << "Base is of type A." << std::endl;
		return ;
	}
	catch(const std::bad_cast &bc)
	{}
	
	try
	{
		Base &test = dynamic_cast<B &>(p);
		(void)test;
		std::cout << "Base is of type B." << std::endl;
		return ;
	}
	catch(const std::bad_cast &bc)
	{}

	try
	{
		Base &test = dynamic_cast<C &>(p);
		(void)test;
		std::cout << "Base is of type C." << std::endl;
		return ;
	}
	catch(const std::bad_cast &bc)
	{}
}