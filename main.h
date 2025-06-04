#pragma once
// Imports
#include <iostream>

#include <cstdlib>

#include <time.h>

#include <vector>

#include <string>

#include <cmath>

#include <array>

#include <random>

#include <unordered_set>

#include <unordered_map>

// #include <print> - can't use yet cause not all compilers support

// Change this to change the number of overs in that match *IMPORTANT*
constexpr int maxOvers = 20;
// extern std::string names[2][11] = { {"Batsman 1", "Batsman 2", "Batsman 3", "Batsman 4", "Batsman 5", "Batsman 6", "Batsman 7", "Batsman 8", "Batsman 9", "Batsman 10", "Batsman 11"}, {"Batsman 1", "Batsman 2", "Batsman 3", "Batsman 4", "Batsman 5", "Batsman 6", "Batsman 7", "Batsman 8", "Batsman 9", "Batsman 10", "Batsman 11"} };

bool outPutRuns(int x, std::array<std::vector<char>, maxOvers> &array, int &runO, int &runT, int overN, int &ballN, int &outs, std::array<int, 2> &batsmen, std::array<int, 2> &index, bool &on, std::vector<std::vector<std::vector<int>>> &team, int inning, std::array<int, 2> &balls, std::vector<int> &partner, std::vector<std::vector<int>> &partners, bool &fHit, std::array<std::vector<std::array<int, 5>>, 2> &fall, int &wickT, int &wickTCount, bool &added, std::array<std::array<std::string, 11>, 2> names);

bool superO(int x, std::array<std::vector<char>, 2> &array, int &runO, int &ballN, int &outs, std::array<int, 2> &batsmen, std::array<int, 2> &index, bool &on, std::vector<std::vector<std::vector<int>>> &team, int inning, std::array<int, 2> &balls, std::vector<int> &partner, std::array<std::array<std::string, 3>, 2> nNames, bool &fHit);

void baseSim();

void draftSim();
