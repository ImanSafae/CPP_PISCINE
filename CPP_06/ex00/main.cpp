/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:14:19 by itaouil           #+#    #+#             */
/*   Updated: 2023/02/07 16:14:19 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

int	findType(std::string arg)
{
	bool	isFloat = false;
	bool	isDouble = false;

	if (arg.size() == 1 && isalpha(arg[0]))
		return (CHAR);

	for (size_t i = 0; i < arg.size(); i++)
	{
		if ((isalpha(arg[i]) && arg[i] != 'f')
			|| (isascii(arg[i]) && !isdigit(arg[i]) && arg[i] != '.' && arg[i] != 'f' && arg[i] != '+' && arg[i] != '-'))
		{
			std::cout << "Wrong type of argument. Please only send arguments of char, int, float or double type." << std::endl;
			exit(EXIT_FAILURE);
		}
		if (arg[i] == '.')
		{
			if (isDouble == false)
				isDouble = true;
			else
			{
				std::cout << "Wrong type of argument. Please only send arguments of char, int, float or double type." << std::endl;
				exit(EXIT_FAILURE);
			}
		}
	}
	if (arg.back() == 'f')
		isFloat = true;
	if (isFloat == true && isDouble == true)
		return (FLOAT);
	else if (isDouble == true)
		return (DOUBLE);
	else
		return (INT);
}

void	convertInt( int arg )
{
	if (isprint(arg))
		std::cout << "char: " << static_cast<char>(arg) << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << arg << std::endl;
	std::cout << "float: " << static_cast<float>(arg) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(arg) << ".0" << std::endl;
}

void	convertFloat( float arg )
{
	int	intVersion = static_cast<int>(arg);

	if (isprint(intVersion))
		std::cout << "char: " << static_cast<char>(intVersion) << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << intVersion << std::endl;
	std::cout << "float: " << arg << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(arg) << std::endl;
}

void	convertDouble( double arg )
{
	int	intVersion	= static_cast<int>(arg);

	if (isprint(intVersion))
		std::cout << "char: " << static_cast<char>(intVersion) << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << intVersion << std::endl;
	std::cout << "float: " << static_cast<float>(arg) << "f" << std::endl;
	std::cout << "double: " << arg << std::endl;
}

void	convertChar( char arg )
{
	int	intVersion	= std::atoi(&arg);
	std::cout << "char: " << arg << std::endl;
	std::cout << "int: " << intVersion << std::endl;
	std::cout << "float: " << static_cast<float>(std::atof(&arg)) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(std::atof(&arg)) << ".0" << std::endl;
}

void	checkInfOrNan( std::string &arg )
{
	if (!arg.compare("nan") || !arg.compare("nanf"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout <<"int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		exit(EXIT_SUCCESS);
	}
	else if (!arg.compare("-inf") || !arg.compare("-inff"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout <<"int: -inf" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		exit(EXIT_SUCCESS);
	}
	else if (!arg.compare("+inf") || !arg.compare("+inff"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout <<"int: +inf" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments. Please only send one argument of char, int, float or double type." << std::endl;
		return (0);
	}
	std::string	arg = argv[1];
	checkInfOrNan(arg);
	int	type = findType(argv[1]);


	switch (type)
	{
		case INT:
		{
			int int_arg = atoi(arg.c_str());
			convertInt(int_arg); break;
		}
		case DOUBLE:
		{
			double double_arg = atof(arg.c_str());
			convertDouble(double_arg); break;
		}
		case FLOAT:
		{
			float float_arg = static_cast<float>(atof(arg.c_str()));
			convertFloat(float_arg); break;
		}
		default:
		{
			convertChar(arg[0]);
			break;
		}
	}


}

// int main(int argc, char **argv)
// {
// 	std::cout << static_cast<int>(std::atoi(argv[1])) << std::endl;
// }
