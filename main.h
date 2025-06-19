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

#include <algorithm>

// #include <print> - can't use yet cause not all compilers support

// Change this to change the number of overs in that match *IMPORTANT*
constexpr int maxOvers = 20;
extern std::array<std::array<std::string, 11>, 2> outBy;
// extern std::string names[2][11] = { {"Batsman 1", "Batsman 2", "Batsman 3", "Batsman 4", "Batsman 5", "Batsman 6", "Batsman 7", "Batsman 8", "Batsman 9", "Batsman 10", "Batsman 11"}, {"Batsman 1", "Batsman 2", "Batsman 3", "Batsman 4", "Batsman 5", "Batsman 6", "Batsman 7", "Batsman 8", "Batsman 9", "Batsman 10", "Batsman 11"} };

bool outPutRuns(std::string type, int x, std::array<std::vector<char>, maxOvers> &array, int &runO, int &runT, int overN, int &ballN, int &outs, std::array<int, 2> &batsmen, std::array<int, 2> &index, bool &on, std::array<std::array<std::array<int, 3>, 11>, 2> &team, int inning, std::array<int, 2> &balls, std::array<int, 4> &partner, std::vector<std::array<int, 4>> &partners, bool &fHit, std::array<std::vector<std::array<int, 5>>, 2> &fall, int &wickT, int &wickTCount, bool &added, std::array<std::array<std::string, 11>, 2> names, std::string bowler);

bool superO(int x, std::array<std::vector<char>, 2> &array, int &runO, int &ballN, int &outs, std::array<int, 2> &batsmen, std::array<int, 2> &index, bool &on, std::array<std::array<std::array<int, 3>, 3>, 2> &team, int inning, std::array<int, 2> &balls, std::array<int, 4> &partner, std::array<std::array<std::string, 3>, 2> nNames, bool &fHit);

void baseSim();

void draftSim(std::string sameTeams);

struct Player
{
  bool batsman = false;
  bool bowler = false;
  bool pace = false;
  float dotPIncrease = 0.0f;
  float dotPDecrease = 0.0f;
  float onePIncrease = 0.0f;
  float onePDecrease = 0.0f;
  float doublePIncrease = 0.0f;
  float doublePDecrease = 0.0f;
  float fourPIncrease = 0.0f;
  float fourPDecrease = 0.0f;
  float sixPIncrease = 0.0f;
  float sixPDecrease = 0.0f;
  float widePIncrease = 0.0f;
  float widePDecrease = 0.0f;
  float bDotPIncrease = 0.0f;
  float bDotPDecrease = 0.0f;
  float bOnePIncrease = 0.0f;
  float bOnePDecrease = 0.0f;
  float bDoublePIncrease = 0.0f;
  float bDoublePDecrease = 0.0f;
  float bFourPIncrease = 0.0f;
  float bFourPDecrease = 0.0f;
  float bSixPIncrease = 0.0f;
  float bSixPDecrease = 0.0f;
  float bWidePIncrease = 0.0f;
  float bWidePDecrease = 0.0f;
  bool coldStart = false;
  bool heatCheck = false;
  bool boomOrBust = false;
  bool PPSmash = false;
  bool paceBuff = false;
  bool spinBuff = false;
  bool redzoneDominator = false;
  bool anchor = false;
  bool flowState = false;
  bool flashpoint = false;
  bool chemistry = false;
  bool savior = false;
  bool carry = false;
  bool chaseMaster = false;
  bool deathSpecial = false;
  bool swingKing = false;
  bool mysterySpin = false;
  bool yorkerGod = false;
  bool tempoMaster = false;
  bool magician = false;
  bool wicketUp = false;
};

void playerMods(std::string name, std::string nSName, std::string bowler, float &dotP, float &oneP, float &doubleP, float &threeP, float &fourP, float &sixP, float &wideP, int ballsP, int runsP, int overN, int overB, int innings, int gillUpgrades, int hardikUpgrades, int kuldeepWickets, int yuziWickets, int warneWickets, int jadduSpell, int steynSpell, int hasarangaSpell, int partnership, double runRate, double requiredRR, bool pace, bool added, bool flashpoint, bool brokenPartner, std::unordered_map<std::string, Player> players);

extern std::unordered_map<std::string, Player> Players;

inline std::mt19937 &global_rng()
{
  static std::mt19937 rng(std::random_device{}()); // seeded ONCE
  return rng;
}
