Go

10s

### Description

"Alpha Go is my little brother, I am much smarter than him."

---

AlphaGo is a computer program developed by Google DeepMind in London to play the board game Go. In October 2015, it became the first Computer Go program to beat a professional human Go player without handicaps on a full-sized 19×19 board.

In March 2016, it beat Lee Sedol in a five-game match, the first time a computer Go program has beaten a 9-dan professional without handicaps. Although it lost to Lee Sedol in the fourth game, Lee resigned the final game, giving a final score of 4 games to 1 in favour of AlphaGo. In recognition of beating Lee Sedol, AlphaGo was awarded an honorary 9-dan by the Korea Baduk Association.

AlphaGo's algorithm uses a Monte Carlo tree search to find its moves based on knowledge previously "learned" by machine learning, specifically by an artificial neural network (a deep learning kind) by extensive training, both from human and computer play.

As of 2016, AlphaGo's algorithm uses a combination of machine learning and tree search techniques, combined with extensive training, both from human and computer play. It uses Monte Carlo tree search, guided by a "value network" and a "policy network," both implemented using deep neural network technology.

A limited amount of game-specific feature detection pre-processing (for example, to highlight whether a move matches a nakade pattern) is applied to the input before it is sent to the neural networks.

The system's neural networks were initially bootstrapped from human gameplay expertise. AlphaGo was initially trained to mimic human play by attempting to match the moves of expert players from recorded historical games, using a database of around 30 million moves.

Once it had reached a certain degree of proficiency, it was trained further by being set to play large numbers of games against other instances of itself, using reinforcement learning to improve its play.

To avoid "disrespectfully" wasting its opponent's time, the program is specifically programmed to resign if its assessment of win probability falls beneath a certain threshold; for the March 2016 match against Lee, the resignation threshold was set to 20%.

AlphaGo's March 2016 victory was a major milestone in artificial intelligence research. Go had previously been regarded as a hard problem in machine learning that was expected to be out of reach for the technology of the time. Most experts thought a Go program as powerful as AlphaGo was at least five years away; some experts thought that it would take at least another decade before computers would beat Go champions.

Most observers at the beginning of the 2016 matches expected Lee to beat AlphaGo.

With games such as checkers (that has been "solved" by Chinook team), chess, and now Go won by computers, victories at popular board games can no longer serve as major milestones for artificial intelligence in the way that they used to. Deep Blue's Murray Campbell called AlphaGo's victory "the end of an era... board games are more or less done and it's time to move on."[32]

When compared with Deep Blue or with Watson, AlphaGo's underlying algorithms are potentially more general-purpose, and may be evidence that the scientific community is making progress toward artificial general intelligence.

Some commentators believe AlphaGo's victory makes for a good opportunity for society to start discussing preparations for the possible future impact of machines with general purpose intelligence. (As noted by entrepreneur Guy Suter, AlphaGo itself only knows how to play Go, and doesn't possess general purpose intelligence: "It couldn't just wake up one morning and decide it wants to learn how to use firearms").

In March 2016, AI researcher Stuart Russell stated that "AI methods are progressing much faster than expected, (which) makes the question of the long-term outcome more urgent," adding that "in order to ensure that increasingly powerful AI systems remain completely under human control... there is a lot of work to do."

Some scholars, such as Stephen Hawking, warned (in May 2015 before matches) that some future self-improving AI could gain actual general intelligence, leading to an unexpected AI takeover; other scholars disagree: AI expert Jean-Gabriel Ganascia believes that "Things like 'common sense'... may never be reproducible", and says "I don't see why we would speak about fears. On the contrary, this raises hopes in many domains such as health and space exploration."

Computer scientist Richard Sutton "I don't think people should be scared... but I do think people should be paying attention."

Now, HE wants to play a Go game with you! Eee ... I'm sorry it is just a kidding. \^_^/

Your task is much more easy. Just count out which side has more  pieces in the board.

### Input

The first line is an integer T, indicate there will be T test cases.

For each test cases:

There will be a 19*19 grid representing the Go board.

"#" means no piece, 0 means white piece and 1 means black piece.

### Output

For each test cases:

First output the case number like "Case #x:", x is the sequence number of that test case.

Then output "Black" if there are more black pieces in the board, or "White" otherwise.

If there are equal number of black pieces and white pieces, just output "Equal".

You don't have to care about whether some pieces will have to be removed from the board. Just count!

### Sample Input

```
1
###################
###################
###10##############
###00##############
###################
###################
###################
###################
###################
###################
###################
###################
###################
###################
##############111##
###############0###
###################
###################
###################
```

### Sample Output

```
Case #1:
Equal
```