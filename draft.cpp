#include "main.h"

static Player defaultPlayer;

static Player Gaikwad{
    .dotPIncrease = 0.0225f,
    .onePIncrease = 0.01f,
    .doublePDecrease = 0.02f,
    .fourPIncrease = 0.005f,
    .sixPDecrease = 0.02f,
    .coldStart = true};

static Player Virat{
    .dotPDecrease = 0.02f,
    .onePIncrease = 0.02f,
    .anchor = true};

static Player Rohit{
    .dotPDecrease = 0.02f,
    .fourPIncrease = 0.01f,
    .sixPIncrease = 0.01f,
    .PPSmash = true};

static Player Sai{
    .dotPDecrease = 0.01f,
    .onePIncrease = 0.01f,
    .anchor = true};

static Player Travis{
    .dotPDecrease = 0.0225f,
    .onePDecrease = 0.015f,
    .fourPIncrease = 0.01f,
    .sixPIncrease = 0.015f,
    .paceBuff = true};

static Player Suryakumar{
    .fourPDecrease = 0.015f,
    .sixPIncrease = 0.015f,
    .spinBuff = true};

static Player Pooran{
    .dotPDecrease = 0.01f,
    .onePDecrease = 0.0075f,
    .fourPIncrease = 0.01f,
    .sixPIncrease = 0.005f,
    .paceBuff = true};

static Player Gill{
    .fourPIncrease = 0.01f,
    .flowState = true};

static Player Jaiswal{
    .dotPDecrease = 0.0075f,
    .onePDecrease = 0.015f,
    .fourPIncrease = 0.015f,
    .sixPIncrease = 0.005f};

static Player Hetmeyer{
    .dotPDecrease = 0.025f,
    .fourPDecrease = 0.005f,
    .sixPIncrease = 0.025f,
    .redzoneDominator = true};

static Player ABD{
    .dotPIncrease = 0.01f,
    .fourPDecrease = 0.005f,
    .chemistry = true};

static Player Shreyas{
    .dotPDecrease = 0.0225f,
    .onePIncrease = 0.005f,
    .fourPIncrease = 0.015f,
    .spinBuff = true};

static Player Dube{
    .dotPIncrease = 0.035f,
    .onePDecrease = 0.025f,
    .doublePDecrease = 0.02f,
    .fourPDecrease = 0.015f,
    .sixPIncrease = 0.02f,
    .spinBuff = true};

static Player Abhishek{
    .onePDecrease = 0.0325f,
    .fourPIncrease = 0.015f,
    .sixPIncrease = 0.015f,
    .PPSmash = true};

static Player Warner{
    .dotPDecrease = 0.01f,
    .fourPIncrease = 0.015f,
    .sixPDecrease = 0.005f,
    .paceBuff = true};

static Player Dhoni{
    .dotPDecrease = 0.01f,
    .onePDecrease = 0.02f,
    .sixPIncrease = 0.0275f,
    .redzoneDominator = true};

static Player KL{
    .dotPIncrease = 0.03f,
    .onePDecrease = 0.005f,
    .fourPDecrease = 0.005f,
    .sixPDecrease = 0.02f,
    .coldStart = true};

static Player Pant{
    .dotPDecrease = 0.015f,
    .onePDecrease = 0.03f,
    .fourPIncrease = 0.005f,
    .sixPIncrease = 0.02f,
    .flashpoint = true};

static Player Quinton{
    .dotPDecrease = 0.025f,
    .onePDecrease = 0.01f,
    .fourPIncrease = 0.01f,
    .sixPIncrease = 0.02f,
    .PPSmash = true};

static Player Sanju{
    .onePDecrease = 0.015f,
    .fourPDecrease = 0.005f,
    .sixPIncrease = 0.01f,
    .boomOrBust = true};

static Player Klaasen{
    .dotPDecrease = 0.01f,
    .onePDecrease = 0.015f,
    .fourPIncrease = 0.01f,
    .sixPIncrease = 0.01f,
    .flashpoint = true};

static Player Buttler{
    .dotPDecrease = 0.025f,
    .onePIncrease = 0.01f,
    .fourPIncrease = 0.015f,
    .sixPDecrease = 0.005f,
    .boomOrBust = true};

static Player Salt{
    .dotPDecrease = 0.025f,
    .onePDecrease = 0.01f,
    .fourPIncrease = 0.015f,
    .sixPIncrease = 0.015f};

static Player Jadeja{
    .bowler = true,
    .pace = false,
    .dotPIncrease = 0.0275f,
    .fourPDecrease = 0.02f,
    .sixPDecrease = 0.005f,
    .bDotPIncrease = 0.005f,
    .bOnePDecrease = 0.015f,
    .bSixPIncrease = 0.01f,
    .heatCheck = true};

static Player Hardik{
    .bowler = true,
    .pace = true,
    .onePDecrease = 0.0175f,
    .sixPIncrease = 0.01f,
    .bDotPDecrease = 0.015f,
    .bFourPIncrease = 0.005f,
    .bSixPIncrease = 0.008f,
    .flowState = true};

static Player Shakib{
    .bowler = true,
    .pace = false,
    .dotPDecrease = 0.035f,
    .onePIncrease = 0.04f,
    .bDotPIncrease = 0.015f,
    .bOnePDecrease = 0.025f,
    .bFourPIncrease = 0.005f,
    .carry = true};

static Player Maxwell{
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
    .bowler = true,
    .pace = true,
    .fourPIncrease = 0.01f,
    .sixPDecrease = 0.0075f,
    .bDotPDecrease = 0.01f,
    .bOnePDecrease = 0.0175f,
    .bFourPIncrease = 0.005f,
    .bSixPIncrease = 0.01f,
    .bWidePIncrease = 0.0125f,
    .savior = true};

static Player Russell{
    .bowler = true,
    .pace = true,
    .dotPDecrease = 0.03f,
    .fourPDecrease = 0.01f,
    .sixPIncrease = 0.035f,
    .bDotPDecrease = 0.0125f,
    .bDoublePDecrease = 0.01f,
    .bSixPIncrease = 0.005f,
    .bWidePIncrease = 0.0175f,
    .redzoneDominator = true};

static Player Bravo{
    .bowler = true,
    .pace = true,
    .dotPDecrease = 0.035f,
    .fourPDecrease = 0.01f,
    .sixPIncrease = 0.02f,
    .widePIncrease = 0.02f,
    .bDotPIncrease = 0.01f,
    .bOnePDecrease = 0.02f,
    .bFourPDecrease = 0.005f,
    .bSixPIncrease = 0.015f};

static Player Gayle{
    .fourPDecrease = 0.01f,
};

static Player Watson{
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
    .bowler = true,
    .pace = true,
    .dotPIncrease = 0.0125f,
    .onePDecrease = 0.035f,
    .sixPIncrease = 0.02f,
    .bDotPDecrease = 0.0325f,
    .bDoublePIncrease = 0.005f,
    .bSixPIncrease = 0.015f,
    .bWidePIncrease = 0.01f,
    .redzoneDominator = true};

static Player Washington{
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

static Player Arshdeep{
    .bowler = true,
    .pace = true,
    .bDotPIncrease = 0.005f,
    .bDoublePIncrease = 0.005f,
    .bFourPDecrease = 0.01f};

static Player Bumrah{
    .bowler = true,
    .pace = true,
    .bDotPIncrease = 0.01f,
    .bOnePDecrease = 0.03f,
    .bFourPIncrease = 0.005f,
    .bSixPIncrease = 0.01f};

static Player Steyn{
    .bowler = true,
    .pace = true,
    .bDotPDecrease = 0.005f,
    .bDoublePDecrease = 0.005f,
    .bFourPIncrease = 0.005f,
    .bSixPIncrease = 0.005f};

static Player Malinga{
    .bowler = true,
    .pace = true,
    .bDotPIncrease = 0.0125f,
    .bOnePDecrease = 0.015f,
    .bDoublePDecrease = 0.01f,
    .bFourPIncrease = 0.01f,
};

static Player Trent{
    .bowler = true,
    .pace = true,
    .bDotPDecrease = 0.015f,
    .bOnePDecrease = 0.005f,
    .bFourPIncrease = 0.02f};

static Player Starc{
    .bowler = true,
    .pace = true,
    .bDotPIncrease = 0.02f,
    .bOnePDecrease = 0.005f,
    .bDoublePDecrease = 0.015f};

static Player Shami{
    .bowler = true,
    .pace = true,
    .bDotPDecrease = 0.015f,
    .bDoublePIncrease = 0.005f,
    .bWidePIncrease = 0.01f};

static Player Bhuvi{
    .bowler = true,
    .pace = true,
    .bDotPIncrease = 0.0075f,
    .bOnePDecrease = 0.015f,
    .bFourPIncrease = 0.005f,
};

static Player Siraj{
    .bowler = true,
    .pace = true,
    .bDotPDecrease = 0.02f,
    .bOnePDecrease = 0.015f,
    .bFourPIncrease = 0.015f,
    .bSixPIncrease = 0.01f,
};

static Player Archer{
    .bowler = true,
    .pace = true,
    .bDotPDecrease = 0.015f,
    .bSixPIncrease = 0.0125f,
};

static Player Marco{
    .bowler = true,
    .pace = true,
    .bDotPDecrease = 0.0175f,
    .bFourPDecrease = 0.005f,
    .bSixPIncrease = 0.015f,
};

static Player Chahar{
    .bowler = true,
    .pace = true,
    .bDotPDecrease = 0.012f,
    .bFourPIncrease = 0.01f,
};

static Player Hasaranga{
    .bowler = true,
    .pace = false,
    .bDotPDecrease = 0.015f,
    .bFourPDecrease = 0.0025f,
    .bSixPIncrease = 0.1f,
    .bWidePIncrease = 0.0075f};

static Player Axar{
    .bowler = true,
    .pace = false,
    .bDotPIncrease = 0.0075f,
    .bOnePDecrease = 0.005f,
    .bFourPDecrease = 0.005f,
};

static Player Rashid{
    .bowler = true,
    .pace = false,
    // Nothing cause everything in his special
};

static Player Chahal{
    .bowler = true,
    .pace = false,
    .bDotPDecrease = 0.015f,
    .bDoublePDecrease = 0.0075f,
    .bFourPIncrease = 0.01f,
    .bWidePIncrease = 0.0075f};

static Player Sunil{
    .bowler = true,
    .pace = false,
    .bDotPDecrease = 0.01f,
    .bDoublePIncrease = 0.005f};

static Player Kuldeep{
    .bowler = true,
    .pace = false,
    .bDotPDecrease = 0.0075f,
    .bOnePDecrease = 0.01f,
    .bSixPIncrease = 0.01f,
    .bWidePIncrease = 0.0075f};

static Player Ashwin{
    .bowler = true,
    .pace = false,
    .bDotPIncrease = 0.0075f,
    .bDoublePDecrease = 0.005f,
    .bSixPDecrease = 0.005f};

static Player Varun{
    .bowler = true,
    .pace = false,
    .bDotPDecrease = 0.0075f,
    .bFourPDecrease = 0.005f,
    .bWidePIncrease = 0.0125f};

static Player Warne{
    .bowler = true,
    .pace = false,
    .bDoublePIncrease = 0.01f,
    .bFourPDecrease = 0.025f,
    .bSixPIncrease = 0.015f};

void playerMods(std::string name, std::string nSName, std::string bowler, float &dotP, float &oneP, float &doubleP, float &threeP, float &fourP, float &sixP, float &wideP, int ballsP, int runsP, int overN, int overB, int gillUpgrades, int hardikUpgrades, int partnership, double runRate, double requiredRR, bool pace, bool added, bool flashpoint, bool brokenPartner, std::unordered_map<std::string, Player> players)
{
  // std::cout << "Bowler is: " << bowler << std::endl;
  if (!players.contains(name) || !players.contains(nSName) || !players.contains(bowler))
  {
    std::cout << "PLAYER " << name << " NOT FOUND\n";
    throw(1);
  }

  static int kohliWickets = 0;
  static int saiWickets = 0;
  if (overN == 1 && overB == 0)
  {
    kohliWickets = 0;
    saiWickets = 0;
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
        // std::cout << "Cold Start\n";
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
        // std::cout << "Cold Start SICKO MODE\n";
        players[name] = defaultPlayer;
        players[name].dotPDecrease = 0.04f;
        players[name].onePIncrease = 0.0175f;
        players[name].fourPIncrease = 0.025f;
        players[name].sixPIncrease = 0.01f;
      }
      else if (ballsP >= 10)
      {
        // std::cout << "Cold Start\n";
        players[name] = defaultPlayer;
        players[name].dotPDecrease = 0.025f;
        players[name].onePIncrease = 0.015f;
        players[name].fourPIncrease = 0.015f;
      }
    }
  }
  else if (players[name].heatCheck)
  {
    if (runsP >= 20)
    {
      // std::cout << "Heat Check\n";
      players[name] = defaultPlayer;
      players[name].dotPDecrease = 0.03f;
      players[name].onePDecrease = 0.0075f;
      players[name].fourPIncrease = 0.015f;
      players[name].sixPIncrease = 0.025f;
    }
  }
  else if (players[name].boomOrBust)
  {
    if (name == "Sanju Samson")
    {
      if (ballsP >= 20)
      {
        // std::cout << "Boom or Bust\n";
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
        // std::cout << "Boom or Bust\n";
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
        // std::cout << "Boom or Bust\n";
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
        // std::cout << "PP Smash\n";
        players[name].onePIncrease = 0.005f;
        players[name].fourPDecrease = 0.01f;
        players[name].sixPIncrease = 0.005f;
      }
      else if (name == "Abhishek Sharma")
      {
        // std::cout << "PP Smash\n";
        players[name].onePDecrease = 0.0175f;
        players[name].fourPIncrease = 0.015f;
      }
      else if (name == "Quinton de Kock")
      {
        // std::cout << "PP Smash\n";
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
      // std::cout << "Pace Buff\n";
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
        // std::cout << "Spin Buff\n";
        players[name].dotPDecrease += 0.026f;
        players[name].fourPDecrease += 0.02f;
        players[name].sixPIncrease += 0.045f;
      }
      else
      {
        // std::cout << "Spin Buff\n";
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
        // std::cout << "Redzone Dominator\n";
        players[name] = defaultPlayer;
        players[name].dotPIncrease = 0.025f;
        players[name].onePDecrease = 0.015f;
        players[name].fourPDecrease = 0.02f;
        players[name].sixPIncrease = 0.01f;
      }
    }
    if (overN < 18)
    {
      if (name == "Kieron Pollard" || name == "Shimron Hetmeyer")
      {
        // std::cout << "Redzone Dominator\n";
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
      // std::cout << "Anchor\n";
      players[name].dotPDecrease += (0.005f * kohliWickets);
      players[name].fourPIncrease += (0.01f * kohliWickets);
    }
    else if (name == "Sai Sudharsan")
    {
      // std::cout << "Anchor\n";
      players[name].onePDecrease += (0.005f * saiWickets);
      players[name].sixPIncrease += (0.0075f * saiWickets);
    }
  }
  else if (players[name].flowState)
  {
    if (name == "Shubman Gill")
    {
      // std::cout << "Gill Upgrades:" << gillUpgrades << std::endl;
      players[name].dotPDecrease += (0.01f * gillUpgrades);
      players[name].fourPIncrease += (0.0075f * gillUpgrades);
    }
    else if (name == "Hardik Pandya")
    {
      // std::cout << "Hardik Upgrades:" << hardikUpgrades << std::endl;
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
        // std::cout << "Chemistry\n";
        players[name].dotPDecrease += (0.0075f * (partnership / 20));
        players[name].fourPIncrease += (0.01f * (partnership / 20));
      }
      else
      {
        // std::cout << "Chemistry\n";
        players[name].dotPDecrease += (0.0075f * 5);
        players[name].fourPIncrease += (0.01f * 5);
      }
    }
    else
    {
      // std::cout << "Broken Chemistry\n";
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
      // std::cout << "Savior\n";
      players[name].onePDecrease += 0.03f;
      players[name].fourPIncrease += 0.005f;
      players[name].sixPIncrease += 0.025f;
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
    // std::cout << "Carry\n";
    players[name].onePDecrease += 0.025f;
    players[name].fourPIncrease += 0.01f;
    players[name].sixPIncrease += 0.01f;
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
      // std::cout << "Flashpoint\n";
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
    {"Shakib Al Hasan", Shakib},
    {"Glenn Maxwell", Maxwell},
    {"Ben Stokes", Stokes},
    {"Andre Russell", Russell},
    {"Dwayne Bravo", Bravo},
    {"Chris Gayle", Gayle},
    {"Shane Watson", Watson},
    {"Kieron Pollard", Pollard},
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
    {"Marco Jansen", Marco},
    {"Deepak Chahar", Chahar},
    {"Wanindu Hasaranga", Hasaranga},
    {"Axar Patel", Axar},
    {"Rashid Khan", Rashid},
    {"Yuzvendra Chahal", Chahal},
    {"Sunil Narine", Sunil},
    {"Kuldeep Yadav", Kuldeep},
    {"Ravichandran Ashwin", Ashwin},
    {"Varun Chakravarthy", Varun},
    {"Shane Warne", Warne},
    {"Washington Sundar", Washington},
};
