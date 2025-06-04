#include "main.h"

int main()
{
  system("cls");
  std::string options = "";
  // Variable Declaration
  // Intro screen timeeee
  while (options != "5")
  {
    std::cout << "\n  _____      _      _        _                  \n / ____|    (_)    | |      | |                 \n| |     _ __ _  ___| | _____| |_                \n| |    | '__| |/ __| |/ / _ \\ __|               \n| |____| |  | | (__|   <  __/ |_                \n \\_____|_|  |_|\\___|_|\\_\\___|\\__| _             \n / ____(_)               | |     | |            \n| (___  _ _ __ ___  _   _| | __ _| |_ ___  _ __ \n \\___ \\| | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__|\n ____) | | | | | | | |_| | | (_| | || (_) | |   \n|_____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|   \n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n1. Draft-based Simulator (Interactive)\n2. Simple Simulator\n3. How to Play\n4. What is Cricket\n5. Exit\n";
    std::cin >> options;
    system("cls");

    switch (std::stoi(options))
    {
    case 1:
      draftSim();
      break;
    case 2:
      baseSim();
      break;
    case 3:
      std::cout << "This program basically generates a random number based on weighted percentages that co-relates to a certain number of runs hit or other activities such as wickets or wide balls.\n\n";
      std::cout << "I play the game by creating two teams of 11 players (one mine, one my brother's) and using the simulator to simulate both innings. I keep everything tracked on a note taking app or on paper and at the end can see the score, who hit the most runs, and see which bowler had the highest economy etc (in the sim bowlers are not implemented so it has to be done on paper). I am by no means have 'pro' level cricket knowledge so the RNG is not perfect but I did my best to keep the games a little high scoring with close matches.\n\nYou can adjust the number of overs by changing par score and changing the max overs variable. Another thing I want to note is that an '*' in the timeline means no ball and the following ball is a free hit. Have fun!\n\n";
      std::cout << "P.S. There is a buff for the chasing team if the batting team scores above 7/6 of par score and a nerf for the chasing team if the batting team scores below 5/6 of par score.\n\n";
      std::cout << "Enter to Continue\n";
      std::cin.ignore();
      std::getline(std::cin, options);
      system("cls");
      break;
    case 4:
      std::cout << "Cricket in a nutshell (from Wikipedia):\n";
      std::cout << "Cricket is a bat-and-ball game played between two teams of eleven players each on a field at the centre of which is a 22-yard (20-metre) pitch with a wicket at each end, each comprising two bails balanced on three stumps. The game proceeds when a player on the fielding team, called the bowler, 'bowls' (propels) the ball from one end of the pitch towards the wicket at the other end, with an 'over' being completed once they have legally done so six times. The batting side has one player at each end of the pitch, with the Player at the opposite end of the pitch from the bowler aiming to strike the ball with a bat. The batting side scores runs either when the ball reaches the boundary of the field, or when the two batters swap ends of the pitch, which results in one run. The fielding side's aim is to prevent run-scoring and dismiss each batter (so they are 'out', and are said to have 'lost their wicket'). Means of dismissal include being bowled, when the bowled ball hits the stumps and dislodges the bails, and by the fielding side either catching a hit ball before it touches the ground, or hitting a wicket with the ball before a batter can cross the crease line in front of the wicket to complete a run. When ten batters have been dismissed, the innings ends and the teams swap roles. The game is adjudicated by two umpires, aided by a third umpire and match referee in international matches.\n\n";
      std::cout << "Forms of cricket range from Twenty20, with each team batting for a single innings of 20 overs and the game generally lasting three hours, to Test matches played over five days.\n\n";
      std::cout << "Enter to Continue\n";
      std::cin.ignore();
      std::getline(std::cin, options);
      system("cls");
      break;
    case 5:
      // End
      std::cout << "Thank you for playing! To re-run, well re-run the program!\n";
      return 0;

    default:
      std::cout << "That is not an option, please try again!\n\n";
      std::cout << "Enter to Continue\n";
      std::cin.ignore();
      std::getline(std::cin, options);
      system("cls");
      break;
    }
  }
}
