# MinionSwarm

Michigan State University
CSE 335 - Object Oriented Software Development (Fall 2017)
Project 01

There are three distinct areas of the screen. The middle area, contained in the green box, is the playing area. To the left of the playing area is the new-game button. To the right is the scoring area. 

In the game area we have Gru . Gru can be dragged around using the mouse. Click on Gru to drag him. Minions appear randomly at the top of the screen every 0.5 to 1 second (randomly selected). The minions flock towards Gru because that's what minions do. There are three different minions:
    -Stuart. Stuart is worth 1 point.
    -Jerry. Jerry is worth 1 point.
    -Mutant Minion. Mutant minions are less common (only about 1 out of every 10) and worth 5 points.

There are three villains on the screen at fixed locations (they do not move):
  -The Juicer. You can guess what it does with Minions and why the juice is yellow. The juicer has a point multiplier of 2.
  -A Pokeball. Yes, we are mixing our cultural references here. The pokeball has a point multiplier of 3.
  -Arya Stark. Arya hates Minions. And, as long as we're mixing our cultural references, we might as well go all the way. Arya has a point    multiplier of 1.
  
When a minion touches a villain, it is destroyed and the points are assigned to that villain and appear on the scoreboard to the right. Each villain has point multiplier indicated in the table above. The points are multiplied by that amount. If a mutant hits Arya stark, 5 points are assigned to Arya (5 points for the mutant times a multiplier of 1). If Jerry hits a Pokeball, 3 points are assigned to the Pokeball score (1 point for Jerry times a multiplier of 3). Pokeballs are smaller and harder to lure the minions to.

If a minion touches Gru or if Gru touches any villain, Gru dies and the game is over. The objective of the game is two-fold: 1) to move Gru around so that he lures the minions into a villain, thereby accumulating points and 2) to keep Gru alive as long as possible.



