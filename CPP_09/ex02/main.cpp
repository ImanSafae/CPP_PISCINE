#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	std::list<std::pair<int, int>>	mainList;
	bool							odd = true;

	for (int i = 0; i < argc; i++)
	{
		if ((i + 1) < argc)
		{
			int	first = atoi(argv[i]);
			int	second = atoi(argv[i + 1]);
			mainList.push_back(std::pair<int, int>(first, second));
		}
		else
		{
			mainList.push_back(argv[i]);
			odd = false;
		}
		i++;
	}

	
}