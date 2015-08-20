#pragma once
#include "IScoringRule.h"
class StraightFlushRule : public IScoringRule
{
    int m_Score;
public:
    StraightFlushRule(int score);
    ScoringRuleResult TryMatch(const std::map<int, int>& diceCount) const override;
};

