#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include <stdlib.h>

std::string	*split(std::string str, char sep)
{
	std::string	*keyAndValue = new std::string[2];

	std::string	key;
	std::string	value;
	int			splitIndex;

	splitIndex = str.find(sep);
	std::cout << "comma found at index " << splitIndex << std::endl;
	key = str.substr(0, splitIndex);
	std::cout << "key is " << key << std::endl;
	value = str.substr(splitIndex + 1, str.size());
	std::cout << "value is " << value << std::endl;
	keyAndValue[0] = key;
	keyAndValue[1] = value;
	return (keyAndValue);
}

std::map<std::string, int>	createDataMap()
{
	std::map<std::string, int>	dataMap;

	std::ifstream	ifs("test");
	std::string		tmp;

	while (!ifs.eof())
	{
		std::getline(ifs, tmp);
		std::string	*keyAndValue = split(tmp, ',');

		std::string key = keyAndValue[0];
		std::string value = keyAndValue[1];
		delete [] keyAndValue;

		dataMap.insert(std::pair<std::string, int>(key, atoi(value.c_str())));

		// char	*tmp2 = const_cast<char *>(tmp.c_str());
		// std::cout << "tmp string = " << tmp2 << std::endl;
		// char	*token = strtok(tmp2, ",");
		// while (token)
		// {
		// 	// std::cout << "token = " << token << std::endl;
		// 	token = strtok(NULL, ",");
		// }
	}
	ifs.close();
	return (dataMap);
}

std::map<std::string, int>	createClientMap(std::ifstream file)
{
	std::map<std::string, int>	clientMap;
	std::string					tmp;

	while (!file.eof())
	{
		std::getline(file, tmp);
		
	}
}


int	main(int argc, char **argv)
{
	std::map<std::string, int>	dataMap = createDataMap(); // 1st step: create map with data from .csv file

	std::ifstream	input(argv[1]);



	// std::map<std::string, int>::iterator	it = dataMap.begin();
	// std::map<std::string, int>::iterator	ite = dataMap.end();

	// while (it != ite)
	// {
	// 	std::cout << it->first << std::endl;
	// 	std::cout << it->second << std::endl;

	// 	*it++;
	// }
	input.close();
}
