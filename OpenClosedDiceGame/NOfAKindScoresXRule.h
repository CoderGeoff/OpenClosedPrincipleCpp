#pragma once
#include "IScoringRule.h"
#include <functional>

class NOfAKindScoresXRule : public IScoringRule
{
    std::function<bool(int)> m_ValuePredicate;
    int m_Count;
    int m_Score;

    bool TryRemoveMatchingDiceFrom(std::map<int, int>& diceCount) const;

public:
    NOfAKindScoresXRule(int value, int count, int score);
    int Score() const override;
    bool Matches(const std::map<int, int>& diceCount, std::map<int, int>* remainingDice) const override;
};

