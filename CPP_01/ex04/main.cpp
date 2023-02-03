/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:30:58 by itaouil           #+#    #+#             */
/*   Updated: 2022/12/09 19:09:23 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	check_nbArgs(int argc)
{
		if (argc != 4)
	{
		std::cout << "Wrong number of arguments." << std::endl;
		exit(EXIT_FAILURE);
	}
}

void	ft_replace( std::string &str, std::string s1, std::string s2 )
{
	size_t	pos_begin;

	pos_begin = str.find(s1, 0);
	if (pos_begin == std::string::npos)
		return ;
	str.erase(pos_begin, s1.length());
	str.insert(pos_begin, s2);
}

int	main(int argc, char **argv)
{

	check_nbArgs(argc);
	std::string		new_filename = ((std::string)(argv[1])).append(".replace");
	std::string		to_replace = argv[2];
	std::string		replacement = argv[3];
	std::string		tmp;

	std::ifstream	ifs(argv[1]);
	std::ofstream	ofs(new_filename);

	while (!ifs.eof())
	{
		ifs >> tmp;
		ft_replace(tmp, to_replace, replacement);
		// if (!tmp.compare(argv[2]))
		// 	tmp.assign(replacement);
		ofs << tmp;
		// std::cout << tmp << std::endl;
		if (!ifs.eof())
			ofs << " ";
	}
	ifs.close();
}