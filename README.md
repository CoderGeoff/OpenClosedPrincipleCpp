# OpenCloseCpp
An exercise to underline the OCP

Here you will see the following classes

In DiceGame:

| Class | Description |
|-------|-------------|
| Scorer | Calculates the score for a throw of one to six dice, based on the rules of "10000"*. The implementation doesn't obey the open - closed principle.|

In OpenClosedDiceGame:

| Class | Description |
|-------|-------------|
| OpenClosedScorer | Calculates the score for a throw of one to six dice, based on the rules of "10000"*. The implementation *does* obey the open - closed principle.|

In WordCounterTests:

| Class | Description |
|-------|-------------|
| ScorerTests | Test a number of key scoring scenarios. The test run on both implementations of the Scorer. |

## Scoring for 10000*
I won't cover all the rules of the game here. It's enough to know that a player can throw between 1 and 6 dice and have them scored
as follows

* Single fives are worth 50 points
* Single ones are worth 100 points
* Three of a kind are worth 100 points times the number rolled, except for three ones which are worth 1000 points
* If four, five, or six of a kind are rolled, each additional die is worth double the three of a kind score. (This makes the highest possible score in a single roll 8000 for six ones: 1000 for three ones, doubled 3 times.)
* A straight from 1 to 6 is worth 1500 points
* Three pairs are worth 750 points
You can only score each die once.

## Task 1
The players want to add a new rule: 
* Three of a kind a pair score the three of a kind value plus 250

Your job is to implement this for 
