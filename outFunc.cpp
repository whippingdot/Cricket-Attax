#include "main.h"

bool outPutRuns(std::string type, int x, std::array<std::vector<char>, maxOvers> &array, int &runO, int &runT, int overN, int &ballN, int &outs, std::array<int, 2> &batsmen, std::array<int, 2> &index, bool &on, std::array<std::array<std::array<int, 3>, 11>, 2> &team, int inning, std::array<int, 2> &balls, std::array<int, 4> &partner, std::vector<std::array<int, 4>> &partners, bool &fHit, std::array<std::vector<std::array<int, 5>>, 2> &fall, int &wickT, int &wickTCount, bool &added, std::array<std::array<std::string, 11>, 2> names, std::string bowler)
{
  char number = ' ';
  int tRandom = std::rand() % 100 + 1;
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

  if (x == 1 || x == 2 || x == 3 || x == 4 || x == 6)
  {
    array[overN - 1].push_back(number);
    fHit = false;
    if (tRandom == 18)
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
    array[overN - 1].push_back('.');
    fHit = false;
    if (tRandom == 18)
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
    if ((tRandom == 18 || tRandom == 21) && !fHit)
    {
      array[overN - 1].push_back('n');
      std::cout << "\nBUT ITS A NO BALL!\n";
      runT++;
      runO++;
      partner[0]++;
    }
    else if (tRandom == 18 || tRandom == 21)
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
      team[inning - 1][index[0]][0] = batsmen[0];
      team[inning - 1][index[0]][1] = balls[0];
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
        outBy[inning - 1][index[0]] = bowler;
      }
      else if (type == "sim")
      {
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
      if (!fHit)
      {
        outs++;
        wickT += 1;
        added = true;
      }
      fHit = false;
      ballN++;
    }
  }

  int ball = (overN - 1) * 6 + ballN;
  // std::cout << "WICKETS IN LAST 20: " << wickT << " + real ball no: " << ball << std::endl;
  if (ball >= 26 && ball - wickTCount == 26)
  {
    // std::cout << wickTCount << std::endl;
    int remainder = wickTCount % 6;
    // std::cout << remainder << std::endl;
    int extras = 0;
    for (int i = 0; i < array[wickTCount / 6].size(); i++)
    {
      // std::cout << array[wickTCount / 6][i] << std::endl;
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

  if (outs == 10)
    return true;

  return false;
}

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