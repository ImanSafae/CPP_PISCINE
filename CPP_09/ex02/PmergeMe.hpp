#pragma once

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include <vector>

void	parseMainList(std::list<std::pair<int, int> > &mainList, int argc, char **argv, bool &odd);
void	sortPairs(std::list<std::pair<int, int> > &pairs, std::list<int> &subList, bool odd);
void	sortSubList(std::list<int> &subList);
void merge(std::list<int> &subList, std::list<std::pair<int, int> > &mainList, bool odd);
