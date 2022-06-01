// Imports
#include <iostream>

#include <cstdlib>

#include <time.h>

#include <vector>

#include <string>

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
  int totalBalls = 0;
  int wideBalls = 0;
  int overBalls = 0;

  double runRate = 0.0;

  char timeline[10][100]; // Had to change this to a 2d array as wides were causing multiple issues

  std::string null = "";

  std::vector<int> vOverBalls = std::vector<int>();

  time_t nTime;

  // Making rand() actually random (it adds a seed which is based on the time which changes every second)
  std::srand((unsigned)time(&nTime));

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
        while (overNumber <= 10)
        {
          while (ballNumber < 6)
          {

            // Getting the random number from 0 - 100, then adding it by 1 so it is from 1 - 101 NOT INCLUDING 101
            random = std::rand() % 100 + 1;

            // The main attraction - weighted randoms
            // The weighted randoms are calculated based on the random number that was generated. As it was from 1 - 100 the weighted randoms work by saying if the number was in this range, it outputs this many runs or wicket or dot
            // The first three are buffed for powerplay, and after that the next two are buffs and nerfs incase the first team plays good or bad
            if ((innings == 2 && oldRuns > 140) && (overNumber == 1 || overNumber > 8))
            {
              std::cout << "POWERPLAY\n---------\n\n";
              if (random <= 10)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '.';
                totalBalls++;
                ballNumber++;
                std::cout << ".\n";
              }
              else if (random > 10 & random <= 30)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '1';
                runs++;
                overRuns++;
                totalBalls++;
                ballNumber++;
                std::cout << "Single (1)\n";
              }
              else if (random > 30 & random <= 35)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '2';
                runs += 2;
                overRuns += 2;
                totalBalls++;
                ballNumber++;
                std::cout << "2 runs\n";
              }
              else if (random > 35 & random <= 40)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '3';
                runs += 3;
                overRuns += 3;
                totalBalls++;
                ballNumber++;
                std::cout << "3 runs\n";
              }
              else if (random > 40 & random <= 67)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '4';
                runs += 4;
                overRuns += 4;
                totalBalls++;
                ballNumber++;
                std::cout << "Boundary (4)\n";
              }
              else if (random > 67 & random <= 83)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '6';
                runs += 6;
                overRuns += 6;
                totalBalls++;
                ballNumber++;
                std::cout << "MAXIMUM (6)\n";
              }
              else if (random > 83)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = 'W';
                wickets++;
                totalBalls++;
                ballNumber++;
                std::cout << "OUT\n";
                // Checking if all out (you will see this in all of the following waited random if statements)
                if (wickets == 10)
                {
                  break;
                }
              }
            }
            else if ((innings == 2 && oldRuns < 100) && (overNumber == 1 || overNumber > 8))
            {
              std::cout << "POWERPLAY\n---------\n\n";
              if (random <= 20)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '.';
                totalBalls++;
                ballNumber++;
                std::cout << ".\n";
              }
              else if (random > 20 & random <= 40)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '1';
                runs++;
                overRuns++;
                totalBalls++;
                ballNumber++;
                std::cout << "Single (1)\n";
              }
              else if (random > 40 & random <= 45)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '2';
                runs += 2;
                overRuns += 2;
                totalBalls++;
                ballNumber++;
                std::cout << "2 runs\n";
              }
              else if (random > 45 & random <= 50)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '3';
                runs += 3;
                overRuns += 3;
                totalBalls++;
                ballNumber++;
                std::cout << "3 runs\n";
              }
              else if (random > 50 & random <= 73)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '4';
                runs += 4;
                overRuns += 4;
                totalBalls++;
                ballNumber++;
                std::cout << "Boundary (4)\n";
              }
              else if (random > 73 & random <= 87)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '6';
                runs += 6;
                overRuns += 6;
                totalBalls++;
                ballNumber++;
                std::cout << "MAXIMUM (6)\n";
              }
              else if (random > 87)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = 'W';
                wickets++;
                totalBalls++;
                ballNumber++;
                std::cout << "OUT\n";
                if (wickets == 10)
                {
                  break;
                }
              }
            }
            else if (overNumber == 1 || overNumber > 8)
            {
              std::cout << "POWERPLAY\n---------\n\n";
              if (random <= 15)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '.';
                totalBalls++;
                ballNumber++;
                std::cout << ".\n";
              }
              else if (random > 15 & random <= 35)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '1';
                runs++;
                overRuns++;
                totalBalls++;
                ballNumber++;
                std::cout << "Single (1)\n";
              }
              else if (random > 35 & random <= 40)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '2';
                runs += 2;
                overRuns += 2;
                totalBalls++;
                ballNumber++;
                std::cout << "2 runs\n";
              }
              else if (random > 40 & random <= 45)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '3';
                runs += 3;
                overRuns += 3;
                totalBalls++;
                ballNumber++;
                std::cout << "3 runs\n";
              }
              else if (random > 45 & random <= 70)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '4';
                runs += 4;
                overRuns += 4;
                totalBalls++;
                ballNumber++;
                std::cout << "Boundary (4)\n";
              }
              else if (random > 70 & random <= 85)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '6';
                runs += 6;
                overRuns += 6;
                totalBalls++;
                ballNumber++;
                std::cout << "MAXIMUM (6)\n";
              }
              else if (random > 85)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = 'W';
                wickets++;
                totalBalls++;
                ballNumber++;
                std::cout << "OUT\n";
                if (wickets == 10)
                {
                  break;
                }
              }
            }
            else if (innings == 2 && oldRuns > 140)
            {
              if (random <= 10)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '.';
                totalBalls++;
                ballNumber++;
                std::cout << ".\n";
              }
              else if (random > 10 && random <= 15)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = 'w';
                runs++;
                overRuns++;
                totalBalls++;
                wideBalls++;
                std::cout << "Wide (w)\n";
              }
              else if (random > 15 & random <= 40)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '1';
                runs++;
                overRuns++;
                totalBalls++;
                ballNumber++;
                std::cout << "Single (1)\n";
              }
              else if (random > 40 & random <= 50)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '2';
                runs += 2;
                overRuns += 2;
                totalBalls++;
                ballNumber++;
                std::cout << "2 runs\n";
              }
              else if (random > 50 & random <= 55)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '3';
                runs += 3;
                overRuns += 3;
                totalBalls++;
                ballNumber++;
                std::cout << "3 runs\n";
              }
              else if (random > 55 & random <= 77)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '4';
                runs += 4;
                overRuns += 4;
                totalBalls++;
                ballNumber++;
                std::cout << "Boundary (4)\n";
              }
              else if (random > 77 & random <= 88)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '6';
                runs += 6;
                overRuns += 6;
                totalBalls++;
                ballNumber++;
                std::cout << "MAXIMUM (6)\n";
              }
              else if (random > 88)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = 'W';
                wickets++;
                totalBalls++;
                ballNumber++;
                std::cout << "OUT\n";
                if (wickets == 10)
                {
                  break;
                }
              }
            }
            else if (innings == 2 && oldRuns < 100)
            {
              if (random <= 20)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '.';
                totalBalls++;
                ballNumber++;
                std::cout << ".\n";
              }
              else if (random > 20 && random <= 25)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = 'w';
                runs++;
                overRuns++;
                totalBalls++;
                wideBalls++;
                std::cout << "Wide (w)\n";
              }
              else if (random > 25 & random <= 50)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '1';
                runs++;
                overRuns++;
                totalBalls++;
                ballNumber++;
                std::cout << "Single (1)\n";
              }
              else if (random > 50 & random <= 60)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '2';
                runs += 2;
                overRuns += 2;
                totalBalls++;
                ballNumber++;
                std::cout << "2 runs\n";
              }
              else if (random > 60 & random <= 65)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '3';
                runs += 3;
                overRuns += 3;
                totalBalls++;
                ballNumber++;
                std::cout << "3 runs\n";
              }
              else if (random > 65 & random <= 83)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '4';
                runs += 4;
                overRuns += 4;
                totalBalls++;
                ballNumber++;
                std::cout << "Boundary (4)\n";
              }
              else if (random > 83 & random <= 92)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '6';
                runs += 6;
                overRuns += 6;
                totalBalls++;
                ballNumber++;
                std::cout << "MAXIMUM (6)\n";
              }
              else if (random > 92)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = 'W';
                wickets++;
                totalBalls++;
                ballNumber++;
                std::cout << "OUT\n";
                if (wickets == 10)
                {
                  break;
                }
              }
            }
            else if (overNumber > 1 && overNumber < 9)
            {
              if (random <= 15)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '.';
                totalBalls++;
                ballNumber++;
                std::cout << ".\n";
              }
              else if (random > 15 && random <= 20)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = 'w';
                runs++;
                overRuns++;
                totalBalls++;
                wideBalls++;
                std::cout << "Wide (w)\n";
              }
              else if (random > 20 & random <= 45)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '1';
                runs++;
                overRuns++;
                totalBalls++;
                ballNumber++;
                std::cout << "Single (1)\n";
              }
              else if (random > 45 & random <= 55)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '2';
                runs += 2;
                overRuns += 2;
                totalBalls++;
                ballNumber++;
                std::cout << "2 runs\n";
              }
              else if (random > 55 & random <= 60)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '3';
                runs += 3;
                overRuns += 3;
                totalBalls++;
                ballNumber++;
                std::cout << "3 runs\n";
              }
              else if (random > 60 & random <= 80)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '4';
                runs += 4;
                overRuns += 4;
                totalBalls++;
                ballNumber++;
                std::cout << "Boundary (4)\n";
              }
              else if (random > 80 & random <= 90)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = '6';
                runs += 6;
                overRuns += 6;
                totalBalls++;
                ballNumber++;
                std::cout << "MAXIMUM (6)\n";
              }
              else if (random > 90)
              {
                timeline[overNumber - 1][ballNumber + wideBalls] = 'W';
                wickets++;
                totalBalls++;
                ballNumber++;
                std::cout << "OUT\n";
                if (wickets == 10)
                {
                  break;
                }
              }
            }

            // Check if won
            if (innings == 2)
            {
              if (runs > oldRuns)
              {
                std::cout << "Enter to Continue\n";
                std::getline(std::cin, null);
                system("cls");
                break;
              }
              // Printing out the amount of runs left to win if in the second innings
              std::cout << "Runs to Win: " << ((oldRuns + 1) - runs) << "\n";
            }
            std::cout << "Enter to Continue\n";
            std::getline(std::cin, null);
            system("cls");
          }

          // vOverBalls is a vector which will contain each over's number of balls. This again is because of wides increasing the number of balls in an over. Also all out requires this
          overBalls = ballNumber + wideBalls;
          vOverBalls.push_back(overBalls);

          // Increasing over number if six balls were finished
          if (ballNumber == 6)
          {
            ballNumber = 0;
            overNumber++;
          }

          // Checking if won or all out again
          if ((wickets == 10) || ((innings == 2) & (runs > oldRuns)))
          {
            break;
          }
          else if ((innings == 2) & (runs > oldRuns))
          {
            break;
          }

          // Timeline after every over
          for (int i = 0; i < overBalls; i++)
          {
            // std::cout << "Over Balls: " << overBalls << "\nOver Number: " << overNumber - 1 << "\ni: " << i << std::endl;
            std::cout << timeline[overNumber - 2][i] << " ";
          }

          // Calculating run rate
          runRate = static_cast<double>(runs) / static_cast<double>((overNumber - 1));

          // Printing all stats out
          std::cout << "\n\n";
          std::cout << "Runs last over: " << overRuns << "\n";
          std::cout << (overNumber - 1) << " over(s) up, " << runs << "/" << wickets << std::endl;
          std::cout << "Current run rate: " << runRate << "\n";
          if (innings == 2)
          {
            std::cout << "Runs to Win: " << ((oldRuns + 1) - runs) << "\n";
          }
          std::cout << "\nEnter to Continue\n";
          std::getline(std::cin, null);
          overRuns = 0;
          wideBalls = 0;
          system("cls");
        }

        // Calculating run rate again
        runRate = static_cast<double>(runs) / static_cast<double>(((overNumber - 1) * 6 + ballNumber)) * static_cast<double>(6);

        // Printing out results
        if (wickets == 10)
        {
          std::cout << "\nAll out at " << runs << " after " << overNumber << "." << ballNumber << " overs with a run rate of " << runRate << "!\n";
        }

        if (innings == 1 && wickets != 10)
        {
          std::cout << "First innings up.\n"
                    << runs << "/" << wickets << " in 10 overs!\nRun rate: " << runRate << std::endl;
        }
        else if (runs == oldRuns && innings == 2)
        {
          std::cout << "Both teams tied\n";
        }
        else if (runs < oldRuns && innings == 2)
        {
          std::cout << "\nTeam 1 won by " << (oldRuns - runs) << " run(s)!\n";
        }
        else if (innings == 2)
        {
          std::cout << "\nTeam 2 won with " << (10 - wickets) << " wicket(s)!\nRun rate: " << runRate << "\n";
        }

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
            // std::cout << "Overs: " << overNumber << "\nX: " << x << std::endl;
            for (int i = 0; i < vOverBalls[x]; i++)
            {
              std::cout << timeline[x][i] << " ";
            }
            std::cout << std::endl;
          }
          // This is for the reduced number of balls in an over due to all out
          if (ballNumber > 0)
          {
            for (int i = 0; i < ballNumber; i++)
            {
              std::cout << timeline[overNumber][i] << " ";
            }
            std::cout << std::endl;
          }
          std::cout << "\nEnter to Continue\n";
          std::getline(std::cin, null);
        }

        system("cls");

        // Buffs and nerfs to chasing team incase batting team op or bad
        if (innings == 1 && runs > 140)
        {
          std::cout << "Chasing team will now get {buffed} as the score was above 140!\n";
        }
        else if (innings == 1 && runs < 100)
        {
          std::cout << "Chasing team will now get {nerfed} as the score was sub 100!\n";
        }
        std::cout << "\nEnter to Continue\n";
        std::getline(std::cin, null);
        system("cls");

        // Resetting all variables
        ballNumber = 0;
        overNumber = 1;
        wickets = 0;
        oldRuns = runs;
        totalBalls = 0;
        runs = 0;
        vOverBalls.clear();
        innings++;
      }
      break;
    case 2:
      std::cout << "This program basically generates a random number based on weighted percentages that co-relates to a certain number of runs hit or other activities such as wickets or wides.\n\n";
      std::cout << "I play the game by creating my own squad or team of 11 players which I use against another squad/team of 11 players and use the rng to determine how many runs were hit or who got out. I keep everything tracked on a note taking app or on paper and at the end can see the score, who hit the most runs, and see which bowler had the highest economy etc. I am by no means a 'pro' on cricket knowledge so the rng is not perfect and I am not sure how accurate it is. It was supposed to be a little like T20 but my brother set all the weights and made it so the average score in these 10 overs is 120 lol.\n\n";
      std::cout << "P.S. There is a buff for the chasing team if the batting team scores above 140 runs and a nerf for the chasing team if the batting team scores below 100 runs.\n\n";
      std::cout << "Enter to Continue\n";
      std::cin.ignore();
      std::getline(std::cin, null);
      system("cls");
      break;
    case 3:
      std::cout << "Cricket in a nutshell (from Wikipedia):\n";
      std::cout << "Cricket is a bat-and-ball game played between two teams of eleven players each on a field at the centre of which is a 22-yard (20-metre) pitch with a wicket at each end, each comprising two bails balanced on three stumps. The game proceeds when a player on the fielding team, called the bowler, 'bowls' (propels) the ball from one end of the pitch towards the wicket at the other end, with an 'over' being completed once they have legally done so six times. The batting side has one player at each end of the pitch, with the player at the opposite end of the pitch from the bowler aiming to strike the ball with a bat. The batting side scores runs either when the ball reaches the boundary of the field, or when the two batters swap ends of the pitch, which results in one run. The fielding side's aim is to prevent run-scoring and dismiss each batter (so they are 'out', and are said to have 'lost their wicket'). Means of dismissal include being bowled, when the bowled ball hits the stumps and dislodges the bails, and by the fielding side either catching a hit ball before it touches the ground, or hitting a wicket with the ball before a batter can cross the crease line in front of the wicket to complete a run. When ten batters have been dismissed, the innings ends and the teams swap roles. The game is adjudicated by two umpires, aided by a third umpire and match referee in international matches.\n\n";
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
