// Imports
#include <iostream>

#include <cstdlib>

#include <time.h>

#include <vector>

#include <string>

#include <cmath>

// #include <print>

// Change this to change the number of overs in the match
const int maxOvers = 20;

using array_type = char[maxOvers][100];

// const std::string names[2][11] = { {"Batsman 1", "Batsman 2", "Batsman 3", "Batsman 4", "Batsman 5", "Batsman 6", "Batsman 7", "Batsman 8", "Batsman 9", "Batsman 10", "Batsman 11"}, {"Batsman 1", "Batsman 2", "Batsman 3", "Batsman 4", "Batsman 5", "Batsman 6", "Batsman 7", "Batsman 8", "Batsman 9", "Batsman 10", "Batsman 11"} };
const std::string names[2][11] = {{"Rohit Sharma", "Quinton de Kock", "Suryakumar Yadav", "Ishan Kishan", "Kieron Pollard", "Hardik Pandya", "Krunal Pandya", "Nathan Coulter-Nile", "Rahul Chahar", "Trent Boult", "Jasprit Bumrah"}, {"Ruturaj Gaikwad", "Devon Conway", "Shivam Dube", "Ajinkya Rahane", "Ambati Rayudu", "MS Dhoni", "Ravindra Jadeja", "Deepak Chahar", "Matheesha Pathirana", "Tushar Deshpande", "Maheesh Theekshana"}};

bool outPutRuns(int x, array_type &array, int &runO, int &runT, int overN, int &ballN, int &ballW, int &outs, int (&batsmen)[2], int (&index)[2], bool &on, std::vector<std::vector<std::vector<int>>> &team, int inning, int (&balls)[2], std::vector<int> &partner, std::vector<std::vector<int>> &partners, bool &fHit);
bool superO(int x, char (&array)[2][100], int &runO, int &ballN, int &ballW, int &outs, int (&batsmen)[2], int (&index)[2], bool &on, std::vector<std::vector<std::vector<int>>> &team, int inning, int (&balls)[2], std::vector<int> &partner, std::string nNames[2][3], bool &fHit);

int main()
{
  system("cls");
  // Variable Declaration
  int overNumber = 1; // This is dumb, I know, and it makes me have to do - 1 wherever I mention overNumber, but I am too lazy to fix it everywhere
  int ballNumber = 0;
  int runs = 0;
  int wickets = 0;
  int innings = 1;
  int random = 0;
  int oldRuns = 0;
  int overRuns = 0;
  int wideBalls = 0;
  int overBalls = 0;
  int counter = 0;

  int dotMax = 0;
  int oMax = 0;
  int dMax = 0;
  int tMax = 0;
  int fMax = 0;
  int sMax = 0;
  int wMax = 0;

  double runRate = 0.0;

  array_type timeline; // Had to change this to a 2d array as wides were causing multiple issues

  bool e = false;
  bool strike = true;
  bool free = false;

  std::string null = "";

  int vOverBalls[maxOvers];

  int current[2] = {0, 0};
  int ballsB[2] = {0, 0};
  int index[2] = {0, 1};
  int notOut[2] = {0, 0};
  std::vector<std::vector<std::vector<int>>> teams = {{{0, 0, 1}, {0, 0, 1}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{0, 0, 1}, {0, 0, 1}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
  std::vector<std::vector<int>> partnerships = std::vector<std::vector<int>>();

  std::vector<int> partnership = {0, 0, 0, 0};
  std::vector<int> savedP = {0, 0, 0, 0};

  time_t nTime;

  // Making rand() actually random (it adds a seed which is based on the time which changes every second)
  std::srand((unsigned)time(&nTime));

  // Making the average number of runs for that over number
  float mOvers = maxOvers;
  float average = 218 * (mOvers / 20);
  int higherScore = (7.0 / 6) * average;
  // std::cout << higherScore << std::endl;
  int lowerScore = (5.0 / 6) * average;
  // std::cout << lowerScore << std::endl;

  // Intro screen timeeee
  while (null != "4")
  {
    std::cout << "   ___                 \\             .   \n .'   \\ .___  `   ___  |   ,   ___  _/_  \n |      /   \\ | .'   ` |  /  .'   `  |   \n |      |   ' | |      |-<   |----'  |   \n  `.__, /     /  `._.' /  \\_ `.___,  \\__/\n                                         \n   _____                    .           .                \n  (      ` , _ , _   ,   .  |     ___  _/_     __.  .___ \n   `--.  | |' `|' `. |   |  |    /   `  |    .'   \\ /   \\\n      |  | |   |   | |   |  |   |    |  |    |    | |   '\n \\___.'  / /   '   / `._/| /\\__ `.__/|  \\__/  `._.' /    \n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n1. Start Simulator\n2. How to Play\n3. What is Cricket\n4. Exit\n";
    std::cin >> null;
    system("cls");

    switch (std::stoi(null))
    {
    case 1:
      innings = 1;
      teams = {{{0, 0, 1}, {0, 0, 1}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{0, 0, 1}, {0, 0, 1}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
      savedP = {0, 0, 0, 0};
      // Let The Games Begin!
      // My friend gave me the obvious idea of a coin flip which my dumb brain forgot
      std::getline(std::cin, null);
      std::cout << "Choose heads or tails and enter to continue when ready.\n";
      std::getline(std::cin, null);
      system("cls");

      random = std::rand() % 2 + 1;
      if (random == 1)
      {
        std::cout << "Heads\nChoose batting or bowling...\nEnter to Continue\n";
        std::getline(std::cin, null);
        system("cls");
      }
      else
      {
        std::cout << "Tails\nChoose batting or bowling...\nEnter to Continue\n";
        std::getline(std::cin, null);
        system("cls");
      }

      // The while loop containing most of our code
      while (innings < 3)
      {
        // Start of innings
        std::cout << "INNINGS NUMBER " << innings << "\n\n";

        // While loops for our over number and ball number
        while (overNumber <= maxOvers)
        {
          while (ballNumber < 6)
          {
            // Getting the random number from 0 - 100, then adding it by 1 so it is from 1 - 101 NOT INCLUDING 101
            random = std::rand() % 1000 + 1;

            // The main attraction - weighted randoms
            // The weighted randoms are calculated based on the random number that was generated. As it was from 1 - 100 the weighted randoms work by saying if the number was in this range, it outputs this many runs or wicket or dot
            // The first three are buffed for powerplay, and after that the next two are buffs and nerfs incase the first team plays good or bad

            if ((innings == 2 && oldRuns > higherScore) && (overNumber <= (maxOvers / 4) || overNumber > (maxOvers - 2)))
            {
              std::cout << "POWERPLAY\n---------\n";
              dotMax = 170;
              oMax = 400;
              dMax = 480;
              tMax = 485;
              fMax = 720;
              sMax = 860;
              wMax = 890;
            }
            else if ((innings == 2 && oldRuns < lowerScore) && (overNumber <= (maxOvers / 4) || overNumber > (maxOvers - 2)))
            {
              std::cout << "POWERPLAY\n---------\n";
              dotMax = 250;
              oMax = 470;
              dMax = 570;
              tMax = 575;
              fMax = 770;
              sMax = 880;
              wMax = 900;
            }
            else if (overNumber <= (maxOvers / 4) || overNumber > (maxOvers - 2))
            {
              std::cout << "POWERPLAY\n---------\n";
              dotMax = 210;
              oMax = 410;
              dMax = 530;
              tMax = 535;
              fMax = 750;
              sMax = 870;
              wMax = 900;
            }
            else if (innings == 2 && oldRuns > higherScore)
            {
              dotMax = 260;
              oMax = 550;
              dMax = 630;
              tMax = 635;
              fMax = 820;
              sMax = 920;
              wMax = 940;
            }
            else if (innings == 2 && oldRuns < lowerScore)
            {
              dotMax = 350;
              oMax = 620;
              dMax = 720;
              tMax = 725;
              fMax = 880;
              sMax = 940;
              wMax = 950;
            }
            else if (overNumber > (maxOvers / 4) && overNumber <= (maxOvers - 2))
            {
              dotMax = 300;
              oMax = 570;
              dMax = 670;
              tMax = 675;
              fMax = 850;
              sMax = 930;
              wMax = 950;
            }

            if (free)
            {
              dotMax = 100;
              oMax = 250;
              dMax = 430;
              tMax = 435;
              fMax = 685;
              sMax = 885;
              wMax = 900;
            }

            if (random <= dotMax)
              e = outPutRuns(5, timeline, overRuns, runs, overNumber, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free);
            else if (random > dotMax && random <= oMax)
              e = outPutRuns(1, timeline, overRuns, runs, overNumber, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free);
            else if (random > oMax && random <= dMax)
              e = outPutRuns(2, timeline, overRuns, runs, overNumber, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free);
            else if (random > dMax && random <= tMax)
              e = outPutRuns(3, timeline, overRuns, runs, overNumber, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free);
            else if (random > tMax && random <= fMax)
              e = outPutRuns(4, timeline, overRuns, runs, overNumber, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free);
            else if (random > fMax && random <= sMax)
              e = outPutRuns(6, timeline, overRuns, runs, overNumber, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free);
            else if (random > sMax && random <= wMax)
              e = outPutRuns(7, timeline, overRuns, runs, overNumber, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free);
            else if (random > wMax)
            {
              e = outPutRuns(8, timeline, overRuns, runs, overNumber, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, partnerships, free);
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

          // vOverBalls is a vector which will contain each over's number of balls. This again is because of wides increasing the number of balls in an over. Also all out requires this
          overBalls = ballNumber + wideBalls;
          vOverBalls[overNumber - 1] = overBalls;
          // vOverBalls.push_back(overBalls);

          // Increasing over number if six balls were finished
          if (ballNumber == 6)
          {
            ballNumber = 0;
            overNumber++;
          }

          // Checking if won or all out again
          if ((wickets == 10) || ((innings == 2) && (runs > oldRuns)))
            break;
          else if ((innings == 2) && (runs > oldRuns))
            break;

          // Timeline after every over
          for (int i = 0; i < overBalls; i++)
          {
            if ((i + 1) != overBalls)
            {
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
            std::cout << "Runs to Win: " << ((oldRuns + 1) - runs) << "\n";
          }
          strike = !strike;
          std::cout << "\nEnter to Continue\n";
          std::getline(std::cin, null);
          overRuns = 0;
          wideBalls = 0;
          system("cls");
        }

        // Calculating run rate again
        runRate = static_cast<double>(runs) / static_cast<double>(((overNumber - 1) * 6 + ballNumber)) * static_cast<double>(6);
        runRate = std::round(runRate * 100.0) / 100.0;

        // Printing out results
        if (wickets == 10)
          if (ballNumber != 0)
            std::cout << "\nAll out at " << runs << " after " << overNumber - 1 << "." << ballNumber << " overs with a run rate of " << runRate << "!\n";
          else
            std::cout << "\nAll out at " << runs << " after " << overNumber - 1 << " overs with a run rate of " << runRate << "!\n";

        if (innings == 1 && wickets != 10)

          std::cout << "First innings up.\n"
                    << runs << "/" << wickets << " in " << maxOvers << " overs!\nRun rate : " << runRate << std::endl;
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
              std::cout << names[0][counter] << ": " << teams[0][counter][0] << " in " << teams[0][counter][1] << "\n";
            else
              std::cout << names[0][counter] << ": " << teams[0][counter][0] << " in " << teams[0][counter][1] << " - OUT\n";
            counter++;
            if (counter == 11)
            {
              break;
            }
          }
          std::cout << "\nLargest partnership: " << savedP[0] << " in " << savedP[1] << " between " << names[0][savedP[2]] << " and " << names[0][savedP[3]] << "\n\n";
          counter = 0;
          while (teams[1][counter][2] != 0)
          {
            if (counter == index[0] || counter == index[1])
              std::cout << names[1][counter] << ": " << teams[1][counter][0] << " in " << teams[1][counter][1] << "\n";
            else
              std::cout << names[1][counter] << ": " << teams[1][counter][0] << " in " << teams[1][counter][1] << " - OUT\n";
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

        // Full innings timeline
        std::cout << "Do you want the full innings timeline(y/n): ";
        std::cin >> null;
        std::cout << "\n";

        std::cin.ignore();

        overNumber--;

        if (null == "y")
        {
          for (int x = 0; x < overNumber; x++)
          {
            for (int i = 0; i < vOverBalls[x]; i++)
            {
              if ((i + 1) != vOverBalls[x])
              {
                if (timeline[x][i + 1] == 'n')
                {
                  std::cout << timeline[x][i] << "* ";
                  i++;
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
            std::cout << std::endl;
          }
          // This is for the reduced number of balls in an over due to all out
          if (ballNumber > 0)
          {
            for (int i = 0; i < ballNumber; i++)
            {
              if ((i + 1) != ballNumber)
              {
                if (timeline[overNumber][i + 1] == 'n')
                {
                  std::cout << timeline[overNumber][i] << "* ";
                  i++;
                }
                else
                {
                  std::cout << timeline[overNumber][i] << " ";
                }
              }
              else
              {
                std::cout << timeline[overNumber][i] << " ";
              }
            }
            std::cout << std::endl;
          }
          std::cout << "\nEnter to Continue\n";
          std::getline(std::cin, null);
        }

        system("cls");

        // Here put the code for super over

        // Buffs and nerfs to chasing team incase batting team op or bad
        if (innings == 1 && runs > higherScore)
          std::cout << "Chasing team will now get {buffed} as the score was above " << higherScore << "!\n";
        else if (innings == 1 && runs < lowerScore)
          std::cout << "Chasing team will now get {nerfed} as the score was sub " << lowerScore << "!\n";

        std::cout << "\nEnter to Continue\n";
        std::getline(std::cin, null);
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
        wideBalls = 0;
        partnership = {0, 0, 0, 0};
        partnerships.clear();
        strike = true;

        for (int i = 0; i < maxOvers; i++)
        {
          vOverBalls[i] = 0;
        }

        if (innings == 2 && runs == oldRuns)
        {
          std::cout
              << "SUPER OVER\n----------\nFirst, we will let players decide "
                 "batsmen. Enter corresponding batting order position\n";
          std::cout << "\nEnter to Continue\n";
          std::getline(std::cin, null);
          system("cls");

          teams = {{{0, 0, 1}, {0, 0, 1}, {0, 0, 0}}, {{0, 0, 1}, {0, 0, 1}, {0, 0, 0}}};
          char sOverT[2][100];
          std::string superOver[2][3] = {{"", "", ""}, {"", "", ""}};

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

          dotMax = 160;
          oMax = 310;
          dMax = 460;
          tMax = 465;
          fMax = 715;
          sMax = 885;
          wMax = 900;

          std::cout << "Team 2 will now bat first!\n";
          std::cout << "\nEnter to Continue\n";
          std::getline(std::cin, null);
          system("cls");

          while (ballNumber < 6)
          {
            random = std::rand() % 1000 + 1;

            if (random <= dotMax)
              e = superO(5, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
            else if (random > dotMax && random <= oMax)
              e = superO(1, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
            else if (random > oMax && random <= dMax)
              e = superO(2, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
            else if (random > dMax && random <= tMax)
              e = superO(3, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
            else if (random > tMax && random <= fMax)
              e = superO(4, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
            else if (random > fMax && random <= sMax)
              e = superO(6, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
            else if (random > sMax && random <= wMax)
              e = superO(7, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
            else if (random > wMax)
            {
              e = superO(8, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
              if (e == true)
                break;
            }

            std::cout << "\nEnter to Continue\n";
            std::getline(std::cin, null);
            system("cls");
          }

          overBalls = ballNumber + wideBalls;
          for (int i = 0; i < overBalls; i++)
            std::cout << sOverT[1][i] << " ";

          // Printing all stats out
          if (index[0] > 2)
          {
            teams[innings - 1][index[1]][0] = current[1];
            teams[innings - 1][index[1]][1] = ballsB[1];
          }
          else if (index[1] > 2)
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
          }

          std::cout << "\n\nSCORECARD\n---------" << std::endl;
          counter = 0;
          while (counter < 3)
          {
            if ((counter == index[0] || counter == index[1]) &&
                teams[1][counter][2] != 0)
              std::cout << superOver[1][counter] << ": " << teams[1][counter][0]
                        << " in " << teams[1][counter][1] << "\n";
            else
            {
              if (teams[1][counter][1] == 0)
                std::cout << superOver[1][counter] << ": DNP\n";
              else
                std::cout << superOver[1][counter] << ": "
                          << teams[1][counter][0] << " in "
                          << teams[1][counter][1] << " - OUT\n";
            }
            counter++;
          }
          std::cout << "\nFirst over: " << overRuns << "/" << wickets << "\n";

          innings--;
          oldRuns = overRuns;
          overRuns = 0;
          ballNumber = 0;
          wideBalls = 0;
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
            random = std::rand() % 1000 + 1;

            if (random <= dotMax)
              e = superO(5, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
            else if (random > dotMax && random <= oMax)
              e = superO(1, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
            else if (random > oMax && random <= dMax)
              e = superO(2, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
            else if (random > dMax && random <= tMax)
              e = superO(3, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
            else if (random > tMax && random <= fMax)
              e = superO(4, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
            else if (random > fMax && random <= sMax)
              e = superO(6, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
            else if (random > sMax && random <= wMax)
              e = superO(7, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
            else if (random > wMax)
            {
              e = superO(8, sOverT, overRuns, ballNumber, wideBalls, wickets, current, index, strike, teams, innings, ballsB, partnership, superOver, free);
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

          overBalls = ballNumber + wideBalls;
          for (int i = 0; i < overBalls; i++)
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
            teams[innings - 1][index[1]][0] = current[1];
            teams[innings - 1][index[1]][1] = ballsB[1];
          }
          else if (index[1] > 2)
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
          }

          std::cout << "\nFULL SCORECARD\n--------------" << std::endl;
          counter = 0;
          while (counter < 3)
          {
            if ((counter == index[0] || counter == index[1]) &&
                teams[1][counter][2] != 0)
              std::cout << superOver[1][counter] << ": " << teams[1][counter][0]
                        << " in " << teams[1][counter][1] << "\n";
            else
            {
              if (teams[1][counter][1] == 0)
                std::cout << superOver[1][counter] << ": DNP\n";
              else
                std::cout << superOver[1][counter] << ": "
                          << teams[1][counter][0] << " in "
                          << teams[1][counter][1] << " - OUT\n";
            }
            counter++;
          }

          std::cout << "\n";
          counter = 0;
          while (counter < 3)
          {
            if ((counter == index[0] || counter == index[1]) &&
                teams[0][counter][2] != 0)
              std::cout << superOver[0][counter] << ": " << teams[0][counter][0]
                        << " in " << teams[0][counter][1] << "\n";
            else
            {
              if (teams[0][counter][1] == 0)
                std::cout << superOver[0][counter] << ": DNP\n";
              else
                std::cout << superOver[0][counter] << ": "
                          << teams[0][counter][0] << " in "
                          << teams[0][counter][1] << " - OUT\n";
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
          wideBalls = 0;
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
      break;
    case 2:
      std::cout << "This program basically generates a random number based on weighted percentages that co-relates to a certain number of runs hit or other activities such as wickets or wide balls.\n\n";
      std::cout << "I play the game by creating two teams of 11 players (one mine, one my brother's) and using the simulator to simulate both innings. I keep everything tracked on a note taking app or on paper and at the end can see the score, who hit the most runs, and see which bowler had the highest economy etc (in the sim bowlers are not implemented so it has to be done on paper). I am by no means have 'pro' level cricket knowledge so the RNG is not perfect but I did my best to keep the games a little high scoring with close matches.\n\nYou can adjust the number of overs by changing par score and changing the max overs variable. Another thing I want to note is that an '*' in the timeline means no ball and the following ball is a free hit. Have fun!\n\n";
      std::cout << "P.S. There is a buff for the chasing team if the batting team scores above 7/6 of par score and a nerf for the chasing team if the batting team scores below 5/6 of par score.\n\n";
      std::cout << "Enter to Continue\n";
      std::cin.ignore();
      std::getline(std::cin, null);
      system("cls");
      break;
    case 3:
      std::cout << "Cricket in a nutshell (from Wikipedia):\n";
      std::cout << "Cricket is a bat-and-ball game played between two teams of eleven players each on a field at the centre of which is a 22-yard (20-metre) pitch with a wicket at each end, each comprising two bails balanced on three stumps. The game proceeds when a player on the fielding team, called the bowler, 'bowls' (propels) the ball from one end of the pitch towards the wicket at the other end, with an 'over' being completed once they have legally done so six times. The batting side has one player at each end of the pitch, with the Player at the opposite end of the pitch from the bowler aiming to strike the ball with a bat. The batting side scores runs either when the ball reaches the boundary of the field, or when the two batters swap ends of the pitch, which results in one run. The fielding side's aim is to prevent run-scoring and dismiss each batter (so they are 'out', and are said to have 'lost their wicket'). Means of dismissal include being bowled, when the bowled ball hits the stumps and dislodges the bails, and by the fielding side either catching a hit ball before it touches the ground, or hitting a wicket with the ball before a batter can cross the crease line in front of the wicket to complete a run. When ten batters have been dismissed, the innings ends and the teams swap roles. The game is adjudicated by two umpires, aided by a third umpire and match referee in international matches.\n\n";
      std::cout << "Forms of cricket range from Twenty20, with each team batting for a single innings of 20 overs and the game generally lasting three hours, to Test matches played over five days.\n\n";
      std::cout << "Enter to Continue\n";
      std::cin.ignore();
      std::getline(std::cin, null);
      system("cls");
      break;
    case 4:
      // End
      std::cout << "Thank you for playing! To re-run, well re-run the program!\n";
      return 0;

    default:
      std::cout << "That is not an option, please try again!\n\n";
      std::cout << "Enter to Continue\n";
      std::cin.ignore();
      std::getline(std::cin, null);
      system("cls");
      break;
    }
  }
}

bool outPutRuns(int x, array_type &array, int &runO, int &runT, int overN, int &ballN, int &ballW, int &outs, int (&batsmen)[2], int (&index)[2], bool &on, std::vector<std::vector<std::vector<int>>> &team, int inning, int (&balls)[2], std::vector<int> &partner, std::vector<std::vector<int>> &partners, bool &fHit)
{
  char number = ' ';
  int tRandom = std::rand() % 100 + 1;
  std::string nul = "";

  if (fHit)
  {
    std::cout << "FREE HIT: ";
  }

  switch (x)
  {
  case 1:
    std::cout << "Single (1)\n";
    number = '1';
    break;
  case 2:
    std::cout << "2 runs\n";
    number = '2';
    break;
  case 3:
    std::cout << "3 runs\n";
    number = '3';
    break;
  case 4:
    std::cout << "Boundary (4)\n";
    number = '4';
    break;
  case 5:
    std::cout << ".\n";
    break;
  case 6:
    std::cout << "MAXIMUM (6)\n";
    number = '6';
    break;
  case 7:
    std::cout << "Wide (w)\n";
    break;
  case 8:
    std::cout << "OUT\n";
    break;

  default:
    std::cout << "Well Something Broke!\n";
    break;
  }

  if (x == 1 || x == 2 || x == 3 || x == 4 || x == 6)
  {
    array[overN - 1][ballN + ballW] = number;
    fHit = false;
    if (tRandom == 18)
    {
      fHit = true;
      array[overN - 1][ballN + ballW + 1] = 'n';
      std::cout << "\nNO BALL! Free hit next ball!\n";
      runT++;
      runO++;
      partner[0]++;
      ballW += 2;
    }
    else
    {
      partner[1]++;
      ballN++;
    }
    runT += x;
    runO += x;
    partner[0] += x;
    if (on)
    {
      batsmen[0] += x;
      if (!fHit)
        balls[0]++;
    }
    else
    {
      batsmen[1] += x;
      if (!fHit)
        balls[1]++;
    }

    if (on)
    {
      std::cout << "\n"
                << names[inning - 1][index[0]] << "*: " << batsmen[0] << " in " << balls[0] << "\n";
      std::cout << names[inning - 1][index[1]] << ": " << batsmen[1] << " in " << balls[1] << "\n\n";
    }
    else
    {
      std::cout << "\n"
                << names[inning - 1][index[1]] << "*: " << batsmen[1] << " in " << balls[1] << "\n";
      std::cout << names[inning - 1][index[0]] << ": " << batsmen[0] << " in " << balls[0] << "\n\n";
    }

    std::cout << "Current partnership: " << partner[0] << " in " << partner[1] << "\n";

    if (x == 1 || x == 3)
      on = !on;
  }
  else if (x == 5)
  {
    array[overN - 1][ballN + ballW] = '.';
    fHit = false;
    if (tRandom == 18)
    {
      fHit = true;
      array[overN - 1][ballN + ballW + 1] = 'n';
      std::cout << "\nNO BALL! Free hit next ball!\n";
      runT++;
      runO++;
      partner[0]++;
      ballW += 2;
    }
    else
    {
      ballN++;
      partner[1]++;
      if (on)
        balls[0]++;
      else
        balls[1]++;
    }

    if (on)
    {
      std::cout << "\n"
                << names[inning - 1][index[0]] << "*: " << batsmen[0] << " in " << balls[0] << "\n";
      std::cout << names[inning - 1][index[1]] << ": " << batsmen[1] << " in " << balls[1] << "\n\n";
    }
    else
    {
      std::cout << "\n"
                << names[inning - 1][index[1]] << "*: " << batsmen[1] << " in " << balls[1] << "\n";
      std::cout << names[inning - 1][index[0]] << ": " << batsmen[0] << " in " << balls[0] << "\n\n";
    }
    std::cout << "Current partnership: " << partner[0] << " in " << partner[1] << "\n";
  }
  else if (x == 7)
  {
    array[overN - 1][ballN + ballW] = 'w';
    if (fHit)
    {
      std::cout << "\nNo ball continued next ball!\n";
    }
    if (on)
    {
      std::cout << "\n"
                << names[inning - 1][index[0]] << "*: " << batsmen[0] << " in " << balls[0] << "\n";
      std::cout << names[inning - 1][index[1]] << ": " << batsmen[1] << " in " << balls[1] << "\n\n";
    }
    else
    {
      std::cout << "\n"
                << names[inning - 1][index[1]] << "*: " << batsmen[1] << " in " << balls[1] << "\n";
      std::cout << names[inning - 1][index[0]] << ": " << batsmen[0] << " in "
                << balls[0] << "\n\n";
    }
    partner[0]++;
    std::cout << "Current partnership: " << partner[0] << " in " << partner[1] << "\n";
    runT++;
    runO++;
    ballW++;
  }
  else if (x == 8)
  {
    array[overN - 1][ballN + ballW] = 'W';
    if ((tRandom == 18 || tRandom == 21) && !fHit)
    {
      array[overN - 1][ballN + ballW + 1] = 'n';
      std::cout << "\nBUT ITS A NO BALL!\n";
      runT++;
      runO++;
      partner[0]++;
      ballW += 2; // MAJOR WARNING - IF I EVER PUT NUMBER OF WIDES THIS WILL CAUSE AN ISSUE
    }
    else if (tRandom == 18 || tRandom == 21)
    {
      array[overN - 1][ballN + ballW + 1] = 'n';
      std::cout << "\nBUT ITS A NO BALL AGAIN!\n";
      runT++;
      runO++;
      partner[0]++;
      ballW += 2;
    }
    else if (fHit)
    {
      std::cout << "\nSince last ball was a no ball it doesn't count...\n";
      on ? balls[0]++ : balls[1]++;
      partner[1]++;
    }
    else if (on)
    {
      balls[0]++;
      team[inning - 1][index[0]][0] = batsmen[0];
      team[inning - 1][index[0]][1] = balls[0];
      std::cout << "\n"
                << names[inning - 1][index[0]] << "*: " << batsmen[0] << " in " << balls[0] << " - OUT\n";
      std::cout << names[inning - 1][index[1]] << ": " << batsmen[1] << " in " << balls[1] << "\n\n";
      batsmen[0] = 0;
      balls[0] = 0;
      partner[2] = index[0];
      partner[3] = index[1];
      if (index[0] > index[1])
        index[0]++;
      else
        index[0] = index[1] + 1;
      if (index[0] <= 10)
      {
        team[inning - 1][index[0]][2] = 1;
      }
    }
    else
    {
      balls[1]++;
      team[inning - 1][index[1]][0] = batsmen[1];
      team[inning - 1][index[1]][1] = balls[1];
      std::cout << "\n"
                << names[inning - 1][index[1]] << "*: " << batsmen[1] << " in " << balls[1] << " - OUT\n";
      std::cout << names[inning - 1][index[0]] << ": " << batsmen[0] << " in " << balls[0] << "\n\n";
      batsmen[1] = 0;
      balls[1] = 0;
      partner[2] = index[0];
      partner[3] = index[1];
      if (index[0] < index[1])
        index[1]++;
      else
        index[1] = index[0] + 1;
      if (index[1] <= 10)
      {
        team[inning - 1][index[1]][2] = 1;
      }
    }

    if (tRandom == 18 || tRandom == 21 || fHit)
    {
      if (on)
      {
        std::cout << "\n"
                  << names[inning - 1][index[0]] << "*: " << batsmen[0] << " in " << balls[0] << "\n";
        std::cout << names[inning - 1][index[1]] << ": " << batsmen[1] << " in " << balls[1] << "\n\n";
      }
      else
      {
        std::cout << "\n"
                  << names[inning - 1][index[1]] << "*: " << batsmen[1] << " in " << balls[1] << "\n";
        std::cout << names[inning - 1][index[0]] << ": " << batsmen[0] << " in " << balls[0] << "\n\n";
      }
      std::cout << "Current partnership: " << partner[0] << " in " << partner[1] << "\n";
    }
    else
    {
      partner[1]++;
      std::cout << "Broken partnership: " << partner[0] << " in " << partner[1] << "\n";
      partners.push_back(partner);
      partner[0] = 0;
      partner[1] = 0;
    }

    if (tRandom == 18 || tRandom == 21)
    {
      fHit = true;
    }
    else
    {
      if (!fHit) {
        outs++;
      }
      fHit = false;
      ballN++;
    }
  }

  if (outs == 10)
    return true;

  return false;
}

bool superO(int x, char (&array)[2][100], int &runO, int &ballN, int &ballW, int &outs, int (&batsmen)[2], int (&index)[2], bool &on, std::vector<std::vector<std::vector<int>>> &team, int inning, int (&balls)[2], std::vector<int> &partner, std::string nNames[2][3], bool &fHit)
{
  char number = ' ';
  int tRandom = std::rand() % 1000 + 1;

  switch (x)
  {
  case 1:
    std::cout << "Single (1)\n";
    number = '1';
    break;
  case 2:
    std::cout << "2 runs\n";
    number = '2';
    break;
  case 3:
    std::cout << "3 runs\n";
    number = '3';
    break;
  case 4:
    std::cout << "Boundary (4)\n";
    number = '4';
    break;
  case 5:
    std::cout << ".\n";
    break;
  case 6:
    std::cout << "MAXIMUM (6)\n";
    number = '6';
    break;
  case 7:
    std::cout << "Wide (w)\n";
    break;
  case 8:
    std::cout << "OUT\n";
    break;

  default:
    std::cout << "Well Something Broke!\n";
    break;
  }

  if (x == 1 || x == 2 || x == 3 || x == 4 || x == 6)
  {
    array[inning - 1][ballN + ballW] = number;
    runO += x;
    partner[0] += x;
    partner[1]++;
    if (on)
    {
      batsmen[0] += x;
      balls[0]++;
    }
    else
    {
      batsmen[1] += x;
      balls[1]++;
    }

    if (on)
    {
      std::cout << "\n"
                << nNames[inning - 1][index[0]] << "*: " << batsmen[0] << " in " << balls[0] << "\n";
      std::cout << nNames[inning - 1][index[1]] << ": " << batsmen[1] << " in "
                << balls[1] << "\n\n";
    }
    else
    {
      std::cout << "\n"
                << nNames[inning - 1][index[1]] << "*: " << batsmen[1] << " in " << balls[1] << "\n";
      std::cout << nNames[inning - 1][index[0]] << ": " << batsmen[0] << " in " << balls[0] << "\n\n";
    }

    std::cout << "Current partnership: " << partner[0] << " in " << partner[1] << "\n";

    if (x == 1 || x == 3)
      on = !on;
    ballN++;
  }
  else if (x == 5)
  {
    array[inning - 1][ballN + ballW] = '.';
    ballN++;
    partner[1]++;
    if (on)
      balls[0]++;
    else
      balls[1]++;
    if (on)
    {
      std::cout << "\n"
                << nNames[inning - 1][index[0]] << "*: " << batsmen[0] << " in " << balls[0] << "\n";
      std::cout << nNames[inning - 1][index[1]] << ": " << batsmen[1] << " in " << balls[1] << "\n\n";
    }
    else
    {
      std::cout << "\n"
                << nNames[inning - 1][index[1]] << "*: " << batsmen[1] << " in " << balls[1] << "\n";
      std::cout << nNames[inning - 1][index[0]] << ": " << batsmen[0] << " in " << balls[0] << "\n\n";
    }
    std::cout << "Current partnership: " << partner[0] << " in " << partner[1] << "\n";
  }
  else if (x == 7)
  {
    array[inning - 1][ballN + ballW] = 'w';
    if (on)
    {
      std::cout << "\n"
                << nNames[inning - 1][index[0]] << "*: " << batsmen[0] << " in " << balls[0] << "\n";
      std::cout << nNames[inning - 1][index[1]] << ": " << batsmen[1] << " in " << balls[1] << "\n\n";
    }
    else
    {
      std::cout << "\n"
                << nNames[inning - 1][index[1]] << "*: " << batsmen[1] << " in " << balls[1] << "\n";
      std::cout << nNames[inning - 1][index[0]] << ": " << batsmen[0] << " in " << balls[0] << "\n\n";
    }
    std::cout << "Current partnership: " << partner[0] << " in " << partner[1] << "\n";
    runO++;
    ballW++;
  }
  else if (x == 8)
  {
    array[inning - 1][ballN + ballW] = 'W';
    if (on)
    {
      balls[0]++;
      team[inning - 1][index[0]][0] = batsmen[0];
      team[inning - 1][index[0]][1] = balls[0];
      std::cout << "\n"
                << nNames[inning - 1][index[0]] << "*: " << batsmen[0] << " in " << balls[0] << " - OUT\n";
      std::cout << nNames[inning - 1][index[1]] << ": " << batsmen[1] << " in " << balls[1] << "\n\n";
      batsmen[0] = 0;
      balls[0] = 0;
      partner[2] = index[0];
      partner[3] = index[1];
      if (index[0] > index[1])
        index[0]++;
      else
        index[0] = index[1] + 1;
      if (index[0] <= 10)
      {
        team[inning - 1][index[0]][2] = 1;
      }
    }
    else
    {
      balls[1]++;
      team[inning - 1][index[1]][0] = batsmen[1];
      team[inning - 1][index[1]][1] = balls[1];
      std::cout << "\n"
                << nNames[inning - 1][index[1]] << "*: " << batsmen[1] << " in " << balls[1] << " - OUT\n";
      std::cout << nNames[inning - 1][index[0]] << ": " << batsmen[0] << " in " << balls[0] << "\n\n";
      batsmen[1] = 0;
      balls[1] = 0;
      partner[2] = index[0];
      partner[3] = index[1];
      if (index[0] < index[1])
        index[1]++;
      else
        index[1] = index[0] + 1;
      if (index[0] <= 10)
      {
        team[inning - 1][index[1]][2] = 1;
      }
    }
    partner[1]++;
    std::cout << "Broken partnership: " << partner[0] << " in " << partner[1] << "\n\n";
    partner[0] = 0;
    partner[1] = 0;
    ballN++;
    outs++;
  }

  if (outs == 2)
    return true;

  return false;
}