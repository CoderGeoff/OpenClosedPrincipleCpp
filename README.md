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
| NOfAKindScoresXRule | A general rule that matches n dice of the same value gives them a score. |
| StraightFlushRule | A  rule that matches a straight flush and gives it a score. |

In WordCounterTests:

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
The players want to add a new rule: 
* Three of a kind plus a pair score the three of a kind value plus 250

Your job is to change Scorer to implement this rule. Write a test for the rule in the test fixture NewRuleTest.

## Task 3
Now change OpenClosedScorer to implement this rule. Before implementing, move your test to ScorerTests, so that it runs on both types of scorer.
