#include "BitcoinExchange.hpp"

void	removeSpaces(std::string &str)
{
	double		spaceIndex = str.find(' ');

	while (spaceIndex != std::string::npos)
	{
		str.erase(spaceIndex, 1);
		spaceIndex = str.find(' ');
	}
}

std::string	*split(std::string str, char sep)
{
	std::string	*keyAndValue = new std::string[2];

	std::string	key;
	std::string	value;
	double			splitIndex;

	splitIndex = str.find(sep);
	if (splitIndex == std::string::npos)
	{
		keyAndValue[0] = str;
		keyAndValue[1] = "";
		return (keyAndValue);
	}
	key = str.substr(0, splitIndex);
	value = str.substr(splitIndex + 1, str.size());
	keyAndValue[0] = key;
	keyAndValue[1] = value;
	return (keyAndValue);
}

std::map<std::string, double>	createDatamap()
{
	std::map<std::string, double>	datamap;

	std::ifstream	ifs("data.csv");
	std::string		tmp;

	while (!ifs.eof())
	{
		std::getline(ifs, tmp);
		std::string	*keyAndValue = split(tmp, ',');

		std::string key = keyAndValue[0];
		std::string value = keyAndValue[1];
		delete [] keyAndValue;

		datamap.insert(std::pair<std::string, double>(key, atof(value.c_str())));
	}
	ifs.close();
	return (datamap);
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
	double	total = price * quantity;
	std::cout << date << " => " << quantity << " = " << total << std::endl;
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

void	bitcoinExchange(std::map<std::string, double> data, std::ifstream &input)
{
	std::string		tmp;

	while (!input.eof())
	{
		std::getline(input, tmp);
		std::string	*keyAndValue = split(tmp, '|');
		removeSpaces(keyAndValue[0]);
		removeSpaces(keyAndValue[1]);
		std::string key = keyAndValue[0];
		std::string value = keyAndValue[1];
		delete [] keyAndValue;

		if (!key.compare("date") || !value.compare("value"))
			continue ;
		if (dateInWrongFormat(key))
		{
			std::cout << "Error: bad input => " << key << std::endl;
			continue ;
		}
		double	price = getPrice(data, key);
		if (price != -1)
			printProduct(key, atof(value.c_str()), price);
		else
		{
			std::map<std::string, double>::iterator it = data.lower_bound(key);
			if (it == data.begin())
			{
				std::cout << "Error: unavailable data for this date." << std::endl;
				continue ;
			}
			it--;
			price = it->second;
			printProduct(key, atof(value.c_str()), price);
			// std::cout << "Error: unavailable data for this date." << std::endl;
		}
	}
}
