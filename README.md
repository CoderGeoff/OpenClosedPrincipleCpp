# OpenCloseCpp
An exercise to underline the OCP

Here you will see the following classes

In DiceGame:

| Class | Description |
|-------|-------------|
| Scorer | Calculates the score for a throw of one to six dice, based on the rules of "10000" (see below). The implementation doesn't obey the open - closed principle.|

In OpenClosedDiceGame:

| Class | Description |
|-------|-------------|
| OpenClosedScorer | Calculates the score for a throw of one to six dice, based on the rules of "10000". The implementation *does* obey the open - closed principle.|
| ScoringRulesFactory | Creates the rules that OpenClosedScorer uses to score the throw of the dice. |
| ScoringRulesResult | Describes the data returned by a scoring rule (including the score!) |
| IScoringRule | Base class for a scoring rule |
| NOfAKindScoresXRule | A general rule that matches n dice that have a value that meets a giving condition, and and gives them a score. |
| PatternScoresXRule | A  general rule that matches a fixed dice pattern and gives it a score. |

In DiceGameTests:

| Class | Description |
|-------|-------------|
| ScorerTests | Test a number of key scoring scenarios. The test run on both implementations of the Scorer. |
| NewRuleTest | An empty test fixture which you will use in the exercise. |

## Scoring for 10000
I won't cover all the rules of the game here. It's enough to know that a player can throw between 1 and 6 dice and have them scored
as follows

* Single fives are worth 50 points
* Single ones are worth 100 points
* Three of a kind are worth 100 points times the number rolled, except for three ones which are worth 1000 points
* If four, five, or six of a kind are rolled, each additional die is worth double the three of a kind score. (This makes the highest possible score in a single roll 8000 for six ones: 1000 for three ones, doubled 3 times.)
* A straight flush from 1 to 6 (that is, a roll of {1, 2, 3, 4, 5, 6}) is worth 1500 points
You can only score each die once.

## Task 1
The players want to change the score for six ones from 8000 to 10000.
Implement this as follows

# Change the test GivenThreeDie_WhenAllOnesAreThrown_ScoreShouldBe1000
# Change Scorer to get it to pass the test
# Change OpenClosedScorer

## Task 2
The players want to remove all the rules that match three of a kind (three 1s, three 2s etc.) 
Implement this as follows

# Change the tests GivenThreeDie...etc. to validate that the score is 0 in each case
# Change Scorer to implement the change
# Change OpenClosedScorer to make the same change

## Task 3
The players want to add a new rule: fours 2s and a pair of 3s score 1500, and so do four 3s and pair of 2s. This is scored instead of the normal score for four 2s or four 3s.
Implement this as follows
# Add two tests to validate the new rule
# Change Scorer to implement the new rule
# Change OpenClosedScorer to make the same change

# Task 4
The tests in ScorerTests were written intially for the scorer that doesn't obey the open-closed principle and were retro-fitted to the OpenClosedScorer. If we had started from 
scratch with the OpenClosed scorer, the tests would have looked very different; jot down two significant differences would you expect to see.
