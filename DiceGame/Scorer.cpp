#include "Scorer.h"

int Scorer::Score(const std::vector<int>& diceThrows) const
{
    int score = 0;
    for (auto i = diceThrows.begin(); i != diceThrows.end(); ++i)
    {
        if (*i == 5) score = 50;
    }
    return score;
}