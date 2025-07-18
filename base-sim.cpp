#include "main.h"

void baseSim()
{
  // The following are all the variable definitions. There are a TON
  int overNumber = 1; // This starts the overNumber as 1 so when the first over finishes it shows up as 1 over completed. I made this decision 3 years ago so I can't change it now but it was very stupid as it requires me to '-1' wherever I mention overNumber
  int ballNumber = 0;
  int runs = 0;
  int wickets = 0;
  int wicketsT = 0;        // Wickets lost in the last 25 balls
  int wicketsTCounter = 0; // Balls since the first 25 balls finished
  int innings = 1;
  int random = 0;  // Used for all the random number based calculations
  int oldRuns = 0; // Run count of first innings
  int overRuns = 0;
  int projected = 0; // Projected score variable used to output the various projected scores
  int counter = 0;   // A regular counter used everywhere in the program
  int balls = 0;

  // The following are all the maximum values that are calculated for each probability value (like if there is 10% chance of a single it will be from dotMax till dotMax + 100 (since full value is 1000))
  int dotMax = 0;
  int oMax = 0;
  int dMax = 0;
  int tMax = 0;
  int fMax = 0;
  int sMax = 0;
  int wMax = 0;
  // These are the actual probabilities that are changed
  float dotP = 0.0f;
  float oneP = 0.0f;
  float doubleP = 0.0f;
  float threeP = 0.0f;
  float fourP = 0.0f;
  float sixP = 0.0f;
  float wideP = 0.0f;

  double runRate = 0.0;

  bool e = false; // Used to check if 10 wickets have fallen
  bool strike = true;
  bool free = false;     // if a free hit
  bool changed = false;  // if wickets in hand at the ending of match
  bool collapse = false; // if in the last 25 balls 3 or more wickets have fallen
  bool added = false;    // if a wicket just fell last ball
  bool buffed = false;
  bool nerfed = false;

  // Used for all inputs
  std::string null = "";

  std::array<int, 2> current = {0, 0};              // Runs for both batsman on pitch
  std::array<int, 2> ballsB = {0, 0};               // Balls faced for both batsman on pitch
  std::array<int, 2> index = {0, 1};                // Index in the names list for both batsman on pitch
  std::array<int, 2> notOut = {0, 0};               // Notes if the ending scorecard has a player out or not out (like if it ended with wicket or not)
  std::array<std::vector<char>, maxOvers> timeline; // Innings timeline
  // Tracks the fall of wickets and all the stats
  std::array<std::vector<std::array<int, 5>>, 2> fallOW = std::array<std::vector<std::array<int, 5>>, 2>();
  // 1 if the batsman has stepped onto the pitch (for the third index of each array) and 0 if they haven't
  std::array<std::array<std::array<int, 3>, 11>, 2> teams = {{{{{{0, 0, 1}}, {{0, 0, 1}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}}}, {{{{0, 0, 1}}, {{0, 0, 1}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}}}}};
  // Saves all the partnerships
  std::vector<std::array<int, 4>> partnerships = std::vector<std::array<int, 4>>();

  std::array<int, 4> partnership = {0, 0, 0, 0}; // Saves current partnership
  std::array<int, 4> savedP = {0, 0, 0, 0};      // Saves largest partnership of first innings

  // A randomizing method that is seeded by the header file inline function
  std::uniform_int_distribution<> dist(1, 1000);
  std::uniform_int_distribution<> two(1, 2);

  float mOvers = maxOvers;
  float average = 211 * (mOvers / 20); // Sets the par score as 211 and the following higherScore and lowerScore decide boundaries for a buff or nerf to chasing team to make the match closer
  int higherScore = static_cast<int>((6.75 / 6) * average);
  int lowerScore = static_cast<int>((5.25 / 6) * average);

  // Names array that can be manually changed by user if they want to play with different batsmen
  std::array<std::array<std::string, 11>, 2> names = {{{"Rohit Sharma", "Quinton de Kock", "Suryakumar Yadav", "Ishan Kishan", "Kieron Pollard", "Hardik Pandya", "Krunal Pandya", "Nathan Coulter-Nile", "Rahul Chahar", "Trent Boult", "Jasprit Bumrah"}, {"Ruturaj Gaikwad", "Devon Conway", "Shivam Dube", "Ajinkya Rahane", "Ambati Rayudu", "MS Dhoni", "Ravindra Jadeja", "Deepak Chahar", "Matheesha Pathirana", "Tushar Deshpande", "Maheesh Theekshana"}}};

  random = two(global_rng());

  // Coin flip system
  std::getline(std::cin, null);
  if (random == 1)
  {
    std::cout << "Player 1: Choose heads (h) or tails (t) and enter to continue when ready.\n";
  }
  else
  {
    std::cout << "Player 2: Choose heads (h) or tails (t) and enter to continue when ready.\n";
  }
  std::cin >> null;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("cls");
  }

  if ((counter == 1 && null == "bowl") || (counter == 2 && null == "bat"))
  {
    // Swaps the first and second array of the function based on who is batting and bowling first
    std::swap(names[0], names[1]);
  }
  counter = 0;

  // The while loop containing most of my code
  while (innings < 3)
  {
    std::cout << "INNINGS NUMBER " << innings << "\n";

    // Setted nerfed and buffed values based on the par score and runs scored in first innings
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

    std::cout << "\nEnter to Continue\n";
    std::getline(std::cin, null);
    system("cls");

    // While loops for all the balls in an over
    while (overNumber <= maxOvers)
    {
      while (ballNumber < 6)
      {
        // This is the random value that is between 1-1000 that is used to decide what this ball's outcome is
        random = dist(global_rng());

        // Setting collapse to true if it meets the conditions stated
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

        // The main attraction - weighted randoms
        // The weighted randoms are calculated based on the random number that was generated. As it was from 1 - 1000 the weighted randoms work by saying if the number was in this range, it outputs this many runs or wicket or dot or wide
        // The first few overs are buffed for powerplay, the next few get regular probabilities, and the last few are buffed for death

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

        // Below modifies the values based on the special changes like a free hit, collapse, etc

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

        if (free)
        {
          dotP = 0.1f;
          oneP = 0.15f;
          doubleP = 0.18f;
          fourP = 0.25f;
          sixP = 0.2f;
          wideP = 0.015f;
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

        // This calculates the ranges that are used below for ball outcome
        dotMax = static_cast<int>(1000 * dotP);
        oMax = static_cast<int>((1000 * oneP) + dotMax);
        dMax = static_cast<int>((1000 * doubleP) + oMax);
        tMax = static_cast<int>((1000 * threeP) + dMax);
        fMax = static_cast<int>((1000 * fourP) + tMax);
        sMax = static_cast<int>((1000 * sixP) + fMax);
        wMax = static_cast<int>((1000 * wideP) + sMax);

        if (random <= dotMax)
          e = outPutRuns("sim", 5, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, "");
        else if (random > dotMax && random <= oMax)
          e = outPutRuns("sim", 1, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, "");
        else if (random > oMax && random <= dMax)
          e = outPutRuns("sim", 2, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, "");
        else if (random > dMax && random <= tMax)
          e = outPutRuns("sim", 3, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, "");
        else if (random > tMax && random <= fMax)
          e = outPutRuns("sim", 4, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, "");
        else if (random > fMax && random <= sMax)
          e = outPutRuns("sim", 6, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, "");
        else if (random > sMax && random <= wMax)
          e = outPutRuns("sim", 7, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, "");
        else if (random > wMax)
        {
          e = outPutRuns("sim", 8, timeline, overRuns, runs, overNumber, ballNumber, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free, fallOW, wicketsT, wicketsTCounter, added, names, "");
          if (e == true)
            break;
        }

        // Checks if won
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
          std::cout << "\nRuns to Win: " << ((oldRuns + 1) - runs) << " from " << ((maxOvers * 6) - (((overNumber - 1) * 6) + ballNumber)) << " balls\n";
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

      // Checking if won or all out again
      if ((wickets == 10) || (innings == 2) && (runs > oldRuns))
        break;

      // Timeline after every over
      for (int i = 0; i < timeline[overNumber - 2].size(); i++)
      {
        if ((i + 1) != timeline[overNumber - 2].size())
        {
          // If the timeline has an 'n' in the next index, we skip that index and replace it with a * instead
          if (timeline[overNumber - 2][i + 1] == 'n')
          {
            std::cout << timeline[overNumber - 2][i] << "* ";
            i++;
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
          runRate = static_cast<double>(oldRuns - runs + 1) / static_cast<double>(maxOvers - (overNumber - 1));
          runRate = std::round(runRate * 100.0) / 100.0;
          std::cout << "Required run rate: " << runRate << "\n";
        }
        std::cout << "\nRuns to Win: " << ((oldRuns + 1) - runs) << " from " << ((maxOvers * 6) - (((overNumber - 1) * 6) + ballNumber)) << " balls\n";
      }
      else
      {
        // Outputting and calculating the projected scores
        projected = static_cast<int>(runRate * maxOvers);
        std::cout << "Projected score at current run rate: " << projected << "\n";
        projected = static_cast<int>(runs + static_cast<double>(10.9 * (maxOvers + 1 - overNumber)));
        std::cout << "Projected score at par run rate : " << projected << "\n";
        projected = static_cast<int>(runs + static_cast<double>(13 * (maxOvers + 1 - overNumber)));
        std::cout << "Projected score at high run rate (13): " << projected << "\n";
      }
      // Switching strike after over finished
      strike = !strike;
      // Setting changed to true if a few overs are left and many wickets are in hand
      if (!changed && (overNumber == 18 && wickets <= 3) || (overNumber == 17 && wickets <= 2))
      {
        changed = true;
      }
      std::cout << "\nEnter to Continue\n";
      std::getline(std::cin, null);
      overRuns = 0;
      system("cls");
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
      // Adding the final partnership to the main partnership variable to find the largest partnership
      partnerships.push_back(partnership);
    }

    // Scorecard outputting everything (should be self-explanatory)
    if (innings == 1)
    {
      std::cout << "\nSCORECARD\n---------" << std::endl;
      while (teams[0][counter][2] != 0)
      {
        if (counter == index[0] || counter == index[1])
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

    // Printing out the fall of wickets
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

    // Full innings timeline
    std::cout << "Do you want the full innings timeline(y/n): ";
    std::cin >> null;
    std::cout << "\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    overNumber--;
    // So 21 overs becomes 20 and 20.3 becomes 19.3

    if (null == "y")
    {
      for (int x = 0; x < overNumber; x++)
      {
        for (int i = 0; i < timeline[x].size(); i++)
        {
          // Adds up the amount of runs in the over so it can be displayed at the end of the timeilne
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
    for (int i = 0; i < timeline.size(); i++)
    {
      timeline[i].clear();
    }

    // The following is super over implementation
    if (innings == 2 && runs == oldRuns)
    {
      std::cout
          << "SUPER OVER\n----------\nFirst, we will let players decide "
             "batsmen. Enter corresponding batting order position\n";
      std::cout << "\nEnter to Continue\n";
      std::getline(std::cin, null);
      system("cls");

      // Initiatlizing variables required for super over
      std::array<std::array<std::array<int, 3>, 3>, 2> superTeams = {{{{{{0, 0, 1}}, {{0, 0, 1}}, {{0, 0, 0}}}}, {{{{0, 0, 1}}, {{0, 0, 1}}, {{0, 0, 0}}}}}};
      std::array<std::vector<char>, 2> sOverT;
      std::array<std::array<std::string, 3>, 2> superOver = {{{"", "", ""}, {"", "", ""}}};

      // System for selecting batsmen for super over
      for (int x = 1; x < 3; x++)
      {
        std::cout << "Player " << x << "\n--------\n";
        for (int i = 1; i < 4; i++)
        {
          std::cout << "Batsman " << i << ": ";
          std::cin >> null;
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

      // Special super over probabilities
      dotP = 0.16f;
      oneP = 0.15f;
      doubleP = 0.15f;
      threeP = 0.005f;
      fourP = 0.25f;
      sixP = 0.17f;
      wideP = 0.015f;

      dotMax = static_cast<int>(1000 * dotP);
      oMax = static_cast<int>((1000 * oneP) + dotMax);
      dMax = static_cast<int>((1000 * doubleP) + oMax);
      tMax = static_cast<int>((1000 * threeP) + dMax);
      fMax = static_cast<int>((1000 * fourP) + tMax);
      sMax = static_cast<int>((1000 * sixP) + fMax);
      wMax = static_cast<int>((1000 * wideP) + sMax);

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

      // Printing output of super over
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
      // Don't need to reset variables since the sim restarts and no variable is static
    }
    oldRuns = runs;
    runs = 0;
    innings++;
  }
}