#include <map>
#include <vector>
#include <queue>
#include <set>
#include "bfs.h"
#include "utils.h"
using namespace std;


map<int, int> find_mapping(map<int, map<int, Airline>>& airlines) {
    // convert the mapping from airport id to continuous id
    map<int, int> airportmap;
    int source, dest, index = 0;
    for(auto iterator1 = airlines.begin(); iterator1 != airlines.end(); iterator1 ++) {
        // source of the airline
        source = iterator1 ->first;
        if(airportmap.find(source) == airportmap.end())
            airportmap[source] = index ++;

        for(auto iterator2 = iterator1 ->second.begin(); iterator2 != iterator1 ->second.end(); iterator2 ++) {
            // destination of the airline
            dest = iterator2 ->first;

            if(airportmap.find(dest) == airportmap.end())
                airportmap[dest] = index ++;
        }
    }
    return airportmap;
}


void build_matrix(
    map<int, map<int, Airline>>& airlines,
    map<int, int>& airport_mapping,
    vector<vector<int>>& adjacent_matrix
) {
    // initialization
    size_t sz = airport_mapping.size();
    for(size_t i = 0; i < sz; i ++) {
        for(size_t j = 0; j < sz; j ++) {
            if(i == j) {
                adjacent_matrix[i][j] = 0;
                continue;
            }
            adjacent_matrix[i][j] = INF;
        }
    }

    int s, d, s_index, d_index;
    for(auto it1 = airlines.begin(); it1 != airlines.end(); it1 ++) {
        s = it1 ->first;
        s_index = airport_mapping[s];
        for(auto it2 = it1 ->second.begin(); it2 != it1 ->second.end(); it2 ++) {
            // there is an airline from s to d
            d = it2 ->first;
            d_index = airport_mapping[d];
            adjacent_matrix[s_index][d_index] = 1;
        }
    }
}

void initialize_path_matrix(
    vector<vector<int>>& adjacent_matrix,
    vector<vector<int>>& path_matrix
) {
    // initialize the path matrix for floyd algorithm
    size_t sz = adjacent_matrix.size();
    for(size_t i = 0; i < sz; i ++) {
        for(size_t j = 0; j < sz; j ++) {

            if(i != j && adjacent_matrix[i][j] != INF) {
                path_matrix[i][j] = i;
            } else path_matrix[i][j] = -1;
        }
    }
}


vector<int> extract_path(
    vector<vector<int>>& path_matrix,
    int s_index, int d_index
) {
    // extract result
    vector<int> path;
    if(path_matrix[s_index][d_index] >= INF) return path;
    int k = path_matrix[s_index][d_index];
    // add the destination into path and then find until the source
    path.push_back(d_index);
    while(k != -1 && k != s_index) {
        path.push_back(k);
        k = path_matrix[s_index][k];
    }
    path.push_back(s_index);
    return path;
}


vector<int> floyd(
    map<int, map<int, Airline>>& airlines,
    int src, int dst
) {
    // initialize the mapping
    map<int, int> airportmap = find_mapping(airlines);
    // reverse the mapping
    map<int, int> airport_mapping_rev;
    // initialize the adjacent matrix and path matrix
    vector<vector<int>> adjacent_matrix, path_matrix;
    size_t sz = airportmap.size();

    for(size_t i = 0; i < sz; i ++) {
        vector<int> row(sz, INF);
        adjacent_matrix.push_back(row);
    }

    // build matrix
    build_matrix(airlines, airportmap, adjacent_matrix);
    // initialize path
    for(size_t i = 0; i < sz; i ++) {
        vector<int> row(sz, -1);
        path_matrix.push_back(row);
    }
    initialize_path_matrix(adjacent_matrix, path_matrix);
    // floyd algorithm
    for(size_t k = 0; k < sz; k ++) {
        for(size_t i = 0; i < sz; i ++) {
            for(size_t j = 0; j < sz; j ++) {
                if(adjacent_matrix[i][j] > adjacent_matrix[i][k] + adjacent_matrix[k][j]) {
                    adjacent_matrix[i][j] = adjacent_matrix[i][k] + adjacent_matrix[k][j];
                    path_matrix[i][j] = path_matrix[k][j];
                }
            }
        }
    }
    //find the path
    int s_index = airportmap[src];
    int d_index = airportmap[dst];
    // reverse the mapping
    for(auto it = airportmap.begin(); it != airportmap.end(); it ++) {
        airport_mapping_rev[it ->second] = it ->first;
    }
    vector<int> path = extract_path(path_matrix, s_index, d_index);
    for(size_t i = 0; i < path.size(); i ++) {
        path[i] = airport_mapping_rev[path[i]];
    }

    reverse_path_helper(path);
    return path;
}
