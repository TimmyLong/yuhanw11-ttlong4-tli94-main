#include "tests.h"
#include "utils.h"
using namespace std;


bool path_is_same(const vector<int>& pa, const vector<int>& pb) {
    // Check if two path is the same
    if(pa.size() != pb.size()) return false;
    for(size_t i = 0; i < pa.size(); i ++) {
        if(pa[i] != pb[i]) return false;
    }
    return true;
}


void test_astar() {
    map<int, Airport> airports = readAirport();
    map<int, map<int, Airline>> airlines = readAirline("airlines.csv");
    cout << "Total " << airports.size() << " airports" << endl;
    cout << "Total " << airlines.size() << " airlines" << endl;

    int src, dst;
    src = 2965;
    dst = 2966;
    // 2965 -> 2948 -> 2966
    auto path_1 = AStar(airlines, airports, src, dst);
    auto correct_path_1 = vector<int> {2965, 2948, 2966};
    if(path_is_same(path_1, correct_path_1)) cout << "Pass test 1" << endl;
    else cout << "Failed test 1" << endl;

    // test 2
    src = 2975;
    dst = 247;
    auto path_2 = AStar(airlines, airports, src, dst);
    auto correct_path_2 = vector<int> {2975, 1382, 246, 247};
    if(path_is_same(path_2, correct_path_2)) cout << "Pass test 2" << endl;
    else cout << "Failed test 2" << endl;

    src = 1678;
    dst = 3199;
    auto path_3 = AStar(airlines, airports, src, dst);
    auto correct_path_3 = vector<int> {1678, 340, 3199};
    if(path_is_same(path_3, correct_path_3)) cout << "Pass test 3" << endl;
    else cout << "Failed test 3" << endl;
}



void test_bfs() {
    map<int, Airport> airports = readAirport();
    map<int, map<int, Airline>> airlines = readAirline("airlines.csv");
    cout << "Test BFS" << endl;
    int src, dst;

    // test 1
    src = 2965;
    dst = 2966;
    auto path_1 = BFS(airlines, src, dst);
    auto correct_path_1 = vector<int> {2965, 2948, 2966};
    if(path_is_same(path_1, correct_path_1)) cout << "Pass test 1" << endl;
    else cout << "Failed test 1" << endl;
    // test 2
    src = 2975;
    dst = 247;
    auto path_2 = BFS(airlines, src, dst);
    auto correct_path_2 = vector<int> {2975, 1382, 246, 247};
    if(path_is_same(path_2, correct_path_2)) cout << "Pass test 2" << endl;
    else cout << "Failed test 2" << endl;

    src = 1678;
    dst = 3199;
    auto path_3 = BFS(airlines, src, dst);
    auto correct_path_3 = vector<int> {1678, 340, 3199};
    if(path_is_same(path_3, correct_path_3)) cout << "Pass test 3" << endl;
    else cout << "Failed test 3" << endl;
}


void test_floyd() {
    map<int, Airport> airports = readAirport();
    map<int, map<int, Airline>> airlines = readAirline("airlines-small.csv");
    cout << "Test Floyd" << endl;

    int src, dst;
    src = 3885;
    dst = 2276;
    auto path_1 = floyd(airlines, src, dst);
    auto correct_path_1 = vector<int> {3885, 2276};
    print_path(path_1, airports);

    if(path_is_same(path_1, correct_path_1)) cout << "Pass test 1" << endl;
    else cout << "Failed test 1" << endl;
}
