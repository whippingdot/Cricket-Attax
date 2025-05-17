# Cricket-Attax

My brother and I had a weird way of playing with Cricket Attax cards that completely ignored the values written on them. The cards were just to show that the player was on your team (when we collect cards it gives us more options), and even that didn't matter cause the entire game was luck based. It was, and still is, a very fun game seeing your favorite players get golden ducked while the bowlers hit centuries!

We used to use Alexa for the RNG between 1 and 6 (5 was wicket). The reason for the creation of this program was to do that same job but with more realistic weighted probabilities. It also allows for the addition of dot balls, no balls, wide balls, etc.

While I recommend running the code after cloning the repo, a slightly outdated version is in the repl below. Replit has changed so I am unsure of whether the repl will work though.

Repl: https://replit.com/@Whippingdot/Cricket-Attax-Gen

## How to Use

Clone the program onto your system and run the C++ file (you can fork the repl and use that to run as it compiles and does everything). After that, all you have to do is press any key and enter to continue while it tells you how many runs was hit on that ball. After each over a timeline of the over will be displayed, and after the whole innings the program asks you if you want the whole innings' timeline. In the second innings it shows the runs to win, and the same other stuff. I have added a bunch of other quality of life features and stats that show you more about the flow of the match as well. Scorecards, partnerships, etc. are all available (with possibly advanced statistics in the future). You can tweak the overs to how many ever you want, but for now mine is kept at 20 to simulate T20.

## Feature Checklist

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
