#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

void	removeSpaces(std::string &str)
{
	double		i = 0;
	double		j = 0;
	double		spaceIndex = str.find(' ');

	while (spaceIndex != std::string::npos)
	{
		str.erase(spaceIndex, 1);
		spaceIndex = str.find(' ');
		// i = spaceIndex;
		// j = spaceIndex + 1;
		// while (str[j] != '\0')
		// {
		// 	str[i] = str[j];
		// 	i++;
		// 	j++;
		// }
		// str[i] = '\0';
	}
}

std::string	*split(std::string str, char sep)
{
	std::string	*keyAndValue = new std::string[2];

	std::string	key;
	std::string	value;
	double			splitIndex;

	splitIndex = str.find(sep);
	// std::cout << "comma found at index " << splitIndex << std::endl;
	key = str.substr(0, splitIndex);
	// std::cout << "key is " << key << std::endl;
	value = str.substr(splitIndex + 1, str.size());
	// std::cout << "value is " << value << std::endl;
	keyAndValue[0] = key;
	keyAndValue[1] = value;
	return (keyAndValue);
}

// make a function that will split the string doubleo key and value
// std::string split_optimized(std::string str, char sep)
// {
// 	std::string	key;
// 	std::string	value;
// 	double			splitIndex;

// 	splitIndex = str.find(sep);
// 	// std::cout << "comma found at index " << splitIndex << std::endl;
// 	key = str.substr(0, splitIndex);
// 	// std::cout << "key is " << key << std::endl;
// 	value = str.substr(splitIndex + 1, str.size());
// 	// std::cout << "value is " << value << std::endl;
// 	return (key);
// }

std::map<std::string, double>	createDataMap()
{
	std::map<std::string, double>	dataMap;

	std::ifstream	ifs("test");
	std::string		tmp;

	while (!ifs.eof())
	{
		std::getline(ifs, tmp);
		std::string	*keyAndValue = split(tmp, ',');

		std::string key = keyAndValue[0];
		std::string value = keyAndValue[1];
		delete [] keyAndValue;

		dataMap.insert(std::pair<std::string, double>(key, atoi(value.c_str())));
	}
	ifs.close();
	return (dataMap);
}

std::map<std::string, double>	createClientMap(std::ifstream &file)
{
	std::map<std::string, double>	clientMap;
	std::string						tmp;

	while (!file.eof())
	{
		std::getline(file, tmp);
		std::string	*keyAndValue = split(tmp, '|');
		removeSpaces(keyAndValue[0]);
		removeSpaces(keyAndValue[1]);
		std::string key = keyAndValue[0];
		std::string value = keyAndValue[1];
		delete [] keyAndValue;

		clientMap.insert(std::pair<std::string, double>(key, atoi(value.c_str())));
	}
	file.close();
	return (clientMap);
}

double	getPrice(std::map<std::string, double> map, std::string date)
{
	std::map<std::string, double>::iterator	it = map.find(date);
	std::map<std::string, double>::iterator	ite = map.end();

	if (it != ite)
		return (it->second);
	return (-1);
}

void	printProduct(std::string const &date, double quantity, double price)
{
	if (quantity < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return ;
	}
	else if (quantity >= INT_MAX)
	{
		std::cout << "Error: too large a number." << std::endl;
		return ;
	}
	std::cout << date << " => " << quantity << " = " << price * quantity << std::endl;
}

bool	dateInWrongFormat(std::string const &date)
{
	if (date.size() != 10)
		return (true);
	if (date[4] != '-' || date[7] != '-')
		return (true);
	for (double i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (date[i] < '0' || date[i] > '9' || !isdigit(date[i]))
			return (true);
	}

	int	month = atoi(date.substr(5, 2).c_str());
	int	day = atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return (true);

	if (month == 2 && day > 29)
		return (true);
	if (day > 30)
	{
		if (month == 4 || month == 6 || month == 9 || month == 11)
			return (true);
	}
	return (false);
}

void	bitcoinExchange(std::map<std::string, double> data, std::map<std::string, double> client)
{
	std::map<std::string, double>::iterator	it = client.begin();
	std::map<std::string, double>::iterator	ite = client.end();

	while (it != ite)
	{
		if (dateInWrongFormat(it->first))
		{
			std::cout << "Error: bad input => " << it->first << std::endl;
			*it++;
			continue ;
		}
		double	price = getPrice(data, it->first);
		if (price != -1)
			printProduct(it->first, it->second, price);
		else
			std::cout << "Error: unavailable data for this date." << std::endl;
		*it++;
	}
}

int	main(int argc, char **argv)
{

	if (argc != 2 || access(argv[1], F_OK) == -1)
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}
	std::ifstream	input(argv[1]);

	std::map<std::string, double>	dataMap = createDataMap(); // 1st step: create map with data from .csv file
	std::map<std::string, double>	clientMap = createClientMap(input); // 2nd step: create map with data from .txt file

	bitcoinExchange(dataMap, clientMap); // 3rd step: print the result


	// std::map<std::string, double>::iterator	it = dataMap.begin();
	// std::map<std::string, double>::iterator	ite = dataMap.end();

	// while (it != ite)
	// {
	// 	std::cout << it->first << std::endl;
	// 	std::cout << it->second << std::endl;

	// 	*it++;
	// }
	input.close();
}
