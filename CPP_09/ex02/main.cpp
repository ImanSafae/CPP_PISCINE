#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	std::list<int>	mainList;
	for (int i = 1; i < argc; i++)
		mainList.push_back(atoi(argv[i]));
}