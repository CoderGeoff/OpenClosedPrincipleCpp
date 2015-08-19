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
    std::map<int, int> m_Subtractions;

    bool fullStraight = true;
    for (int diceThrow = 1; diceThrow <= 6; ++diceThrow)
    {
        fullStraight = fullStraight && GetCountOf(diceThrow) - m_Subtractions[diceThrow] == 1;
    }
    if (fullStraight)
    {
        for (int diceThrow = 1; diceThrow <= 6; ++diceThrow)
        {
            m_Subtractions[diceThrow]++;
        }
        score += 1500;
    }

    for (int diceThrow = 1; diceThrow <= 6; ++diceThrow)
    {
        int scoreMultiplier = diceThrow == 1 ? 10 : diceThrow;
        int numberOfDice = GetCountOf(diceThrow) - m_Subtractions[diceThrow];
        if (numberOfDice >= 3)
        {
            score += (100 * scoreMultiplier) * static_cast<int>(pow(2, numberOfDice - 3));
            m_Subtractions[diceThrow] += numberOfDice;
        }
    }

    score += (GetCountOf(5) - m_Subtractions[5]) * 50;
    score += (GetCountOf(1) - m_Subtractions[1]) * 100;

    return score;
}

int Scorer::GetCountOf(int diceThrow) const
{
    auto finder = m_Count.find(diceThrow);
    return finder == m_Count.end() ? 0 : finder->second;
}
