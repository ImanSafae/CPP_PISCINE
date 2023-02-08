/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:11:32 by itaouil           #+#    #+#             */
/*   Updated: 2023/02/08 20:56:40 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t	serialize(Data* ptr)
{
	uintptr_t	newPtr;

	newPtr = reinterpret_cast<uintptr_t>(ptr);
	return (newPtr);
}

Data	*deserialize(uintptr_t raw)
{
	Data	*myStruct;

	myStruct = reinterpret_cast<Data *>(raw);
	return (myStruct);
}
