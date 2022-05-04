#include <map>
#include <vector>
#include <set>
#include "astar.h"
#include "utils.h"
using namespace std;


void build_path(vector<int>& path, map<int, int>& parent, int cur) {
    // Helper function for A* algorithm, find the path
    while(cur != 0) {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse_path_helper(path);
}


map<int, double>::iterator find_min(map<int, double>& open) {
    // Helper function for A* algorithm, find the minimum elements
    auto min_it = open.begin();
    for(auto it = open.begin(); it != open.end(); it ++) {
        if(it ->second < min_it ->second) min_it = it;
    }
    return min_it;
}


vector<int> AStar(
    map<int, map<int, Airline>>& airlines,
    map<int, Airport>& airports,
    int src, int dst
) {
    // A* algorithm, given the information of airlines and airports, return an vector of path from src to dst.

    // the path
    vector<int> path;
    map<int, double> open;
    set<int> close;
    // parent of each search node
    map<int, int> parent;

    // the parent node of src set to 0, means the source has no parent
    parent[src] = 0;
    int cur, d;

    // put the source
    open[src] = 0;

    while(!open.empty()) {
        // get an node from the priority queue, which has smallest cost
        auto min_it = find_min(open);

        // cur is the current airport
        cur = min_it ->first;
        // g is the actual cost (distance)
        double g = min_it ->second;
        // remove from open
        open.erase(min_it);
        close.insert(cur);

        // if current is the dst
        if(cur == dst) {
            build_path(path, parent, cur);
            return path;
        }

        auto tit = airlines.find(cur);
        if(tit == airlines.end()) continue;
        // scan for all possible next airport the current airport can reach
        for(auto it = tit ->second.begin(); it != tit ->second.end(); it ++) {
            d = it ->first;
            if(close.find(d) != close.end())
                continue;
            auto oit = open.find(d);
            // not in open list
            if(oit == open.end() || g + 1 < oit ->second) {
                parent[d] = cur;
                open[d] = g + 1;
                if(d == dst) {
                    build_path(path, parent, d);
                    return path;
                }
                continue;
            }
        }
    }
    return path;
}

