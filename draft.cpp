#include "main.h"

static Player defaultPlayer;

static Player Gaikwad{
    .dotPIncrease = 0.045f,
    .onePIncrease = 0.02f,
    .doublePDecrease = 0.04f,
    .fourPIncrease = 0.01f,
    .sixPDecrease = 0.04f,
    .coldStart = true};

static Player Virat{
    .dotPDecrease = 0.04f,
    .onePIncrease = 0.04f,
    .anchor = true};

static Player Rohit{
    .dotPDecrease = 0.04f,
    .fourPIncrease = 0.02f,
    .sixPIncrease = 0.02f,
    .PPSmash = true};

static Player Sai{
    .dotPDecrease = 0.02f,
    .onePIncrease = 0.02f,
    .anchor = true};

static Player Travis{
    .dotPDecrease = 0.045f,
    .onePDecrease = 0.03f,
    .fourPIncrease = 0.02f,
    .sixPIncrease = 0.03f,
    .paceBuff = true};

static Player Suryakumar{
    .fourPDecrease = 0.03f,
    .sixPIncrease = 0.03f,
    .spinBuff = true};

static Player Pooran{
    .dotPDecrease = 0.02f,
    .onePDecrease = 0.015f,
    .fourPIncrease = 0.02f,
    .sixPIncrease = 0.01f,
    .paceBuff = true};

static Player Gill{
    .fourPIncrease = 0.02f,
    .flowState = true};

static Player Jaiswal{
    .dotPDecrease = 0.015f,
    .onePDecrease = 0.03f,
    .fourPIncrease = 0.03f,
    .sixPIncrease = 0.01f};

static Player Hetmeyer{
    .dotPDecrease = 0.05f,
    .fourPDecrease = 0.01f,
    .sixPIncrease = 0.05f,
    .redzoneDominator = true};

static Player ABD{
    .dotPIncrease = 0.02f,
    .fourPDecrease = 0.01f,
    .chemistry = true};

static Player Shreyas{
    .dotPDecrease = 0.045f,
    .onePIncrease = 0.01f,
    .fourPIncrease = 0.03f,
    .spinBuff = true};

static Player Dube{
    .dotPIncrease = 0.07f,
    .onePDecrease = 0.05f,
    .doublePDecrease = 0.04f,
    .fourPDecrease = 0.03f,
    .sixPIncrease = 0.04f,
    .spinBuff = true};

static Player Abhishek{
    .onePDecrease = 0.065f,
    .fourPIncrease = 0.03f,
    .sixPIncrease = 0.03f,
    .PPSmash = true};

static Player Warner{
    .dotPDecrease = 0.02f,
    .fourPIncrease = 0.03f,
    .sixPDecrease = 0.01f,
    .paceBuff = true};

static Player Dhoni{
    .dotPDecrease = 0.02f,
    .onePDecrease = 0.04f,
    .sixPIncrease = 0.055f,
    .redzoneDominator = true};

static Player KL{
    .dotPIncrease = 0.06f,
    .onePDecrease = 0.01f,
    .fourPDecrease = 0.01f,
    .sixPDecrease = 0.04f,
    .coldStart = true};

static Player Pant{
    .dotPDecrease = 0.03f,
    .onePDecrease = 0.06f,
    .fourPIncrease = 0.03f,
    .sixPIncrease = 0.04f,
    .flashpoint = true};

static Player Quinton{
    .dotPDecrease = 0.05f,
    .onePDecrease = 0.02f,
    .fourPIncrease = 0.02f,
    .sixPIncrease = 0.04f,
    .PPSmash = true};

static Player Sanju{
    .onePDecrease = 0.03f,
    .fourPDecrease = 0.01f,
    .sixPIncrease = 0.02f,
    .boomOrBust = true};

static Player Klaasen{
    .dotPDecrease = 0.02f,
    .onePDecrease = 0.03f,
    .fourPIncrease = 0.02f,
    .sixPIncrease = 0.02f,
    .flashpoint = true};

static Player Buttler{
    .dotPDecrease = 0.05f,
    .onePIncrease = 0.02f,
    .fourPIncrease = 0.03f,
    .sixPDecrease = 0.01f,
    .boomOrBust = true};

static Player Salt{
    .dotPDecrease = 0.05f,
    .onePDecrease = 0.02f,
    .fourPIncrease = 0.03f,
    .sixPIncrease = 0.03f};

static Player Jadeja{
    .dotPIncrease = 0.055f,
    .fourPDecrease = 0.04f,
    .sixPDecrease = 0.01f,
    .heatCheck = true};

static Player Hardik{
    .onePDecrease = 0.035f,
    .sixPIncrease = 0.02f,
    .flowState = true};

static Player Shakib{
    .dotPDecrease = 0.07f,
    .onePIncrease = 0.08f,
    .carry = true};

static Player Maxwell{
    .dotPDecrease = 0.005f,
    .onePDecrease = 0.07f,
    .fourPIncrease = 0.02f,
    .sixPIncrease = 0.04f,
    .flashpoint = true};

static Player Stokes{
    .fourPIncrease = 0.02f,
    .sixPDecrease = 0.015f,
    .savior = true};

static Player Russell{
    .dotPDecrease = 0.06f,
    .fourPDecrease = 0.02f,
    .sixPIncrease = 0.07f,
    .redzoneDominator = true};

static Player Bravo{
    .dotPDecrease = 0.07f,
    .fourPDecrease = 0.02f,
    .sixPIncrease = 0.04f,
    .widePIncrease = 0.04f};

static Player Gayle{
    // Different things completely so please follow. We can't do +8 for when death so have different conditions if death
    .fourPDecrease = 0.02f,
};

static Player Watson{
    .dotPDecrease = 0.08f,
    .fourPIncrease = 0.03f,
    .sixPIncrease = 0.04f,
    .boomOrBust = true};

static Player Pollard{
    .dotPIncrease = 0.025f,
    .onePDecrease = 0.07f,
    .sixPIncrease = 0.04f,
    .redzoneDominator = true};

static Player Washington{
    .dotPDecrease = 0.005f,
    .onePIncrease = 0.05f,
    .sixPDecrease = 0.02f};

static Player Arshdeep{};

static Player Bumrah{};

static Player Steyn{};

static Player Malinga{};

static Player Trent{};

static Player Starc{};

static Player Shami{};

static Player Bhuvi{};

static Player Siraj{};

static Player Archer{};

static Player Marco{};

static Player Chahar{};

static Player Hasaranga{};

static Player Axar{};

static Player Rashid{};

static Player Chahal{};

static Player Sunil{};

static Player Kuldeep{};

static Player Ashwin{};

static Player Varun{};

static Player Warne{};

void playerMods(std::string name, std::string nSName, float &dotP, float &oneP, float &doubleP, float &threeP, float &fourP, float &sixP, float &wideP, int ballsP, int runsP, int overN, int overB, int gillUpgrades, int hardikUpgrades, int partnership, double runRate, double requiredRR, bool pace, bool added, bool flashpoint, bool brokenPartner)
{
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

  if (!players.contains(name)) {
    std::cout << "PLAYER NOT FOUND\n";
    throw(1);
  }

  static int kohliWickets = 0;
  static int saiWickets = 0;
  if (overN == 1 && overB == 0) {
    kohliWickets = 0;
    saiWickets = 0;
  }

	if (added) {
    if ((nSName == "Virat Kohli" && overB != 0) || (name == "Virat Kohli" && overB == 0)) {
      kohliWickets++;
    }
    else if ((nSName == "Sai Sudharsan" && overB != 0) || (name == "Sai Sudharsan" && overB == 0)) {
      saiWickets++;
    }
  }

  if (kohliWickets > 4) {
    kohliWickets = 4;
  }
  else if (saiWickets > 7) {
    saiWickets = 7;
  }

  if (players[name].coldStart) {
    if (name == "Ruturaj Gaikwad") {
      if (ballsP >= 12) {
        //std::cout << "Cold Start\n";
        players[name] = defaultPlayer;
        players[name].dotPDecrease = 0.055f;
        players[name].onePIncrease = 0.02f;
        players[name].fourPIncrease = 0.05f;
      }
    }
    else if (name == "KL Rahul") {
      if (ballsP >= 40) {
        //std::cout << "Cold Start SICKO MODE\n";
        players[name] = defaultPlayer;
        players[name].dotPDecrease = 0.08f;
        players[name].onePIncrease = 0.035f;
        players[name].fourPIncrease = 0.05f;
        players[name].sixPIncrease = 0.02f;
      }
      else if (ballsP >= 10) {
        //std::cout << "Cold Start\n";
        players[name] = defaultPlayer;
        players[name].dotPDecrease = 0.05f;
        players[name].onePIncrease = 0.03f;
        players[name].fourPIncrease = 0.03f;
      }
    }
  }
  else if (players[name].heatCheck) {
    if (runsP >= 20) {
      //std::cout << "Heat Check\n";
      players[name] = defaultPlayer;
      players[name].dotPDecrease = 0.06f;
      players[name].onePDecrease = 0.015f;
      players[name].fourPIncrease = 0.03f;
      players[name].sixPIncrease = 0.05f;
    }
  }
  else if (players[name].boomOrBust) {
    if (name == "Sanju Samson") {
      if (ballsP >= 20) {
        //std::cout << "Boom or Bust\n";
        players[name] = defaultPlayer;
        players[name].dotPDecrease = 0.035f;
        players[name].fourPIncrease = 0.04f;
        players[name].sixPIncrease = 0.02f;
      }
    }
    else if (name == "Jos Buttler") {
      if (ballsP >= 14) {
        //std::cout << "Boom or Bust\n";
        players[name] = defaultPlayer;
        players[name].onePDecrease = 0.03f;
        players[name].fourPIncrease = 0.01f;
        players[name].sixPIncrease = 0.03f;
      }
    }
    else if (name == "Shane Watson") {
      if (ballsP >= 18) {
        //std::cout << "Boom or Bust\n";
        players[name] = defaultPlayer;
        players[name].onePIncrease = 0.015f;
        players[name].fourPDecrease = 0.01f;
        players[name].sixPDecrease = 0.01f;
      }
    }
  }
  else if (players[name].PPSmash) {
    if (overN >= 6) {
      players[name] = defaultPlayer;
      if (name == "Rohit Sharma") {
        //std::cout << "PP Smash\n";
        players[name].onePIncrease = 0.01f;
        players[name].fourPDecrease = 0.02f;
        players[name].sixPIncrease = 0.01f;
      }
      else if (name == "Abhishek Sharma") {
        //std::cout << "PP Smash\n";
        players[name].onePDecrease = 0.035f;
        players[name].fourPIncrease = 0.03f;
      }
      else if (name == "Quinton de Kock") {
        //std::cout << "PP Smash\n";
        players[name].dotPIncrease = 0.005f;
        players[name].onePDecrease = 0.02f;
        players[name].fourPIncrease = 0.01f;
        players[name].sixPIncrease = 0.01f;
      }
    }
  }
  else if (players[name].paceBuff) {
    if (pace) {
      //std::cout << "Pace Buff\n";
      players[name].dotPDecrease += 0.04f;
      players[name].fourPIncrease += 0.02f;
      players[name].sixPIncrease += 0.02f;
    }
  }
  else if (players[name].spinBuff) {
    if (!pace) {
      if (name == "Shivam Dube") {
        //std::cout << "Spin Buff\n";
        players[name].dotPDecrease += 0.052f;
        players[name].fourPDecrease += 0.04f;
        players[name].sixPIncrease += 0.09f;
      }
      else {
        //std::cout << "Spin Buff\n";
        players[name].dotPDecrease += 0.03f;
        players[name].onePDecrease += 0.01f;
        players[name].fourPIncrease += 0.01f;
        players[name].sixPIncrease += 0.03f;
      }
    }
  }
  else if (players[name].redzoneDominator) {
    if (overN < 17) {
      if (name == "MS Dhoni" || name == "Andre Russell") {
        //std::cout << "Redzone Dominator\n";
        players[name] = defaultPlayer;
        players[name].dotPIncrease = 0.05f;
        players[name].onePDecrease = 0.03f;
        players[name].fourPDecrease = 0.04f;
        players[name].sixPIncrease = 0.02f;
      }
    }
    if (overN < 18) {
      if (name == "Kieron Pollard" || name == "Shimron Hetmeyer") {
        //std::cout << "Redzone Dominator\n";
        players[name] = defaultPlayer;
        players[name].onePDecrease = 0.02f;
        players[name].sixPIncrease = 0.02f;
      }
    }
  }
  else if (players[name].anchor) {
    if (name == "Virat Kohli") {
      //std::cout << "Anchor\n";
      players[name].dotPDecrease += (0.01f * kohliWickets);
      players[name].fourPIncrease += (0.02f * kohliWickets);
    }
    else if (name == "Sai Sudharsan") {
      //std::cout << "Anchor\n";
      players[name].onePDecrease += (0.01f * saiWickets);
      players[name].sixPIncrease += (0.015f * saiWickets);
    }
  }
  else if (players[name].flowState) {
    if (name == "Shubman Gill") {
      //std::cout << "Gill Upgrades:" << gillUpgrades << std::endl;
      players[name].dotPDecrease += (0.02f * gillUpgrades);
      players[name].fourPIncrease += (0.015f * gillUpgrades);
    }
    else if (name == "Hardik Pandya") {
      //std::cout << "Hardik Upgrades:" << hardikUpgrades << std::endl;
      players[name].dotPDecrease += (0.015f * hardikUpgrades);
      players[name].onePDecrease += (0.002f * hardikUpgrades);
      players[name].fourPIncrease += (0.01f * hardikUpgrades);
      players[name].sixPIncrease += (0.01f * hardikUpgrades);
    }
  }
  else if (players[name].chemistry) {
    if (!brokenPartner) {
      if (partnership < 100) {
        //std::cout << "Chemistry\n";
        players[name].dotPDecrease += (0.015f * (partnership/20));
        players[name].fourPIncrease += (0.02f * (partnership/20));
      }
      else {
        //std::cout << "Chemistry\n";
        players[name].dotPDecrease += (0.015f * 5);
        players[name].fourPIncrease += (0.02f * 5);
      }
    }
    else {
      //std::cout << "Broken Chemistry\n";
      players[name] = defaultPlayer;
      players[name].dotPDecrease = 0.05f;
      players[name].fourPIncrease = 0.02f;
      players[name].sixPIncrease = 0.04f;
    }
  }
  else if (players[name].savior) {
    if (runRate <= 9.5 || requiredRR >= 12.5) {
      //std::cout << "Savior\n";
      players[name].onePDecrease += 0.06f;
      players[name].fourPIncrease += 0.01f;
      players[name].sixPIncrease += 0.05f;
    }
  }

  if (nSName == "Sai Sudharsan") {
    players[name].dotPIncrease += (0.004f * saiWickets);
  }
  else if (nSName == "AB de Villiers") {
	  if (!brokenPartner) {
	    if (partnership < 100) {
			  players[name].dotPIncrease += (0.02f * (partnership/20));
			  players[name].onePDecrease += (0.015f * (partnership/20));
		  }
		  else {
			  players[name].dotPIncrease += (0.02f * 5);
			  players[name].onePDecrease += (0.015f * 5);
		  }
	  }
  }
  else if (players[nSName].carry) {
    //std::cout << "Carry\n";
    players[name].onePDecrease += 0.05f;
    players[name].fourPIncrease += 0.02f;
    players[name].sixPIncrease += 0.02f;
  }

  dotP += players[name].dotPIncrease - players[name].dotPDecrease;
  oneP += players[name].onePIncrease - players[name].onePDecrease;
  doubleP += players[name].doublePIncrease - players[name].doublePDecrease;
  threeP += players[name].threePIncrease - players[name].threePDecrease;
  fourP += players[name].fourPIncrease - players[name].fourPDecrease;
  if (name == "Chris Gayle") {
    if (oneP < 0.18f) {
      sixP += oneP - 0.1f;
      dotP += 0.01f;
    }
    else {
      sixP += 0.08f;
      dotP += oneP - 0.17f; // cause plus 0.01f anyway
    }
    oneP = 0.1f;
  }
  else {
    sixP += players[name].sixPIncrease - players[name].sixPDecrease;
  }
  wideP += players[name].widePIncrease - players[name].widePDecrease;

  if (players[name].flashpoint) {
    if (flashpoint) {
      //std::cout << "Flashpoint\n";
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
