/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 23:28:45 by itaouil           #+#    #+#             */
/*   Updated: 2022/12/12 00:15:39 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	srand(time(0));
	Harl	annoying_guy;

	std::string	levels[4] = {"debug", "info", "warning", "error"};
	int			randint = rand() % 4;
	
	annoying_guy.complain(levels[randint]);
	// annoying_guy.complain("debug");
	// annoying_guy.complain("info");
	// annoying_guy.complain("warning");
	// annoying_guy.complain("error");

	

}