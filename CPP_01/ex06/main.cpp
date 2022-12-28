/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:18:01 by itaouil           #+#    #+#             */
/*   Updated: 2022/12/12 01:14:26 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	parse_args(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout << "For once, Harl doesn't seem to be complaining. Harl ate and left the restaurant." << std::endl;
		exit(EXIT_SUCCESS);
	}

	std::string	level = argv[1];
	tolower_str(&level);

	if (!level.compare("debug"))
		return (1);
	else if (!level.compare("info"))
		return (2);
	else if (!level.compare("warning"))
		return (3);
	else if (!level.compare("error"))
		return (4);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	Harl	annoying_guy;
	int		filterLevel;

	filterLevel = parse_args(argc, argv);
	switch(filterLevel)
	{
		case 1:
			debug_level(&annoying_guy); break;
		case 2:
			info_level(&annoying_guy); break;
		case 3:
			warning_level(&annoying_guy); break;
		case 4:
			error_level(&annoying_guy); break;
		default:
			nonsense_level(); break;
	}
}