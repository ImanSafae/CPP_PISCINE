#include "RPN.hpp"

bool    checkCharValidity(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || isdigit(c) || c == ' ')
        return (true);
    return (false);
}

int	calculator(std::stack<std::string> &rpnstack)
{
    std::string    a, b, op;
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

void    rpn(std::string request, std::stack<std::string> &rpnstack)
{
    for (size_t i = 0; i < request.length(); i++)
    {
        while (i < request.length() && rpnstack.size() != 3)
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
            rpnstack.push(tmp);
            i++;
        }
        int res = calculator(rpnstack);
        std::stringstream ss;
        ss << res;
        std::string resStr = ss.str();
		rpnstack.push(resStr);
    }
}