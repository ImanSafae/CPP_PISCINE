/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:00:54 by itaouil           #+#    #+#             */
/*   Updated: 2023/02/11 18:45:01 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	Span	test(5);

	test.addNumber(13);
	test.addNumber(1);
	test.addNumber(4);
	test.addNumber(10);
	test.addNumber(12);

	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;

	Span	test2(10000);
	
	test2.addLotsOfNbrs();
	std::cout << test2.shortestSpan() << std::endl;
	std::cout << test2.longestSpan() << std::endl;
}