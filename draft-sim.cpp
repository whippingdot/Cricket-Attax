#include "main.h"

// Initialization of two functions that are defined below
std::string draftInput();                                                             // draftInput gives us a string value that the user inputted (allows for user to output newlines that do not register and more than one word)
void draftOutput(std::array<std::array<std::string, 11>, 2> names, std::string type); // draftOutput just outputs the player list along with coloring selected players

// Defines a variable that tracks who took whose wicket
std::array<std::array<std::string, 11>, 2> outBy = {{{{{""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}}}, {{{""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}}}}};

void draftSim(std::string sameTeams)
{
  // Resets the outBy variable every time the draft simulation is called (so it doesn't save values from previous match)
  outBy = {{{{{""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}}}, {{{""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}}}}};
  int overNumber = 1;
  int ballNumber = 0;
  int runs = 0;
  int wickets = 0;
  int wicketsT = 0;
  int wicketsTCounter = 0;
  int oldWickets = 0; // How many wickets fell uptil the last ball
  int innings = 1;
  int bowlerInnings = 0; // The innings that bowler indexes must follow (could have just make this normal but flipped where I inputted values)
  int random = 0;
  int hundoGen = 0; // Used to decide whether the ball is a yorker or not
  int oldRuns = 0;
  int overRuns = 0;
  int projected = 0;
  int extras = 0; // Used to count the number of extra balls a bowler bowls
  int counter = 0;
  int batsmenCounter = 0; // Used to iteratore through batsmen that people can choose from
  int balls = 0;

  // The following variables are used to add upgrades to the bowleres and batsmen based on certain conditions
  int gillStarted = 300;
  int gillUp = 0;
  int hardikStarted = 300;
  int hardikUp = 0;
  int kuldeepWickets = 0;
  int yuziWickets = 0;
  int warneWickets = 0;

  int special = 0;
  int bouncer = 0;

  // Used to draft the players at correct indices
  int teamAC = 0;
  int teamBC = 0;

  int dotMax = 0;
  int oMax = 0;
  int dMax = 0;
  int tMax = 0;
  int fMax = 0;
  int sMax = 0;
  int wMax = 0;
  float dotP = 0.0f;
  float oneP = 0.0f;
  float doubleP = 0.0f;
  float threeP = 0.0f;
  float fourP = 0.0f;
  float sixP = 0.0f;
  float wideP = 0.0f;

  double runRate = 0.0;
  // Required run rate calculation
  double requiredRR = 0.0;
  // Economy of bowler calculation
  double economy = 0.0;

  bool e = false;
  bool strike = true;
  bool free = false;
  bool changed = false;
  bool collapse = false;
  bool added = false;
  bool buffed = false;
  bool nerfed = false;
  bool debug = false; // Condition for whether the sim is ran in debug mode or not

  bool flashP = false; // Condition for a certain type of player

  std::string null = "";
  std::string bowlerName = "";

  std::array<int, 2> current = {0, 0};
  std::array<int, 2> ballsB = {0, 0};
  std::array<int, 2> index = {0, 0};
  std::array<int, 2> notOut = {0, 0};

  // These variables track the stats of the spells of certain bowlers with spell related buffs. Number of overs the spell has ran and the last over they bowled in a spell
  std::array<int, 2> jadduSpell = {0, 0};
  std::array<int, 2> steynSpell = {0, 0};
  std::array<int, 2> hasarangaSpell = {0, 0};

  std::array<int, 3> chemistryPartner = {12, 0, 0}; // Used to track the stats of ABD's ability

  std::vector<int> batsmenOrder = std::vector<int>(); // Batting order of batsman (because of draft the order is randomized)
  std::vector<int> oldBatsmenOrder = std::vector<int>();

  std::unordered_map<int, int> batters = std::unordered_map<int, int>();           // Used to track drafting of batsmen
  std::array<std::vector<int>, 2> bowlerNames = std::array<std::vector<int>, 2>(); // Used to track bowlers selected
  std::vector<std::array<int, 4>> partnerships = std::vector<std::array<int, 4>>();
  std::array<std::vector<char>, maxOvers> timeline = std::array<std::vector<char>, maxOvers>();
  std::array<std::vector<std::array<int, 5>>, 2> fallOW = std::array<std::vector<std::array<int, 5>>, 2>();
  std::array<std::vector<std::array<int, 6>>, 2> bowlerStats = std::array<std::vector<std::array<int, 6>>, 2>();
  std::array<std::unordered_map<std::string, int>, 2> bowlers = std::array<std::unordered_map<std::string, int>, 2>(); // Another variable used to track bowler names
  std::array<std::array<std::array<int, 3>, 11>, 2> teams = {{{{{{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}}}, {{{{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}}}}};

  std::array<int, 4> partnership = {0, 0, 0, 0};
  std::array<int, 4> savedP = {0, 0, 0, 0};

  // New random number generator based on the a special algorithm
  std::uniform_int_distribution<> dist(1, 10000); // Now a 1-10000 chance because the player effects became very precise (up to 2 dp) when I forced to halve them
  std::uniform_int_distribution<> two(1, 2);
  std::uniform_int_distribution<> hundo(1, 100); // Used to have yorker balls

  float mOvers = maxOvers;
  float average = 211 * (mOvers / 20);
  int higherScore = static_cast<int>((6.75 / 6) * average);
  int lowerScore = static_cast<int>((5.25 / 6) * average);

  // The following is the list of all available players. Their names are given followed by the full name with proper capitalization for outputting
  std::unordered_map<std::string, std::string> players = {
      // Batsmen (full + first)
      {"gaikwad", "Ruturaj Gaikwad"},
      {"virat", "Virat Kohli"},
      {"kohli", "Virat Kohli"},
      {"rohit", "Rohit Sharma"},
      {"sai", "Sai Sudharsan"},
      {"head", "Travis Head"},
      {"travis", "Travis Head"},
      {"sky", "Suryakumar Yadav"},
      {"suryakumar", "Suryakumar Yadav"},
      {"pooran", "Nicholas Pooran"},
      {"gill", "Shubman Gill"},
      {"jaiswal", "Yashasvi Jaiswal"},
      {"hetmyer", "Shimron Hetmyer"},
      {"abd", "AB de Villiers"},
      {"shreyas", "Shreyas Iyer"},
      {"dube", "Shivam Dube"},
      {"abhishek", "Abhishek Sharma"},
      {"warner", "David Warner"},
      {"gayle", "Chris Gayle"},
      {"mccullum", "Brendon McCullum"},
      {"brendon", "Brendon McCullum"},
      {"don", "Don Bradman"},
      {"bradman", "Don Bradman"},
      {"sachin", "Sachin Tendulkar"},
      // Wicket Keepers (full + first)
      {"msd", "MS Dhoni"},
      {"dhoni", "MS Dhoni"},
      {"kl", "KL Rahul"},
      {"pant", "Rishabh Pant"},
      {"buttler", "Jos Buttler"},
      {"klaasen", "Heinrich Klaasen"},
      {"sanju", "Sanju Samson"},
      {"quinton", "Quinton de Kock"},
      {"qdk", "Quinton de Kock"},
      // All Rounders (full + first)
      {"jadeja", "Ravindra Jadeja"},
      {"hardik", "Hardik Pandya"},
      {"shakib", "Shakib Al Hasan"},
      {"maxwell", "Glenn Maxwell"},
      {"ben", "Ben Stokes"},
      {"stokes", "Ben Stokes"},
      {"russell", "Andre Russell"},
      {"bravo", "Dwayne Bravo"},
      {"watson", "Shane Watson"},
      {"pollard", "Kieron Pollard"},
      {"washington", "Washington Sundar"},
      {"axar", "Axar Patel"},
      // Pace Bowlers (full + first)
      {"steyn", "Dale Steyn"},
      {"malinga", "Lasith Malinga"},
      {"boult", "Trent Boult"},
      {"starc", "Mitchell Starc"},
      {"shami", "Mohammed Shami"},
      {"bhuvi", "Bhuvneshwar Kumar"},
      {"bhuvneshwar", "Bhuvneshwar Kumar"},
      {"siraj", "Mohammed Siraj"},
      {"archer", "Jofra Archer"},
      {"morne", "Morne Morkel"},
      {"chahar", "Deepak Chahar"},
      {"arshdeep", "Arshdeep Singh"},
      {"bumrah", "Jasprit Bumrah"},
      // Spin Bowlers (full + first)
      {"hasaranga", "Wanindu Hasaranga"},
      {"rashid", "Rashid Khan"},
      {"chahal", "Yuzvendra Chahal"},
      {"narine", "Sunil Narine"},
      {"kuldeep", "Kuldeep Yadav"},
      {"ashwin", "Ravichandran Ashwin"},
      {"varun", "Varun Chakravarthy"},
      {"shane", "Shane Warne"},
      // FULL NAMES
      {"ruturaj gaikwad", "Ruturaj Gaikwad"},
      {"virat kohli", "Virat Kohli"},
      {"rohit sharma", "Rohit Sharma"},
      {"sai sudharsan", "Sai Sudharsan"},
      {"travis head", "Travis Head"},
      {"suryakumar yadav", "Suryakumar Yadav"},
      {"nicholas pooran", "Nicholas Pooran"},
      {"shubman gill", "Shubman Gill"},
      {"yashasvi jaiswal", "Yashasvi Jaiswal"},
      {"shimron hetmyer", "Shimron Hetmyer"},
      {"ab de villiers", "AB de Villiers"},
      {"shreyas iyer", "Shreyas Iyer"},
      {"shivam dube", "Shivam Dube"},
      {"abhishek sharma", "Abhishek Sharma"},
      {"david warner", "David Warner"},
      {"chris gayle", "Chris Gayle"},
      {"brendon mccullum", "Brendon McCullum"},
      {"don bradman", "Don Bradman"},
      {"sachin tendulkar", "Sachin Tendulkar"},
      {"ms dhoni", "MS Dhoni"},
      {"kl rahul", "KL Rahul"},
      {"rishabh pant", "Rishabh Pant"},
      {"jos buttler", "Jos Buttler"},
      {"heinrich klaasen", "Heinrich Klaasen"},
      {"sanju samson", "Sanju Samson"},
      {"quinton de kock", "Quinton de Kock"},
      {"ravindra jadeja", "Ravindra Jadeja"},
      {"hardik pandya", "Hardik Pandya"},
      {"shakib al hasan", "Shakib Al Hasan"},
      {"glenn maxwell", "Glenn Maxwell"},
      {"ben stokes", "Ben Stokes"},
      {"andre russell", "Andre Russell"},
      {"dwayne bravo", "Dwayne Bravo"},
      {"shane watson", "Shane Watson"},
      {"kieron pollard", "Kieron Pollard"},
      {"washington sundar", "Washington Sundar"},
      {"axar patel", "Axar Patel"},
      {"dale steyn", "Dale Steyn"},
      {"lasith malinga", "Lasith Malinga"},
      {"trent boult", "Trent Boult"},
      {"mitchell starc", "Mitchell Starc"},
      {"mohammed shami", "Mohammed Shami"},
      {"bhuvneshwar kumar", "Bhuvneshwar Kumar"},
      {"mohammed siraj", "Mohammed Siraj"},
      {"jofra archer", "Jofra Archer"},
      {"morne morkel", "Morne Morkel"},
      {"deepak chahar", "Deepak Chahar"},
      {"arshdeep singh", "Arshdeep Singh"},
      {"jasprit bumrah", "Jasprit Bumrah"},
      {"wanindu hasaranga", "Wanindu Hasaranga"},
      {"rashid khan", "Rashid Khan"},
      {"yuzvendra chahal", "Yuzvendra Chahal"},
      {"sunil narine", "Sunil Narine"},
      {"kuldeep yadav", "Kuldeep Yadav"},
      {"ravichandran ashwin", "Ravichandran Ashwin"},
      {"varun chakravarthy", "Varun Chakravarthy"},
      {"shane warne", "Shane Warne"}};

  static std::array<std::array<std::string, 11>, 2> names; // The names of all chosen players

  // Draft system that is skipped when debug is selected
  if (sameTeams != "y" && sameTeams != "debug")
  {
    names = {{{"", "", "", "", "", "", "", "", "", "", ""}, {"", "", "", "", "", "", "", "", "", "", ""}}};

    // Draft
    std::cout << "+-----------------------+\n| ___            __ _   |\n||   \\ _ _ __ _ / _| |_ |\n|| |) | '_/ _` |  _|  _||\n||___/|_| \\__,_|_|  \\__||\n+-----------------------+\n\n";
    draftOutput(names, "first");

    random = two(global_rng());
    std::cout << "Player " << random << " make the first pick: ";
    null = draftInput();
    if (null == "debug")
    {
      debug = true;
      // names = {{{"Rohit Sharma", "Quinton de Kock", "Suryakumar Yadav", "Glenn Maxwell", "Kieron Pollard", "Hardik Pandya", "Heinrich Klaasen", "Rashid Khan", "Axar Patel", "Trent Boult", "Jasprit Bumrah"}, {"Ruturaj Gaikwad", "Sai Sudharsan", "Shivam Dube", "Nicholas Pooran", "Shakib Al Hasan", "MS Dhoni", "Ravindra Jadeja", "Deepak Chahar", "Mohammed Siraj", "Lasith Malinga", "Varun Chakravarthy"}}};
      // names = {{{"Shubman Gill", "Yashasvi Jaiswal", "KL Rahul", "AB de Villiers", "Rishabh Pant", "Washington Sundar", "Dwayne Bravo", "Sunil Narine", "Morne Morkel", "Jofra Archer", "Arshdeep Singh"}, {"David Warner", "Chris Gayle", "Brendon McCullum", "Virat Kohli", "Ben Stokes", "Shimron Hetmyer", "Wanindu Hasaranga", "Kuldeep Yadav", "Bhuvneshwar Kumar", "Mitchell Starc", "Shane Warne"}}};
      names = {{{"Brendon McCullum", "Don Bradman", "Sachin Tendulkar", "AB de Villiers", "Rishabh Pant", "Washington Sundar", "Rashid Khan", "Sunil Narine", "Morne Morkel", "Lasith Malinga", "Arshdeep Singh"}, {"Travis Head", "Shane Watson", "Jos Buttler", "Abhishek Sharma", "Shreyas Iyer", "Sanju Samson", "Andre Russell", "Ravichandran Ashwin", "Dale Steyn", "Mohammed Shami", "Yuzvendra Chahal"}}};
    }
    else if (players.contains(null))
    {
      names[random - 1][0] = players[null];
    }
    else
    {
      while (!players.contains(null))
      {
        std::cout << "Enter a proper name or enter the full name\nPlayer " << random << " make the first pick: ";
        null = draftInput();
      }
      names[random - 1][0] = players[null];
    }
    random == 1 ? teamAC++ : teamBC++;

    system("cls");
    for (int i = 2; i < 23; i++)
    {
      if (names[0][10] != "" && names[1][10] != "")
      {
        break;
      }

      draftOutput(names, "");
      random == 1 ? random = 2 : random = 1;

      for (int j = 0; j < 2; j++)
      {
        if (i == 22)
        {
          std::cout << "Player " << random << " make the last pick: ";
        }
        else
        {
          std::cout << "Player " << random << " make pick " << i << ": ";
        }
        null = draftInput();
        if (players.contains(null) && std::find(names[0].begin(), names[0].end(), players[null]) == names[0].end() && std::find(names[1].begin(), names[1].end(), players[null]) == names[1].end())
        {
          if (random == 1)
          {
            names[random - 1][teamAC] = players[null];
            teamAC++;
          }
          else
          {
            names[random - 1][teamBC] = players[null];
            teamBC++;
          }
        }
        else
        {
          while (!players.contains(null) || std::find(names[0].begin(), names[0].end(), players[null]) != names[0].end() || std::find(names[1].begin(), names[1].end(), players[null]) != names[1].end())
          {
            if (i == 22)
            {
              if (!players.contains(null))
              {
                std::cout << "Enter a proper name or enter the full name\nPlayer " << random << " make the last pick: ";
              }
              else
              {
                std::cout << "That player has already been chosen\nPlayer " << random << " make the last pick: ";
              }
            }
            else
            {
              if (!players.contains(null))
              {
                std::cout << "Enter a proper name or enter the full name\nPlayer " << random << " make pick " << i << ": ";
              }
              else
              {
                std::cout << "That player has already been chosen\nPlayer " << random << " make pick " << i << ": ";
              }
            }
            null = draftInput();
          }
          if (random == 1)
          {
            names[random - 1][teamAC] = players[null];
            teamAC++;
          }
          else
          {
            names[random - 1][teamBC] = players[null];
            teamBC++;
          }
        }
        if (i == 22)
        {
          break;
        }
        i++;
      }
      i--;
      system("cls");
    }

    std::cout << "\nEnter to Continue\n";
    std::getline(std::cin, null);
    system("cls");
  }

  if (sameTeams == "debug")
  {
    debug = true;
  }

  random = two(global_rng());

  if (random == 1)
  {
    std::cout << "Player 1: Choose heads (h) or tails (t) and enter to continue when ready.\n";
  }
  else
  {
    std::cout << "Player 2: Choose heads (h) or tails (t) and enter to continue when ready.\n";
  }
  std::cin >> null;
  system("cls");
  counter = random;

  random = two(global_rng());
  if (random == 1)
  {
    std::cout << "Heads!\n";
    if (counter == 1)
    {
      if (null == "h")
      {
        std::cout << "Player 1: Choose batting (bat) or bowling (bowl). Type in your answer.\n";
      }
      else
      {
        std::cout << "Player 2: Choose batting (bat) or bowling (bowl). Type in your answer.\n";
        counter = 2;
      }
    }
    else
    {
      if (null == "h")
      {
        std::cout << "Player 2: Choose batting (bat) or bowling (bowl). Type in your answer.\n";
        counter = 2;
      }
      else
      {
        std::cout << "Player 1: Choose batting (bat) or bowling (bowl). Type in your answer.\n";
        counter = 1;
      }
    }
    std::cin >> null;
    system("cls");
  }
  else
  {
    std::cout << "Tails!\n";
    if (counter == 1)
    {
      if (null == "h")
      {
        std::cout << "Player 2: Choose batting (bat) or bowling (bowl). Type in your answer.\n";
        counter = 2;
      }
      else
      {
        std::cout << "Player 1: Choose batting (bat) or bowling (bowl). Type in your answer.\n";
      }
    }
    else
    {
      if (null == "h")
      {
        std::cout << "Player 1: Choose batting (bat) or bowling (bowl). Type in your answer.\n";
        counter = 1;
      }
      else
      {
        std::cout << "Player 2: Choose batting (bat) or bowling (bowl). Type in your answer.\n";
        counter = 2;
      }
    }
    std::cin >> null;
    system("cls");
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  if ((counter == 1 && null == "bowl") || (counter == 2 && null == "bat"))
  {
    std::swap(names[0], names[1]);
  }

  counter = 0;
  // Sets the bowlers selected into both variables
  for (int i = 0; i < 2; i++)
  {
    counter = 0;
    for (int j = 0; j < 11; j++)
    {
      if (Players[names[i][j]].bowler)
      {
        bowlers[i][names[i][j]] = counter;
        bowlerNames[i].push_back(j);
        bowlerStats[i].push_back({0, 0, 0, 0, 0, 0});
        counter++;
      }
    }
  }

  counter = 0;
  while (innings < 3)
  {
    std::cout << "INNINGS NUMBER " << innings << "\n";

    if (oldRuns >= higherScore && innings == 2)
    {
      buffed = true;
    }
    else if (oldRuns <= lowerScore && innings == 2)
    {
      nerfed = true;
    }

    // Sets bowlerInnings variable based on the actual innings
    innings == 1 ? bowlerInnings = 1 : bowlerInnings = 0;

    // Bowler selection for first over
    if (!debug)
    {
      std::cout << "\nChoose your bowler for the first over (number):\n";
      for (int a = 0; a < bowlerNames[bowlerInnings].size(); a++)
      {
        std::cout << a + 1 << ". " << names[bowlerInnings][bowlerNames[bowlerInnings][a]] << std::endl;
      }
      std::cin >> null;

      while ((std::stoi(null) - 1) >= bowlerNames[bowlerInnings].size())
      {
        system("cls");
        std::cout << "That is an incorrect index. Please choose again!\nChoose your bowler for the first over (number):\n";
        for (int a = 0; a < bowlerNames[bowlerInnings].size(); a++)
        {
          std::cout << a + 1 << ". " << names[bowlerInnings][bowlerNames[bowlerInnings][a]] << std::endl;
        }
        std::cin >> null;
      }
      bowlerName = names[bowlerInnings][bowlerNames[bowlerInnings][std::stoi(null) - 1]];
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      system("cls");
    }
    else
    {
      counter = 0;
      bowlerName = names[bowlerInnings][bowlerNames[bowlerInnings][counter]];
      std::cout << "\nEnter to Continue\n";
      std::getline(std::cin, null);
      system("cls");
    }

    // Openers selection
    std::cout << "Pick on-strike opener (number):\n";
    batsmenCounter = 1;
    for (int i = 0; i < 11; i++)
    {
      if (teams[innings - 1][i][2] != 1)
      {
        std::cout << batsmenCounter << ". " << names[innings - 1][i] << std::endl;
        batters[batsmenCounter] = i;
        batsmenCounter++;
      }
    }
    std::cin >> null;
    while (std::stoi(null) >= batsmenCounter || std::stoi(null) <= 0)
    {
      batsmenCounter = 1;
      std::cout << "\nThat is an incorrect index. Please choose again!\nPick on-strike opener (number):\n";
      for (int i = 0; i < 11; i++)
      {
        if (teams[innings - 1][i][2] != 1)
        {
          std::cout << batsmenCounter << ". " << names[innings - 1][i] << std::endl;
          batsmenCounter++;
        }
      }
      std::cin >> null;
    }
    index[0] = batters[std::stoi(null)];
    batsmenOrder.push_back(batters[std::stoi(null)]);
    batters.clear();
    teams[innings - 1][index[0]][2] = 1;

    std::cout << "\nPick off-strike opener (number):\n";
    batsmenCounter = 1;
    for (int i = 0; i < 11; i++)
    {
      if (teams[innings - 1][i][2] != 1)
      {
        std::cout << batsmenCounter << ". " << names[innings - 1][i] << std::endl;
        batters[batsmenCounter] = i;
        batsmenCounter++;
      }
    }
    std::cin >> null;
    while (std::stoi(null) >= batsmenCounter || std::stoi(null) <= 0)
    {
      batsmenCounter = 1;
      std::cout << "\nThat is an incorrect index. Please choose again!\nPick off-strike opener (number):\n";
      for (int i = 0; i < 11; i++)
      {
        if (teams[innings - 1][i][2] != 1)
        {
          std::cout << batsmenCounter << ". " << names[innings - 1][i] << std::endl;
          batsmenCounter++;
        }
      }
      std::cin >> null;
    }
    index[1] = batters[std::stoi(null)];
    batsmenOrder.push_back(batters[std::stoi(null)]);
    batters.clear();
    teams[innings - 1][index[1]][2] = 1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("cls");

    while (overNumber <= maxOvers)
    {
      while (ballNumber < 6)
      {
        random = dist(global_rng());
        hundoGen = hundo(global_rng());

        if (wicketsT >= 3 && (added || !collapse))
        {
          collapse = true;
          balls = 1;
        }
        else if (collapse && balls > 8)
        {
          collapse = false;
        }
        else if (collapse)
        {
          balls++;
        }

        // ABD's buff logic
        if ((chemistryPartner[0] == 12) && (partnership[0] >= 50) && (names[innings - 1][index[0]] == "AB de Villiers" || names[innings - 1][index[1]] == "AB de Villiers"))
        {
          // Sets both indexes as 0 and 1 so that if either change in the future, we know that the partnership has been broken
          chemistryPartner[0] = index[0];
          chemistryPartner[1] = index[1];
        }
        else if (chemistryPartner[0] != 12 && (chemistryPartner[0] != index[0] || chemistryPartner[1] != index[1]) && chemistryPartner[2] == 0)
        {
          // Broken partnership indicator
          chemistryPartner[2] = 1;
        }

        // Similar logic for the next few batsmen - saving the starting runs into a variable and dividing the difference between current runs and runs then by an increment each time to add a bigger buff per increment
        if ((names[innings - 1][partnership[2]] == "Shubman Gill" || names[innings - 1][partnership[3]] == "Shubman Gill") && gillStarted == 300)
        {
          gillStarted = runs;
        }
        else if (gillStarted != 300)
        {
          gillUp = (runs - gillStarted) / 20;
          if (gillUp > 5)
          {
            gillUp = 5;
          }
        }

        if ((names[innings - 1][partnership[2]] == "Hardik Pandya" || names[innings - 1][partnership[3]] == "Hardik Pandya") && hardikStarted == 300)
        {
          hardikStarted = runs;
        }
        else if (hardikStarted != 300)
        {
          hardikUp = (runs - hardikStarted) / 10;
          if (hardikUp > 5)
          {
            hardikUp = 5;
          }
        }

        // Different logic for checking if a real batsman or not because this time each cricketer has a toggle for whether they can bat or bowl
        if ((Players[names[innings - 1][index[0]]].batsman && strike) || (Players[names[innings - 1][index[1]]].batsman && !strike))
        {
          if (overNumber > ((maxOvers / 4) + 1) && overNumber <= (maxOvers - 2))
          {
            dotP = 0.30f;
            oneP = 0.27f;
            doubleP = 0.1f;
            threeP = 0.005f;
            fourP = 0.175f;
            sixP = 0.08f;
            wideP = 0.02f;
          }
          else if (overNumber <= ((maxOvers / 4) + 1))
          {
            std::cout << "POWERPLAY\n---------\n";
            dotP = 0.305f;
            oneP = 0.20f;
            doubleP = 0.1f;
            threeP = 0.005f;
            fourP = 0.195f;
            sixP = 0.1f;
            wideP = 0.03f;
          }
          else if (overNumber > (maxOvers - 2))
          {
            std::cout << "DEATH\n-----\n";
            dotP = 0.30f;
            oneP = 0.15f;
            doubleP = 0.14f;
            threeP = 0.01f;
            fourP = 0.19f;
            sixP = 0.12f;
            wideP = 0.015f;
          }
        }
        else
        {
          if (overNumber > ((maxOvers / 4) + 1) && overNumber <= (maxOvers - 2))
          {
            dotP = 0.43f;
            oneP = 0.26f;
            doubleP = 0.1f;
            threeP = 0.005f;
            fourP = 0.08f;
            sixP = 0.05f;
            wideP = 0.01f;
          }
          else if (overNumber <= ((maxOvers / 4) + 1))
          {
            std::cout << "POWERPLAY\n---------\n";
            dotP = 0.345f;
            oneP = 0.27f;
            doubleP = 0.1f;
            threeP = 0.005f;
            fourP = 0.125f;
            sixP = 0.06f;
            wideP = 0.02f;
          }
          else if (overNumber > (maxOvers - 2))
          {
            std::cout << "DEATH\n-----\n";
            dotP = 0.285f;
            oneP = 0.15f;
            doubleP = 0.14f;
            threeP = 0.02f;
            fourP = 0.19f;
            sixP = 0.12f;
            wideP = 0.005f;
          }
        }

        if (changed)
        {
          dotP -= 0.045f;
          doubleP -= 0.02f;
          fourP += 0.025f;
          sixP += 0.03f;
        }

        if (collapse)
        {
          fourP -= 0.02f;
          sixP -= 0.01f;
          dotP += 0.05f;
        }

        if (buffed)
        {
          fourP += 0.03f;
          sixP += 0.02f;
          dotP -= 0.06f;
        }
        else if (nerfed)
        {
          oneP += 0.12f;
          fourP -= 0.04f;
          sixP -= 0.03f;
          wideP -= 0.005f;
          doubleP -= 0.035f;
        }

        // This is the logic for adding buffs and nerfs based on the cricketer. The block looks big because I have to account for on strike or off strike. I could cut it in half by using strike and !strike but lite
        strike ? playerMods(names[innings - 1][index[0]], names[innings - 1][index[1]], bowlerName, dotP, oneP, doubleP, threeP, fourP, sixP, wideP, ballsB[0], current[0], overNumber, ballNumber, innings, gillUp, hardikUp, kuldeepWickets, yuziWickets, warneWickets, jadduSpell[0], steynSpell[0], hasarangaSpell[0], partnership[0], runRate, requiredRR, Players[bowlerName].pace, added, flashP, chemistryPartner[2], Players, special) : playerMods(names[innings - 1][index[1]], names[innings - 1][index[0]], bowlerName, dotP, oneP, doubleP, threeP, fourP, sixP, wideP, ballsB[1], current[1], overNumber, ballNumber, innings, gillUp, hardikUp, kuldeepWickets, yuziWickets, warneWickets, jadduSpell[0], steynSpell[0], hasarangaSpell[0], partnership[0], runRate, requiredRR, Players[bowlerName].pace, added, flashP, chemistryPartner[2], Players, special);

        if (special == 1) {
          bouncer++;
        }

        // Free hits are not affected by striker or non-striker since if they were the 10% dot ball chance would cause issues
        if (free)
        {
          dotP = 0.1f;
          oneP = 0.15f;
          doubleP = 0.18f;
          threeP = 0.005f;
          fourP = 0.25f;
          sixP = 0.2f;
          wideP = 0.015f;
        }
        else if (!special && (hundoGen <= 3 && Players[bowlerName].pace))
        {
          // 3% chance for yorker for a pace bowler normally
          std::cout << "A yorker ball! ";
          dotP = 0.5f;
          oneP = 0.15f;
          doubleP = 0.05f;
          threeP = 0.0f;
          fourP = 0.15f;
          sixP = 0.02f;
          wideP = 0.0f;
        }
        else if (!special && (hundoGen >= 5 && hundoGen <= 25 && Players[bowlerName].yorkerGod))
        {
          // 21% chance added for yorker for special 'Yorker God' bowlers
          std::cout << "OH MY WHAT A YORKER! ";
          dotP = 0.5f;
          oneP = 0.15f;
          doubleP = 0.05f;
          threeP = 0.0f;
          fourP = 0.15f;
          sixP = 0.02f;
          wideP = 0.0f;
        }

        dotMax = static_cast<int>(10000 * dotP);
        std::cout << dotMax << std::endl;
        oMax = static_cast<int>((10000 * oneP) + dotMax);
        std::cout << oMax << std::endl;
        dMax = static_cast<int>((10000 * doubleP) + oMax);
        std::cout << dMax << std::endl;
        tMax = static_cast<int>((10000 * threeP) + dMax);
        std::cout << tMax << std::endl;
        fMax = static_cast<int>((10000 * fourP) + tMax);
        std::cout << fMax << std::endl;
        sMax = static_cast<int>((10000 * sixP) + fMax);
        std::cout << sMax << std::endl;
        wMax = static_cast<int>((10000 * wideP) + sMax);
        std::cout << wMax << std::endl;

        if (random <= dotMax)
          e = outPutRuns("draft", 5, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, bowlerName, special, bouncer);
        else if (random > dotMax && random <= oMax)
          e = outPutRuns("draft", 1, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, bowlerName, special, bouncer);
        else if (random > oMax && random <= dMax)
          e = outPutRuns("draft", 2, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, bowlerName, special, bouncer);
        else if (random > dMax && random <= tMax)
          e = outPutRuns("draft", 3, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, bowlerName, special, bouncer);
        else if (random > tMax && random <= fMax)
          e = outPutRuns("draft", 4, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, bowlerName, special, bouncer);
        else if (random > fMax && random <= sMax)
          e = outPutRuns("draft", 6, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, bowlerName, special, bouncer);
        else if (random > sMax && random <= wMax)
          e = outPutRuns("draft", 7, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, bowlerName, special, bouncer);
        else if (random > wMax)
        {
          e = outPutRuns("draft", 8, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, bowlerName, special, bouncer);
          if (e == true)
            break;
        }

        // Outputs the bowler stats after every ball
        if (ballNumber != 6)
        {
          std::cout << "\n"
                    << bowlerName << ": " << bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][0] << "." << ballNumber << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][3] + overRuns << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][4] + wickets - oldWickets << std::endl;
          std::cout << "\nScorecard: " << (overNumber - 1) << "." << ballNumber << ", " << runs << "/" << wickets << std::endl;
        }
        else
        {
          std::cout << "\n"
                    << bowlerName << ": " << bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][0] + 1 << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][3] + overRuns << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][4] + wickets - oldWickets << std::endl;
          std::cout << "\nScorecard: " << overNumber << ", " << runs << "/" << wickets << std::endl;
        }

        // Increases effectiveness of certain bowlers when taking wickets
        if (added)
        {
          if (bowlerName == "Kuldeep Yadav" && kuldeepWickets < 4)
          {
            kuldeepWickets++;
          }
          else if (bowlerName == "Yuzvendra Chahal" && yuziWickets < 6)
          {
            yuziWickets++;
          }
          else if (bowlerName == "Shane Warne")
          {
            warneWickets++;
          }

          // Choice of next batsman when wicket falls
          if (strike)
          {
            std::cout << "\nPick the next batter (number):\n";
            batsmenCounter = 1;
            for (int i = 0; i < 11; i++)
            {
              if (teams[innings - 1][i][2] != 1)
              {
                std::cout << batsmenCounter << ". " << names[innings - 1][i] << std::endl;
                batters[batsmenCounter] = i;
                batsmenCounter++;
              }
            }
            std::cin >> null;
            while (std::stoi(null) >= batsmenCounter || std::stoi(null) <= 0)
            {
              batsmenCounter = 1;
              std::cout << "\nThat is an incorrect index. Please choose again!\nPick the next batter (number):\n";
              for (int i = 0; i < 11; i++)
              {
                if (teams[innings - 1][i][2] != 1)
                {
                  std::cout << batsmenCounter << ". " << names[innings - 1][i] << std::endl;
                  batsmenCounter++;
                }
              }
              std::cin >> null;
            }
            index[0] = batters[std::stoi(null)];
            batsmenOrder.push_back(batters[std::stoi(null)]);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            batters.clear();
            teams[innings - 1][index[0]][2] = 1;
          }
          else
          {
            std::cout << "\nPick the next batter (number):\n";
            batsmenCounter = 1;
            for (int i = 0; i < 11; i++)
            {
              if (teams[innings - 1][i][2] != 1)
              {
                std::cout << batsmenCounter << ". " << names[innings - 1][i] << std::endl;
                batters[batsmenCounter] = i;
                batsmenCounter++;
              }
            }
            std::cin >> null;
            while (std::stoi(null) >= batsmenCounter || std::stoi(null) <= 0)
            {
              batsmenCounter = 1;
              std::cout << "\nThat is an incorrect index. Please choose again!\nPick the next batter (number):\n";
              for (int i = 0; i < 11; i++)
              {
                if (teams[innings - 1][i][2] != 1)
                {
                  std::cout << batsmenCounter << ". " << names[innings - 1][i] << std::endl;
                  batsmenCounter++;
                }
              }
              std::cin >> null;
            }
            index[1] = batters[std::stoi(null)];
            batsmenOrder.push_back(batters[std::stoi(null)]);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            batters.clear();
            teams[innings - 1][index[1]][2] = 1;
          }
        }

        if (innings == 2)
        {
          if (runs > oldRuns)
          {
            std::cout << "\nEnter to Continue\n";
            std::getline(std::cin, null);
            system("cls");
            break;
          }
          std::cout << "\nRuns to Win: " << ((oldRuns + 1) - runs) << " from " << ((maxOvers * 6) - (((overNumber - 1) * 6) + ballNumber)) << " balls\n";
        }
        std::cout << "\nEnter to Continue\n";
        std::getline(std::cin, null);
        system("cls");
      }
      bouncer = 0;

      if (ballNumber == 6)
      {
        ballNumber = 0;
        bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][0]++; // Increments overs bowled by bowler
        overNumber++;
      }

      if (overRuns == 0)
      {
        // Maiden overs bowled by bowler
        bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][2]++;
      }
      bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][3] += overRuns;             // Total runs given by bowler
      bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][4] += wickets - oldWickets; // Total wickets taken by bowler
      oldWickets = wickets;

      // Calculating extras bowled by bowler if match ended (so mid-over check and add)
      if ((wickets == 10) || (innings == 2) && (runs > oldRuns))
      {
        for (int i = 0; i < timeline[overNumber - 2].size(); i++)
        {
          if (timeline[overNumber - 2][i] == 'w')
          {
            extras++;
          }
          else if (timeline[overNumber - 2][i] == 'n')
          {
            extras++;
          }
        }
        bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][5] += extras;
        extras = 0;
        break;
      }

      for (int i = 0; i < timeline[overNumber - 2].size(); i++)
      {
        if (timeline[overNumber - 2][i] == 'w')
        {
          extras++;
        }
        if ((i + 1) != timeline[overNumber - 2].size())
        {
          if (timeline[overNumber - 2][i + 1] == 'n')
          {
            std::cout << timeline[overNumber - 2][i] << "* ";
            i++;
            extras++;
          }
          else
          {
            std::cout << timeline[overNumber - 2][i] << " ";
          }
        }
        else
        {
          std::cout << timeline[overNumber - 2][i] << " ";
        }
      }

      bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][5] += extras; // Regular addition of extras bowled in over
      extras = 0;

      // Calculating run rate
      runRate = static_cast<double>(runs) / static_cast<double>((overNumber - 1));
      runRate = std::round(runRate * 100.0) / 100.0;

      // Printing all stats out
      std::cout << "\n\n";
      std::cout << names[innings - 1][index[0]] << ": " << current[0] << " in " << ballsB[0] << "\n";
      std::cout << names[innings - 1][index[1]] << ": " << current[1] << " in " << ballsB[1] << "\n\n";
      std::cout << "Runs last over: " << overRuns << "\n";
      std::cout << (overNumber - 1) << " over(s) up, " << runs << "/" << wickets << std::endl;
      std::cout << "Current run rate: " << runRate << "\n";
      if (innings == 2)
      {
        if (overNumber != maxOvers + 1)
        {
          requiredRR = static_cast<double>(oldRuns - runs + 1) / static_cast<double>(maxOvers - (overNumber - 1));
          requiredRR = std::round(requiredRR * 100.0) / 100.0;
          std::cout << "Required run rate: " << requiredRR << "\n";
        }
        std::cout << "\nRuns to Win: " << ((oldRuns + 1) - runs) << " from " << ((maxOvers * 6) - (((overNumber - 1) * 6) + ballNumber)) << " balls\n";
      }
      else
      {
        projected = static_cast<int>(runRate * maxOvers);
        std::cout << "Projected score at current run rate: " << projected << "\n";
        projected = static_cast<int>(runs + static_cast<double>(10.9 * (maxOvers + 1 - overNumber)));
        std::cout << "Projected score at par run rate : " << projected << "\n";
        projected = static_cast<int>(runs + static_cast<double>(13 * (maxOvers + 1 - overNumber)));
        std::cout << "Projected score at high run rate (13): " << projected << "\n";
      }

      if (debug)
      {
        if (counter + 1 == bowlerNames[bowlerInnings].size())
        {
          counter = 0;
        }
        else
        {
          counter++;
        }
        bowlerName = names[bowlerInnings][bowlerNames[bowlerInnings][counter]];
      }

      // Choice of next bowler. Stats of every bowler are also given when asking for next choice
      if (overNumber != 21 && !debug)
      {
        std::cout << "\nChoose a bowler for the next over (number):\n";
        for (int a = 0; a < bowlerNames[bowlerInnings].size(); a++)
        {
          if (bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][0] == 4)
          {
            std::cout << "\033[1;31m" << a + 1 << ". " << names[bowlerInnings][bowlerNames[bowlerInnings][a]] << ": " << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][0] << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][3] << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][4] << "\033[0m" << std::endl;
          }
          else
          {
            std::cout << a + 1 << ". " << names[bowlerInnings][bowlerNames[bowlerInnings][a]] << ": " << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][0] << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][3] << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][4] << std::endl;
          }
        }
        std::cin >> null;

        while ((std::stoi(null) - 1) >= bowlerNames[bowlerInnings].size() || bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][std::stoi(null) - 1]]]][0] == 4 || bowlerName == names[bowlerInnings][bowlerNames[bowlerInnings][std::stoi(null) - 1]])
        {
          system("cls");
          if (std::stoi(null) - 1 >= bowlerNames[bowlerInnings].size())
          {
            std::cout << "That is an incorrect index. Please choose again!\nChoose your bowler for the first over (number):\n";
          }
          else if (bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][std::stoi(null) - 1]]]][0] == 4)
          {
            std::cout << "That bowler has already bowled 4 overs. Please choose again!\nChoose your bowler for the first over (number):\n";
          }
          else
          {
            std::cout << "That bowler has bowled the previous over. Please choose again!\nChoose your bowler for the first over (number):\n";
          }
          for (int a = 0; a < bowlerNames[bowlerInnings].size(); a++)
          {
            if (bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][0] == 4)
            {
              std::cout << "\033[1;31m" << a + 1 << ". " << names[bowlerInnings][bowlerNames[bowlerInnings][a]] << ": " << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][0] << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][3] << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][4] << "\033[0m" << std::endl;
            }
            else
            {
              std::cout << a + 1 << ". " << names[bowlerInnings][bowlerNames[bowlerInnings][a]] << ": " << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][0] << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][3] << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][4] << std::endl;
            }
          }
          std::cin >> null;
        }
        bowlerName = names[bowlerInnings][bowlerNames[bowlerInnings][std::stoi(null) - 1]];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("cls");
      }
      else
      {
        std::cout << "\nEnter to Continue\n";
        std::getline(std::cin, null);
        system("cls");
      }

      // Spell-related bowlers who get better (incrementing their buff for every over they bowl in a spell)
      if (bowlerName == "Ravindra Jadeja")
      {
        if ((overNumber - jadduSpell[1]) == 2 && jadduSpell[1] != 0)
        {
          jadduSpell[0]++;
        }
        else
        {
          jadduSpell[0] = 0;
        }
        jadduSpell[1] = overNumber;
      }
      else if (bowlerName == "Dale Steyn")
      {
        if ((overNumber - steynSpell[1]) == 2 && steynSpell[1] != 0)
        {
          steynSpell[0]++;
        }
        else
        {
          steynSpell[0] = 0;
        }
        steynSpell[1] = overNumber;
      }
      else if (bowlerName == "Wanindu Hasaranga")
      {
        if ((overNumber - hasarangaSpell[1]) == 2 && hasarangaSpell[1] != 0)
        {
          hasarangaSpell[0]++;
        }
        else
        {
          hasarangaSpell[0] = 0;
        }
        hasarangaSpell[1] = overNumber;
      }

      // Setting flash point variable true if the last over qualified
      if (overRuns <= 9)
      {
        flashP = true;
      }
      else
      {
        flashP = false;
      }
      strike = !strike;
      if (!changed && (overNumber == 18 && wickets <= 3) || (overNumber == 17 && wickets <= 2))
      {
        changed = true;
      }
      overRuns = 0;
    }

    // Calculating run rate again
    runRate = static_cast<double>(runs) / static_cast<double>(((overNumber - 1) * 6 + ballNumber)) * static_cast<double>(6);
    runRate = std::round(runRate * 100.0) / 100.0;

    if (wickets == 10)
    {
      if (strike) {
        index[0] = 11;
      }
      else {
        index[1] = 11;
      }
      if (ballNumber != 0)
      {
        std::cout << "\nAll out at " << runs << " after " << overNumber - 1 << "." << ballNumber << " overs with a run rate of " << runRate << "!\n";
      }
      else
      {
        std::cout << "\nAll out at " << runs << " after " << overNumber - 1 << " overs with a run rate of " << runRate << "!\n";
      }
    }

    if (innings == 1 && wickets != 10)
    {
      std::cout << "First innings up.\n"
                << runs << "/" << wickets << " in " << maxOvers << " overs!\nRun rate : " << runRate << std::endl;
    }
    else if (runs == oldRuns && innings == 2)
    {
      std::cout << "Both teams tied\n";
      std::cout << "\nTeam 2 scored " << runs << "/" << wickets << " in " << maxOvers << " overs!\nRun rate : " << runRate << std::endl;
    }
    else if (runs < oldRuns && innings == 2)
    {
      std::cout << "\nTeam 1 won by " << (oldRuns - runs) << " run(s)!\n";
      if (wickets != 10)
        std::cout << "\nTeam 2 scored " << runs << "/" << wickets << " in " << maxOvers << " overs!\nRun rate : " << runRate << std::endl;
    }
    else if (innings == 2)
    {
      if (ballNumber != 0)
      {
        std::cout << "\nTeam 2 won with " << (10 - wickets) << " wicket(s)!\n"
                  << runs << "/" << wickets << " in " << overNumber - 1 << "." << ballNumber << " overs!\nRun rate : " << runRate << std::endl;
      }
      else
      {
        std::cout << "\nTeam 2 won with " << (10 - wickets) << " wicket(s)!\n"
                  << runs << "/" << wickets << " in " << overNumber - 1 << " overs!\nRun rate : " << runRate << std::endl;
      }
    }

    if (index[0] > 10)
    {
      teams[innings - 1][index[1]][0] = current[1];
      teams[innings - 1][index[1]][1] = ballsB[1];
    }
    else if (index[1] > 10)
    {
      teams[innings - 1][index[0]][0] = current[0];
      teams[innings - 1][index[0]][1] = ballsB[0];
    }
    else
    {
      teams[innings - 1][index[0]][0] = current[0];
      teams[innings - 1][index[0]][1] = ballsB[0];
      teams[innings - 1][index[1]][0] = current[1];
      teams[innings - 1][index[1]][1] = ballsB[1];
      partnership[2] = index[0];
      partnership[3] = index[1];
      partnerships.push_back(partnership);
    }

    if (ballNumber != 0)
    {
      // If over was incomplete ball number is added
      bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][1] = ballNumber;
    }

    if (innings == 1)
    {
      std::cout << "\nSCORECARD\n---------" << std::endl;
      counter = 0;
      for (int z = 0; z < batsmenOrder.size(); z++)
      {
        if (batsmenOrder[counter] == index[0] || batsmenOrder[counter] == index[1])
          std::cout << names[0][batsmenOrder[counter]] << ": " << teams[0][batsmenOrder[counter]][0] << " in " << teams[0][batsmenOrder[counter]][1] << "\n";
        else
          std::cout << names[0][batsmenOrder[counter]] << ": " << teams[0][batsmenOrder[counter]][0] << " in " << teams[0][batsmenOrder[counter]][1] << " b. " << outBy[0][batsmenOrder[counter]] << std::endl;
        counter++;
      }
      counter = 0;
      for (int i = 0; i < partnerships.size(); i++)
      {
        if (partnerships[i][0] > partnerships[counter][0])
        {
          counter = i;
        }
      }
      notOut[0] = index[0];
      notOut[1] = index[1];
      savedP = partnerships[counter];
    }
    else
    {
      std::cout << "\nFULL MATCH SCORECARD\n---------------------" << std::endl;
      counter = 0;
      for (int z = 0; z < oldBatsmenOrder.size(); z++)
      {
        if (oldBatsmenOrder[counter] == notOut[0] || oldBatsmenOrder[counter] == notOut[1])
          std::cout << names[0][oldBatsmenOrder[counter]] << ": " << teams[0][oldBatsmenOrder[counter]][0] << " in " << teams[0][oldBatsmenOrder[counter]][1] << "\n";
        else
          std::cout << names[0][oldBatsmenOrder[counter]] << ": " << teams[0][oldBatsmenOrder[counter]][0] << " in " << teams[0][oldBatsmenOrder[counter]][1] << " b. " << outBy[0][oldBatsmenOrder[counter]] << std::endl;
        counter++;
      }
      std::cout << "\nLargest partnership: " << savedP[0] << " in " << savedP[1] << " between " << names[0][savedP[2]] << " and " << names[0][savedP[3]] << "\n\n";
      counter = 0;

      std::cout << "Fall of wickets: ";
      for (int i = 0; i < fallOW[0].size(); i++)
      {
        std::cout << fallOW[0][i][0] << "-" << fallOW[0][i][1] << " (" << names[0][fallOW[0][i][2]] << ", " << fallOW[0][i][3] << "." << fallOW[0][i][4] << " ov)";
        if (i + 1 < fallOW[0].size())
        {
          std::cout << ", ";
        }
      }
      std::cout << "\n\n";

      // Outputting bowler stats
      for (int a = 0; a < bowlerNames[1].size(); a++)
      {
        if (bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][1] == 0)
        {
          economy = static_cast<double>(bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][3]) / static_cast<double>(bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][0]);
          economy = std::round(economy * 100.0) / 100.0;
          std::cout << names[1][bowlerNames[1][a]] << ": " << bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][0] << "-" << bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][3] << "-" << bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][4] << " - " << bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][2] << " maiden - " << bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][5] << " extras - " << economy << " economy\n";
        }
        else
        {
          economy = static_cast<double>(bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][3]) / static_cast<double>((bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][0] + (static_cast<double>(bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][1]) / 6.0)));
          economy = std::round(economy * 100.0) / 100.0;
          std::cout << names[1][bowlerNames[1][a]] << ": " << bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][0] << "." << bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][1] << "-" << bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][3] << "-" << bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][4] << " - " << bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][2] << " maiden - " << bowlerStats[1][bowlers[1][names[1][bowlerNames[1][a]]]][5] << " extras - " << economy << " economy\n";
        }
      }

      std::cout << "\n";

      for (int z = 0; z < batsmenOrder.size(); z++)
      {
        if (batsmenOrder[counter] == index[0] || batsmenOrder[counter] == index[1])
          std::cout << names[1][batsmenOrder[counter]] << ": " << teams[1][batsmenOrder[counter]][0] << " in " << teams[1][batsmenOrder[counter]][1] << "\n";
        else
          std::cout << names[1][batsmenOrder[counter]] << ": " << teams[1][batsmenOrder[counter]][0] << " in " << teams[1][batsmenOrder[counter]][1] << " b. " << outBy[1][batsmenOrder[counter]] << std::endl;
        counter++;
      }
      counter = 0;

      for (int i = 0; i < partnerships.size(); i++)
      {
        if (partnerships[i][0] > partnerships[counter][0])
        {
          counter = i;
        }
      }
    }
    std::cout << "\n";

    std::cout << "Largest partnership: " << partnerships[counter][0] << " in " << partnerships[counter][1] << " between " << names[innings - 1][partnerships[counter][2]] << " and " << names[innings - 1][partnerships[counter][3]] << "\n\n";
    counter = 0;

    std::cout << "Fall of wickets: ";
    for (int i = 0; i < fallOW[innings - 1].size(); i++)
    {
      std::cout << fallOW[innings - 1][i][0] << "-" << fallOW[innings - 1][i][1] << " (" << names[innings - 1][fallOW[innings - 1][i][2]] << ", " << fallOW[innings - 1][i][3] << "." << fallOW[innings - 1][i][4] << " ov)";
      if (i + 1 < fallOW[innings - 1].size())
      {
        std::cout << ", ";
      }
    }
    std::cout << "\n\n";

    // Outputting bowler stats
    for (int a = 0; a < bowlerNames[bowlerInnings].size(); a++)
    {
      if (bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][1] == 0)
      {
        economy = static_cast<double>(bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][3]) / static_cast<double>(bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][0]);
        economy = std::round(economy * 100.0) / 100.0;
        std::cout << names[bowlerInnings][bowlerNames[bowlerInnings][a]] << ": " << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][0] << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][3] << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][4] << " - " << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][2] << " maiden - " << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][5] << " extras - " << economy << " economy\n";
      }
      else
      {
        economy = static_cast<double>(bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][3]) / static_cast<double>((bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][0] + (static_cast<double>(bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][1]) / 6.0)));
        economy = std::round(economy * 100.0) / 100.0;
        std::cout << names[bowlerInnings][bowlerNames[bowlerInnings][a]] << ": " << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][0] << "." << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][1] << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][3] << "-" << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][4] << " - " << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][2] << " maiden - " << bowlerStats[bowlerInnings][bowlers[bowlerInnings][names[bowlerInnings][bowlerNames[bowlerInnings][a]]]][5] << " extras - " << economy << " economy\n";
      }
    }

    std::cout << "\nDo you want the full innings timeline(y/n): ";
    std::cin >> null;
    std::cout << "\n";

    std::cin.ignore();

    overNumber--;

    if (null == "y")
    {
      for (int x = 0; x < overNumber; x++)
      {
        for (int i = 0; i < timeline[x].size(); i++)
        {
          switch (timeline[x][i])
          {
          case '1':
            counter++;
            break;
          case '2':
            counter += 2;
            break;
          case '3':
            counter += 3;
            break;
          case '4':
            counter += 4;
            break;
          case '6':
            counter += 6;
            break;
          case 'w':
            counter++;
            break;
          default:
            break;
          }

          if ((i + 1) != timeline[x].size())
          {
            if (timeline[x][i + 1] == 'n')
            {
              std::cout << timeline[x][i] << "* ";
              i++;
              counter++;
            }
            else
            {
              std::cout << timeline[x][i] << " ";
            }
          }
          else
          {
            std::cout << timeline[x][i];
          }
        }
        std::cout << " - " << counter << std::endl;
        counter = 0;
      }
      counter = 0;
      if (overNumber != 20 && timeline[overNumber].size() > 0)
      {
        for (int i = 0; i < timeline[overNumber].size(); i++)
        {
          switch (timeline[overNumber][i])
          {
          case '1':
            counter++;
            break;
          case '2':
            counter += 2;
            break;
          case '3':
            counter += 3;
            break;
          case '4':
            counter += 4;
            break;
          case '6':
            counter += 6;
            break;
          case 'w':
            counter++;
            break;
          default:
            break;
          }

          if ((i + 1) != timeline[overNumber].size())
          {
            if (timeline[overNumber][i + 1] == 'n')
            {
              std::cout << timeline[overNumber][i] << "* ";
              i++;
              counter++;
            }
            else
            {
              std::cout << timeline[overNumber][i] << " ";
            }
          }
          else
          {
            std::cout << timeline[overNumber][i];
          }
        }
        std::cout << " - " << counter << std::endl;
      }
      std::cout << "\nEnter to Continue\n";
      std::getline(std::cin, null);
    }
    counter = 0;

    system("cls");

    current[0] = 0;
    ballsB[0] = 0;
    current[1] = 0;
    ballsB[1] = 0;
    index[0] = 0;
    index[1] = 0;
    ballNumber = 0;
    overNumber = 1;
    wickets = 0;
    overRuns = 0;
    partnership = {0, 0, 0, 0};
    partnerships.clear();
    strike = true;
    changed = false;
    wicketsT = 0;
    balls = 0;
    collapse = false;
    added = false;
    wicketsTCounter = 0;
    buffed = false;
    nerfed = false;
    gillStarted = 300;
    gillUp = 0;
    hardikStarted = 300;
    hardikUp = 300;
    flashP = false;
    chemistryPartner = {12, 0, 0};
    oldWickets = 0;
    kuldeepWickets = 0;
    yuziWickets = 0;
    warneWickets = 0;
    jadduSpell = {0, 0};
    steynSpell = {0, 0};
    hasarangaSpell = {0, 0};
    oldBatsmenOrder = batsmenOrder;
    batsmenOrder.clear();

    for (int i = 0; i < timeline.size(); i++)
    {
      timeline[i].clear();
    }

    if (innings == 2 && runs == oldRuns)
    {
      std::cout
          << "SUPER OVER\n----------\nFirst, we will let players decide "
             "batsmen. Enter corresponding batting order position\n";
      std::cout << "\nEnter to Continue\n";
      std::getline(std::cin, null);
      system("cls");

      std::array<std::array<std::array<int, 3>, 3>, 2> superTeams = {{{{{{0, 0, 1}}, {{0, 0, 1}}, {{0, 0, 0}}}}, {{{{0, 0, 1}}, {{0, 0, 1}}, {{0, 0, 0}}}}}};
      std::array<std::vector<char>, 2> sOverT;
      std::array<std::array<std::string, 3>, 2> superOver = {{{"", "", ""}, {"", "", ""}}};

      for (int x = 1; x < 3; x++)
      {
        std::cout << "Player " << x << "\n--------\n";
        for (int i = 1; i < 4; i++)
        {
          std::cout << "Batsman " << i << ": ";
          std::cin >> null;
          if (names[x - 1][std::stoi(null) - 1] == superOver[x - 1][0] ||
              names[x - 1][std::stoi(null) - 1] == superOver[x - 1][1])
          {
            std::cout << "That player has already been selected, please "
                         "try again\n";
            --i;
            continue;
          }
          superOver[x - 1][i - 1] = names[x - 1][std::stoi(null) - 1];
        }
        std::cout << "\nEnter to Continue\n";
        std::getline(std::cin, null);
        system("cls");
      }

      // For later - I will add the function that changes probabilities here so I have it ready for later
      dotP = 0.16f;
      oneP = 0.15f;
      doubleP = 0.15f;
      threeP = 0.005f;
      fourP = 0.25f;
      sixP = 0.17f;
      wideP = 0.015f;

      dotMax = static_cast<int>(10000 * dotP);
      oMax = static_cast<int>((10000 * oneP) + dotMax);
      dMax = static_cast<int>((10000 * doubleP) + oMax);
      tMax = static_cast<int>((10000 * threeP) + dMax);
      fMax = static_cast<int>((10000 * fourP) + tMax);
      sMax = static_cast<int>((10000 * sixP) + fMax);
      wMax = static_cast<int>((10000 * wideP) + sMax);

      std::cout << "Team 2 will now bat first!\n";
      std::cout << "\nEnter to Continue\n";
      std::getline(std::cin, null);
      system("cls");

      while (ballNumber < 6)
      {
        random = dist(global_rng());

        if (random <= dotMax)
          e = superO(5, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
        else if (random > dotMax && random <= oMax)
          e = superO(1, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
        else if (random > oMax && random <= dMax)
          e = superO(2, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
        else if (random > dMax && random <= tMax)
          e = superO(3, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
        else if (random > tMax && random <= fMax)
          e = superO(4, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
        else if (random > fMax && random <= sMax)
          e = superO(6, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
        else if (random > sMax && random <= wMax)
          e = superO(7, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
        else if (random > wMax)
        {
          e = superO(8, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
          if (e == true)
            break;
        }

        std::cout << "\nEnter to Continue\n";
        std::getline(std::cin, null);
        system("cls");
      }

      for (int i = 0; i < sOverT[innings - 1].size(); i++)
        std::cout << sOverT[1][i] << " ";

      // Printing all stats out
      if (index[0] > 2)
      {
        superTeams[innings - 1][index[1]][0] = current[1];
        superTeams[innings - 1][index[1]][1] = ballsB[1];
      }
      else if (index[1] > 2)
      {
        superTeams[innings - 1][index[0]][0] = current[0];
        superTeams[innings - 1][index[0]][1] = ballsB[0];
      }
      else
      {
        superTeams[innings - 1][index[0]][0] = current[0];
        superTeams[innings - 1][index[0]][1] = ballsB[0];
        superTeams[innings - 1][index[1]][0] = current[1];
        superTeams[innings - 1][index[1]][1] = ballsB[1];
      }

      std::cout << "\n\nSCORECARD\n---------" << std::endl;
      counter = 0;
      while (counter < 3)
      {
        if ((counter == index[0] || counter == index[1]) &&
            superTeams[1][counter][2] != 0)
          std::cout << superOver[1][counter] << ": " << superTeams[1][counter][0]
                    << " in " << superTeams[1][counter][1] << "\n";
        else
        {
          if (superTeams[1][counter][1] == 0)
            std::cout << superOver[1][counter] << ": DNP\n";
          else
            std::cout << superOver[1][counter] << ": "
                      << superTeams[1][counter][0] << " in "
                      << superTeams[1][counter][1] << " - OUT\n";
        }
        counter++;
      }
      std::cout << "\nFirst over: " << overRuns << "/" << wickets << "\n";

      innings--;
      oldRuns = overRuns;
      overRuns = 0;
      ballNumber = 0;
      wickets = 0;
      current[0] = 0;
      current[1] = 0;
      index[0] = 0;
      index[1] = 1;
      strike = true;
      ballsB[0] = 0;
      ballsB[1] = 0;
      partnership = {0, 0, 0, 0};

      std::cout << "\nEnter to Continue\n";
      std::getline(std::cin, null);
      system("cls");

      while (ballNumber < 6)
      {
        random = dist(global_rng());

        if (random <= dotMax)
          e = superO(5, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
        else if (random > dotMax && random <= oMax)
          e = superO(1, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
        else if (random > oMax && random <= dMax)
          e = superO(2, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
        else if (random > dMax && random <= tMax)
          e = superO(3, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
        else if (random > tMax && random <= fMax)
          e = superO(4, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
        else if (random > fMax && random <= sMax)
          e = superO(6, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
        else if (random > sMax && random <= wMax)
          e = superO(7, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
        else if (random > wMax)
        {
          e = superO(8, sOverT, overRuns, ballNumber, wickets, current, index, strike, superTeams, innings, ballsB, partnership, superOver, free);
          if (e == true)
            break;
        }

        if (overRuns > oldRuns)
        {
          std::cout << "\nEnter to Continue\n";
          std::getline(std::cin, null);
          system("cls");
          break;
        }

        // Printing out the amount of runs left to win if in the second
        // innings
        std::cout << "\nRuns to Win: " << ((oldRuns + 1) - overRuns)
                  << "\n";
        std::cout << "\nEnter to Continue\n";
        std::getline(std::cin, null);
        system("cls");
      }

      for (int i = 0; i < sOverT[innings - 1].size(); i++)
        std::cout << sOverT[0][i] << " ";

      if (overRuns > oldRuns)
        std::cout << "\n\nTEAM 1 WINS IN SUPER OVER!\n"
                  << overRuns << "/" << wickets << " in " << ballNumber
                  << " balls!\n";
      else if (overRuns == oldRuns)
        std::cout << "\n\nTHE GAME ENDS IN A TIE\n"
                  << overRuns << "/" << wickets << " in " << ballNumber
                  << " balls!\n";
      else
        std::cout << "\n\nTEAM 2 WINS BY " << oldRuns - overRuns
                  << " RUNS IN SUPER OVER!\n"
                  << overRuns << "/" << wickets << " in " << ballNumber
                  << " balls for Team 1!\n";

      // Printing all stats out
      if (index[0] > 2)
      {
        superTeams[innings - 1][index[1]][0] = current[1];
        superTeams[innings - 1][index[1]][1] = ballsB[1];
      }
      else if (index[1] > 2)
      {
        superTeams[innings - 1][index[0]][0] = current[0];
        superTeams[innings - 1][index[0]][1] = ballsB[0];
      }
      else
      {
        superTeams[innings - 1][index[0]][0] = current[0];
        superTeams[innings - 1][index[0]][1] = ballsB[0];
        superTeams[innings - 1][index[1]][0] = current[1];
        superTeams[innings - 1][index[1]][1] = ballsB[1];
      }

      std::cout << "\nFULL SCORECARD\n--------------" << std::endl;
      counter = 0;
      while (counter < 3)
      {
        if ((counter == index[0] || counter == index[1]) &&
            superTeams[1][counter][2] != 0)
          std::cout << superOver[1][counter] << ": " << superTeams[1][counter][0]
                    << " in " << superTeams[1][counter][1] << "\n";
        else
        {
          if (superTeams[1][counter][1] == 0)
            std::cout << superOver[1][counter] << ": DNP\n";
          else
            std::cout << superOver[1][counter] << ": "
                      << superTeams[1][counter][0] << " in "
                      << superTeams[1][counter][1] << " - OUT\n";
        }
        counter++;
      }

      std::cout << "\n";
      counter = 0;
      while (counter < 3)
      {
        if ((counter == index[0] || counter == index[1]) &&
            superTeams[0][counter][2] != 0)
          std::cout << superOver[0][counter] << ": " << superTeams[0][counter][0]
                    << " in " << superTeams[0][counter][1] << "\n";
        else
        {
          if (superTeams[0][counter][1] == 0)
            std::cout << superOver[0][counter] << ": DNP\n";
          else
            std::cout << superOver[0][counter] << ": "
                      << superTeams[0][counter][0] << " in "
                      << superTeams[0][counter][1] << " - OUT\n";
        }
        counter++;
      }
      std::cout << "\nEnter to Continue\n";
      std::getline(std::cin, null);
      system("cls");
      innings = 2;
      // RESET REST VARIABLES
      overRuns = 0;
      ballNumber = 0;
      wickets = 0;
      current[0] = 0;
      current[1] = 0;
      index[0] = 0;
      index[1] = 1;
      strike = true;
      ballsB[0] = 0;
      ballsB[1] = 0;
      partnership = {0, 0, 0, 0};
    }
    oldRuns = runs;
    runs = 0;
    innings++;
  }
}

// Combines both getline and cin methods meaning a new line doesn't count as an input but you can have multiple words as input
std::string draftInput()
{
  std::string str;
  while (true)
  {
    std::getline(std::cin, str);
    if (!str.empty())
      break;
  }
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
}

// Outputs the full draft list in an easy way (called easily instead of a block being put in the code constantly). If the below arrays are changed, the draft list changes. Players are highlighted based on team color if picked
void draftOutput(std::array<std::array<std::string, 11>, 2> names, std::string type)
{
  std::array<std::string, 19> batsmen = {{"Ruturaj Gaikwad", "Virat Kohli", "Rohit Sharma", "Sai Sudharsan", "Travis Head", "Suryakumar Yadav", "Nicholas Pooran", "Shubman Gill", "Yashasvi Jaiswal", "Shimron Hetmyer", "AB de Villiers", "Shreyas Iyer", "Shivam Dube", "Abhishek Sharma", "David Warner", "Chris Gayle", "Brendon McCullum", "Don Bradman", "Sachin Tendulkar"}};
  std::array<std::string, 7> wicketKeepers = {{"MS Dhoni", "KL Rahul", "Rishabh Pant", "Jos Buttler", "Heinrich Klaasen", "Sanju Samson", "Quinton de Kock"}};
  std::array<std::string, 11> allRounders = {{"Ravindra Jadeja", "Hardik Pandya", "Shakib Al Hasan", "Glenn Maxwell", "Ben Stokes", "Andre Russell", "Dwayne Bravo", "Shane Watson", "Kieron Pollard", "Washington Sundar", "Axar Patel"}};
  std::array<std::string, 12> paceBowlers = {{"Dale Steyn", "Lasith Malinga", "Trent Boult", "Mitchell Starc", "Mohammed Shami", "Bhuvneshwar Kumar", "Mohammed Siraj", "Jofra Archer", "Morne Morkel", "Deepak Chahar", "Arshdeep Singh", "Jasprit Bumrah"}};
  std::array<std::string, 8> spinBowlers = {{"Wanindu Hasaranga", "Rashid Khan", "Yuzvendra Chahal", "Sunil Narine", "Kuldeep Yadav", "Ravichandran Ashwin", "Varun Chakravarthy", "Shane Warne"}};

  std::cout << "Batsmen             Wicket Keepers      All Rounders        Pace Bowlers        Spin Bowlers\n--------            ---------------     -------------       -------------       -------------\n";
  if (type == "first")
  {
    for (int i = 0; i < batsmen.size(); i++)
    {
      std::cout << batsmen[i];
      for (int a = 0; a < 20 - batsmen[i].size(); a++)
      {
        std::cout << " ";
      }

      if (i < wicketKeepers.size())
      {
        std::cout << wicketKeepers[i];
        for (int a = 0; a < 20 - wicketKeepers[i].size(); a++)
        {
          std::cout << " ";
        }
      }
      else
      {
        for (int a = 0; a < 20; a++)
        {
          std::cout << " ";
        }
      }

      if (i < allRounders.size())
      {
        std::cout << allRounders[i];
        for (int a = 0; a < 20 - allRounders[i].size(); a++)
        {
          std::cout << " ";
        }
      }
      else
      {
        for (int a = 0; a < 20; a++)
        {
          std::cout << " ";
        }
      }

      if (i < paceBowlers.size())
      {
        std::cout << paceBowlers[i];
        for (int a = 0; a < 20 - paceBowlers[i].size(); a++)
        {
          std::cout << " ";
        }
      }
      else
      {
        for (int a = 0; a < 20; a++)
        {
          std::cout << " ";
        }
      }

      if (i < spinBowlers.size())
      {
        std::cout << spinBowlers[i];
      }
      std::cout << std::endl;
    }
  }
  else
  {
    for (int i = 0; i < batsmen.size(); i++)
    {
      if (std::find(names[0].begin(), names[0].end(), batsmen[i]) != names[0].end())
      {
        std::cout << "\033[96m" << batsmen[i] << "\033[0m";
      }
      else if (std::find(names[1].begin(), names[1].end(), batsmen[i]) != names[1].end())
      {
        std::cout << "\033[92m" << batsmen[i] << "\033[0m";
      }
      else
      {
        std::cout << batsmen[i];
      }
      for (int a = 0; a < 20 - batsmen[i].size(); a++)
      {
        std::cout << " ";
      }

      if (i < wicketKeepers.size())
      {
        if (std::find(names[0].begin(), names[0].end(), wicketKeepers[i]) != names[0].end())
        {
          std::cout << "\033[96m" << wicketKeepers[i] << "\033[0m";
        }
        else if (std::find(names[1].begin(), names[1].end(), wicketKeepers[i]) != names[1].end())
        {
          std::cout << "\033[92m" << wicketKeepers[i] << "\033[0m";
        }
        else
        {
          std::cout << wicketKeepers[i];
        }
        for (int a = 0; a < 20 - wicketKeepers[i].size(); a++)
        {
          std::cout << " ";
        }
      }
      else
      {
        for (int a = 0; a < 20; a++)
        {
          std::cout << " ";
        }
      }

      if (i < allRounders.size())
      {
        if (std::find(names[0].begin(), names[0].end(), allRounders[i]) != names[0].end())
        {
          std::cout << "\033[96m" << allRounders[i] << "\033[0m";
        }
        else if (std::find(names[1].begin(), names[1].end(), allRounders[i]) != names[1].end())
        {
          std::cout << "\033[92m" << allRounders[i] << "\033[0m";
        }
        else
        {
          std::cout << allRounders[i];
        }
        for (int a = 0; a < 20 - allRounders[i].size(); a++)
        {
          std::cout << " ";
        }
      }
      else
      {
        for (int a = 0; a < 20; a++)
        {
          std::cout << " ";
        }
      }

      if (i < paceBowlers.size())
      {
        if (std::find(names[0].begin(), names[0].end(), paceBowlers[i]) != names[0].end())
        {
          std::cout << "\033[96m" << paceBowlers[i] << "\033[0m";
        }
        else if (std::find(names[1].begin(), names[1].end(), paceBowlers[i]) != names[1].end())
        {
          std::cout << "\033[92m" << paceBowlers[i] << "\033[0m";
        }
        else
        {
          std::cout << paceBowlers[i];
        }
        for (int a = 0; a < 20 - paceBowlers[i].size(); a++)
        {
          std::cout << " ";
        }
      }
      else
      {
        for (int a = 0; a < 20; a++)
        {
          std::cout << " ";
        }
      }

      if (i < spinBowlers.size())
      {
        if (std::find(names[0].begin(), names[0].end(), spinBowlers[i]) != names[0].end())
        {
          std::cout << "\033[96m" << spinBowlers[i] << "\033[0m";
        }
        else if (std::find(names[1].begin(), names[1].end(), spinBowlers[i]) != names[1].end())
        {
          std::cout << "\033[92m" << spinBowlers[i] << "\033[0m";
        }
        else
        {
          std::cout << spinBowlers[i];
        }
      }
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}
