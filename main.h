#pragma once
// Imports
#include <iostream>

#include <cstdlib>

#include <time.h>

#include <vector>

#include <string>

#include <cmath>

#include <algorithm>

// #include <print> - can't use yet cause not all compilers support

// Change this to change the number of overs in that match *IMPORTANT*
constexpr int maxOvers = 20;
using array_type = char[maxOvers][100];
extern std::string names[2][11];
// extern std::string names[2][11] = { {"Batsman 1", "Batsman 2", "Batsman 3", "Batsman 4", "Batsman 5", "Batsman 6", "Batsman 7", "Batsman 8", "Batsman 9", "Batsman 10", "Batsman 11"}, {"Batsman 1", "Batsman 2", "Batsman 3", "Batsman 4", "Batsman 5", "Batsman 6", "Batsman 7", "Batsman 8", "Batsman 9", "Batsman 10", "Batsman 11"} };

bool outPutRuns(int x, array_type &array, int &runO, int &runT, int overN, int &ballN, int &ballW, int &outs, int (&batsmen)[2], int (&index)[2], bool &on, std::vector<std::vector<std::vector<int>>> &team, int inning, int (&balls)[2], std::vector<int> &partner, std::vector<std::vector<int>> &partners, bool &fHit);

bool superO(int x, char (&array)[2][100], int &runO, int &ballN, int &ballW, int &outs, int (&batsmen)[2], int (&index)[2], bool &on, std::vector<std::vector<std::vector<int>>> &team, int inning, int (&balls)[2], std::vector<int> &partner, std::string nNames[2][3], bool &fHit);