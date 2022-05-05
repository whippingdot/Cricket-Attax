#include <iostream>

#include <cstdlib>

#include <time.h>

#include <vector>

int main() {
  int overNumber = 1;
  int ballNumber = 0;
  int runs = 0;
  int wickets = 0;
  int innings = 1;
  int random = 0;
  int timelineNumber = 0;
  int oldRuns = 0;

  std::string null = "";

  std::vector < char > timeline = std::vector < char > ();

  time_t nTime;

  std::srand((unsigned) time( & nTime));

  while (innings < 3) {
    std::cout << "INNINGS NUMBER " << innings << std::endl;
    while (overNumber <= 10) {
      while (ballNumber < 6) {
        random = std::rand() % 100 + 1;
        ballNumber++;

        if (random <= 35) {
          timeline.push_back('.');
          std::cout << ".\n";
        } else if (random > 35 & random <= 63) {
          timeline.push_back('1');
          runs++;
          std::cout << "Single (1)\n";
        } else if (random > 63 & random <= 78) {
          timeline.push_back('2');
          runs += 2;
          std::cout << "2 runs\n";
        } else if (random > 78 & random <= 80) {
          timeline.push_back('3');
          runs += 3;
          std::cout << "3 runs\n";
        } else if (random > 80 & random <= 90) {
          timeline.push_back('4');
          runs += 4;
          std::cout << "Boundary (4)\n";
        } else if (random > 90 & random <= 95) {
          timeline.push_back('6');
          runs += 6;
          std::cout << "MAXIMUM (6)\n";
        } else if (random > 95 & random <= 100) {
          timeline.push_back('W');
          wickets++;
          std::cout << "OUT\n";
          if (wickets == 10) {
            break;
          }
        }

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
      if (ballNumber == 6) {
        ballNumber = 0;
        overNumber++;
      }

      if ((wickets == 10) || ((innings == 2) & (runs > oldRuns))) {
        break;
      } else if ((innings == 2) & (runs > oldRuns)) {
        break;
      }

      for (int i = 0; i < 6; i++) {
        timelineNumber = (6 * (overNumber - 2)) + i;
        std::cout << timeline[timelineNumber] << " ";
      }

      std::cout << "\n\n";
      std::cout << (overNumber - 1) << " over(s) up, " << runs << "/" << wickets << std::endl;
      if (innings == 2) {
        std::cout << "Runs to Win: " << ((oldRuns + 1) - runs) << "\n";
      }
      std::cout << "\nEnter 'c' to Continue\n";
      std::cin >> null;
      system("clear");
    }
    if (wickets == 10) {
      std::cout << "All out at " << runs << " after " << overNumber << "." << ballNumber << " overs!\n";
    } else {
      if (innings == 1) {
        std::cout << "First innings up.\n" << runs << "/" << wickets << " in 10 overs!\n";
      } else if (runs == oldRuns) {
        std::cout << "Both teams tied\n";
      } else if (runs < oldRuns) {
        std::cout << "Team 1 won by " << (oldRuns - runs) << " runs!\n";
      } else {
        std::cout << "Team 2 won with " << (10 - wickets) << " wickets!\n";
      }
    }

    std::cout << "Do you want the full innings timeline(y/n): ";
    std::cin >> null;

    ballNumber = 6 * overNumber + ballNumber;

    if (null == "y") {
      for (int i = 0; i < ballNumber; i++) {
        std::cout << timeline[i] << " ";
        if (i % 6 == 5) {
          std::cout << std::endl;
        }
      }
      std::cout << "Enter 'c' to Continue\n";
      std::cin >> null;
    }
    system("clear");
    ballNumber = 0;
    overNumber = 1;
    wickets = 0;
    oldRuns = runs;
    runs = 0;
    timeline.clear();
    innings++;
  }
}
