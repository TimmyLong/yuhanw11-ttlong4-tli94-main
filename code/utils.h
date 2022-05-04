#pragma once
#include <map>
#include <cmath>
#include "airport.h"

const int INF = 1 << 16;


int to_int(string s);
double to_double(string s);
std::map<int, Airport> readAirport(std::string filename="airports.csv");
std::map<int, std::map<int, Airline>> readAirline(std::string filename="airlines.csv");
void print_path(vector<int>& path, map<int, Airport>& airports);
double dist(double x1, double y1, double x2, double y2);
double estimate(int s, int d, map<int, Airport>& airports);
void reverse_path_helper(vector<int>& path);
