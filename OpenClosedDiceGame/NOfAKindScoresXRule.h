#pragma once
#include "IScoringRule.h"
#include <functional>

class NOfAKindScoresXRule : public IScoringRule
{
    std::function<bool(int)> m_ValuePredicate;
    int m_Count;
    std::function<int(int)> m_ScoreEvaluator;

    bool TryRemoveMatchingDiceFrom(std::map<int, int>& diceCount) const;

public:
    NOfAKindScoresXRule(int value, int count, int score);
    NOfAKindScoresXRule(std::function<bool(int)> valuePredicate, int count, std::function<int(int)> scoreEvaluator);
    ScoringRuleResult TryMatch(const std::map<int, int>& diceCount) const override;
};

