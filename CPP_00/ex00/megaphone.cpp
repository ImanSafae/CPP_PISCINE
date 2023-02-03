/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:17:32 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/29 19:29:41 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::endl;

int	main(int argc, char **argv)
{
	int	i = 1;
	int	j = 0;

	if (!argv[i])
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	else
	{
		while (i < argc)
		{
			while (argv && argv[i] && argv[i][j])
			{
				cout << (char)toupper(argv[i][j]);
				j++;
			}
			j = 0;
			i++;
		}
		cout << endl;
	}
}
