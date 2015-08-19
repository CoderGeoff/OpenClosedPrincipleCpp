#include <math.h>
#include "Scorer.h"

int Scorer::Score(const std::vector<int>& diceThrows) const
{
    int score = 0;

    for (int diceThrow = 1; diceThrow <= 6; ++diceThrow)
    {
        int scoreMultiplier = diceThrow == 1 ? 10 : diceThrow;
        int numberOfDuplicatesFound = std::count(diceThrows.begin(), diceThrows.end(), diceThrow);
        if (numberOfDuplicatesFound >= 3)
        {
            score += (100 * scoreMultiplier) * static_cast<int>(pow(2, numberOfDuplicatesFound - 3));
        }
    }

    if (std::count(diceThrows.begin(), diceThrows.end(), 5) == 1)
        score += 50;

    if (std::count(diceThrows.begin(), diceThrows.end(), 1) == 1)
        score += 100;

    return score;
}