/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:13:01 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/20 18:45:59 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "[NEW BRAIN THINKS]" << std::endl;
}

Brain::Brain( Brain const &src )
{
	std::cout << "[CLONING BRAIN]" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src.getIdeas(i);
}

Brain::~Brain( void )
{
	std::cout << "[BRAIN SHUTTING DOWN]" << std::endl;
}

Brain &Brain::operator=( Brain const &src )
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src.getIdeas(i);
	return (*this);
}

std::string	Brain::getIdeas( int index ) const
{
	return ((this->_ideas)[index]);
}
