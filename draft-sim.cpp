#include "main.h"

std::string toLower(std::string str);

void draftSim()
{
  int overNumber = 1; // This is dumb, I know, and it makes me have to do - 1 wherever I mention overNumber, but I am too lazy to fix it everywhere
  int ballNumber = 0;
  int runs = 0;
  int wickets = 0;
  int wicketsT = 0;
  int oldWickets = 0;
  int wicketsTCounter = 0;
  int innings = 1;
  int bowlerInnings = 0;
  int random = 0;
  int oldRuns = 0;
  int overRuns = 0;
  int projected = 0;
  int extras = 0;
  int counter = 0;
  int balls = 0;
  int gillStarted = 300;
  int gillUp = 0;
  int hardikStarted = 300;
  int hardikUp = 0;
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
  double requiredRR = 0.0;
  double economy = 0.0;

  bool e = false;
  bool strike = true;
  bool free = false;
  bool changed = false;
  bool collapse = false;
  bool added = false;
  bool buffed = false;
  bool nerfed = false;
  bool flashP = false;
  bool debug = false;

  std::string null = "";
  std::string bowlerName = "";

  std::array<int, 2> current = {0, 0};
  std::array<int, 2> ballsB = {0, 0};
  std::array<int, 2> index = {0, 1};
  std::array<int, 2> notOut = {0, 0};
  std::array<int, 3> chemistryPartner = {12, 0, 0};
  std::array<std::vector<int>, 2> bowlerNames = std::array<std::vector<int>, 2>();
  std::array<std::unordered_map<std::string, int>, 2> bowlers = std::array<std::unordered_map<std::string, int>, 2>();
  std::array<std::vector<char>, maxOvers> timeline; // Had to change this to a 2d array as wides were causing multiple issues
  std::array<std::vector<std::array<int, 5>>, 2> fallOW = std::array<std::vector<std::array<int, 5>>, 2>();
  std::array<std::array<std::array<int, 3>, 11>, 2> teams = {{{{{{0, 0, 1}}, {{0, 0, 1}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}}}, {{{{0, 0, 1}}, {{0, 0, 1}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}}}}};
  std::array<std::vector<std::array<int, 6>>, 2> bowlerStats = std::array<std::vector<std::array<int, 6>>, 2>();
  std::vector<std::array<int, 4>> partnerships = std::vector<std::array<int, 4>>();

  std::array<int, 4> partnership = {0, 0, 0, 0};
  std::array<int, 4> savedP = {0, 0, 0, 0};

  // Making rand() actually random (it adds a seed which is based on the time which changes every second)
  std::mt19937 gen(std::random_device{}());
  std::uniform_int_distribution<> dist(1, 10000);
  std::uniform_int_distribution<> two(1, 2);

  // Making the average number of runs for that over number
  float mOvers = maxOvers;
  float average = 211 * (mOvers / 20);
  int higherScore = static_cast<int>((6.75 / 6) * average);
  // std::cout << higherScore << std::endl;
  int lowerScore = static_cast<int>((5.25 / 6) * average);

  std::array<std::array<std::string, 11>, 2> names = {{{"", "", "", "", "", "", "", "", "", "", ""}, {"", "", "", "", "", "", "", "", "", "", ""}}};
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
      {"hetmeyer", "Shimron Hetmyer"},
      {"abd", "AB de Villiers"},
      {"shreyas", "Shreyas Iyer"},
      {"dube", "Shivam Dube"},
      {"abhishek", "Abhishek Sharma"},
      {"warner", "David Warner"},
      {"gayle", "Chris Gayle"},
      // Wicket Keepers (full + first)
      {"msd", "MS Dhoni"},
      {"dhoni", "MS Dhoni"},
      {"kl", "KL Rahul"},
      {"pant", "Rishabh Pant"},
      {"buttler", "Jos Buttler"},
      {"phil", "Phil Salt"},
      {"salt", "Phil Salt"},
      {"klaasen", "Heinrich Klaasen"},
      {"sanju", "Sanju Samson"},
      {"quinton", "Quinton de Kock"},
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
      {"jansen", "Marco Jansen"},
      {"chahar", "Deepak Chahar"},
      {"arshdeep", "Arshdeep Singh"},
      {"bumrah", "Jasprit Bumrah"},
      // Spin Bowlers (full + first)
      {"hasaranga", "Wanindu Hasaranga"},
      {"axar", "Axar Patel"},
      {"rashid", "Rashid Khan"},
      {"chahal", "Yuzvendra Chahal"},
      {"narine", "Sunil Narine"},
      {"kuldeep", "Kuldeep Yadav"},
      {"ashwin", "Ravichandran Ashwin"},
      {"varun", "Varun Chakravarthy"},
      {"shane", "Shane Warne"},
  };

  // Draft
  std::cout << "+-----------------------+\n| ___            __ _   |\n||   \\ _ _ __ _ / _| |_ |\n|| |) | '_/ _` |  _|  _||\n||___/|_| \\__,_|_|  \\__||\n+-----------------------+\n\n";

  std::cout << "Batsmen             Wicket Keepers      All Rounders        Pace Bowlers        Spin Bowlers\n--------            ---------------     -------------       -------------       -------------\nRuturaj Gaikwad     MS Dhoni            Ravindra Jadeja     Dale Steyn          Wanindu Hasaranga\nVirat Kohli         KL Rahul            Hardik Pandya       Lasith Malinga      Axar Patel\nRohit Sharma        Rishabh Pant        Shakib Al Hasan     Trent Boult         Rashid Khan\nSai Sudharsan       Jos Buttler         Glenn Maxwell       Mitchell Starc      Yuzvendra Chahal\nTravis Head         Phil Salt           Ben Stokes          Mohammed Shami      Sunil Narine\nSuryakumar Yadav    Heinrich Klaasen    Andre Russell       Bhuvneshwar Kumar   Kuldeep Yadav\nNicholas Pooran     Sanju Samson        Dwayne Bravo        Mohammed Siraj      Ravichandran Ashwin\nShubman Gill        Quinton de Kock     Shane Watson        Jofra Archer        Varun Chakravarthy\nYashasvi Jaiswal                        Kieron Pollard      Marco Jansen        Shane Warne\nShimron Hetmyer                         Washington Sundar   Deepak Chahar\nAB de Villiers                                              Arshdeep Singh\nShreyas Iyer                                                Jasprit Bumrah\nShivam Dube\nAbhishek Sharma\nDavid Warner\nChris Gayle\n\n";
  random = two(gen);
  std::cout << "Player " << random << " make the first pick: ";
  std::cin >> null;
  if (null == "debug")
  {
    debug = true;
    // names = {{{"Rohit Sharma", "Quinton de Kock", "Suryakumar Yadav", "Glenn Maxwell", "Kieron Pollard", "Hardik Pandya", "Heinrich Klaasen", "Rashid Khan", "Axar Patel", "Trent Boult", "Jasprit Bumrah"}, {"Ruturaj Gaikwad", "Sai Sudharsan", "Shivam Dube", "Nicholas Pooran", "Shakib Al Hasan", "MS Dhoni", "Ravindra Jadeja", "Deepak Chahar", "Mohammed Siraj", "Lasith Malinga", "Varun Chakravarthy"}}};
    // names = {{{"Shubman Gill", "Yashasvi Jaiswal", "KL Rahul", "AB de Villiers", "Rishabh Pant", "Washington Sundar", "Dwayne Bravo", "Sunil Narine", "Marco Jansen", "Jofra Archer", "Arshdeep Singh"}, {"David Warner", "Chris Gayle", "Phil Salt", "Virat Kohli", "Ben Stokes", "Shimron Hetmeyer", "Wanindu Hasaranga", "Kuldeep Yadav", "Bhuvneshwar Kumar", "Mitchell Starc", "Shane Warne"}}};
    names = {{{"Shubman Gill", "Yashasvi Jaiswal", "KL Rahul", "AB de Villiers", "Rishabh Pant", "Washington Sundar", "Dwayne Bravo", "Sunil Narine", "Marco Jansen", "Jofra Archer", "Arshdeep Singh"}, {"Travis Head", "Shane Watson", "Jos Buttler", "Abhishek Sharma", "Shreyas Iyer", "Sanju Samson", "Andre Russell", "Ravichandran Ashwin", "Dale Steyn", "Mohammed Shami", "Yuzvendra Chahal"}}};
  }
  else if (players.contains(toLower(null)))
  {
    names[random - 1][0] = players[null];
  }
  else
  {
    while (!players.contains(toLower(null)))
    {
      std::cout << "Enter a proper name or enter the full name\nPlayer " << random << " make the first pick: ";
      std::cin >> null;
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
    std::cout << "Batsmen             Wicket Keepers      All Rounders        Pace Bowlers        Spin Bowlers\n--------            ---------------     -------------       -------------       -------------\nRuturaj Gaikwad     MS Dhoni            Ravindra Jadeja     Dale Steyn          Wanindu Hasaranga\nVirat Kohli         KL Rahul            Hardik Pandya       Lasith Malinga      Axar Patel\nRohit Sharma        Rishabh Pant        Shakib Al Hasan     Trent Boult         Rashid Khan\nSai Sudharsan       Jos Buttler         Glenn Maxwell       Mitchell Starc      Yuzvendra Chahal\nTravis Head         Phil Salt           Ben Stokes          Mohammed Shami      Sunil Narine\nSuryakumar Yadav    Heinrich Klaasen    Andre Russell       Bhuvneshwar Kumar   Kuldeep Yadav\nNicholas Pooran     Sanju Samson        Dwayne Bravo        Mohammed Siraj      Ravichandran Ashwin\nShubman Gill        Quinton de Kock     Shane Watson        Jofra Archer        Varun Chakravarthy\nYashasvi Jaiswal                        Kieron Pollard      Marco Jansen        Shane Warne\nShimron Hetmyer                         Washington Sundar   Deepak Chahar\nAB de Villiers                                              Arshdeep Singh\nShreyas Iyer                                                Jasprit Bumrah\nShivam Dube\nAbhishek Sharma\nDavid Warner\nChris Gayle\n\n";
    random == 1 ? random = 2 : random = 1;
    if (i == 22)
    {
      std::cout << "Player " << random << " make the last pick: ";
      std::cin >> null;
      if (players.contains(toLower(null)))
      {
        names[random - 1][10] = players[null];
      }
      else
      {
        while (!players.contains(toLower(null)))
        {
          std::cout << "Enter a proper name or enter the full name\nPlayer " << random << " make the last pick: ";
          std::cin >> null;
        }
        names[random - 1][10] = players[null];
      }
      break;
    }

    for (int j = 0; j < 2; j++)
    {
      std::cout << "Player " << random << " make pick " << i << ": ";
      std::cin >> null;
      if (players.contains(toLower(null)))
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
        while (!players.contains(toLower(null)))
        {
          std::cout << "Enter a proper name or enter the full name\nPlayer " << random << " make pick " << i << ": ";
          std::cin >> null;
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
      i++;
    }
    i--;
    system("cls");
  }

  std::cout << "\nEnter to Continue\n";
  std::getline(std::cin, null);
  system("cls");

  random = two(gen);
  // Let The Games Begin!
  // My friend gave me the obvious idea of a coin flip which my dumb brain forgot
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

  random = two(gen);
  if (random == 1)
  {
    std::cout << "Heads!\n";
    if (counter == 1)
    {
      if (null == "h")
      {
        std::cout << "Player 1: Choose batting (bat) or bowling (bowl).\nEnter to Continue\n";
      }
      else
      {
        std::cout << "Player 2: Choose batting (bat) or bowling (bowl).\nEnter to Continue\n";
        counter = 2;
      }
    }
    else
    {
      if (null == "h")
      {
        std::cout << "Player 2: Choose batting (bat) or bowling (bowl).\nEnter to Continue\n";
        counter = 2;
      }
      else
      {
        std::cout << "Player 1: Choose batting (bat) or bowling (bowl).\nEnter to Continue\n";
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
        std::cout << "Player 2: Choose batting (bat) or bowling (bowl).\nEnter to Continue\n";
        counter = 2;
      }
      else
      {
        std::cout << "Player 1: Choose batting (bat) or bowling (bowl).\nEnter to Continue\n";
      }
    }
    else
    {
      if (null == "h")
      {
        std::cout << "Player 1: Choose batting (bat) or bowling (bowl).\nEnter to Continue\n";
        counter = 1;
      }
      else
      {
        std::cout << "Player 2: Choose batting (bat) or bowling (bowl).\nEnter to Continue\n";
        counter = 2;
      }
    }
    std::cin >> null;
    system("cls");
  }

  if ((counter == 1 && null == "bowl") || (counter == 2 && null == "bat"))
  {
    std::swap(names[0], names[1]);
  }

  counter = 0;
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
  // The while loop containing most of our code
  while (innings < 3)
  {
    // Start of innings
    std::cout << "INNINGS NUMBER " << innings << "\n";

    // While loops for our over number and ball number
    if (oldRuns >= higherScore && innings == 2)
    {
      buffed = true;
      std::cout << "\nThe chasing team has been buffed due to a score high above par!\n";
    }
    else if (oldRuns <= lowerScore && innings == 2)
    {
      nerfed = true;
      std::cout << "\nThe chasing team has been nerfed due to a score much lower than par!\n";
    }

    innings == 1 ? bowlerInnings = 1 : bowlerInnings = 0;
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

    while (overNumber <= maxOvers)
    {
      while (ballNumber < 6)
      {
        random = dist(gen);

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

        if ((chemistryPartner[0] == 12) && (partnership[0] >= 50) && (names[innings - 1][index[0]] == "AB de Villiers" || names[innings - 1][index[1]] == "AB de Villiers"))
        {
          chemistryPartner[0] = index[0];
          chemistryPartner[1] = index[1];
        }
        else if (chemistryPartner[0] != 12 && (chemistryPartner[0] != index[0] || chemistryPartner[1] != index[1]) && chemistryPartner[2] == 0)
        {
          chemistryPartner[2] = 1;
        }

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

        // The main attraction - weighted randoms
        // The weighted randoms are calculated based on the random number that was generated. As it was from 1 - 100 the weighted randoms work by saying if the number was in this range, it outputs this many runs or wicket or dot
        // The first three are buffed for powerplay, and after that the next two are buffs and nerfs incase the first team plays good or bad

        if ((index[0] < 7 && strike) || (index[1] < 7 && !strike))
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

        if (free)
        {
          dotP = 0.1f;
          oneP = 0.15f;
          doubleP = 0.18f;
          fourP = 0.25f;
          sixP = 0.2f;
          wideP = 0.015f;
        }

        // std::cout << "Makes it here\n";
        strike ? playerMods(names[innings - 1][index[0]], names[innings - 1][index[1]], bowlerName, dotP, oneP, doubleP, threeP, fourP, sixP, wideP, ballsB[0], current[0], overNumber, ballNumber, gillUp, hardikUp, partnership[0], runRate, requiredRR, Players[bowlerName].pace, added, flashP, chemistryPartner[2], Players) : playerMods(names[innings - 1][index[1]], names[innings - 1][index[0]], bowlerName, dotP, oneP, doubleP, threeP, fourP, sixP, wideP, ballsB[1], current[1], overNumber, ballNumber, gillUp, hardikUp, partnership[0], runRate, requiredRR, Players[bowlerName].pace, added, flashP, chemistryPartner[2], Players);

        dotMax = static_cast<int>(10000 * dotP);
        oMax = static_cast<int>((10000 * oneP) + dotMax);
        dMax = static_cast<int>((10000 * doubleP) + oMax);
        tMax = static_cast<int>((10000 * threeP) + dMax);
        fMax = static_cast<int>((10000 * fourP) + tMax);
        sMax = static_cast<int>((10000 * sixP) + fMax);
        wMax = static_cast<int>((10000 * wideP) + sMax);
        std::cout << dotMax << " " << oMax << " " << dMax << " " << tMax << " " << fMax << " " << sMax << " " << wMax << std::endl;

        if (random <= dotMax)
          e = outPutRuns(5, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names);
        else if (random > dotMax && random <= oMax)
          e = outPutRuns(1, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names);
        else if (random > oMax && random <= dMax)
          e = outPutRuns(2, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names);
        else if (random > dMax && random <= tMax)
          e = outPutRuns(3, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names);
        else if (random > tMax && random <= fMax)
          e = outPutRuns(4, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names);
        else if (random > fMax && random <= sMax)
          e = outPutRuns(6, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names);
        else if (random > sMax && random <= wMax)
          e = outPutRuns(7, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names);
        else if (random > wMax)
        {
          e = outPutRuns(8, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names);
          if (e == true)
            break;
        }

        // Check if won
        if (innings == 2)
        {
          if (runs > oldRuns)
          {
            std::cout << "\nEnter to Continue\n";
            std::getline(std::cin, null);
            system("cls");
            break;
          }
          // Printing out the amount of runs left to win if in the second innings
          std::cout << "\nRuns to Win: " << ((oldRuns + 1) - runs) << "\n";
        }
        std::cout << "\nEnter to Continue\n";
        std::getline(std::cin, null);
        system("cls");
      }

      // Increasing over number if six balls were finished
      if (ballNumber == 6)
      {
        ballNumber = 0;
        overNumber++;
      }

      bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][0]++;
      if (overRuns == 0)
      {
        bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][2]++;
      }
      bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][3] += overRuns;
      bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][4] += wickets - oldWickets;
      oldWickets = wickets;

      // Checking if won or all out again
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

      // Timeline after every over
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

      bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][5] += extras;
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
        std::cout << "Runs to Win: " << ((oldRuns + 1) - runs) << "\n";
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

    // Printing out results
    if (wickets == 10)
    {
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

    // Adding runs from last 2 batsmen
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
      bowlerStats[bowlerInnings][bowlers[bowlerInnings][bowlerName]][1] = ballNumber;
      std::cout << ballNumber << std::endl;
    }

    // Scorecard
    if (innings == 1)
    {
      std::cout << "\nSCORECARD\n---------" << std::endl;
      counter = 0;
      while (teams[0][counter][2] != 0)
      {
        if (counter == index[0] || counter == index[1])
          std::cout << names[0][counter] << ": " << teams[0][counter][0] << " in " << teams[0][counter][1] << "\n";
        else
          std::cout << names[0][counter] << ": " << teams[0][counter][0] << " in " << teams[0][counter][1] << " - OUT\n";
        counter++;
        if (counter == 11)
        {
          break;
        }
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
      while (teams[0][counter][2] != 0)
      {
        if (counter == notOut[0] || counter == notOut[1])
        {
          std::cout << names[0][counter] << ": " << teams[0][counter][0] << " in " << teams[0][counter][1] << "\n";
        }
        else
        {
          std::cout << names[0][counter] << ": " << teams[0][counter][0] << " in " << teams[0][counter][1] << " - OUT\n";
        }
        counter++;
        if (counter == 11)
        {
          break;
        }
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

      while (teams[1][counter][2] != 0)
      {
        if (counter == index[0] || counter == index[1])
        {
          std::cout << names[1][counter] << ": " << teams[1][counter][0] << " in " << teams[1][counter][1] << "\n";
        }
        else
        {
          std::cout << names[1][counter] << ": " << teams[1][counter][0] << " in " << teams[1][counter][1] << " - OUT\n";
        }
        counter++;
        if (counter == 11)
        {
          break;
        }
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

    // Printing out largest partnership

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

    // Full innings timeline
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
      // This is for the reduced number of balls in an over due to all out
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

    //// Buffs and nerfs to chasing team incase batting team op or bad
    // if (innings == 1 && runs > higherScore)
    //	std::cout << "Chasing team will now get {buffed} as the score was above " << higherScore << "!\n";
    // else if (innings == 1 && runs < lowerScore)
    //	std::cout << "Chasing team will now get {nerfed} as the score was sub " << lowerScore << "!\n";

    // Resetting all variables
    current[0] = 0;
    ballsB[0] = 0;
    current[1] = 0;
    ballsB[1] = 0;
    index[0] = 0;
    index[1] = 1;
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
        random = dist(gen);

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
        random = dist(gen);

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

std::string toLower(std::string str)
{
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
}
