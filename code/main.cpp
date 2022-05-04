#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include "airport.h"
#include "bfs.h"
#include "astar.h"
#include "utils.h"
#include "tests.h"
using namespace std;


int main() {
    // test_bfs();
    // test_astar();
    // test_floyd();
    map<int, Airport> airports = readAirport();
    //please change the "airlines.csv" to "airlines-small.csv" in order to run the floyd algorithem
    map<int, map<int, Airline>> airlines = readAirline("airlines-small.csv");
    cout << "Total " << airports.size() << " airports" << endl;
    cout << "Total " << airlines.size() << " airlines" << endl;

    int src = 2965;
    int dst = 2990;
    cout << "Enter source airport id: ";
    while(true) {
        cin >> src;
        if(airports.find(src) == airports.end()) {
            cout << "Airport " << src << " not found, try again: " << endl;
        } else break;
    }

    cout << "Enter destination airport id: ";
    while(true) {
        cin >> dst;
        if(airports.find(dst) == airports.end()) {
            cout << "Airport " << dst << " not found, try again: " << endl;
        } else break;
    }
    cout << "From airport " << src << " to airport " << dst << endl;
    // bfs
    //auto path = BFS(airlines, src, dst);
    // AStar
    //auto path = AStar(airlines, airports, src, dst);
    // Floyd: In order to run the algorithem, remember to change the "airlines.csv" to "airlines-small.csv"
    auto path = floyd(airlines, src, dst);
    print_path(path, airports);

    return 0;
}
