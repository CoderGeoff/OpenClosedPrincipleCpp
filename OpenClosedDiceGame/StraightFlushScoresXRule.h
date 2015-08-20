#pragma once
#include "IScoringRule.h"
class StraightFlushScoresXRule : public IScoringRule
{
    int m_Score;
public:
    StraightFlushScoresXRule(int score);
    ScoringRuleResult TryMatch(const std::map<int, int>& diceCount) const override;
};

