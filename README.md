# Cricket Attax Sim
This project is a cricket simulator that incorporates weighted probabilities to make certain outcomes more likely than others. The program is built for T20 but can be easily modified to a 10 over or 50 over format. It was built to solve a problem me and my brother had with our method of playing with cricket attax cards and has since developed into a cricket sim with no balls, wides, dots, super over, and much more.

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
2. Build and run it using a C++ compiler (MSVC Works)
3. To run the sim and just see innings scorecard / timeline, hold enter until it auto stops
4. To watch ball by ball, simply press enter to move to the next ball
5. To finish the sim, hold enter again till innings 2 ends and a full match scorecard appears
6. To get timeline at end of innings, type 'y' and press enter in the console

## Personalize
### Teams
Change the teams by changing the names array on line 22 (put your new teams in batting order). The first team is always batting first but the second team always bats first in the super over. Change the position of the teams in the array to change who bats first (will be changed soon).

### Run Rate
Change probabilities by changing the values between line 138 and 211 (will be changed soon). After you change probabilities, calculate the par score (like 13 overs of regular play and 7 overs of powerplay - will be changed to 5 overs of powerplay and 2 overs of death soon) and replace 218 with it in the 'average' variable.

## Contributions
This game is open to contributions. With all the issues public, just solve any one of them and create a PR / comment on the issue to move towards merging it. I would greatly appreciate it as it helps reduce some of the work I have to do!

## Backstory
My brother and I had a weird way of playing with Cricket Attax cards that completely ignored the values written on them. The cards were just to show that the player was on your team (when we collect cards it gives us more options), and even that didn't matter cause the entire game was luck based. It was, and still is, a very fun game seeing your favorite players get golden ducked while the bowlers hit centuries! We used to use Alexa for the RNG between 1 and 6 (5 was wicket). This program replaces that.
