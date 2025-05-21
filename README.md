# Cricket Attax Sim
Console-based cricket match simulator based on weighted probabilities, inspired by a game I used to play with my brother using Cricket-Attax cards.

## Overview
This project is a cricket simulator that uses weighted probabilities realistically simulate T20 cricket matches (at a higher average run rate). The program is built for T20 but can be easily modified to a 10 over or 50 over format. Originally built to digitize a game my brother and I played using Cricket Attax cards and Alexa for randomness, the sim has evolved into a full-fledged text-based simulation with no balls, wides, dots, super overs, and much more.

## Features
The simulator has support for several features and is still being developed to add more. This is what we currently have and what is planned:
- [x] Basic 1, 2, 3, 4, 6, Wicket, dot ball
- [x] Wide balls
- [x] No balls
- [x] Over timeline
- [x] Match timeline
- [x] Run rate and required run rate
- [x] Super over
- [x] Scorecard
- [x] Powerplay weightage
- [ ] Death weightage (currently same as powerplay)
- [ ] Bowlers bat worse (different playing style different probabilties)
- [x] Partnerships
- [ ] Fall of wickets
- [ ] Projected Scores
- [ ] Choice of bowler and bowling stats
- [ ] Advanced stastics scorecard
- [ ] Randomized commentary

You can check issues on this repository for more planned changes as all will not be reflected here.

## Installation and Usage Instructions
1. Download the main.cpp file from this repo
2. Compile it using a C++ compiler (MSVC Works)
3. Run the compiled file

### Usage
- Press enter repeatedly to simulate ball-by-ball action
- Hold enter to simulate an innings entirely (wait till it auto stops)
- Type y at the end of an inning to get its timeline

## Personalize
### Teams
Change the teams by changing the names array on line 22 (put your new teams in batting order). The first team is always batting first but the second team always bats first in the super over. Change the position of the teams in the array to change who bats first (will be changed soon).

### Run Rate
Change probabilities by changing the values between line 138 and 211 (will be changed soon). After you change probabilities, calculate the par score (like 13 overs of regular play and 7 overs of powerplay - will be changed to 5 overs of powerplay and 2 overs of death soon) and replace 218 with it in the 'average' variable.

## Contributions
This game is open to contributions. With all the issues public, just solve any one of them and create a PR / comment on the issue to move towards merging it. I would greatly appreciate it!

## Backstory
My brother and I had a unique way of playing with Cricket Attax cards that completely ignored the values written on them. The cards were just to show that the player was on your team (when we collect cards it gives us more options) and had no impact other than that. Looking back, even that didn't matter since probabilities didn't change down the order. It was, and still is, fun to see your favorite player score 0 while a bowler hits a century! We used to use Alexa for the RNG between 1 and 6 (5 was wicket). This program replaces that.
