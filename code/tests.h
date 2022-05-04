#pragma once
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
#include "floyd.h"



bool path_is_same(const vector<int>& pa, const vector<int>& pb);
void test_astar();
void test_bfs();
void test_floyd();
