#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

void							bitcoinExchange(std::map<std::string, double> data, std::ifstream &input);
std::map<std::string, double>	createDatamap();