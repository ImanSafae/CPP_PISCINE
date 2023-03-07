#include "PmergeMe.hpp"

void	insertion(std::list<int> &subList, int value)
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
	subList.push_back(value);
}

void merge(std::list<int> &subList, std::list<std::pair<int, int> > &mainList, bool odd)
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
				insertion(subList, it2->second);
				mainList.erase(it2);
				break ;
				
			}
			else if ((odd == false && *it == it2->second) || (odd == true && it2 != last && *it == it2->second))
			{
				insertion(subList, it2->first);
				mainList.erase(it2);
				break ;
			}
			it2++;
		}
		it++;
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

void	sortPairs(std::list<std::pair<int, int> > &pairs, std::list<int> &subList, bool odd)
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
	}
}

void	parseMainList(std::list<std::pair<int, int> > &mainList, int argc, char **argv, bool &odd)
{
	for (int i = 0; i < argc; i++)
	{
		if ((i + 1) < argc)
		{
			int	first = atoi(argv[i]);
			int	second = atoi(argv[i + 1]);
			std::cout << "Inserting pair: " << first << ", " << second << std::endl;
			mainList.push_back(std::pair<int, int>(first, second));
		}
		else
		{
			std::pair<int, int>	lastPair;
			lastPair.first = atoi(argv[i]);
			mainList.push_back(lastPair);
			odd = false;
		}
	}
}
