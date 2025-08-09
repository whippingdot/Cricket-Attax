#include "main.h"

static Player defaultPlayer;

static Player Gaikwad{
    .batsman = true,
    .dotPIncrease = 0.0225f,
    .onePIncrease = 0.01f,
    .doublePDecrease = 0.02f,
    .fourPIncrease = 0.005f,
    .sixPDecrease = 0.02f,
    .coldStart = true};

static Player Virat{
    .batsman = true,
    .dotPDecrease = 0.02f,
    .onePIncrease = 0.02f,
    .anchor = true};

static Player Rohit{
    .batsman = true,
    .dotPDecrease = 0.02f,
    .fourPIncrease = 0.01f,
    .sixPIncrease = 0.01f,
    .PPSmash = true};

static Player Sai{
    .batsman = true,
    .dotPDecrease = 0.01f,
    .onePIncrease = 0.01f,
    .anchor = true};

static Player Travis{
    .batsman = true,
    .dotPDecrease = 0.0225f,
    .onePDecrease = 0.015f,
    .fourPIncrease = 0.01f,
    .sixPIncrease = 0.015f,
    .paceBuff = true};

static Player Suryakumar{
    .batsman = true,
    .fourPDecrease = 0.015f,
    .sixPIncrease = 0.015f,
    .spinBuff = true};

static Player Pooran{
    .batsman = true,
    .dotPDecrease = 0.01f,
    .onePDecrease = 0.0075f,
    .fourPIncrease = 0.01f,
    .sixPIncrease = 0.005f,
    .paceBuff = true};

static Player Gill{
    .batsman = true,
    .fourPIncrease = 0.01f,
    .flowState = true};

static Player Jaiswal{
    .batsman = true,
    .dotPDecrease = 0.0075f,
    .onePDecrease = 0.015f,
    .fourPIncrease = 0.015f,
    .sixPIncrease = 0.005f};

static Player Hetmyer{
    .batsman = true,
    .dotPDecrease = 0.025f,
    .fourPDecrease = 0.005f,
    .sixPIncrease = 0.025f,
    .redzoneDominator = true};

static Player ABD{
    .batsman = true,
    .dotPIncrease = 0.01f,
    .fourPDecrease = 0.005f,
    .chemistry = true};

static Player Shreyas{
    .batsman = true,
    .dotPDecrease = 0.0225f,
    .onePIncrease = 0.005f,
    .fourPIncrease = 0.015f,
    .spinBuff = true};

static Player Dube{
    .batsman = true,
    .dotPIncrease = 0.035f,
    .onePDecrease = 0.025f,
    .doublePDecrease = 0.02f,
    .fourPDecrease = 0.015f,
    .sixPIncrease = 0.02f,
    .spinBuff = true};

static Player Abhishek{
    .batsman = true,
    .onePDecrease = 0.0325f,
    .fourPIncrease = 0.015f,
    .sixPIncrease = 0.015f,
    .PPSmash = true};

static Player Warner{
    .batsman = true,
    .dotPDecrease = 0.01f,
    .fourPIncrease = 0.015f,
    .sixPDecrease = 0.005f,
    .paceBuff = true};

static Player Gayle{
    .batsman = true,
    .fourPDecrease = 0.01f};

static Player Don{
    .batsman = true,
    .onePIncrease = 0.0075f,
    .doublePIncrease = 0.01f,
    .sixPDecrease = 0.01f,
    .heatCheck = true};

static Player Tendulkar{
    .batsman = true,
    .dotPDecrease = 0.029f,
    .doublePIncrease = 0.01f,
    .fourPIncrease = 0.02f,
    .sixPDecrease = 0.005f,
    .chaseMaster = true};

static Player Dhoni{
    .batsman = true,
    .dotPDecrease = 0.01f,
    .onePDecrease = 0.02f,
    .sixPIncrease = 0.0275f,
    .redzoneDominator = true};

static Player KL{
    .batsman = true,
    .dotPIncrease = 0.03f,
    .onePDecrease = 0.005f,
    .fourPDecrease = 0.005f,
    .sixPDecrease = 0.02f,
    .coldStart = true};

static Player Pant{
    .batsman = true,
    .dotPDecrease = 0.015f,
    .onePDecrease = 0.03f,
    .fourPIncrease = 0.005f,
    .sixPIncrease = 0.02f,
    .flashpoint = true};

static Player Quinton{
    .batsman = true,
    .dotPDecrease = 0.025f,
    .onePDecrease = 0.01f,
    .fourPIncrease = 0.01f,
    .sixPIncrease = 0.02f,
    .PPSmash = true};

static Player Sanju{
    .batsman = true,
    .onePDecrease = 0.015f,
    .fourPDecrease = 0.005f,
    .sixPIncrease = 0.01f,
    .boomOrBust = true};

static Player Klaasen{
    .batsman = true,
    .dotPDecrease = 0.01f,
    .onePDecrease = 0.015f,
    .fourPIncrease = 0.01f,
    .sixPIncrease = 0.01f,
    .flashpoint = true};

static Player Buttler{
    .batsman = true,
    .dotPDecrease = 0.025f,
    .onePIncrease = 0.01f,
    .fourPIncrease = 0.015f,
    .sixPDecrease = 0.005f,
    .boomOrBust = true};

static Player McCullum{
    .batsman = true,
    .dotPDecrease = 0.025f,
    .onePDecrease = 0.01f,
    .fourPIncrease = 0.015f,
    .sixPIncrease = 0.015f};

static Player Jadeja{
    .batsman = true,
    .bowler = true,
    .pace = false,
    .dotPIncrease = 0.0275f,
    .fourPDecrease = 0.02f,
    .sixPDecrease = 0.005f,
    .bDotPIncrease = 0.005f,
    .bOnePDecrease = 0.015f,
    .bSixPIncrease = 0.01f,
    .heatCheck = true,
    .magician = true};

static Player Hardik{
    .batsman = true,
    .bowler = true,
    .pace = true,
    .onePDecrease = 0.0175f,
    .sixPIncrease = 0.01f,
    .bDotPDecrease = 0.015f,
    .bFourPIncrease = 0.005f,
    .bSixPIncrease = 0.008f,
    .flowState = true,
    .deathSpecial = true};

static Player Shakib{
    .batsman = true,
    .bowler = true,
    .pace = false,
    .dotPDecrease = 0.035f,
    .onePIncrease = 0.04f,
    .bDotPIncrease = 0.015f,
    .bOnePDecrease = 0.025f,
    .bFourPIncrease = 0.005f,
    .carry = true};

static Player Maxwell{
    .batsman = true,
    .bowler = true,
    .pace = false,
    .dotPDecrease = 0.0025f,
    .onePDecrease = 0.035f,
    .fourPIncrease = 0.01f,
    .sixPIncrease = 0.02f,
    .bDotPDecrease = 0.026f,
    .bOnePDecrease = 0.015f,
    .bFourPIncrease = 0.015f,
    .bWidePIncrease = 0.02f,
    .flashpoint = true};

static Player Stokes{
    .batsman = true,
    .bowler = true,
    .pace = true,
    .fourPIncrease = 0.01f,
    .sixPDecrease = 0.0075f,
    .bDotPDecrease = 0.01f,
    .bOnePDecrease = 0.0175f,
    .bFourPIncrease = 0.005f,
    .bSixPIncrease = 0.01f,
    .bWidePIncrease = 0.0125f,
    .savior = true,
    .tempoMaster = true};

static Player Russell{
    .batsman = true,
    .bowler = true,
    .pace = true,
    .dotPDecrease = 0.03f,
    .fourPDecrease = 0.01f,
    .sixPIncrease = 0.035f,
    .bDotPDecrease = 0.0125f,
    .bDoublePDecrease = 0.01f,
    .bSixPIncrease = 0.005f,
    .bWidePIncrease = 0.0175f,
    .redzoneDominator = true,
    .deathSpecial = true};

static Player Bravo{
    .batsman = true,
    .bowler = true,
    .pace = true,
    .dotPDecrease = 0.035f,
    .fourPDecrease = 0.01f,
    .sixPIncrease = 0.02f,
    .widePIncrease = 0.02f,
    .bDotPIncrease = 0.01f,
    .bOnePDecrease = 0.02f,
    .bFourPDecrease = 0.005f,
    .bSixPIncrease = 0.015f,
    .deathSpecial = true};

static Player Watson{
    .batsman = true,
    .bowler = true,
    .pace = true,
    .dotPDecrease = 0.04f,
    .fourPIncrease = 0.015f,
    .sixPIncrease = 0.02f,
    .bDotPIncrease = 0.01f,
    .bOnePDecrease = 0.025f,
    .bDoublePDecrease = 0.005f,
    .bFourPIncrease = 0.005f,
    .bSixPIncrease = 0.01f,
    .boomOrBust = true};

static Player Pollard{
    .batsman = true,
    .bowler = true,
    .pace = true,
    .dotPIncrease = 0.0125f,
    .onePDecrease = 0.035f,
    .sixPIncrease = 0.02f,
    .bDotPDecrease = 0.0325f,
    .bDoublePIncrease = 0.005f,
    .bSixPIncrease = 0.015f,
    .bWidePIncrease = 0.01f,
    .redzoneDominator = true,
    .tempoMaster = true};

static Player Washington{
    .batsman = true,
    .bowler = true,
    .pace = false,
    .dotPDecrease = 0.0025f,
    .onePIncrease = 0.025f,
    .sixPDecrease = 0.01f,
    .bDotPIncrease = 0.04f,
    .bOnePDecrease = 0.01f,
    .bDoublePDecrease = 0.01f,
    .bFourPDecrease = 0.005f,
    .bWidePDecrease = 0.015f};

static Player Axar{
    .batsman = true,
    .bowler = true,
    .pace = false,
    .bDotPIncrease = 0.0075f,
    .bOnePDecrease = 0.005f,
    .bFourPDecrease = 0.005f};

static Player Arshdeep{
    .bowler = true,
    .pace = true,
    .bDotPIncrease = 0.005f,
    .bDoublePIncrease = 0.005f,
    .bFourPDecrease = 0.01f,
    .deathSpecial = true};

static Player Bumrah{
    .bowler = true,
    .pace = true,
    .bDotPIncrease = 0.01f,
    .bOnePDecrease = 0.03f,
    .bFourPIncrease = 0.005f,
    .bSixPIncrease = 0.01f,
    .yorkerGod = true};

static Player Steyn{
    .bowler = true,
    .pace = true,
    .bDotPDecrease = 0.005f,
    .bDoublePDecrease = 0.005f,
    .bFourPIncrease = 0.005f,
    .bSixPIncrease = 0.005f,
    .magician = true};

static Player Malinga{
    .bowler = true,
    .pace = true,
    .bDotPIncrease = 0.0125f,
    .bOnePDecrease = 0.015f,
    .bDoublePDecrease = 0.01f,
    .bFourPIncrease = 0.01f,
    .yorkerGod = true};

static Player Trent{
    .bowler = true,
    .pace = true,
    .bDotPDecrease = 0.015f,
    .bOnePDecrease = 0.005f,
    .bFourPIncrease = 0.02f,
    .swingKing = true};

static Player Starc{
    .bowler = true,
    .pace = true,
    .bDotPIncrease = 0.02f,
    .bOnePDecrease = 0.005f,
    .bDoublePDecrease = 0.015f,
    .yorkerGod = true};

static Player Shami{
    .bowler = true,
    .pace = true,
    .bDotPDecrease = 0.015f,
    .bDoublePIncrease = 0.005f,
    .bWidePIncrease = 0.01f,
    .swingKing = true};

static Player Bhuvi{
    .bowler = true,
    .pace = true,
    .bDotPIncrease = 0.0075f,
    .bOnePDecrease = 0.015f,
    .bFourPIncrease = 0.005f,
    .swingKing = true};

static Player Siraj{
    .bowler = true,
    .pace = true,
    .bDotPDecrease = 0.02f,
    .bOnePDecrease = 0.015f,
    .bFourPIncrease = 0.015f,
    .bSixPIncrease = 0.01f};

static Player Archer{
    .bowler = true,
    .pace = true,
    .bDotPDecrease = 0.015f,
    .bSixPIncrease = 0.0125f,
    .tempoMaster = true};

static Player Morne{
    .bowler = true,
    .pace = true,
    .bDotPDecrease = 0.0175f,
    .bFourPDecrease = 0.005f,
    .bSixPIncrease = 0.015f};

static Player Chahar{
    .bowler = true,
    .pace = true,
    .bDotPDecrease = 0.012f,
    .bFourPIncrease = 0.01f,
    .swingKing = true};

static Player Hasaranga{
    .bowler = true,
    .pace = false,
    .bDotPDecrease = 0.015f,
    .bFourPDecrease = 0.0025f,
    .bSixPIncrease = 0.01f,
    .bWidePIncrease = 0.0075f,
    .magician = true};

static Player Rashid{
    .bowler = true,
    .pace = false,
    // All his buffs are in his 'mysterySpin' ability
    .mysterySpin = true};

static Player Chahal{
    .bowler = true,
    .pace = false,
    .bDotPDecrease = 0.015f,
    .bDoublePDecrease = 0.0075f,
    .bFourPIncrease = 0.01f,
    .bWidePIncrease = 0.0075f,
    .wicketUp = true};

static Player Sunil{
    .bowler = true,
    .pace = false,
    .bDotPDecrease = 0.01f,
    .bDoublePIncrease = 0.005f,
    .mysterySpin = true};

static Player Kuldeep{
    .bowler = true,
    .pace = false,
    .bDotPDecrease = 0.0075f,
    .bOnePDecrease = 0.01f,
    .bSixPIncrease = 0.01f,
    .bWidePIncrease = 0.0075f,
    .wicketUp = true};

static Player Ashwin{
    .bowler = true,
    .pace = false,
    .dotPDecrease = 0.01f,
    .onePDecrease = 0.005f,
    .doublePIncrease = 0.005f,
    .sixPIncrease = 0.01f,
    .bDotPIncrease = 0.0075f,
    .bDoublePDecrease = 0.005f,
    .bSixPDecrease = 0.005f};

static Player Varun{
    .bowler = true,
    .pace = false,
    .bDotPDecrease = 0.0075f,
    .bFourPDecrease = 0.005f,
    .bWidePIncrease = 0.0125f,
    .mysterySpin = true};

static Player Warne{
    .bowler = true,
    .pace = false,
    .bDoublePIncrease = 0.01f,
    .bFourPDecrease = 0.025f,
    .bSixPIncrease = 0.015f,
    .wicketUp = true};

double randomDouble(int min, int max);

void playerMods(std::string name, std::string nSName, std::string bowler, float &dotP, float &oneP, float &doubleP, float &threeP, float &fourP, float &sixP, float &wideP, int ballsP, int runsP, int overN, int overB, int innings, int gillUpgrades, int hardikUpgrades, int kuldeepWickets, int yuziWickets, int warneWickets, int jadduSpell, int steynSpell, int hasarangaSpell, int partnership, double runRate, double requiredRR, bool pace, bool added, bool flashpoint, bool brokenPartner, std::unordered_map<std::string, Player> players, int &special)
{
  if (!players.contains(name) || !players.contains(nSName) || !players.contains(bowler))
  {
    std::cout << "PLAYER " << name << " NOT FOUND\n";
    throw(1);
  }

  double random = 0;
  static int kohliWickets = 0;
  static int saiWickets = 0;
  static float dotDecrease = 0.0f;
  static float sixIncrease = 0.0f;
  static float oneIncrease = 0.0f;
  static float fourIncrease = 0.0f;
  static float doubleIncrease = 0.0f;
  static bool narineBuff = false;

  special = 0;

  if (overN == 1 && overB == 0)
  {
    kohliWickets = 0;
    saiWickets = 0;
    narineBuff = false;
  }

  if (added)
  {
    if ((nSName == "Virat Kohli" && overB != 0) || (name == "Virat Kohli" && overB == 0))
    {
      kohliWickets++;
    }
    else if ((nSName == "Sai Sudharsan" && overB != 0) || (name == "Sai Sudharsan" && overB == 0))
    {
      saiWickets++;
    }
  }

  if (kohliWickets > 4)
  {
    kohliWickets = 4;
  }
  else if (saiWickets > 7)
  {
    saiWickets = 7;
  }

  if (players[name].coldStart)
  {
    if (name == "Ruturaj Gaikwad")
    {
      if (ballsP >= 12)
      {
        players[name] = defaultPlayer;
        players[name].dotPDecrease = 0.0275f;
        players[name].onePIncrease = 0.01f;
        players[name].fourPIncrease = 0.025f;
      }
    }
    else if (name == "KL Rahul")
    {
      if (ballsP >= 40)
      {
        players[name] = defaultPlayer;
        players[name].dotPDecrease = 0.04f;
        players[name].onePIncrease = 0.0175f;
        players[name].fourPIncrease = 0.025f;
        players[name].sixPIncrease = 0.01f;
      }
      else if (ballsP >= 10)
      {
        players[name] = defaultPlayer;
        players[name].dotPDecrease = 0.025f;
        players[name].onePIncrease = 0.015f;
        players[name].fourPIncrease = 0.015f;
      }
    }
  }
  else if (players[name].heatCheck)
  {
    if (name == "Ravindra Jadeja")
    {
      if (runsP >= 20)
      {
        players[name] = defaultPlayer;
        players[name].dotPDecrease = 0.03f;
        players[name].onePDecrease = 0.0075f;
        players[name].fourPIncrease = 0.015f;
        players[name].sixPIncrease = 0.025f;
      }
    }
    else if (name == "Don Bradman")
    {
      if (runsP >= 50)
      {
        players[name] = defaultPlayer;
        players[name].dotPDecrease = 0.035f;
        players[name].onePDecrease = 0.025f;
        players[name].doublePDecrease = 0.01f;
        players[name].fourPIncrease = 0.085f;
        players[name].sixPDecrease = 0.02f;
      }
    }
  }
  else if (players[name].boomOrBust)
  {
    if (name == "Sanju Samson")
    {
      if (ballsP >= 20)
      {
        players[name] = defaultPlayer;
        players[name].dotPDecrease = 0.0175f;
        players[name].fourPIncrease = 0.02f;
        players[name].sixPIncrease = 0.01f;
      }
    }
    else if (name == "Jos Buttler")
    {
      if (ballsP >= 14)
      {
        players[name] = defaultPlayer;
        players[name].onePDecrease = 0.015f;
        players[name].fourPIncrease = 0.005f;
        players[name].sixPIncrease = 0.015f;
      }
    }
    else if (name == "Shane Watson")
    {
      if (ballsP >= 18)
      {
        players[name] = defaultPlayer;
        players[name].onePIncrease = 0.0075f;
        players[name].fourPDecrease = 0.005f;
        players[name].sixPDecrease = 0.005f;
      }
    }
  }
  else if (players[name].PPSmash)
  {
    if (overN >= 7)
    {
      players[name] = defaultPlayer;
      if (name == "Rohit Sharma")
      {
        players[name].onePIncrease = 0.005f;
        players[name].fourPDecrease = 0.01f;
        players[name].sixPIncrease = 0.005f;
      }
      else if (name == "Abhishek Sharma")
      {
        players[name].onePDecrease = 0.0175f;
        players[name].fourPIncrease = 0.015f;
      }
      else if (name == "Quinton de Kock")
      {
        players[name].dotPIncrease = 0.0025f;
        players[name].onePDecrease = 0.01f;
        players[name].fourPIncrease = 0.005f;
        players[name].sixPIncrease = 0.005f;
      }
    }
  }
  else if (players[name].paceBuff)
  {
    if (pace)
    {
      players[name].dotPDecrease += 0.02f;
      players[name].fourPIncrease += 0.01f;
      players[name].sixPIncrease += 0.01f;
    }
  }
  else if (players[name].spinBuff)
  {
    if (!pace)
    {
      if (name == "Shivam Dube")
      {
        players[name].dotPDecrease += 0.026f;
        players[name].fourPDecrease += 0.02f;
        players[name].sixPIncrease += 0.045f;
      }
      else
      {
        players[name].dotPDecrease += 0.015f;
        players[name].onePDecrease += 0.005f;
        players[name].fourPIncrease += 0.005f;
        players[name].sixPIncrease += 0.015f;
      }
    }
  }
  else if (players[name].redzoneDominator)
  {
    if (overN < 17)
    {
      if (name == "MS Dhoni" || name == "Andre Russell")
      {
        players[name] = defaultPlayer;
        players[name].dotPIncrease = 0.025f;
        players[name].onePDecrease = 0.015f;
        players[name].fourPDecrease = 0.02f;
        players[name].sixPIncrease = 0.01f;
      }
    }
    if (overN < 18)
    {
      if (name == "Kieron Pollard" || name == "Shimron Hetmyer")
      {
        players[name] = defaultPlayer;
        players[name].onePDecrease = 0.01f;
        players[name].sixPIncrease = 0.01f;
      }
    }
  }
  else if (players[name].anchor)
  {
    if (name == "Virat Kohli")
    {
      players[name].dotPDecrease += (0.005f * kohliWickets);
      players[name].fourPIncrease += (0.01f * kohliWickets);
    }
    else if (name == "Sai Sudharsan")
    {
      players[name].onePDecrease += (0.005f * saiWickets);
      players[name].sixPIncrease += (0.0075f * saiWickets);
    }
  }
  else if (players[name].flowState)
  {
    if (name == "Shubman Gill")
    {
      if (gillUpgrades == 300)
      {
        gillUpgrades = 0;
      }
      players[name].dotPDecrease += (0.01f * gillUpgrades);
      players[name].fourPIncrease += (0.0075f * gillUpgrades);
    }
    else if (name == "Hardik Pandya")
    {
      if (hardikUpgrades == 300)
      {
        hardikUpgrades = 0;
      }
      players[name].dotPDecrease += (0.0075f * hardikUpgrades);
      players[name].onePDecrease += (0.001f * hardikUpgrades);
      players[name].fourPIncrease += (0.005f * hardikUpgrades);
      players[name].sixPIncrease += (0.005f * hardikUpgrades);
    }
  }
  else if (players[name].chemistry)
  {
    if (!brokenPartner)
    {
      if (partnership < 100)
      {
        players[name].dotPDecrease += (0.0075f * (partnership / 20));
        players[name].fourPIncrease += (0.01f * (partnership / 20));
      }
      else
      {
        players[name].dotPDecrease += (0.0075f * 5);
        players[name].fourPIncrease += (0.01f * 5);
      }
    }
    else
    {
      players[name] = defaultPlayer;
      players[name].dotPDecrease = 0.025f;
      players[name].fourPIncrease = 0.01f;
      players[name].sixPIncrease = 0.02f;
    }
  }
  else if (players[name].savior)
  {
    if (runRate <= 9.5 || requiredRR >= 12.5)
    {
      players[name].onePDecrease += 0.03f;
      players[name].fourPIncrease += 0.005f;
      players[name].sixPIncrease += 0.025f;
    }
  }
  else if (players[name].chaseMaster)
  {
    if (innings == 2)
    {
      players[name] = defaultPlayer;
      players[name].dotPDecrease = 0.03f;
      players[name].onePIncrease = 0.01f;
      players[name].doublePDecrease = 0.01f;
      players[name].fourPIncrease = 0.03f;
    }
  }
  else if (name == "Rashid Khan")
  {
    if (overN >= 17)
    {
      players[name].dotPDecrease = 0.005f;
      players[name].onePDecrease = 0.015f;
      players[name].fourPDecrease = 0.02f;
      players[name].sixPIncrease = 0.04f;
    }
  }
  else if (name == "Sunil Narine")
  {
    if (overN < 7 || narineBuff)
    {
      players[name].dotPDecrease = 0.0195f;
      players[name].onePDecrease = 0.015f;
      players[name].fourPIncrease = 0.01f;
      players[name].sixPIncrease = 0.0225f;
      narineBuff = true;
    }
  }

  if (nSName == "Sai Sudharsan")
  {
    players[name].dotPIncrease += (0.002f * saiWickets);
  }
  else if (nSName == "AB de Villiers")
  {
    if (!brokenPartner)
    {
      if (partnership < 100)
      {
        players[name].dotPIncrease += (0.01f * (partnership / 20));
        players[name].onePDecrease += (0.0075f * (partnership / 20));
      }
      else
      {
        players[name].dotPIncrease += (0.01f * 5);
        players[name].onePDecrease += (0.0075f * 5);
      }
    }
  }
  else if (players[nSName].carry)
  {
    players[name].onePDecrease += 0.025f;
    players[name].fourPIncrease += 0.01f;
    players[name].sixPIncrease += 0.01f;
  }

  if (players[bowler].deathSpecial)
  {
    if (overN >= 17)
    {
      players[bowler] = defaultPlayer;
      if (bowler == "Hardik Pandya")
      {
        players[bowler].bDotPIncrease = 0.01f;
        players[bowler].bOnePDecrease = 0.015f;
        players[bowler].bDoublePIncrease = 0.01f;
        players[bowler].bFourPDecrease = 0.01f;
        players[bowler].bSixPDecrease = 0.005f;
      }
      else if (bowler == "Andre Russell")
      {
        players[bowler].bDotPDecrease = 0.015f;
        players[bowler].bSixPIncrease = 0.005f;
      }
      else if (bowler == "Dwayne Bravo")
      {
        players[bowler].bOnePIncrease = 0.005f;
        players[bowler].bDoublePIncrease = 0.005f;
        players[bowler].bFourPDecrease = 0.005f;
        players[bowler].bSixPDecrease = 0.015f;
        players[bowler].bWidePIncrease = 0.005f;
      }
      else if (bowler == "Arshdeep Singh")
      {
        players[bowler].bDotPIncrease = 0.03f;
        players[bowler].bDoublePIncrease = 0.01f;
        players[bowler].bFourPDecrease = 0.02f;
        players[bowler].bSixPIncrease = 0.02f;
      }
    }
  }
  else if (players[bowler].swingKing)
  {
    if (overN < 7)
    {
      players[bowler] = defaultPlayer;
      if (bowler == "Trent Boult")
      {
        players[bowler].bOnePDecrease = 0.0135f;
        players[bowler].bDoublePIncrease = 0.02f;
        players[bowler].bFourPIncrease = 0.01f;
        players[bowler].bSixPDecrease = 0.02f;
      }
      else if (bowler == "Mohammed Shami")
      {
        players[bowler].bDotPDecrease = 0.0175f;
        players[bowler].bFourPIncrease = 0.015f;
        players[bowler].bSixPDecrease = 0.005f;
      }
      else if (bowler == "Bhuvneshwar Kumar")
      {
        players[bowler].bDotPIncrease = 0.03f;
        players[bowler].bOnePDecrease = 0.015f;
        players[bowler].bFourPDecrease = 0.01f;
        players[bowler].bSixPDecrease = 0.01f;
        players[bowler].bWidePIncrease = 0.005f;
      }
      else if (bowler == "Deepak Chahar")
      {
        players[bowler].bDotPIncrease = 0.013f;
        players[bowler].bDoublePDecrease = 0.005f;
        players[bowler].bWidePDecrease = 0.015f;
      }
    }
  }
  else if (players[bowler].mysterySpin)
  {
    if (bowler == "Rashid Khan")
    {
      if (overB == 0)
      {
        random = randomDouble(0, 100);
        players[bowler].bDotPDecrease += static_cast<float>(random);
        dotDecrease = static_cast<float>(random);
        random = randomDouble(-150, 150);
        players[bowler].bSixPIncrease += static_cast<float>(random);
        players[bowler].bOnePIncrease += static_cast<float>(-1 * random);
        sixIncrease = static_cast<float>(random);
        oneIncrease = static_cast<float>(-1 * random);
        random = randomDouble(-50, 50);
        players[bowler].bFourPIncrease += static_cast<float>(random);
        players[bowler].bDoublePIncrease += static_cast<float>(-1 * random);
        fourIncrease = static_cast<float>(random);
        doubleIncrease = static_cast<float>(-1 * random);
      }
      else
      {
        players[bowler].bDotPDecrease += dotDecrease;
        players[bowler].bSixPIncrease += sixIncrease;
        players[bowler].bOnePIncrease += oneIncrease;
        players[bowler].bFourPIncrease += fourIncrease;
        players[bowler].bDoublePIncrease += doubleIncrease;
      }
    }
    else if (bowler == "Sunil Narine")
    {
      random = randomDouble(-100, 100);
      players[bowler].bSixPIncrease += static_cast<float>(random);
      players[bowler].bDoublePIncrease += static_cast<float>(-1 * random);
      random = randomDouble(-50, 50);
      players[bowler].bFourPIncrease += static_cast<float>(random);
      players[bowler].bOnePIncrease += static_cast<float>(-1 * random);
    }
    else if (bowler == "Varun Chakravarthy")
    {
      random = randomDouble(0, 50);
      players[bowler].bDotPDecrease += static_cast<float>(random);
      random = randomDouble(-50, 50);
      players[bowler].bSixPIncrease += static_cast<float>(random);
      players[bowler].bWidePIncrease += static_cast<float>(-1 * random);
      random = randomDouble(-100, 100);
      players[bowler].bFourPIncrease += static_cast<float>(random);
      players[bowler].bOnePIncrease += static_cast<float>(-1 * random);
    }
  }
  else if (players[bowler].tempoMaster)
  {
    std::uniform_int_distribution<> ballType(1, 100);
    if (ballType(global_rng()) > 0 && ballType(global_rng()) <= 8)
    {
      // Bouncer
      std::cout << "Bouncer! ";
      players[bowler] = defaultPlayer;
      players[bowler].bDotPIncrease = 0.02f;
      players[bowler].bOnePDecrease = 0.045f;
      players[bowler].bDoublePDecrease = 0.02f;
      players[bowler].bFourPIncrease = 0.01f;
      players[bowler].bSixPIncrease = 0.01f;
      players[bowler].bWidePIncrease = 0.005f;
      special = 1;
    }
    else if (ballType(global_rng()) >= 20 && ballType(global_rng()) < 30)
    {
      // Slow Ball
      std::cout << "Slow ball! ";
      players[bowler] = defaultPlayer;
      players[bowler].bDotPDecrease = 0.015f;
      players[bowler].bDoublePDecrease = 0.02f;
      players[bowler].bFourPIncrease = 0.01f;
      players[bowler].bSixPIncrease = 0.015f;
      special = 2;
    }
  }
  else if (players[bowler].magician)
  {
    if (bowler == "Ravindra Jadeja")
    {
      if (jadduSpell)
      {
        players[bowler] = defaultPlayer;
        players[bowler].bOnePIncrease = 0.015f;
        players[bowler].bDoublePIncrease = 0.01f;
        players[bowler].bFourPDecrease = 0.01f;
        players[bowler].bSixPDecrease = 0.005f;
        players[bowler].bWidePDecrease = 0.015f;
      }
    }
    else if (bowler == "Dale Steyn")
    {
      players[bowler].bDotPIncrease += (0.01f * steynSpell);
      players[bowler].bOnePDecrease += (0.01f * steynSpell);
      players[bowler].bFourPDecrease += (0.005f * steynSpell);
    }
    else if (bowler == "Wanindu Hasaranga")
    {
      players[bowler].bDotPIncrease += (0.01f * hasarangaSpell);
      players[bowler].bDoublePIncrease += (0.005f * hasarangaSpell);
      players[bowler].bFourPDecrease += (0.015f * hasarangaSpell);
      players[bowler].bWidePDecrease += (0.0025f * hasarangaSpell);
    }
  }
  else if (players[bowler].wicketUp)
  {
    if (bowler == "Yuzvendra Chahal")
    {
      players[bowler].bDotPIncrease += (0.0025f * yuziWickets);
      players[bowler].bDoublePIncrease += (0.005f * yuziWickets);
      players[bowler].bFourPDecrease += (0.005f * yuziWickets);
      players[bowler].bSixPDecrease += (0.0025f * yuziWickets);
      players[bowler].bWidePDecrease += (0.0025f * yuziWickets);
    }
    else if (bowler == "Kuldeep Yadav")
    {
      players[bowler].bDotPIncrease += (0.01f * kuldeepWickets);
      players[bowler].bFourPDecrease += (0.005f * kuldeepWickets);
      players[bowler].bSixPDecrease += (0.005f * kuldeepWickets);
      players[bowler].bWidePDecrease += (0.005f * kuldeepWickets);
    }
    else if (bowler == "Shane Warne")
    {
      if (warneWickets >= 2)
      {
        players[bowler] = defaultPlayer;
        players[bowler].bDotPDecrease = 0.0075f;
        players[bowler].bFourPDecrease = 0.01f;
      }
    }
  }

  dotP += (players[name].dotPIncrease + players[bowler].bDotPIncrease) - (players[name].dotPDecrease + players[bowler].bDotPDecrease);
  oneP += (players[name].onePIncrease + players[bowler].bOnePIncrease) - (players[name].onePDecrease + players[bowler].bOnePDecrease);
  doubleP += (players[name].doublePIncrease + players[bowler].bDoublePIncrease) - (players[name].doublePDecrease + players[bowler].bDoublePDecrease);
  fourP += (players[name].fourPIncrease + players[bowler].bFourPIncrease) - (players[name].fourPDecrease + players[bowler].bFourPDecrease);
  if (name == "Chris Gayle")
  {
    if (oneP < 0.14f)
    {
      sixP += oneP - 0.1f;
      dotP += 0.005f;
    }
    else
    {
      sixP += 0.04f;
      dotP += oneP - 0.135f; // cause plus 0.01f anyway
    }
    oneP = 0.1f;
    sixP += players[bowler].bSixPIncrease - players[bowler].bDotPDecrease;
  }
  else
  {
    sixP += (players[name].sixPIncrease + players[bowler].bSixPIncrease) - (players[name].sixPDecrease + players[bowler].bSixPDecrease);
  }
  wideP += (players[name].widePIncrease + players[bowler].bWidePIncrease) - (players[name].widePDecrease + players[bowler].bWidePDecrease);

  if (players[name].flashpoint)
  {
    if (flashpoint)
    {
      dotP = 0.1f;
      oneP = 0.35f;
      doubleP = 0.18f;
      threeP = 0.005f;
      fourP = 0.15f;
      sixP = 0.15f;
      wideP = 0.015f;
    }
  }
}

std::unordered_map<std::string, Player> Players = {
    {"Ruturaj Gaikwad", Gaikwad},
    {"Virat Kohli", Virat},
    {"Rohit Sharma", Rohit},
    {"Sai Sudharsan", Sai},
    {"Travis Head", Travis},
    {"Suryakumar Yadav", Suryakumar},
    {"Nicholas Pooran", Pooran},
    {"Shubman Gill", Gill},
    {"Yashasvi Jaiswal", Jaiswal},
    {"Shimron Hetmyer", Hetmyer},
    {"AB de Villiers", ABD},
    {"Shreyas Iyer", Shreyas},
    {"Shivam Dube", Dube},
    {"Abhishek Sharma", Abhishek},
    {"David Warner", Warner},
    {"Chris Gayle", Gayle},
    {"Brendon McCullum", McCullum},
    {"Don Bradman", Don},
    {"Sachin Tendulkar", Tendulkar},
    {"MS Dhoni", Dhoni},
    {"KL Rahul", KL},
    {"Rishabh Pant", Pant},
    {"Quinton de Kock", Quinton},
    {"Sanju Samson", Sanju},
    {"Heinrich Klaasen", Klaasen},
    {"Jos Buttler", Buttler},
    {"Ravindra Jadeja", Jadeja},
    {"Hardik Pandya", Hardik},
    {"Shakib Al Hasan", Shakib},
    {"Glenn Maxwell", Maxwell},
    {"Ben Stokes", Stokes},
    {"Andre Russell", Russell},
    {"Dwayne Bravo", Bravo},
    {"Shane Watson", Watson},
    {"Kieron Pollard", Pollard},
    {"Washington Sundar", Washington},
    {"Axar Patel", Axar},
    {"Arshdeep Singh", Arshdeep},
    {"Jasprit Bumrah", Bumrah},
    {"Dale Steyn", Steyn},
    {"Lasith Malinga", Malinga},
    {"Trent Boult", Trent},
    {"Mitchell Starc", Starc},
    {"Mohammed Shami", Shami},
    {"Bhuvneshwar Kumar", Bhuvi},
    {"Mohammed Siraj", Siraj},
    {"Jofra Archer", Archer},
    {"Morne Morkel", Morne},
    {"Deepak Chahar", Chahar},
    {"Wanindu Hasaranga", Hasaranga},
    {"Rashid Khan", Rashid},
    {"Yuzvendra Chahal", Chahal},
    {"Sunil Narine", Sunil},
    {"Kuldeep Yadav", Kuldeep},
    {"Ravichandran Ashwin", Ashwin},
    {"Varun Chakravarthy", Varun},
    {"Shane Warne", Warne},
};

double randomDouble(int min, int max)
{
  std::uniform_int_distribution<int> rDouble(min, max);
  return rDouble(global_rng()) / 10000.0;
}
