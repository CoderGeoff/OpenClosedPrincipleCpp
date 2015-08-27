#include "Scorer.h"

int Scorer::Score(const std::vector<int>& diceThrows) const
{
    int score = 0;
    int diceCount[7];

    for (int i = 0; i <= 6; ++i)
    {
        diceCount[i] = std::count(diceThrows.begin(), diceThrows.end(), i);
    }

    bool fullStraight = true;
    for (int diceThrow = 1; diceThrow <= 6; ++diceThrow)
    {
        fullStraight = fullStraight && diceCount[diceThrow] == 1;
    }
    if (fullStraight)
    {
        for (int diceThrow = 1; diceThrow <= 6; ++diceThrow)
        {
            diceCount[diceThrow]--;
        }
        score += 1500;
    }

    for (int diceThrow = 1; diceThrow <= 6; ++diceThrow)
    {
        int scoreMultiplier = diceThrow == 1 ? 10 : diceThrow;
        if (diceCount[diceThrow] >= 3)
        {
            score += (100 * scoreMultiplier) * static_cast<int>(pow(2, diceCount[diceThrow] - 3));
            diceCount[diceThrow] = 0;
        }
    }

    score += (diceCount[5]) * 50;
    score += (diceCount[1]) * 100;

    return score;
}
