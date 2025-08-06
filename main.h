// This makes it so that even if many of the compiled files include this header, it only compiles once (if it compiles many times there will be many issues and it will waste time). This is usefull when you have a multi-file program with multiple files that import the header
#pragma once
// Importing all the required libraries
#include <iostream>

#include <cstdlib>

#include <vector>

#include <string>

#include <cmath>

#include <array>

#include <random>

#include <unordered_set>

#include <unordered_map>

#include <algorithm>

// #include <print> - While my preferred output method is this, I am unable to use this since not all compilers can support it yet. It is a c++23 feature and most compilers only have almost-full support till c++20. I find it easier to use cout instead of format

// If you wish to change the number of max overs in the program, change this. Please note that the probability values will not change with this though and wicket rates will be low enough that barely any wickets will fall in shorter matches and a lot of wickets will fall in longer matches
constexpr int maxOvers = 20;
// This initializes a global variable that can be used in any function. I made this a global variable since the regular sim will not use this variable so I can't include it in function parameters so instead I just use it if the 'type' of the function is draft. It is cleared on every run of the draft-sim function
extern std::array<std::array<std::string, 11>, 2> outBy;

// Function initializations for all other files. These make it so that it can be used in any file that includes the header. This function is to change all stats and values whenever a ball occurs
bool outPutRuns(std::string type, int x, std::array<std::vector<char>, maxOvers> &array, int &runO, int &runT, int overN, int &ballN, int &outs, std::array<int, 2> &batsmen, std::array<int, 2> &index, bool &on, std::array<std::array<std::array<int, 3>, 11>, 2> &team, int inning, std::array<int, 2> &balls, std::array<int, 4> &partner, std::vector<std::array<int, 4>> &partners, bool &fHit, std::array<std::vector<std::array<int, 5>>, 2> &fall, int &wickT, int &wickTCount, bool &added, std::array<std::array<std::string, 11>, 2> names, std::string bowler, int special, int bouncer);

// This function has the same functionality as the above one but is only for super overs. It is not refined with a lot of new features though
bool superO(int x, std::array<std::vector<char>, 2> &array, int &runO, int &ballN, int &outs, std::array<int, 2> &batsmen, std::array<int, 2> &index, bool &on, std::array<std::array<std::array<int, 3>, 3>, 2> &team, int inning, std::array<int, 2> &balls, std::array<int, 4> &partner, std::array<std::array<std::string, 3>, 2> nNames, bool &fHit);

void baseSim();

void draftSim(std::string sameTeams);

// The Player struct is used to define the custom buffs and nerfs along with special effects for every single player supported. The boolean values are used to check if they have a special effect and in the draft file you will see that there is working that makes the special effect have an outcome
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

// This function is in the draft function and is what changes all probabilities based on the batsman and bowler
void playerMods(std::string name, std::string nSName, std::string bowler, float &dotP, float &oneP, float &doubleP, float &threeP, float &fourP, float &sixP, float &wideP, int ballsP, int runsP, int overN, int overB, int innings, int gillUpgrades, int hardikUpgrades, int kuldeepWickets, int yuziWickets, int warneWickets, int jadduSpell, int steynSpell, int hasarangaSpell, int partnership, double runRate, double requiredRR, bool pace, bool added, bool flashpoint, bool brokenPartner, std::unordered_map<std::string, Player> players, int& special);

// This is the initialization of a variable that is used to get the buffs, nerfs, and status of different players using their name as the string. I used an unordered_map here since index / order didn't matter
extern std::unordered_map<std::string, Player> Players;

// This function is used to seed the random generator just once. If I constantly seed it in different functions it will cause the values to not be truly random. It is an inline function so its definition is here
inline std::mt19937 &global_rng()
{
  static std::mt19937 rng(std::random_device{}()); // seeded ONCE
  return rng;
}
