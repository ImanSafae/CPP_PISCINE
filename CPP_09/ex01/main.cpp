#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: wrong number of arguments." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::stack<std::string>	RPNstack;
	std::string		 request = argv[1];
		

	rpn(request, RPNstack);
	std::cout << RPNstack.top() << std::endl;
}