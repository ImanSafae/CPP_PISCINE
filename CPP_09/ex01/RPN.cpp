#include "RPN.hpp"

bool	checkCharValidity(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || isdigit(c) || c == ' ')
		return (true);
	return (false);
}

int	calculator(std::stack<std::string> &rpnstack)
{
	if (rpnstack.size() < 3)
	{
		std::cout << "Error" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string	a, b, op;
	int		aInt, bInt, res;

	op = rpnstack.top();
	rpnstack.pop();

	a = rpnstack.top();
	aInt = atoi(a.c_str());
	rpnstack.pop();

	b = rpnstack.top();
	bInt = atoi(b.c_str());
	rpnstack.pop();

	if (!op.compare("+"))
		res = aInt + bInt;
	else if (!op.compare("-"))
		res = bInt - aInt;
	else if (!op.compare("*"))
		res = aInt * bInt;
	else if (!op.compare("/"))
		res = bInt / aInt;
	else
	{
		std::cout << "Error" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (res);
}

void	rpn(std::string request, std::stack<std::string> &rpnstack)
{
	for (size_t i = 0; i < request.length(); i++)
	{
		// while (i < request.length() && rpnstack.size() != 3)
		while (i < request.length())
		{
			if (request[i] == ' ')
			{
				i++;
				continue;
			}
			if (!checkCharValidity(request[i]))
			{
				std::cout << "Error" <<std::endl;
				exit(EXIT_FAILURE);
			}
			std::string tmp;
			tmp += request[i];
			if (request[i + 1] && !isdigit(request[i + 1]))
			{
				std::cout << "Error" << std::endl;
				exit(EXIT_FAILURE);
			}
			if (request[i + 1] && isdigit(request[i + 1]) && request[i] == '-')
			{
				tmp += request[i + 1];
				i++;
			}
			rpnstack.push(tmp);
			i++;
			if (!tmp.compare("+") || !tmp.compare("-") || !tmp.compare("*") || !tmp.compare("/"))
			{
				break ;
			}
		}
		int res = calculator(rpnstack);
		std::stringstream ss;
		ss << res;
		std::string resStr = ss.str();
		rpnstack.push(resStr);
	}
}
