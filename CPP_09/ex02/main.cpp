#include "PmergeMe.hpp"

void printSubList(std::list<int> &subList)
{
	// std::cout << "Sorted list: ";
	std::list<int>::iterator it = subList.begin();
	std::list<int>::iterator ite = subList.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	printSubVector(std::vector<int> &subVector)
{
	// std::cout << "Sorted vector: ";
	std::vector<int>::iterator it = subVector.begin();
	std::vector<int>::iterator ite = subVector.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void listSorting(std::list<std::pair<int, int> > &mainList, std::list<int> &subList, bool odd)
{
	sortPairsList(mainList, subList, odd);
	sortSubList(subList);
	mergeList(subList, mainList, odd);
}

void vectorSorting(std::vector<std::pair<int, int> > &mainVector, std::vector<int> &subVector, bool odd)
{
	sortPairsVector(mainVector, subVector, odd);
	sortSubVector(subVector);
	mergeVector(subVector, mainVector, odd);
}

void	printTime(double &listTime, double &vectorTime, int argc)
{
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: " << listTime << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << vectorTime << " us" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	clock_t startList, endList, startVector, endVector;
	double 	listTime, vectorTime;

	std::list<std::pair<int, int> >		mainList;
	std::list<int>						subList;

	std::vector<std::pair<int, int> >	mainVector;
	std::vector<int>					subVector;
	subVector.reserve(argc - 1);

	bool								odd = false;


	parseMainList(mainList, argc, argv, odd);
	parseMainVector(mainVector, argc, argv, odd);

	std::cout << "Before: ";
	printMainList(mainList, odd);
	// printMainVector(mainVector, odd);

	startList = clock();
	listSorting(mainList, subList, odd);
	endList = clock();
	listTime = (double)(endList - startList) * pow(10, 6) / CLOCKS_PER_SEC;

	startVector = clock();
	vectorSorting(mainVector, subVector, odd);
	endVector = clock();
	vectorTime = (double)(endVector - startVector) * pow(10, 6) / CLOCKS_PER_SEC;

	std::cout << "After: ";
	printSubList(subList);
	// printSubVector(subVector);

	printTime(listTime, vectorTime, argc);
}
