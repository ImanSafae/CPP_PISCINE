#include "PmergeMe.hpp"

//////////////////////////////////////////////////////////////////////////
////////////////////////////// L I S T ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////

void	insertionList(std::list<int> &subList, int value)
{
	std::list<int>::iterator it = subList.begin();
	std::list<int>::iterator ite = subList.end();

	while (it != ite)
	{
		if (value < *it)
		{
			subList.insert(it, value);
			return ;
		}
		it++;
	}
	// subList.push_back(value);
}

void mergeList(std::list<int> &subList, std::list<std::pair<int, int> > &mainList, bool odd)
{
	std::list<int>::iterator it = subList.begin();
	std::list<int>::iterator ite = subList.end();

	while (it != ite)
	{
		std::list<std::pair<int, int> >::iterator it2 = mainList.begin();
		std::list<std::pair<int, int> >::iterator ite2 = mainList.end();
		std::list<std::pair<int, int> >::iterator last = ite2;
		last--;

		while (it2 != ite2)
		{
			if ((*it == it2->first) && !(odd == true && it2 == last))
			{
				insertionList(subList, it2->second);
				mainList.erase(it2);
				break ;
				
			}
			else if ((odd == false && *it == it2->second) || (odd == true && it2 != last && *it == it2->second))
			{
				insertionList(subList, it2->first);
				mainList.erase(it2);
				break ;
			}
			it2++;
		}
		// std::cout << "incrementing it. current value: " << *it << std::endl;
		it++;
		// std::cout << "incremented it. new value:  " << *it << std::endl;
	}
}

void	sortSubList(std::list<int> &subList)
{
	std::list<int>::iterator it = subList.begin();
	std::list<int>::iterator ite = subList.end();

	while (it != ite)
	{
		std::list<int>::iterator it2 = it;
		it2++;
		while (it2 != ite)
		{
			if (*it > *it2)
			{
				int tmp = *it;
				*it = *it2;
				*it2 = tmp;
			}
			it2++;
		}
		it++;
	}
}

void	sortPairsList(std::list<std::pair<int, int> > &pairs, std::list<int> &subList, bool odd)
{
	std::list<std::pair<int, int> >::iterator it = pairs.begin();
	std::list<std::pair<int, int> >::iterator ite = pairs.end();
	std::list<std::pair<int, int> >::iterator last = ite;
	last--;

	while (it != ite)
	{
		int biggest;
		if ((it != last && it->first > it->second) || (it == last && odd == false && it->first > it->second))
		{
			// int tmp = it->first;
			// it->first = it->second;
			// it->second = tmp;
			biggest = it->first;
		}
		else if ((it != last && it->first < it->second) || (it == last && odd == false && it->first < it->second))
			biggest = it->second;
		else if (it == last && odd == true)
			biggest = it->first;
		subList.push_back(biggest);
		it++;
	}
}

void	parseMainList(std::list<std::pair<int, int> > &mainList, int argc, char **argv, bool &odd)
{
	for (int i = 1; i < argc; i++)
	{
		if ((i + 1) < argc)
		{
			int	first = atoi(argv[i]);
			int	second = atoi(argv[i + 1]);
			if (first < 0 || second < 0)
			{
				std::cout << "Error" << std::endl;
				exit(EXIT_FAILURE);
			}
			mainList.push_back(std::pair<int, int>(first, second));
		}
		else
		{
			int first = atoi(argv[i]);
			if (first < 0)
			{
				std::cout << "Error" << std::endl;
				exit(EXIT_FAILURE);
			}
			std::pair<int, int>	lastPair;
			lastPair.first = first;
			mainList.push_back(lastPair);
			odd = true;
		}
		i+= 1;
	}
}

void	printMainList(std::list<std::pair<int, int> > &mainList, bool odd)
{
	std::list<std::pair<int, int> >::iterator it = mainList.begin();
	std::list<std::pair<int, int> >::iterator ite = mainList.end();
	std::list<std::pair<int, int> >::iterator last = ite;
	last--;

	// std::cout << "Unsorted list: ";
	while (it != ite)
	{
		if (odd == true && it == last)
			std::cout << it->first << " ";
		else
			std::cout << it->first << " " << it->second << " ";
		it++;
	}
	std::cout << std::endl;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////// V E C T O R /////////////////////////////////
//////////////////////////////////////////////////////////////////////////

void	parseMainVector(std::vector<std::pair<int, int> > &mainVector, int argc, char **argv, bool &odd)
{
	for (int i = 1; i < argc; i++)
	{
		if ((i + 1) < argc)
		{
			int	first = atoi(argv[i]);
			int	second = atoi(argv[i + 1]);
			if (first < 0 || second < 0)
			{
				std::cout << "Error" << std::endl;
				exit(EXIT_FAILURE);
			}
			mainVector.push_back(std::pair<int, int>(first, second));
		}
		else
		{
			int first = atoi(argv[i]);
			if (first < 0)
			{
				std::cout << "Error" << std::endl;
				exit(EXIT_FAILURE);
			}
			std::pair<int, int>	lastPair;
			lastPair.first = first;
			mainVector.push_back(lastPair);
			odd = true;
		}
		i+= 1;
	}
}

void	sortPairsVector(std::vector<std::pair<int, int> > &pairs, std::vector<int> &subVector, bool odd)
{
	std::vector<std::pair<int, int> >::iterator it = pairs.begin();
	std::vector<std::pair<int, int> >::iterator ite = pairs.end();
	std::vector<std::pair<int, int> >::iterator last = ite;
	last--;

	while (it != ite)
	{
		int biggest;
		if ((it != last && it->first > it->second) || (it == last && odd == false && it->first > it->second))
		{
			// int tmp = it->first;
			// it->first = it->second;
			// it->second = tmp;
			biggest = it->first;
		}
		else if ((it != last && it->first < it->second) || (it == last && odd == false && it->first < it->second))
			biggest = it->second;
		else
			biggest = it->first;
		subVector.push_back(biggest);
		it++;
	}
}

void	sortSubVector(std::vector<int> &subVector)
{
	std::vector<int>::iterator it = subVector.begin();
	std::vector<int>::iterator ite = subVector.end();

	while (it != ite)
	{
		std::vector<int>::iterator it2 = it;
		it2++;
		while (it2 != ite)
		{
			if (*it > *it2)
			{
				int tmp = *it;
				*it = *it2;
				*it2 = tmp;
			}
			it2++;
		}
		it++;
	}
}

void	insertionVector(std::vector<int> &subVector, int value)
{
	std::vector<int>::iterator it = subVector.begin();
	std::vector<int>::iterator ite = subVector.end();

	while (it != ite)
	{
		if (value < *it)
		{
			subVector.insert(it, value);
			return ;
		}
		it++;
	}
	subVector.push_back(value);
}

// void mergeVector(std::vector<int> &subvector, std::vector<std::pair<int, int> > &mainvector, bool odd)
// {
// 	std::vector<int>::const_iterator it = subvector.begin();
// 	std::vector<int>::const_iterator ite = subvector.end();

// 	while (it != ite)
// 	{
// 		std::vector<std::pair<int, int> >::iterator it2 = mainvector.begin();
// 		std::vector<std::pair<int, int> >::iterator ite2 = mainvector.end();
// 		std::vector<std::pair<int, int> >::iterator last = ite2;
// 		last--;
// 		std::cout << "value : " << *it << std::endl;
// 		while (it2 != ite2)
// 		{
// 			if ((*it == it2->first) && !(odd == true && it2 == last))
// 			{
// 				insertionVector(subvector, it2->second);
// 				mainvector.erase(it2);
// 				break ;
				
// 			}
// 			else if ((odd == false && *it == it2->second) || (odd == true && it2 != last && *it == it2->second))
// 			{
// 				insertionVector(subvector, it2->first);
// 				mainvector.erase(it2);
// 				break ;
// 			}
// 			it2++;
// 		}
// 		std::cout << "incrementing it. current value: " << *it << std::endl;
// 		it++;
// 		std::cout << "incremented it. new value:  " << *it << std::endl;
// 	}
// }

void	mergeVector(std::vector<int> &subVector, std::vector<std::pair<int, int> > &mainVector, bool odd)
{
	std::vector<int>::const_iterator it = subVector.begin();
	std::vector<int>::const_iterator ite = subVector.end();

	while (it != ite)
	{
		
		std::vector<std::pair<int, int> >::const_iterator it2 = mainVector.begin();
		std::vector<std::pair<int, int> >::const_iterator ite2 = mainVector.end();
		std::vector<std::pair<int, int> >::const_iterator last = ite2;
		last--;

		while (it2 != ite2)
		{
			// std::cout << "checking " << *it << std::endl;
			if ((*it == it2->first) && !(odd == true && it2 == last))
			{
				insertionVector(subVector, it2->second);
				it++;
				break ;
			}
			else if ((odd == false && *it == it2->second) || (odd == true && it2 != last && *it == it2->second))
			{
				insertionVector(subVector, it2->first);
				it++;
				break ;
			}
			it2++;
		}
		it++;
		ite = subVector.end();
	}
}

void	printMainVector(std::vector<std::pair<int, int> > &mainVector, bool odd)
{
	std::vector<std::pair<int, int> >::iterator it = mainVector.begin();
	std::vector<std::pair<int, int> >::iterator ite = mainVector.end();
	std::vector<std::pair<int, int> >::iterator last = ite;
	last--;

	// std::cout << "Unsorted vector: ";
	while (it != ite)
	{
		if (odd == true && it == last)
			std::cout << it->first << " ";
		else
			std::cout << it->first << " " << it->second << " ";
		it++;
	}
	std::cout << std::endl;
}