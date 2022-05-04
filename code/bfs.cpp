#include <map>
#include <vector>
#include <queue>
#include <set>
#include "bfs.h"
#include "utils.h"
using namespace std;


vector<int> BFS(map<int, map<int, Airline>>& airlines, int src, int dst) {
    // A* algorithm, given the information of airlines, return an vector of path from src to dst.

    // queue
    queue<int> q;
    // indicate if the airport has been visited in search
    set<int> visited;
    // parent of each search node
    map<int, int> parent;
    // the path
    vector<int> path;

    q.push(src);
    parent[src] = 0;
    int cur, d;
    while(!q.empty()) {
        // get an node from the queue
        cur = q.front();
        q.pop();
        // if current is the dst
        if(cur == dst) {
            // then find the path
            while(cur != 0) {
                path.push_back(cur);
                cur = parent[cur];
            }
            reverse_path_helper(path);
            return path;
        }
        // if cur is visited, skip it
        if(visited.find(cur) != visited.end()) continue;
        // mark cur as visited
        visited.insert(cur);

        auto tit = airlines.find(cur);
        if(tit == airlines.end()) continue;
        for(auto it = tit ->second.begin(); it != tit ->second.end(); it ++) {
            d = it ->first;
            if(visited.find(d) == visited.end()) {
                q.push(d);
                if(parent.find(d) == parent.end())
                    parent[d] = cur;
            }
        }
    }
    return path;
}
