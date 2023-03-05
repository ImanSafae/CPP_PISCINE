#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{

	if (argc != 2 || access(argv[1], F_OK) == -1)
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}
	std::ifstream	input(argv[1]);

	std::map<std::string, double>	datamap = createDatamap();

	bitcoinExchange(datamap, input);

	input.close();
}
