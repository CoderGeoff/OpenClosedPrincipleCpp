#include "NOfAKindScoresXRule.h"


NOfAKindScoresXRule::NOfAKindScoresXRule(int value, int count, int score)
    :m_ValuePredicate([value](int n){ return n == value; }),
    m_Count(count),
    m_Score(score)
{
}

int NOfAKindScoresXRule::Score() const
{
    return m_Score;
}

bool NOfAKindScoresXRule::Matches(const std::map<int, int>& diceCount, std::map<int, int>* remainingDice) const
{
    std::map<int, int> diceCountAfterApplyingRule = diceCount;
    bool result = TryRemoveMatchingDiceFrom(diceCountAfterApplyingRule);
    *remainingDice = result ? diceCountAfterApplyingRule : diceCount;
    return result;
}

bool NOfAKindScoresXRule::TryRemoveMatchingDiceFrom(std::map<int, int>& diceCount) const
{
    for (int n = 1; n <= 6; ++n)
    {
        if (m_ValuePredicate(n) && diceCount[n] == m_Count)
        {
            diceCount[n] = 0;
            return true;
        }
    }
    return false;
}
