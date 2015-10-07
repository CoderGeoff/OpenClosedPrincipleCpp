#pragma once
#include "IScoringRule.h"
#include <functional>

class NOfAKindScoresXRule : public IScoringRule
{
    int m_Count;
    std::function<bool(int)> m_ValuePredicate;
    std::function<int(int)> m_ScoreEvaluator;

public:
    NOfAKindScoresXRule(int count, std::function<bool(int)> valuePredicate, std::function<int(int)> scoreEvaluator);
    ScoringRuleResult TryMatch(const std::map<int, int>& diceCount) const override;
};

