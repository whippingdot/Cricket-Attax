#include "main.h"
// Hello! Welcome to my repository and code for the Cricket Attax Simulator I made! Feel free to explore all the files and attempt to understand the code - it is all very basic and I hope I can explain it in an easy way for anyone new!
int main()
{
  // Clearing the screen for the UI
  system("cls");
  // Variable Declaration
  std::string options = "";
  std::string rerun = "";

  // Intro screen (UI) and choice of either draft-based sim, regular sim, or questions about Cricket / the sim
  while (options != "5")
  {
    if (rerun != "y" && rerun != "debug")
    {
      // You can get these large text boxes that look nice by searching up ASCII art generators. Remember to add a '\' before every '\' in the string since back slashes usually precede a command in C++ strings so it will not show up when outputting solo
      std::cout << "\n  _____      _      _        _                  \n / ____|    (_)    | |      | |                 \n| |     _ __ _  ___| | _____| |_                \n| |    | '__| |/ __| |/ / _ \\ __|               \n| |____| |  | | (__|   <  __/ |_                \n \\_____|_|  |_|\\___|_|\\_\\___|\\__| _             \n / ____(_)               | |     | |            \n| (___  _ _ __ ___  _   _| | __ _| |_ ___  _ __ \n \\___ \\| | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__|\n ____) | | | | | | | |_| | | (_| | || (_) | |   \n|_____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|   \n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n1. Draft-based Simulator (Interactive)\n2. Simple Simulator\n3. How to Play\n4. What is Cricket\n5. Exit\n";
      // This is what will be used throughout the program along with getline (below) to get inputs. When you get an input from cin, it adds a newline to the end of the input so if getline is used right after it, it will skip that getline. For this reason you have to use cin.ignore to clear the input box before running std::getline
      std::cin >> options;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      system("cls");
    }

    // This is a switch-case block where we use stoi to convert the string input to an integer value and we have different outcomes based on the interger value. Each case in a switch case requires a break at the end otherwise it will go from the case to the default and also perform the action in default even when not intended
    switch (std::stoi(options))
    {
    case 1:
      // I decided to create functions for both the draft-based sim and the regular sim as they both had lots of logic and having all the logic here would make this file extremely hard to navigate. Creating a seperate file and function which you 'extern' in the header file is much more practical
      draftSim(rerun);
      std::cout << "Do you want to run it back with the same teams (y/n)? ";
      // This is the other method of getting an input. The difference is cin doesn't count whitespace or new lines as input while getline does. This is why you need to clear cin cache using cin.ignore before running getline
      std::getline(std::cin, rerun);
      system("cls");
      break;
    case 2:
      // Function for the base simulation
      baseSim();
      break;
    case 3:
      // Just large strings that explain a lot of stuff are put here and in case 4. This is just to help introduce someone to the game or to cricket
      std::cout << "This program basically generates a random number based on weighted percentages that co-relates to a certain number of runs hit or other activities such as wickets or wide balls.\n\n";
      std::cout << "I play the game by creating two teams of 11 players (one mine, one my brother's) and using the simulator to simulate both innings. I keep everything tracked on a note taking app or on paper and at the end can see the score, who hit the most runs, and see which bowler had the highest economy etc (in the sim bowlers are not implemented so it has to be done on paper). I am by no means have 'pro' level cricket knowledge so the RNG is not perfect but I did my best to keep the games a little high scoring with close matches.\n\nYou can adjust the number of overs by changing par score and changing the max overs variable. Another thing I want to note is that an '*' in the timeline means no ball and the following ball is a free hit. Have fun!\n\n";
      std::cout << "P.S. There is a buff for the chasing team if the batting team scores above 7/6 of par score and a nerf for the chasing team if the batting team scores below 5/6 of par score.\n\n";
      std::cout << "Enter to Continue\n";
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
      std::cout << "Thank you for playing! To re-run, well re-run the program!\n";
      // Return 0 ends the program without any errors
      return 0;

    default:
      // In a switch-case block the default option is the backup incase someone enters something not expected. This will only work in case of a number not expected tho as above we converted the input to a number and anything else would return an error and crash the program
      std::cout << "That is not an option, please try again!\n\n";
      std::cout << "Enter to Continue\n";
      std::getline(std::cin, options);
      system("cls");
      break;
    }
  }
}
