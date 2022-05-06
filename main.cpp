// Imports
#include <iostream>

#include <cstdlib>

#include <time.h>

#include <vector>

int main() {
  // Variable Declaration
  int overNumber = 1; // This is dumb, I know, and it makes me have to do - 1 wherever I mention overNumber, but I am too lazy to fix it everywhere
  int ballNumber = 0;
  int runs = 0;
  int wickets = 0;
  int innings = 1;
  int random = 0;
  int timelineNumber = 0;
  int oldRuns = 0;
  int overRuns = 0;

  double runRate = 0.0;

  std::string null = "";

  std::vector < char > timeline = std::vector < char > ();

  time_t nTime;
  
  // Making rand() actually random (it adds a seed which is based on the time which changes every second)
  std::srand((unsigned) time( & nTime));

  // The while loop containing most of our code
  while (innings < 3) {
    std::cout << "INNINGS NUMBER " << innings << "\n\n";

    // While loops for our over number and ball number
    while (overNumber <= 10) {
      while (ballNumber < 6) {
        
        // Getting the random number from 0 - 100, then adding it by 1 so it is from 1 - 101 NOT INCLUDING 101
        random = std::rand() % 100 + 1;
        ballNumber++;

        // The main attraction - weighted randoms
        // The weighted randoms are calculated based on the random number that was generated. As it was from 1 - 100 the weighted randoms work by saying if the number was in this range, it outputs this many runs or wicket or dot
        // The first three are buffed for powerplay, and after that the next two are buffs and nerfs incase the first team plays good or bad
        if ((innings == 2 && oldRuns > 140) && (overNumber == 1 || overNumber > 8)) {
          std::cout << "POWERPLAY\n---------\n\n";
          if (random <= 10) {
            timeline.push_back('.');
            std::cout << ".\n";
          } else if (random > 10 & random <= 30) {
            timeline.push_back('1');
            runs++;
            overRuns++;
            std::cout << "Single (1)\n";
          } else if (random > 30 & random <= 35) {
            timeline.push_back('2');
            runs += 2;
            overRuns += 2;
            std::cout << "2 runs\n";
          } else if (random > 35 & random <= 40) {
            timeline.push_back('3');
            runs += 3;
            overRuns += 3;
            std::cout << "3 runs\n";
          } else if (random > 40 & random <= 67) {
            timeline.push_back('4');
            runs += 4;
            overRuns += 4;
            std::cout << "Boundary (4)\n";
          } else if (random > 67 & random <= 83) {
            timeline.push_back('6');
            runs += 6;
            overRuns += 6;
            std::cout << "MAXIMUM (6)\n";
          } else if (random > 83) {
            timeline.push_back('W');
            wickets++;
            std::cout << "OUT\n";
            if (wickets == 10) {
              break;
            }
          }
        } else if ((innings == 2 && oldRuns < 100) && (overNumber == 1 || overNumber > 8)) {
          std::cout << "POWERPLAY\n---------\n\n";
          if (random <= 20) {
            timeline.push_back('.');
            std::cout << ".\n";
          } else if (random > 20 & random <= 40) {
            timeline.push_back('1');
            runs++;
            overRuns++;
            std::cout << "Single (1)\n";
          } else if (random > 40 & random <= 45) {
            timeline.push_back('2');
            runs += 2;
            overRuns += 2;
            std::cout << "2 runs\n";
          } else if (random > 45 & random <= 50) {
            timeline.push_back('3');
            runs += 3;
            overRuns += 3;
            std::cout << "3 runs\n";
          } else if (random > 50 & random <= 73) {
            timeline.push_back('4');
            runs += 4;
            overRuns += 4;
            std::cout << "Boundary (4)\n";
          } else if (random > 73 & random <= 87) {
            timeline.push_back('6');
            runs += 6;
            overRuns += 6;
            std::cout << "MAXIMUM (6)\n";
          } else if (random > 87) {
            timeline.push_back('W');
            wickets++;
            std::cout << "OUT\n";
            if (wickets == 10) {
              break;
            }
          }
        } else if (overNumber == 1 || overNumber > 8) {
          std::cout << "POWERPLAY\n---------\n\n";
          if (random <= 15) {
            timeline.push_back('.');
            std::cout << ".\n";
          } else if (random > 15 & random <= 35) {
            timeline.push_back('1');
            runs++;
            overRuns++;
            std::cout << "Single (1)\n";
          } else if (random > 35 & random <= 40) {
            timeline.push_back('2');
            runs += 2;
            overRuns += 2;
            std::cout << "2 runs\n";
          } else if (random > 40 & random <= 45) {
            timeline.push_back('3');
            runs += 3;
            overRuns += 3;
            std::cout << "3 runs\n";
          } else if (random > 45 & random <= 70) {
            timeline.push_back('4');
            runs += 4;
            overRuns += 4;
            std::cout << "Boundary (4)\n";
          } else if (random > 70 & random <= 85) {
            timeline.push_back('6');
            runs += 6;
            overRuns += 6;
            std::cout << "MAXIMUM (6)\n";
          } else if (random > 85) {
            timeline.push_back('W');
            wickets++;
            std::cout << "OUT\n";
            if (wickets == 10) {
              break;
            }
          }
        } else if (innings == 2 && oldRuns > 140) {
          if (random <= 15) {
            timeline.push_back('.');
            std::cout << ".\n";
          } else if (random > 15 & random <= 40) {
            timeline.push_back('1');
            runs++;
            overRuns++;
            std::cout << "Single (1)\n";
          } else if (random > 40 & random <= 50) {
            timeline.push_back('2');
            runs += 2;
            overRuns += 2;
            std::cout << "2 runs\n";
          } else if (random > 50 & random <= 55) {
            timeline.push_back('3');
            runs += 3;
            overRuns += 3;
            std::cout << "3 runs\n";
          } else if (random > 55 & random <= 77) {
            timeline.push_back('4');
            runs += 4;
            overRuns += 4;
            std::cout << "Boundary (4)\n";
          } else if (random > 77 & random <= 88) {
            timeline.push_back('6');
            runs += 6;
            overRuns += 6;
            std::cout << "MAXIMUM (6)\n";
          } else if (random > 88) {
            timeline.push_back('W');
            wickets++;
            std::cout << "OUT\n";
            if (wickets == 10) {
              break;
            }
          }
        } else if (innings == 2 && oldRuns < 100) {
          if (random <= 25) {
            timeline.push_back('.');
            std::cout << ".\n";
          } else if (random > 25 & random <= 50) {
            timeline.push_back('1');
            runs++;
            overRuns++;
            std::cout << "Single (1)\n";
          } else if (random > 50 & random <= 60) {
            timeline.push_back('2');
            runs += 2;
            overRuns += 2;
            std::cout << "2 runs\n";
          } else if (random > 60 & random <= 65) {
            timeline.push_back('3');
            runs += 3;
            overRuns += 3;
            std::cout << "3 runs\n";
          } else if (random > 65 & random <= 83) {
            timeline.push_back('4');
            runs += 4;
            overRuns += 4;
            std::cout << "Boundary (4)\n";
          } else if (random > 83 & random <= 92) {
            timeline.push_back('6');
            runs += 6;
            overRuns += 6;
            std::cout << "MAXIMUM (6)\n";
          } else if (random > 92) {
            timeline.push_back('W');
            wickets++;
            std::cout << "OUT\n";
            if (wickets == 10) {
              break;
            }
          }
        } else if (overNumber > 1 && overNumber < 9) {
          if (random <= 20) {
            timeline.push_back('.');
            std::cout << ".\n";
          } else if (random > 20 & random <= 45) {
            timeline.push_back('1');
            runs++;
            overRuns++;
            std::cout << "Single (1)\n";
          } else if (random > 45 & random <= 55) {
            timeline.push_back('2');
            runs += 2;
            overRuns += 2;
            std::cout << "2 runs\n";
          } else if (random > 55 & random <= 60) {
            timeline.push_back('3');
            runs += 3;
            overRuns += 3;
            std::cout << "3 runs\n";
          } else if (random > 60 & random <= 80) {
            timeline.push_back('4');
            runs += 4;
            overRuns += 4;
            std::cout << "Boundary (4)\n";
          } else if (random > 80 & random <= 90) {
            timeline.push_back('6');
            runs += 6;
            overRuns += 6;
            std::cout << "MAXIMUM (6)\n";
          } else if (random > 90) {
            timeline.push_back('W');
            wickets++;
            std::cout << "OUT\n";
            if (wickets == 10) {
              break;
            }
          }
        }

        // Check if won
        if (innings == 2) {
          if (runs > oldRuns) {
            break;
          }
          std::cout << "Runs to Win: " << ((oldRuns + 1) - runs) << "\n";
        }
        std::cout << "Enter 'c' to Continue\n";
        std::cin >> null;
        system("clear");
      }

      // Increasing over number if six balls were finished
      if (ballNumber == 6) {
        ballNumber = 0;
        overNumber++;
      }

      // Checking if won or all out again
      if ((wickets == 10) || ((innings == 2) & (runs > oldRuns))) {
        break;
      } else if ((innings == 2) & (runs > oldRuns)) {
        break;
      }
      
      // Timeline after every over
      for (int i = 0; i < 6; i++) {
        timelineNumber = (6 * (overNumber - 2)) + i;
        std::cout << timeline[timelineNumber] << " ";
      }

      // Calculating run rate
      runRate = static_cast < double > (runs) / static_cast < double > ((overNumber - 1));

      // Printing all stats out
      std::cout << "\n\n";
      std::cout << "Runs last over: " << overRuns << "\n";
      std::cout << (overNumber - 1) << " over(s) up, " << runs << "/" << wickets << std::endl;
      std::cout << "Current run rate: " << runRate << "\n";
      if (innings == 2) {
        std::cout << "Runs to Win: " << ((oldRuns + 1) - runs) << "\n";
      }
      std::cout << "\nEnter 'c' to Continue\n";
      std::cin >> null;
      overRuns = 0;
      system("clear");
    }

    // Calculating run rate again
    runRate = static_cast < double > (runs) / static_cast < double > (((overNumber - 1) * 6 + ballNumber)) * static_cast < double > (6);

    // Printing out results
    if (wickets == 10) {
      std::cout << "All out at " << runs << " after " << overNumber << "." << ballNumber << " overs with a run rate of " << runRate << "!\n";
    } else {
      if (innings == 1) {
        std::cout << "First innings up.\n" << runs << "/" << wickets << " in 10 overs!\nRun rate: " << runRate << std::endl;
      } else if (runs == oldRuns) {
        std::cout << "Both teams tied\n";
      } else if (runs < oldRuns) {
        std::cout << "\nTeam 1 won by " << (oldRuns - runs) << " runs!\n";
      } else {
        std::cout << "\nTeam 2 won with " << (10 - wickets) << " wickets!\nRun rate: " << runRate << "\n";
      }
    }

    // Full innings timeline
    std::cout << "Do you want the full innings timeline(y/n): ";
    std::cin >> null;
    std::cout << "\n";

    // Total number of balls in innings (incase all out)
    ballNumber = 6 * (overNumber - 1) + ballNumber;

    
    if (null == "y") {
      for (int i = 0; i < ballNumber; i++) {
        std::cout << timeline[i] << " ";
        if (i % 6 == 5) {
          std::cout << std::endl;
        }
      }
      std::cout << "\nEnter 'c' to Continue\n";
      std::cin >> null;
    }
    
    system("clear");

    // Buffs and nerfs to chasing team incase batting team op or bad
    if (innings == 1 && runs > 140) {
      std::cout << "Chasing team will now get {buffed} as the score was above 140!\n";
    } else if (innings == 1 && runs < 100) {
      std::cout << "Chasing team will now get {nerfed} as the score was sub 100!\n";
    }
    std::cout << "\nEnter 'c' to Continue\n";
    std::cin >> null;
    system("clear");
    
    // Resetting all variables
    ballNumber = 0;
    overNumber = 1;
    wickets = 0;
    oldRuns = runs;
    runs = 0;
    timeline.clear();
    innings++;
  }
  // End
  std::cout << "Thank you for playing! To re-run, well re-run the program!\n";
}
