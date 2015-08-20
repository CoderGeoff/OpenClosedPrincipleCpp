#pragma once
#include "IScoringRule.h"
#include <vector>

class PatternScoresXRule : public IScoringRule
{
    std::vector<int> m_Pattern;
    int m_Score;
public:
    PatternScoresXRule(std::initializer_list<int> pattern, int score);
    ScoringRuleResult TryMatch(const std::map<int, int>& diceCount) const override;
};

