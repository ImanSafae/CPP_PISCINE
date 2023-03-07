#include "PmergeMe.hpp"

void	printMainList(std::list<std::pair<int, int> > &mainList, bool odd)
{
	std::list<std::pair<int, int> >::iterator it = mainList.begin();
	std::list<std::pair<int, int> >::iterator ite = mainList.end();
	std::list<std::pair<int, int> >::iterator last = ite;
	last--;

	while (it != ite)
	{
		std::cout << "Printing..." << std::endl;
		if (odd == true && it == last)
			std::cout << it->first << std::endl;
		else
			std::cout << it->first << " " << it->second << std::endl;
		it++;
	}
}

void printSubList(std::list<int> &subList)
{
	std::list<int>::iterator it = subList.begin();
	std::list<int>::iterator ite = subList.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	std::list<std::pair<int, int> >	mainList;
	std::list<int>					subList;
	bool							odd = true;

	parseMainList(mainList, argc, argv, odd);
	std::cout << "Before: ";
	printMainList(mainList, odd);
	sortPairs(mainList, subList, odd);
	sortSubList(subList);
	merge(subList, mainList, odd);

	std::cout << "After: ";
	printSubList(subList);
}
