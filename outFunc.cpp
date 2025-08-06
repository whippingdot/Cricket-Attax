#include "main.h"

bool outPutRuns(std::string type, int x, std::array<std::vector<char>, maxOvers> &array, int &runO, int &runT, int overN, int &ballN, int &outs, std::array<int, 2> &batsmen, std::array<int, 2> &index, bool &on, std::array<std::array<std::array<int, 3>, 11>, 2> &team, int inning, std::array<int, 2> &balls, std::array<int, 4> &partner, std::vector<std::array<int, 4>> &partners, bool &fHit, std::array<std::vector<std::array<int, 5>>, 2> &fall, int &wickT, int &wickTCount, bool &added, std::array<std::array<std::string, 11>, 2> names, std::string bowler, int special, int bouncer)
{
  // Variable declaration - the number variable is a char because it is used in a character array that is used to have the full innings' timeline
  char number = ' ';
  std::uniform_int_distribution<> hundo(1, 100);
  int tRandom = hundo(global_rng());
  // Resets the 'added' variable which tracks if a wicket was taken last ball which helps when introducing the collapse tracker and resetting it on a new wicket
  added = false;

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

  if (special == 1 && bouncer >= 2) {
    std::cout << "\nNot the first bouncer of the over so...";
  }

  if (x == 1 || x == 2 || x == 3 || x == 4 || x == 6)
  {
    // array is the timeline variable which stores the whole timeline of the innings
    array[overN - 1].push_back(number);
    // Resets if the last ball was a free hit
    fHit = false;
    if ((special == 1 && bouncer >= 2) || tRandom == 18)
    {
      // Logic for a free hit. Adding 'n' to the timeline is useful as when outputting the timeline we check for 'n' and convert it to *, skipping its index
      fHit = true;
      array[overN - 1].push_back('n');
      std::cout << "\nNO BALL! Free hit next ball!\n";
      runT++;
      runO++;
      partner[0]++;
    }
    else
    {
      partner[1]++;
      // Only if not free hit we increment ball number
      ballN++;
    }
    runT += x;
    runO += x;
    partner[0] += x;
    // Individual batsman run incrementing logic
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

    // Outputting batsman stats
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

    // Changing strike
    if (x == 1 || x == 3)
      on = !on;
  }
  else if (x == 5)
  {
    array[overN - 1].push_back('.');
    fHit = false;
    if ((special == 1 && bouncer >= 2) || tRandom == 18)
    {
      fHit = true;
      array[overN - 1].push_back('n');
      std::cout << "\nNO BALL! Free hit next ball!\n";
      runT++;
      runO++;
      partner[0]++;
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
    array[overN - 1].push_back('w');
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
  }
  else if (x == 8)
  {
    array[overN - 1].push_back('W');
    if (((special == 1 && bouncer >= 2) || (tRandom == 18 || tRandom == 21)) && !fHit)
    {
      array[overN - 1].push_back('n');
      std::cout << "\nBUT ITS A NO BALL!\n";
      runT++;
      runO++;
      partner[0]++;
    }
    else if ((special == 1 && bouncer >= 2) || tRandom == 18 || tRandom == 21)
    {
      array[overN - 1].push_back('n');
      std::cout << "\nBUT ITS A NO BALL AGAIN!\n";
      runT++;
      runO++;
      partner[0]++;
    }
    else if (fHit)
    {
      std::cout << "\nSince last ball was a no ball it doesn't count...\n";
      on ? balls[0]++ : balls[1]++;
      partner[1]++;
    }
    else if (on)
    {
      std::array<int, 5> fOW = std::array<int, 5>();
      balls[0]++;
      // This saves the batsman's stats before replacing his index
      team[inning - 1][index[0]][0] = batsmen[0];
      team[inning - 1][index[0]][1] = balls[0];
      // This variable tracks the fall of wickets and all its required stats
      fOW[0] = outs + 1;
      fOW[1] = runT;
      fOW[2] = index[0];
      fOW[3] = overN - 1;
      fOW[4] = ballN + 1;
      fall[inning - 1].push_back(fOW);
      std::cout << "\n"
                << names[inning - 1][index[0]] << "*: " << batsmen[0] << " in " << balls[0] << " - OUT\n";
      std::cout << names[inning - 1][index[1]] << ": " << batsmen[1] << " in " << balls[1] << "\n\n";
      batsmen[0] = 0;
      balls[0] = 0;
      partner[2] = index[0];
      partner[3] = index[1];

      if (type == "draft")
      {
        // If it is the draft sim we add the bowler to outBy, a global variable that tracks who took whose wicket
        outBy[inning - 1][index[0]] = bowler;
      }
      else if (type == "sim")
      {
        // If regular sim we just change the index of the batsman. This is not done in the draft sim since the choice of next batsman is given
        if (index[0] > index[1])
          index[0]++;
        else
          index[0] = index[1] + 1;

        if (index[0] <= 10)
        {
          team[inning - 1][index[0]][2] = 1;
        }
      }
    }
    else
    {
      std::array<int, 5> fOW = std::array<int, 5>();
      balls[1]++;
      team[inning - 1][index[1]][0] = batsmen[1];
      team[inning - 1][index[1]][1] = balls[1];
      fOW[0] = outs + 1;
      fOW[1] = runT;
      fOW[2] = index[1];
      fOW[3] = overN - 1;
      fOW[4] = ballN + 1;
      fall[inning - 1].push_back(fOW);
      std::cout << "\n"
                << names[inning - 1][index[1]] << "*: " << batsmen[1] << " in " << balls[1] << " - OUT\n";
      std::cout << names[inning - 1][index[0]] << ": " << batsmen[0] << " in " << balls[0] << "\n\n";
      batsmen[1] = 0;
      balls[1] = 0;
      partner[2] = index[0];
      partner[3] = index[1];

      if (type == "draft")
      {
        outBy[inning - 1][index[1]] = bowler;
      }
      else if (type == "sim")
      {
        if (index[0] < index[1])
          index[1]++;
        else
          index[1] = index[0] + 1;
        if (index[1] <= 10)
        {
          team[inning - 1][index[1]][2] = 1;
        }
      }
    }

    if ((special == 1 && bouncer >= 2) || tRandom == 18 || tRandom == 21 || fHit)
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
      // When not a free hit and when the wicket actually falls, we have to save the partnership and start a new one
      partner[1]++;
      std::cout << "Broken partnership: " << partner[0] << " in " << partner[1] << "\n";
      partners.push_back(partner);
      partner[0] = 0;
      partner[1] = 0;
    }

    if ((special == 1 && bouncer >= 2) || tRandom == 18 || tRandom == 21)
    {
      fHit = true;
    }
    else
    {
      if (!fHit)
      {
        // This is when a wicket actually falls instead of it being a free hit ball
        outs++;
        wickT += 1;
        added = true;
      }
      fHit = false;
      ballN++;
    }
  }

  // The following variable notes the current ball number (including the extras in this over) so it can accurately iterate through the last 25 balls and see if 3 wickets have fallen (triggers the collapse effect that reduces run rate while decreasing wicket chance)
  int ball = (overN - 1) * 6 + ballN;
  // wickTCount is a counter that is delayed by 26 and starts only on the 26th ball (so it counts from when this collapse indicator is viable)
  if (ball >= 26 && ball - wickTCount == 26)
  {
    int remainder = wickTCount % 6;
    // Tracks number of extras in an over so it can correctly track number of correct balls passed
    int extras = 0;
    for (int i = 0; i < array[wickTCount / 6].size(); i++)
    {
      if (array[wickTCount / 6][i] == 'w')
      {
        extras += 1;
      }
      else if (i + 1 != array[wickTCount / 6].size())
      {
        if (array[wickTCount / 6][i + 1] == 'n')
        {
          extras += 2;
        }
      }
      if (i - extras == remainder)
      {
        break;
      }
    }
    remainder += extras;

    if (array[wickTCount / 6][remainder] == 'W')
    {
      wickT--;
    }

    wickTCount++;
  }

  // Returns true causing 'e' to be true which breaks out of the ball and over loop. This is if all out occurs
  if (outs == 10)
    return true;

  return false;
}

// Super over system that lacks bowler logic and a few other features that were added after super overs were implemented
bool superO(int x, std::array<std::vector<char>, 2> &array, int &runO, int &ballN, int &outs, std::array<int, 2> &batsmen, std::array<int, 2> &index, bool &on, std::array<std::array<std::array<int, 3>, 3>, 2> &team, int inning, std::array<int, 2> &balls, std::array<int, 4> &partner, std::array<std::array<std::string, 3>, 2> nNames, bool &fHit)
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
    array[inning - 1].push_back(number);
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
    array[inning - 1].push_back('.');
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
    array[inning - 1].push_back('w');
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
  }
  else if (x == 8)
  {
    array[inning - 1].push_back('W');
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
      {
        index[1]++;
      }
      else
      {
        index[1] = index[0] + 1;
      }
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
  {
    return true;
  }

  return false;
}