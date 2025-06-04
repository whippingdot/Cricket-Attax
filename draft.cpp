#include "main.h"

static Player Gaikwad{
    .dotPIncrease = 0.045f,
    .onePIncrease = 0.02f,
    .doublePDecrease = 0.04f,
    .fourPIncrease = 0.01f,
    .sixPDecrease = 0.04f};

static Player Virat{
    .dotPDecrease = 0.04f,
    .onePIncrease = 0.04f};

static Player Rohit{
    .dotPDecrease = 0.04f,
    .fourPIncrease = 0.02f,
    .sixPIncrease = 0.02f};

static Player Sai{
    .dotPDecrease = 0.02f,
    .onePIncrease = 0.02f};

static Player Travis{
    .dotPDecrease = 0.045f,
    .onePDecrease = 0.03f,
    .fourPIncrease = 0.02f,
    .sixPIncrease = 0.03f};

static Player Suryakumar{
    .fourPDecrease = 0.03f,
    .sixPIncrease = 0.03f};

static Player Pooran{
    .dotPDecrease = 0.02f,
    .onePDecrease = 0.015f,
    .fourPIncrease = 0.02f,
    .sixPIncrease = 0.01f};

static Player Gill{
    .fourPIncrease = 0.02f};

static Player Jaiswal{
    .dotPDecrease = 0.015f,
    .onePDecrease = 0.03f,
    .fourPIncrease = 0.03f,
    .sixPIncrease = 0.01f};

static Player Hetmeyer{
    .dotPDecrease = 0.05f,
    .fourPDecrease = 0.01f,
    .sixPIncrease = 0.05f,
};

static Player ABD{
    .dotPIncrease = 0.02f,
    .fourPDecrease = 0.01f};

static Player Shreyas{
    .dotPDecrease = 0.045f,
    .onePIncrease = 0.01f,
    .fourPIncrease = 0.03f};

static Player Dube{
    .dotPIncrease = 0.07f,
    .onePDecrease = 0.05f,
    .doublePDecrease = 0.04f,
    .fourPDecrease = 0.03f,
    .sixPIncrease = 0.04f};

static Player Abhishek{
    .onePDecrease = 0.065f,
    .fourPIncrease = 0.03f,
    .sixPIncrease = 0.03f};

static Player Warner{
    .dotPDecrease = 0.02f,
    .fourPIncrease = 0.03f,
    .sixPDecrease = 0.01f};

static Player Dhoni{
    .dotPDecrease = 0.02f,
    .onePDecrease = 0.04f,
    .sixPIncrease = 0.055f};

static Player KL{
    .dotPIncrease = 0.06f,
    .onePDecrease = 0.01f,
    .fourPDecrease = 0.01f,
    .sixPDecrease = 0.04f};

static Player Pant{
    .dotPDecrease = 0.03f,
    .onePDecrease = 0.06f,
    .fourPIncrease = 0.03f,
    .sixPIncrease = 0.04f,
};

static Player Quinton{
    .dotPDecrease = 0.05f,
    .onePDecrease = 0.02f,
    .fourPIncrease = 0.02f,
    .sixPIncrease = 0.04f};

static Player Sanju{
    .onePDecrease = 0.03f,
    .fourPDecrease = 0.01f,
    .sixPIncrease = 0.02f};

static Player Klaasen{
    .dotPDecrease = 0.02f,
    .onePDecrease = 0.03f,
    .fourPIncrease = 0.02f,
    .sixPIncrease = 0.02f};

static Player Buttler{
    .dotPDecrease = 0.05f,
    .onePIncrease = 0.02f,
    .fourPIncrease = 0.03f,
    .sixPDecrease = 0.01f};

static Player Salt{
    .dotPDecrease = 0.05f,
    .onePDecrease = 0.02f,
    .fourPIncrease = 0.03f,
    .sixPIncrease = 0.03f};

static Player Jadeja{
    .dotPIncrease = 0.055f,
    .fourPDecrease = 0.04f,
    .sixPDecrease = 0.01f};

static Player Hardik{
    .dotPDecrease = 0.045f,
    .onePIncrease = 0.03f,
    .sixPIncrease = 0.02f,
};

static Player Shakib{
    .dotPDecrease = 0.07f,
    .onePIncrease = 0.08f};

static Player Maxwell{
    .dotPDecrease = 0.005f,
    .onePDecrease = 0.07f,
    .fourPIncrease = 0.02f,
    .sixPIncrease = 0.04f};

static Player Stokes{
    .fourPIncrease = 0.02f,
    .sixPDecrease = 0.015f};

static Player Russell{
    .dotPDecrease = 0.06f,
    .fourPDecrease = 0.02f,
    .sixPIncrease = 0.07f};

static Player Bravo{
    .dotPDecrease = 0.07f,
    .fourPDecrease = 0.02f,
    .sixPIncrease = 0.04f,
    .widePIncrease = 0.04f};

static Player Gayle{
    // Different things completely so please follow. We can't do +8 for when death so have different conditions if death
    .onePIncrease = 0.01f,
    .fourPDecrease = 0.02f,
    .sixPIncrease = 0.08f,
};

static Player Watson{
    .dotPDecrease = 0.08f,
    .fourPIncrease = 0.03f,
    .sixPIncrease = 0.04f};

static Player Pollard{
    .dotPIncrease = 0.025f,
    .onePDecrease = 0.07f,
    .sixPIncrease = 0.04f};

static Player Washington{
    .dotPDecrease = 0.005f,
    .onePIncrease = 0.05f,
    .sixPDecrease = 0.02f};

std::unordered_map<std::string, Player> players = {
    {"Ruturaj Gaikwad", Gaikwad},
    {"Virat Kohli", Virat},
    {"Rohit Sharma", Rohit},
    {"Sai Sudharsan", Sai},
    {"Travis Head", Travis},
    {"Suryakumar Yadav", Suryakumar},
    {"Nicholas Pooran", Pooran},
    {"Shubman Gill", Gill},
    {"Yashasvi Jaiswal", Jaiswal},
    {"Shimron Hetmeyer", Hetmeyer},
    {"AB de Villiers", ABD},
    {"Shreyas Iyer", Shreyas},
    {"Shivam Dube", Dube},
    {"Abhishek Sharma", Abhishek},
    {"David Warner", Warner},
    {"MS Dhoni", Dhoni},
    {"KL Rahul", KL},
    {"Rishabh Pant", Pant},
    {"Quinton de Kock", Quinton},
    {"Sanju Samson", Sanju},
    {"Heinrich Klaasen", Klaasen},
    {"Jos Buttler", Buttler},
    {"Phil Salt", Salt},
    {"Ravindra Jadeja", Jadeja},
    {"Hardik Pandya", Hardik},
    {"Shakib al Hasan", Shakib},
    {"Glenn Maxwell", Maxwell},
    {"Ben Stokes", Stokes},
    {"Andre Russell", Russell},
    {"Dwayne Bravo", Bravo},
    {"Chris Gayle", Gayle},
    {"Shane Watson", Watson},
    {"Kieron Pollard", Pollard},
    {"Washington Sundar", Washington}};

void playerMods(std::string name, float &dotP, float &oneP, float &doubleP, float &threeP, float &fourP, float &sixP, float &wideP)
{
  dotP += players[name].dotPIncrease - players[name].dotPDecrease;
  oneP += players[name].onePIncrease - players[name].onePDecrease;
  doubleP += players[name].doublePIncrease - players[name].doublePDecrease;
  threeP += players[name].threePIncrease - players[name].threePDecrease;
  fourP += players[name].fourPIncrease - players[name].fourPDecrease;
  sixP += players[name].sixPIncrease - players[name].sixPDecrease;
  wideP += players[name].widePIncrease - players[name].widePDecrease;
}
