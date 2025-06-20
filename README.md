# Cricket Attax Sim

Console cricket match simulator built using weighted probabilities, inspired by a game I used to play with my brother using Cricket-Attax cards.

## Overview

This project is a cricket simulator that uses weighted probabilities to realistically simulate T20 cricket matches (at a higher average run rate). The program is built for T20 but can be easily modified to a 10 over or 50 over format. Originally built to make a game my brother and I played using Cricket Attax cards and Alexa for randomness more realistic, the sim has evolved into a full-fledged text-based simulation with no balls, wides, dots, super overs, a draft, dynamic play, strategy, and much more.

## Features

The simulator has the implementation of the basic rules of cricket and has some nuances of cricket like pitch conditions and dew backlogged for the future. This is what I currently have developed and what is planned:

- [x] Basic 1, 2, 3, 4, 6, Wicket, dot ball
- [x] Wide balls
- [x] No balls
- [x] Over timeline
- [x] Match timeline
- [x] Run rate and required run rate
- [x] Super over
- [x] Scorecard
- [x] Powerplay weightage
- [x] Death weightage
- [x] Different set of probabilities for non-batsmen
- [x] Partnerships
- [x] Fall of wickets
- [x] Projected Scores
- [x] Choice of bowler and bowling stats
- [x] Choice of batter whenever wicket falls
- [x] Draft system before the game
- [x] Custom probability changes for every implemented batsman and all rounder (when batting)
- [x] Custom probability changes for every implemented bowler and all rounder (when bowling)
- [x] Yorker ball chance for pace bowlers
- [ ] Implement more factors that affect the game (dew, pressure, pitch conditions)
- [ ] Punish batters playing out of position (like a finisher playing higher up the order)
- [ ] Advanced stastics scorecard
- [ ] Randomized commentary

You can check issues on this repository for more planned changes as all will not be reflected here.

## Installation and Usage Instructions

### Option 1

The easiest way to run the program is to follow the onlineGDB link and run it in the built in console there (enlarge it): https://onlinegdb.com/yMbm0ecu1R

### Option 2

If you prefer more customization or an editable experience, I recommend cloning the respository and running the files. To run the files you require a C++ compiler that supports **c++20**, preferably [MSYS2 MinGW Compiler](https://www.msys2.org/), and [VSCode](https://code.visualstudio.com/) or another text editor / IDE you are comfortable with (I use Visual Studio).

1. Either clone the repository using Git or download the ZIP file
2. When using x64 machine, after downloading MSYS2 and your editor run the following in MSYS2 MinGW 64-bit terminal:
   ```bash
   pacman -Syu
   pacman -S mingw-w64-x86_64-gcc make clang
   ```
3. That installs the C++ compiler and build tools. Open the extracted project on VSCode now. Ensure the C/C++ extension on VSCode is installed
4. To compile and run the code, the easiest way is to create a task (serach online) for it or run the provided makefile by going to the repository folder in your MinGW terminal and running:
   ```bash
   make
   ./main
   ```

### Usage

- In draft mode simply pick batsmen and bowlers alternatively (snake draft style) till pick 22
- The players you pick have an effect on gameplay and each have their special buffs, nerfs, and special effects (check out Buffs&Nerfs.md for more)
- Afterwards, pick bowlers every over and your opening batsmen along with other batsmen whenever a wicket falls
- Press enter repeatedly to simulate ball-by-ball action
- At the end of a match, type y on the pop-up that asks you if you want to replay the match with the same teams if you wish to repeat with same teams or type n if you wish to start a new draft / end the game

- In default sim mode, simply hold enter to simulate an innings entirely (wait till it auto stops) or press enter repeatedly to simulate ball-by-ball action

- In both sim types, type y at the end of an inning to get its timeline

## Default Sim Mode Personalization

### Teams

To add to the available batsmen, add:

- On draft-sim.cpp: Your required batsman full name to the `players` unordered_map in the same format, add their nickname in the same format, add their name to the variable for the position they play
- On draft.cpp: A struct for your required batsman with custom made nerfs, special buffs below in the function, and their full name in the Players map along with their struct name

### Run Rate

To change the run rate, change all the percentage values (values in the form of 0.03 - meaning 3% - and such) of dots, singles, two runs, three runs, fours, sixes, and wides. The remaining percentage is the wicket chance.

## Default Sim Mode Personalization

### Teams

Change the teams by changing the names array on line 70 (put your new teams in batting order as ability to choose batsman or bowler not available in this base sim). The changing of teams has no effect on gameplay.

### Run Rate

Same principle as for the Draft Sim.

## Contributions

This game is open to contributions. With all the issues public, just solve any one of them and create a PR / comment on the issue to move towards merging it. I would greatly appreciate it!

## Backstory

My brother and I had a unique way of playing with Cricket Attax cards that completely ignored the values written on them. The cards were just to show that the player was on your team (when we collect cards it gives us more options) and had no impact other than that. Looking back, even that didn't matter since probabilities didn't change down the order. It was, and still is, fun to see your favorite player score 0 while a bowler hits a century! We used to use Alexa for the RNG between 1 and 6 (5 was wicket). This program replaces that.
