/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:31:04 by itaouil           #+#    #+#             */
/*   Updated: 2022/12/12 00:04:37 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

Harl::Harl( void )
{
	std::cout << "Harl has entered the restaurant. Brace yourself." << std::endl << std::endl;
	this->string_tab = new std::string[4];
	this->string_tab[0] = "debug";
	this->string_tab[1] = "info";
	this->string_tab[2] = "warning";
	this->string_tab[3] = "error";
	this->complaints[0] = &Harl::debug;
	this->complaints[1] = &Harl::info;
	this->complaints[2] = &Harl::warning;
	this->complaints[3] = &Harl::error;
}

Harl::~Harl( void )
{
	delete [] this->string_tab;
}

// ************************************************************************** //
//                                    Utils                                   //
// ************************************************************************** //

void	tolower_str( std::string *str )
{
	int	i = 0;

	while ((*str)[i])
	{
		(*str)[i] = tolower((*str)[i]);
		i++;
	}
}

// ************************************************************************** //
//                                 Complaints                                 //
// ************************************************************************** //

void	Harl::debug( void )
{
	std::cout << "\"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\"" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "\"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\"" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "\"I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\"" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "\"This is unacceptable! I want to speak to the manager now.\"" << std::endl;
}

void	Harl::complain ( std::string level )
{
	tolower_str(&level);
	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(this->string_tab[i]))
		{
			((this->*complaints[i]))();
			break ;
		}
	}
}
