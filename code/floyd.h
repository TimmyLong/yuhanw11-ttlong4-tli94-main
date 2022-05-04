#pragma once
#include <map>
#include <vector>
#include "airport.h"
using namespace std;

map<int, int> find_mapping(map<int, map<int, Airline>>& airlines);
void build_matrix(
    map<int, map<int, Airline>>& airlines,
    map<int, int>& airport_mapping,
    vector<vector<int>>& adjacent_matrix
);
void initialize_path_matrix(
    vector<vector<int>>& adjacent_matrix,
    vector<vector<int>>& path_matrix
);
vector<int> extract_path(
    vector<vector<int>>& path_matrix,
    int s_index, int d_index
);
vector<int> floyd(
    map<int, map<int, Airline>>& airlines,
    int src, int dst
);
