#include "Scorer.h"

int Scorer::Score(const std::vector<int>& diceThrows) const
{
    int score = 0;

    if (std::count(diceThrows.begin(), diceThrows.end(), 5) == 1)
        score += 50;

    if (std::count(diceThrows.begin(), diceThrows.end(), 1) == 1)
        score += 100;

    return score;
}