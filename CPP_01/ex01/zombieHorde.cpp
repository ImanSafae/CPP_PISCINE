/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:57:56 by itaouil           #+#    #+#             */
/*   Updated: 2022/12/12 18:58:49 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie	*zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	Zombie	*horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);

	return (horde);
}
