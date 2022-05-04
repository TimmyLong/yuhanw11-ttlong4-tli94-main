#ifndef BFS_H_INCLUDED
#define BFS_H_INCLUDED
#include <map>
#include <vector>
#include "airport.h"

std::vector<int> BFS(std::map<int, std::map<int, Airline>>& airlines, int src, int dst);

#endif // BFS_H_INCLUDED
