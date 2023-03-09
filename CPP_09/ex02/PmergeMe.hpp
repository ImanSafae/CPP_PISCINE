#pragma once

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include <vector>
#include <ctime>
#include <cmath>

// LIST
void	parseMainList(std::list<std::pair<int, int> > &mainList, int argc, char **argv, bool &odd);
void	sortPairsList(std::list<std::pair<int, int> > &pairs, std::list<int> &subList, bool odd);
void	sortSubList(std::list<int> &subList);
void	mergeList(std::list<int> &subList, std::list<std::pair<int, int> > &mainList, bool odd);
void	printMainList(std::list<std::pair<int, int> > &mainList, bool odd);


// VECTOR
void	parseMainVector(std::vector<std::pair<int, int> > &mainVector, int argc, char **argv, bool &odd);
void	sortPairsVector(std::vector<std::pair<int, int> > &pairs, std::vector<int> &subVector, bool odd);
void	sortSubVector(std::vector<int> &subVector);
void	mergeVector(std::vector<int> &subvector, std::vector<std::pair<int, int> > &mainvector, bool odd);
void	printMainVector(std::vector<std::pair<int, int> > &mainVector, bool odd);


