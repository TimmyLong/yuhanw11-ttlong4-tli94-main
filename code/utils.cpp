#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include "utils.h"


int to_int(string s) {
    // convert string s to integer
    stringstream ss(s);
    int e;
    ss >> e;
    return e;
}


double to_double(string s) {
    // convert string s to double
    stringstream ss(s);
    double e;
    ss >> e;
    return e;
}

map<int, Airport> readAirport(string filename) {
    map<int, Airport> airports;
    ifstream fin(filename);
    if(!fin.is_open()) {
        cerr << "Failed to open file " << filename << endl;
        return airports;
    }

    string line, tmp;
    int id;
    string name, city, country, iata, icao;
    double latitude;
    double longitude;
    int altitude;
    string timezone;

    bool first = true;
    size_t pos;
    while(getline(fin, line)) {
        // ignore the header
        if(first) {
            first = false;
            continue;
        }

        pos = line.find(",");
        tmp = line.substr(0, pos);
        id = to_int(tmp);
        line = line.substr(pos + 1);

        pos = line.find(",");
        name = line.substr(0, pos);
        line = line.substr(pos + 1);

        pos = line.find(",");
        city = line.substr(0, pos);
        line = line.substr(pos + 1);

        pos = line.find(",");
        country = line.substr(0, pos);
        line = line.substr(pos + 1);

        pos = line.find(",");
        iata = line.substr(0, pos);
        line = line.substr(pos + 1);

        pos = line.find(",");
        icao = line.substr(0, pos);
        line = line.substr(pos + 1);

        pos = line.find(",");
        tmp = line.substr(0, pos);
        latitude = to_double(tmp);
        line = line.substr(pos + 1);

        pos = line.find(",");
        tmp = line.substr(0, pos);
        longitude = to_double(tmp);
        line = line.substr(pos + 1);

        pos = line.find(",");
        tmp = line.substr(0, pos);
        altitude = to_int(tmp);
        line = line.substr(pos + 1);

        timezone = line;

        Airport airport(id, name, city, country, iata, icao,
                        latitude, longitude, altitude, timezone);
        airports[id] = airport;
    }

    fin.close();
    return airports;
}


map<int, map<int, Airline>> readAirline(string filename) {
    // read in data
    map<int, map<int, Airline>> airlines;

    ifstream fin(filename);
    if(!fin.is_open()) {
        cerr << "Failed to open file " << filename << endl;
        return airlines;
    }

    string line, tmp;
    string airline_name;
    int airline_id;
    string src;
    int src_id;
    string dst;
    int dst_id;

    bool first = true;
    size_t pos;
    while(getline(fin, line)) {
        // ignore the header
        if(first) {
            first = false;
            continue;
        }

        pos = line.find(",");
        airline_name = line.substr(0, pos);
        line = line.substr(pos + 1);

        pos = line.find(",");
        tmp = line.substr(0, pos);
        airline_id = to_int(tmp);
        line = line.substr(pos + 1);

        pos = line.find(",");
        src = line.substr(0, pos);
        line = line.substr(pos + 1);

        pos = line.find(",");
        tmp = line.substr(0, pos);
        src_id = to_int(tmp);
        line = line.substr(pos + 1);

        pos = line.find(",");
        dst = line.substr(0, pos);
        line = line.substr(pos + 1);

        pos = line.find(",");
        tmp = line.substr(0, pos);
        dst_id = to_int(tmp);
        line = line.substr(pos + 1);

        Airline airline(airline_name, airline_id, src, src_id, dst, dst_id);

        if(airlines.find(src_id) == airlines.end())
            airlines[src_id] = map<int, Airline>();
        auto it = airlines.find(src_id);
        it ->second[dst_id] = airline;
    }

    fin.close();
    return airlines;
}

void print_path(vector<int>& path, map<int, Airport>& airports) {
    if(path.size() == 0) {
        cout << "There is no path." << endl;
        return;
    }
    int id;

    cout << "Path: " << endl;
    cout << "\tAirport ids: ";
    for(size_t i = 0; i < path.size(); i ++) {
        id = path[i];
        cout << id;
        if(i != path.size() - 1) cout << " -> ";
    }
    cout << endl;
    cout << "\tAirport names: ";
    for(size_t i = 0; i < path.size(); i ++) {
        id = path[i];
        auto airport = airports[id];
        cout << airport.name;
        if(i != path.size() - 1) cout << " -> ";
    }
    cout << endl;
}


double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double estimate(int s, int d, map<int, Airport>& airports) {
    // estimate the distance from airport s and airport d, using Euclidean distance
    auto a1 = airports[s];
    auto a2 = airports[d];
    return dist(a1.latitude, a1.longitude, a2.latitude, a2.longitude);
}

void reverse_path_helper(vector<int>& path) {
    int tmp;
    size_t i, j;
    for(i = 0, j = path.size() - 1; i < j; i ++, j --) {
        tmp = path[i];
        path[i] = path[j];
        path[j] = tmp;
    }
}

