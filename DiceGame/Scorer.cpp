#include <math.h>
#include "Scorer.h"

Scorer::Scorer(const std::vector<int>& diceThrows)
{
    for (int i = 1; i <= 6; ++i)
    {
        m_Count[i] = std::count(diceThrows.begin(), diceThrows.end(), i);
    }
}


int Scorer::Score() const
{
    int score = 0;

    for (int diceThrow = 1; diceThrow <= 6; ++diceThrow)
    {
        int scoreMultiplier = diceThrow == 1 ? 10 : diceThrow;
        if (GetCountOf(diceThrow) >= 3)
        {
            score += (100 * scoreMultiplier) * static_cast<int>(pow(2, GetCountOf(diceThrow) - 3));
        }
    }

    if (GetCountOf(5) == 1)
        score += 50;

    if (GetCountOf(1) == 1)
        score += 100;

    return score;
}

int Scorer::GetCountOf(int diceThrow) const
{
    auto finder = m_Count.find(diceThrow);
    return finder == m_Count.end() ? 0 : finder->second;
}
