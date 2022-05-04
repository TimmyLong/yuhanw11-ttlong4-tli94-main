#ifndef ASTAR_H_INCLUDED
#define ASTAR_H_INCLUDED

#include <map>
#include <vector>
#include "airport.h"

void build_path(vector<int>& path, map<int, int>& parent, int cur);
std::vector<int> AStar(
    std::map<int, std::map<int, Airline>>& airlines,
    std::map<int, Airport>& airports,
    int src, int dst
);


#endif // ASTAR_H_INCLUDED
